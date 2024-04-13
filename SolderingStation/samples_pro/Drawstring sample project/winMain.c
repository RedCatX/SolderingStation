/*********************************************************************
 * Sample code to draw character with "General *.c file"             *
 *                      == created by BitFontCreator                 *
 *                      == http://www.iseasoft.com/                  *
 *                      == support@iseatech.com                      *
 *                                                                   *
 * NOTE: BitFontCreator can generate various format data,            *
 *       This smaple code is limited to the format blow:             *
 *       Font Type:     1-bpp, 2-bpp, 4-bpp                          *
 *       Data length:   8 bit                                        *
 *       Bit order:     Big Endian                                   *
 *       Scan based:    Row                                          *
 *       Scan prefered: Row                                          *
 *       Data Packed:   No                                           *
 *********************************************************************/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN

/* NOTE: Since this is a Windows application, not a console one,     *
 *       you should make sure to set the following link option:      *
 *                                                                   *
 *       /subsystem:windows                                          *
 *                                                                   *
 *       to compile it successfully.                                 *
 *********************************************************************/

#include "bfcfont.h"
#include "drawstring.h"

const char g_szClassName[] = "bfcWindowClass";

//extern const BFC_FONT fontLucida_Sans_Unicode16h_rowrowBig;
extern const BFC_FONT fontLucida_Sans_Unicode16h_colcolLit;

// 4. the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			
			// ascii string
			char strA_big[]   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			char strA_sm[]    = "abcdefghijklmnopqrstuvwxyz";
			char strA_digit[] = "1234567890(#$&%!=+-@?)";
			// chinese string
			unsigned short strW_chinese[]  = L"\x4f60\x597d\xff0c\x4e16\x754c\x676f";
			// japanese string
			unsigned short strW_japanese[] = L"\x3053\x3093\x306b\x3061\x306f\xff64\x30ef\x30fc\x30eb\x30c9\x30ab\x30c3\x30d7";
			// korean string
			unsigned short strW_korean[]   = L"\xc548\xb155\xd558\xc138\xc694\xff0c\xc6d4\xb4dc\xcef5";

			// Font
			//const BFC_FONT *pFont = &fontLucida_Sans_Unicode16h_rowrowBig;
			const BFC_FONT *pFont = &fontLucida_Sans_Unicode16h_colcolLit;

			int x = 80;
			int y = 30;
			int height = GetFontHeight(pFont);
			int delta = height + 5;

			// Prepare
			HDC hdc = BeginPaint(hwnd, &ps);

			DrawStringA(hdc, x, y, pFont, strA_big, strlen(strA_big));
			y += delta;
			DrawStringA(hdc, x, y, pFont, strA_sm, strlen(strA_sm));
			y += delta;
			DrawStringA(hdc, x, y, pFont, strA_digit, strlen(strA_digit));
			y += delta;

			y += 10;
			DrawStringW(hdc, x, y, pFont, strW_chinese, sizeof(strW_chinese)/sizeof(unsigned short) - 1);
			y += delta;
			DrawStringW(hdc, x, y, pFont, strW_japanese, sizeof(strW_japanese)/2 - 1);
			y += delta;
			DrawStringW(hdc, x, y, pFont, strW_korean, sizeof(strW_korean)/2 - 1);

			// End
			EndPaint(hwnd, &ps);
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return 0;
}

int WINAPI WinMain(  HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;

	// 1. Registering the window class
	wc.cbSize			= sizeof(WNDCLASSEX);
	wc.style			= 0;
	wc.lpfnWndProc		= WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= hInstance;
	wc.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm			= LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= g_szClassName;

	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Regsitration Failed!", "Error!", 
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	// 2. Creating the Window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		"Sample: draw strings via BitFontCreator Pro 3.x",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 480, 240,
		NULL, NULL, hInstance, NULL);

	if(hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!", 
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// 3. The Message Loop
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}



