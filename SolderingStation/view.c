/*
 * view.c
 *
 * Created: 05.11.2021 22:01:32
 *  Author: RedCAT
 */ 

#include "view.h"
#include "display.h"
#include "strings.h"
#include "images.h"
#include "fonts.h"
#include "model.h"
#include "controller.h"
#include "fcpu.h"

#include <stdbool.h>
#include <stdarg.h>

typedef void* (*menu_val_func_t)();

typedef enum MenuItemType
{
    MENUITEM_TEXTONLY = 0,
    MENUITEM_VALUE,
    MENUITEM_CHECKBOX
} menuitem_type_t;

typedef struct MenuItem
{
    wchar_t *text;
    const char* bitmap;
    menu_val_func_t func;
    menuitem_type_t type;
} menuitem_t;

typedef struct Menu
{
    wchar_t *title;
    uint8_t count;
    menuitem_t items[];
} menu_t;

#define TEXT_BUFFER_SIZE 32
wchar_t textBuffer[TEXT_BUFFER_SIZE];

wchar_t iron_tip[] = L"T12-K";

disp_handle_t display;
bool dirtyFlag = false;
rect_t dirtyArea;

const menu_t* pMenu;
uint8_t menuFirstItem = 0,
        menuLastItem = 3,
        menuSelection = 0;

int bprintf(const wchar_t format[], ...)
{
    unsigned char i = 0, 
                  buf_i = 0;
                  
    va_list argptr;
    va_start(argptr, format);
    
    while (format[i] != 0)
    {
        if (format[i] == L'%')
        {
            i++;
            if (format[i] == L'%')
            {
                textBuffer[buf_i] = format[i];
                buf_i++;
            }
            else if (format[i] == L'd')
            {
                int number = va_arg(argptr, int); 
                unsigned char digitsCount = 0, 
                              lastDigitPos = buf_i;
                char m = 1;
                              
                if (number < 0)
                    m = -1;
                
                do {                   
                    for (; lastDigitPos > buf_i; lastDigitPos--)
                        textBuffer[lastDigitPos] = textBuffer[lastDigitPos - 1];
                    
                    textBuffer[buf_i] = L'0' + number % 10 * m;
                    number /= 10;
                    digitsCount++;
                    lastDigitPos = buf_i + digitsCount;
                    if (lastDigitPos == TEXT_BUFFER_SIZE - 2)
                        lastDigitPos--;
                } while (number > 0);
                
                if (m == -1)
                {
                    for (; lastDigitPos > buf_i; lastDigitPos--)
                        textBuffer[lastDigitPos] = textBuffer[lastDigitPos - 1];
                    
                    textBuffer[buf_i] = L'-';
                }
                
                buf_i = lastDigitPos;
            }
            else if (format[i] == L's')
            {
                wchar_t* str = va_arg(argptr, wchar_t*);
                unsigned char j = 0;
                while (str[j] != 0)
                {
                    textBuffer[buf_i] = str[j];
                    buf_i++;
                    j++;
                    if (buf_i == TEXT_BUFFER_SIZE - 1)
                        break;
                }
            }
        }
        else
        {
            textBuffer[buf_i] = format[i];
            buf_i++;
        }
        // End of buffer
        if (buf_i == TEXT_BUFFER_SIZE - 1)
            break;
            
        i++;
    }
    
    va_end(argptr);
    
    textBuffer[buf_i] = 0;
    return buf_i;
}

void* get_iron_tip()
{
    return iron_tip;
}

void* get_temp_val()
{
    bprintf(str_CelsiusDeg, get_temperature());
    return textBuffer;
}

void* get_boost_val() 
{
    return L"+50С°, 30с"; 
}

void* get_sleep_val() 
{ 
    return L"через 10 мин."; 
}

