/*
 * display.h
 *
 *  Author: RedCAT
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>
#include <avr/io.h>

#define wchar_t int16_t
#define NULL ((void*)0)

#define MASTER_DISPLAY 0x78

#define INVERT_COLORS 1
#define SOLID         2
#define OVERLAY_XOR   4

typedef char* bitmap_t;
typedef void* disp_handle_t;
typedef void (*paint_func_t)(disp_handle_t);

typedef struct Rect {
    uint8_t x;
    uint8_t y;
    uint8_t width;
    uint8_t height;        
} rect_t;

extern const rect_t DISPLAY_FULL;

disp_handle_t disp_init(uint8_t address);
void disp_refresh(disp_handle_t display);
void disp_refresh_rect(disp_handle_t display, rect_t rect);

void disp_set_paint_handler(disp_handle_t display, paint_func_t handler);
void disp_set_font(disp_handle_t display, const char font[]);
void disp_pixel(disp_handle_t display, uint8_t x, uint8_t y, uint8_t options);
void disp_line(disp_handle_t display, uint8_t x, uint8_t y, uint8_t x2, uint8_t y2, uint8_t options);
void disp_rectangle(disp_handle_t display, rect_t rect, uint8_t options);
void disp_draw_bitmap(disp_handle_t display, bitmap_t bitmap, uint8_t x, uint8_t y, uint8_t options);
void disp_draw_text(disp_handle_t display, uint8_t x, uint8_t y, const wchar_t text[], uint8_t options);
void disp_get_text_metrics(disp_handle_t display, const wchar_t text[], uint16_t* width, uint16_t* height);
void disp_get_bitmap_metrics(const char* bitmap, uint16_t* width, uint16_t* height);
uint16_t disp_get_font_baseline(disp_handle_t display);
void disp_clear();



#endif /* DISPLAY_H_ */