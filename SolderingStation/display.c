/*
 * display.c
 *
 *  Author: RedCAT
 */ 

#include <avr/pgmspace.h>
#include <stdbool.h>
#include "display.h"
#include "setup.h"

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

#define I2CPORT PORTD
// A bit set to 1 in the DDR is an output, 0 is an INPUT
#define I2CDDR DDRD

// Pin or port numbers for SDA and SCL
#define BB_SDA 2
#define BB_SCL 3

#if F_CPU > 8000000L
    #define I2C_CLK_LOW() I2CPORT &= ~(1 << BB_SCL) //compiles to cbi instruction taking 2 clock cycles, extending the clock pulse
#else
    #define I2C_CLK_LOW() I2CPORT = bOld //setting a port instruction takes 1 clock cycle
#endif

#define __(h) ((struct DisplayOptions*) h)

struct DisplayOptions {
    uint8_t      address;
    rect_t       rect;
    const char  *font;
    uint8_t      drawOptions;
    paint_func_t onPaint;
};

struct CharacterInfo {
    uint16_t width;
    uint16_t size;
    const char* bitmap;
};

const rect_t DISPLAY_FULL = { 0, 0, 128, 64 };

struct DisplayOptions Displays[2] = { 0 };

uint8_t DisplayBuf[1024];
uint8_t DisplayInit[22] = { 0x00, 0xAE, 0xA8, 0x3F, 0xD3, 0x00, 0x40, 0xA1,
                            0xC8, 0xDA, 0x12, 0x81, 0xFF, 0xA4, 0xA6, 0xD5,
                            0x80, 0x8D, 0x14, 0xAF, 0x20, 0x00 };
                            
//
// Transmit a byte and ack bit
//
static inline void i2c_byte_out(uint8_t b)
{
    uint8_t i;
    uint8_t bOld = I2CPORT & ~((1 << BB_SDA) | (1 << BB_SCL));
    for (i = 0; i < 8; i++) 
    {
        bOld &= ~(1 << BB_SDA);
        if (b & 0x80)
            bOld |= (1 << BB_SDA);
        I2CPORT = bOld;
        I2CPORT |= (1 << BB_SCL);
        I2C_CLK_LOW();
        b <<= 1;
    }
    // ACK bit
    I2CPORT = bOld & ~(1 << BB_SDA); // set data low
    I2CPORT |= (1 << BB_SCL); // toggle clock
    I2C_CLK_LOW();
}  

void i2c_start(uint8_t address)
{
    I2CPORT |= ((1 << BB_SDA) + (1 << BB_SCL));
    I2CDDR |= ((1 << BB_SDA) + (1 << BB_SCL));
    I2CPORT &= ~(1 << BB_SDA); // data line low first
    I2CPORT &= ~(1 << BB_SCL); // then clock line low is a START signal
    i2c_byte_out(address); // send the slave address
}

void i2c_write(uint8_t *pData, uint8_t bLen)
{
    uint8_t i, b;
    uint8_t bOld = I2CPORT & ~((1 << BB_SDA) | (1 << BB_SCL));

    while (bLen--)
    {
        b = *pData++;
        if (b == 0 || b == 0xff) // special case can save time
        {
            bOld &= ~(1 << BB_SDA);
            if (b & 0x80)
            bOld |= (1 << BB_SDA);
            I2CPORT = bOld;
            for (i = 0; i < 8; i++)
            {
                I2CPORT |= (1 << BB_SCL); // just toggle SCL, SDA stays the same
                I2C_CLK_LOW();
            }
        }
        else // normal uint8_t needs every bit tested
        {
            for (i = 0; i < 8; i++)
            {
                bOld &= ~(1 << BB_SDA);
                if (b & 0x80)
                    bOld |= (1 << BB_SDA);

                I2CPORT = bOld;
                I2CPORT |= (1 << BB_SCL);
                I2C_CLK_LOW();
                b <<= 1;
            }
        }
        // ACK bit seems to need to be set to 0, but SDA line doesn't need to be tri-state
        I2CPORT &= ~(1 << BB_SDA);
        I2CPORT |= (1 << BB_SCL); // toggle clock
        I2CPORT &= ~(1 << BB_SCL);
    }
}

//
// Send I2C STOP condition
//
void i2c_stop()
{
    I2CPORT &= ~(1 << BB_SDA);
    I2CPORT |= (1 << BB_SCL);
    I2CPORT |= (1 << BB_SDA);
    I2CDDR &= ~((1 << BB_SDA) | (1 << BB_SCL)); // let the lines float (tri-state)
}

// Wrapper function to write I2C data
static void i2c_send(uint8_t address, uint8_t* data, uint16_t len)
{
    i2c_start(address);
    i2c_write(data, len);
    i2c_stop();
}  

static void disp_command(uint8_t address, uint8_t command)  
{
    uint8_t CmdBuf[2];
    CmdBuf[0] = 0x00;
    CmdBuf[1] = command;
    i2c_send(address, CmdBuf, 2);
}   