void on_draw_menu(disp_handle_t disp)
{
    uint8_t itemY = 13;
    uint16_t textWidth;
    uint16_t bitmapWidth = 0;
    rect_t rect = {0, 7, 128, 57};
 
    disp_set_font(disp, fontMSSansSerif8pt);
    disp_get_text_metrics(disp, pMenu->title, &textWidth, NULL);
    
    // Draw frame
    disp_rectangle(disp, rect, 0);
    // Draw title
    disp_line(disp, (122 - textWidth) / 2, 7, (134 + textWidth) / 2, 7, OVERLAY_XOR);
    disp_draw_text(disp, (128 - textWidth) / 2, 0, pMenu->title, SOLID | INVERT_COLORS);
    
    rect.height = menuSelection == menuLastItem ? 13 : 12;
    
    for (uint8_t i = menuFirstItem; i <= menuLastItem; i++)
    {
        if (i == menuSelection)
        {
            rect.y = itemY + 1;
            disp_rectangle(disp, rect, SOLID);
        }
        
        if (pMenu->items[i].bitmap)
        {
            disp_get_bitmap_metrics(pMenu->items[i].bitmap, &bitmapWidth, NULL);
            bitmapWidth += 2;
            disp_draw_bitmap(disp, pMenu->items[i].bitmap, 4, itemY + 2, OVERLAY_XOR);
            disp_draw_text(disp, bitmapWidth + 4, itemY, pMenu->items[i].text, OVERLAY_XOR);
        }
        else 
        {
            disp_draw_text(disp, 4, itemY, pMenu->items[i].text, OVERLAY_XOR);
        }            
            
        if (pMenu->items[i].type == MENUITEM_VALUE)
        {
            disp_get_text_metrics(disp, pMenu->items[i].text, &textWidth, NULL);
            disp_draw_text(disp, 7 + textWidth + bitmapWidth, itemY, pMenu->items[i].func(), OVERLAY_XOR);
        }
        else if (pMenu->items[i].type == MENUITEM_CHECKBOX)
        {
            disp_get_text_metrics(disp, pMenu->items[i].text, &textWidth, NULL);
            disp_draw_bitmap(disp, (pMenu->items[i].func() ? bmpCheckbox_1 : bmpCheckbox_0), 7 + textWidth + bitmapWidth, itemY + 2, OVERLAY_XOR);
            disp_draw_text(disp, 29 + textWidth + bitmapWidth, itemY, (pMenu->items[i].func() ? str_On : str_Off), OVERLAY_XOR);
        }
        
        itemY += 12;
    }
}

void on_draw_main_scrren(disp_handle_t disp)
{
    uint16_t textWidth;

    // Draw "Set" info
    bprintf(str_Set, get_temperature());
    disp_set_font(disp, fontMSSansSerif8pt);
    disp_get_text_metrics(disp, textBuffer, &textWidth, NULL);
    disp_draw_text(disp, (128 - textWidth) / 2, 0, textBuffer, 0);
    
    // Draw "Tip" info
    bprintf(str_IronTip, get_iron_tip());
    disp_get_text_metrics(disp, textBuffer, &textWidth, NULL); 
    disp_draw_text(disp, (128 - textWidth) / 2, 50, textBuffer, 0);
    if (get_boost_mode())
        disp_draw_bitmap(disp, bmpFire, 12, 15, 0);
    else
        disp_draw_bitmap(disp, bmpThermometer, 12, 15, 0);
    
    // Draw current temperature
    disp_set_font(disp, fontCalibri28pt);
    bprintf(str_CelsiusDeg, get_measured_temp());
    disp_draw_text(disp, 34, 14, textBuffer, 0);
}

void invalidate_screen()
{
    dirtyFlag = true;
    dirtyArea = DISPLAY_FULL;
}

void view_init()
{
    display = disp_init(MASTER_DISPLAY);
}

void view_update()
{
    if (dirtyFlag)
    {
        disp_refresh(display);
        dirtyFlag = false;
    }
}

void view_main_screen()
{
    dirtyFlag = true;
    dirtyArea = DISPLAY_FULL;
    disp_set_paint_handler(display, &on_draw_main_scrren);
}

