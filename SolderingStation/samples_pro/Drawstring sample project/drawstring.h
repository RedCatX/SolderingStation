/*********************************************************************
 * Example code to draw character with "General *.c file"            *
 *                      == http://www.iseasoft.com/                  *
 *                      == support@iseatech.com                      *
 *                                                                   *
 * NOTE: BitFontCreator can generate various format data,            *
 *       This sample code is limited to the format blow:             *
 *       Font Type:     1-bpp, 2-bpp, 4-bpp                          *
 *       Data length:   8 bit                                        *
 *       Bit order:     Big Endian, Little Endian                    *
 *       Scan based:    Row, Column                                  *
 *       Scan prefered: Row, Column                                  *
 *       Data Packed:   No                                           *
 *********************************************************************/
#ifndef __DRAW_STRING_BFC_H_INCLUDE__
#define __DRAW_STRING_BFC_H_INCLUDE__

#include <windef.h>
#include "bfcfont.h"

//  font height: in pixels
int GetFontHeight(const BFC_FONT *pFont);
//  draw ansi string
void DrawStringA(HDC hdc, int x0, int y0, const BFC_FONT *pFont, const char *str, int length);
//  draw wide string
void DrawStringW(HDC hdc, int x0, int y0, const BFC_FONT *pFont, const unsigned short *str, int length);


//  bpp: 1, 2, 4 or 8 (bits per pixel)
int GetFontBpp(unsigned long FontType);
//  bit order: 0 (Big Endian), or 1 (Little Endian)
int GetFontEndian(unsigned long FontType);
//  scan based: 0 (row), or 1 (column)
int GetFontScanBase(unsigned long FontType);
//  scan prfered: 0 (row), or 1 (column)
int GetFontScanPrefer(unsigned long FontType);
//  data packed: 0 (No), or 1 (Yes)
int GetFontDataPack(unsigned long FontType);

const BFC_CHARINFO* GetCharInfo(const BFC_FONT *pFont, unsigned short ch);
unsigned long LCD_GetColorBasedPixel(int pixel, int bpp);

void LCD_DrawPixel(HDC hdc, int x, int y, int color);
int  DrawChar(HDC hdc, int x0, int y0, const BFC_FONT *pFont, unsigned short ch);
int  DrawChar_RowRowUnpacked(HDC hdc, int x0, int y0, const BFC_FONT *pFont, unsigned short ch);
int  DrawChar_ColColUnpacked(HDC hdc, int x0, int y0, const BFC_FONT *pFont, unsigned short ch);

#endif