void disp_send_buffer(disp_handle_t display)
{
    const uint8_t startPage = __(display)->rect.y / 8,
                  endPage = (__(display)->rect.y + __(display)->rect.height - 1) / 8;
    
    disp_command(__(display)->address, 0x21);
    disp_command(__(display)->address, __(display)->rect.x);
    disp_command(__(display)->address, __(display)->rect.x + __(display)->rect.width - 1);
    disp_command(__(display)->address, 0x22);
    disp_command(__(display)->address, startPage);
    disp_command(__(display)->address, endPage);
    
    for (uint8_t page = startPage; page <= endPage; page++) 
    {
        i2c_start(__(display)->address);
        i2c_byte_out(0x40);
        i2c_write(DisplayBuf + __(display)->rect.x + 128 * page, __(display)->rect.width);
        i2c_stop();
    }
}             

disp_handle_t disp_init(uint8_t address)
{    
    struct DisplayOptions* d;
                   
    if (Displays[0].address == address || 
        Displays[0].address == 0)
    {
        d = &(Displays[0]);    
    }                   
    else {
        d = &(Displays[1]);
    }
    
    d->address = address;
    d->drawOptions = 0;
    d->font = NULL;
    d->onPaint = NULL;
    d->rect = DISPLAY_FULL;
    
    i2c_send(address, DisplayInit, 22);
    disp_clear();
    disp_send_buffer(d);
    
    return d;
}

void disp_refresh(disp_handle_t display)
{
    disp_refresh_rect(display, DISPLAY_FULL);
}

void disp_refresh_rect(disp_handle_t display, rect_t rect)
{
    disp_clear();
    
    __(display)->rect = rect;
    if (__(display)->onPaint)
        __(display)->onPaint(display);
        
    disp_send_buffer(display);
}

void disp_set_paint_handler(disp_handle_t display, paint_func_t handler)
{
    __(display)->onPaint = handler;
}

void disp_set_font(disp_handle_t display, const char font[])
{
    __(display)->font = font;
}

bool intersects(rect_t a, rect_t b)
{
    return (a.y < b.y + b.height || 
            a.y + a.height > b.y || 
            a.x + a.width < b.x  || 
            a.x > b.x + b.width);
}

#define OR  0
#define AND 1
#define XOR 2 

void disp_set_segment(uint8_t pageNum, uint8_t segNum, uint8_t seg, uint8_t overlay)
{
    if (pageNum <= 7 && segNum <= 127)
    {
        switch (overlay) {
            case AND:
                DisplayBuf[pageNum * 128 + segNum] &= seg;
                break;
            
            case XOR:
                DisplayBuf[pageNum * 128 + segNum] ^= seg;
                break;
            
            case OR:    
            default:
                DisplayBuf[pageNum * 128 + segNum] |= seg;
                break;
        }
    }
}   

void disp_pixel(disp_handle_t display, uint8_t x, uint8_t y, uint8_t options)
{
    const uint8_t page = y / 8;
    const uint8_t overlayMode = (options & OVERLAY_XOR ? XOR : OR);
    
    disp_set_segment(page, x, 1 << (y % 8), overlayMode);
} 

void disp_line(disp_handle_t display, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t options)
{
    uint8_t dx, dy;
    int8_t sx, sy;
    int16_t err;
    
    if (x1 < x2)
    {
        dx = x2 - x1;
        sx = 1;
    }
    else 
    {
        dx = x1 - x2;
        sx = -1;
    }
    
    if (y1 < y2)
    {
        dy = y2 - y1;
        sy = 1;
    }
    else 
    {
        dy = y1 - y2;
        sy = -1;
    }
    
    err = (dx - dy) * 2;
    disp_pixel(display, x2, y2, options);
    while (x1 != x2 || y1 != y2)
    {       
        disp_pixel(display, x1, y1, options);
        if (err > -dy)
        {
            err -= dy * 2;
            x1 += sx;
        }
        if (err < dx)
        {
            err += dx * 2;
            y1 += sy;
        }
    }
}

void disp_rectangle(disp_handle_t display, rect_t rect, uint8_t options)
{
    if (intersects(rect, __(display)->rect)) 
    {
        const uint8_t startPage = rect.y / 8,
                      endPage = (rect.y + rect.height - 1) / 8;
        const uint8_t overlayMode = (options & OVERLAY_XOR ? XOR : OR);
        const uint8_t x1 = rect.x + rect.width - 1,
                      y1 = rect.y + rect.height - 1;
        
        uint8_t page, x;
        
        if (startPage == endPage) 
        {
            uint8_t seg = (0xFF << (rect.y % 8)) & (0xFF >> (7 - y1 % 8));
            if (options & SOLID) 
            {
                for (x = rect.x; x <= x1; x++)
                    disp_set_segment(startPage, x, seg, overlayMode);
            }
            else 
            {
                disp_set_segment(startPage, rect.x, seg, overlayMode);
                disp_set_segment(startPage, x1, seg, overlayMode);
                seg = (1 << (rect.y % 8)) | (1 << (y1 % 8));
                for (x = rect.x + 1; x < x1; x++)
                    disp_set_segment(startPage, x, seg, overlayMode);
            }                
        }
        else {
            uint8_t startPageSeg = 0xFF << (rect.y % 8),
                    endPageSeg = 0xFF >> (7 - y1 % 8);
                    
            disp_set_segment(startPage, rect.x, startPageSeg, overlayMode);
            disp_set_segment(startPage, x1, startPageSeg, overlayMode);
            disp_set_segment(endPage, rect.x, endPageSeg, overlayMode);
            disp_set_segment(endPage, x1, endPageSeg, overlayMode);
            
            if ((options & SOLID) == 0) 
            {
                startPageSeg = 1 << (rect.y % 8);
                endPageSeg = 1 << (y1 % 8);
            }
            
            for (x = rect.x + 1; x < x1; x++) 
            {
                disp_set_segment(startPage, x, startPageSeg, overlayMode);
                disp_set_segment(endPage, x, endPageSeg, overlayMode);
            }
            
            for (page = startPage + 1; page <= endPage - 1; page++)
            {
                disp_set_segment(page, rect.x, 0xFF, overlayMode);
                disp_set_segment(page, x1, 0xFF, overlayMode);
                if (options & SOLID) 
                {
                    for (x = rect.x; x <= x1; x++)
                        disp_set_segment(page, x, 0xFF, overlayMode);
                }
            }               
        }   
    }
}