void view_menu(const menu_t* menu)
{
    dirtyFlag = true;
    dirtyArea = DISPLAY_FULL;
    pMenu = menu;
    menuFirstItem = 0;
    menuLastItem = 3;
    menuSelection = 0;
    disp_set_paint_handler(display, &on_draw_menu);
}

void view_main_menu()
{
    static const menu_t settingsMenu = 
    {
        str_Settings, 
        6,
        {{
            str_Return,
            bmpSmallArrowLeft,
            NULL,
            MENUITEM_TEXTONLY
         }, {
            str_IronTip,
            bmpSmallArrowRight,
            &get_iron_tip,
            MENUITEM_VALUE
         }, {
             str_Temperature,
             bmpSmallArrowRight,
             &get_temp_val,
             MENUITEM_VALUE
         }, {
             str_Boost,
             bmpSmallArrowRight,
             &get_boost_val,
             MENUITEM_VALUE
         }, {
             str_Sleep,
             bmpSmallArrowRight,
             &get_sleep_val,
             MENUITEM_VALUE
         }, {
             str_Beep,
             bmpBullet,
             &get_signal_state,
             MENUITEM_CHECKBOX
         }}    
    };
    
    view_menu(&settingsMenu);
}

void menu_selection_up()
{
    if (menuSelection > 0)
    {
        dirtyFlag = true;
        menuSelection--;
        
        if (menuSelection < menuFirstItem)
        {
            menuFirstItem--;
            menuLastItem--;
            dirtyArea = DISPLAY_FULL;
        }
        else
        {
            dirtyArea.x = 0;
            dirtyArea.y = 13 + (menuSelection - menuFirstItem) * 12;
            dirtyArea.width = 128; 
            dirtyArea.height = 24; 
        }
    }
}

void menu_selection_down()
{
    if (menuSelection < pMenu->count - 1)
    {
        dirtyFlag = true;
        menuSelection++;
        
        if (menuSelection > menuLastItem)
        {
            menuFirstItem++;
            menuLastItem++;
            dirtyArea = DISPLAY_FULL;
        }
        else
        {
            dirtyArea.x = 0;
            dirtyArea.y = 13 + (menuSelection - menuFirstItem - 1) * 12;
            dirtyArea.width = 128;
            dirtyArea.height = 24;
        }
    }       
}

void menu_refresh_selected()
{
    dirtyFlag = true;
    dirtyArea.x = 0;
    dirtyArea.y = 13 + (menuSelection - menuFirstItem) * 12;
    dirtyArea.width = 128;
    dirtyArea.height = 12;
}

void on_draw_temp_screen(disp_handle_t disp)
{
    uint16_t textWidth;
    
    disp_set_font(disp, fontMSSansSerif8pt);
    disp_get_text_metrics(disp, str_Temperature, &textWidth, NULL);
    disp_draw_text(disp, (128 - textWidth) / 2, 0, str_Temperature, 0);
    disp_get_text_metrics(disp, str_Finish, &textWidth, NULL);
    disp_draw_text(disp, (128 - textWidth) / 2, 49, str_Finish, 0);
    disp_draw_bitmap(disp, bmpClick, (106 - textWidth) / 2, 50, 0);
    disp_set_font(disp, fontCalibri28pt);
    bprintf(str_CelsiusDeg, get_temp_adj());
    disp_get_text_metrics(disp, textBuffer, &textWidth, NULL);
    disp_draw_text(disp, (128 - textWidth) / 2, 14, textBuffer, 0);
    disp_draw_bitmap(disp, bmpArrowLeft, 2, 25, 0);
    disp_draw_bitmap(disp, bmpArrowRight, 113, 25, 0);
}

void view_temp_set_screen()
{
    dirtyFlag = true;
    dirtyArea = DISPLAY_FULL;
    disp_set_paint_handler(display, &on_draw_temp_screen);
}

void temp_set_screen_refresh()
{
    dirtyFlag = true;
}