void disp_draw_glyph(disp_handle_t display, const char* bmp, uint8_t size, rect_t rect, uint8_t options)
{
    const uint8_t offsetY = rect.y % 8;
    const uint8_t overlayMode = (options & OVERLAY_XOR ? XOR : OR);
    
    uint8_t page = rect.y / 8;
    uint8_t offsetX = 0;
      
    for (uint16_t i = 0; i < size; i++)
    {
        offsetX = i % rect.width;
        if (offsetX == 0 && i > 0)
            page++;
            
        disp_set_segment(page, rect.x + offsetX, pgm_read_byte(bmp + i) << offsetY, overlayMode);
        if (offsetY > 0)
            disp_set_segment(page + 1, rect.x + offsetX, pgm_read_byte(bmp + i) >> (8 - offsetY), overlayMode);        
    }
}

void disp_draw_bitmap(disp_handle_t display, bitmap_t bitmap, uint8_t x, uint8_t y, uint8_t options)
{
    rect_t bmpRect = { x, y, pgm_read_byte(bitmap), pgm_read_byte(bitmap + 1) };
    disp_draw_glyph(display, bitmap + 4, pgm_read_word(bitmap + 2), bmpRect, options);
}

struct CharacterInfo get_char_info(disp_handle_t display, wchar_t ch)
{
    struct CharacterInfo charInfo = { 0, 0, 0 };
    
    uint16_t rangesCount = pgm_read_word(__(display)->font + 4);
    uint16_t base = 6 + rangesCount * 4;
    
    for (uint16_t i = 6; i < (6 + rangesCount * 4); i += 4)
    {
        const wchar_t firstChar = pgm_read_word(__(display)->font + i),
                      lastChar = pgm_read_word(__(display)->font + i + 2);
        
        if (ch >= firstChar && ch <= lastChar)
        {
            base += (ch - firstChar) * 6;
            charInfo.width = pgm_read_word(__(display)->font + base);
            charInfo.size = pgm_read_word(__(display)->font + base + 2);
            charInfo.bitmap = __(display)->font + pgm_read_word(__(display)->font + base + 4);
            break;
        }
        
        base += (lastChar - firstChar + 1) * 6;
    }
    
    return charInfo;
}

void disp_draw_text(disp_handle_t display, uint8_t x, uint8_t y, const wchar_t text[], uint8_t options)
{
    if (!__(display)->font)
        return;
    
    rect_t chRect = { x, y, 0, pgm_read_word(__(display)->font) };    
    struct CharacterInfo chInfo;
    
    for (uint8_t i = 0; i < 255; i++) 
    {
        if (text[i] != 0)
        {
            chInfo = get_char_info(display, text[i]);
            chRect.width = chInfo.width;
            disp_draw_glyph(display, chInfo.bitmap, chInfo.size, chRect, options);
            chRect.x += chRect.width;
        }
        else
            break;        
    }
}

void disp_get_text_metrics(disp_handle_t display, const wchar_t text[], uint16_t* width, uint16_t* height)
{
    if (!__(display)->font)
        return; 
        
    if (height)
        *height = pgm_read_word(__(display)->font);
    
    if (width)
    {
        *width = 0;
        for (uint8_t i = 0; i < 255; i++)
        {
            if (text[i] != 0)
                *width += get_char_info(display, text[i]).width;
            else
                break;
        }
    }
}

void disp_get_bitmap_metrics(const char* bitmap, uint16_t* width, uint16_t* height)
{
    if (width) 
        *width = pgm_read_byte(bitmap);
        
    if (height) 
        *height = pgm_read_byte(bitmap + 1);
}

uint16_t disp_get_font_baseline(disp_handle_t display)
{
    if (__(display)->font)
        return pgm_read_word(__(display)->font + 2);
        
    return 0;
}

void disp_clear()
{
    for (uint16_t i = 0; i < 1024; i++)
        DisplayBuf[i] = 0;
}
