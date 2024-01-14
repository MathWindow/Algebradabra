#pragma once
#include <windows.h>
#include <commdlg.h>
#include <array>
#include <cstring>

#ifndef macro_header_color_dialog
#define macro_header_color_dialog

CHOOSECOLORW choose_color_1;
static COLORREF rgb_current_1 = RGB(200, 200, 200);
std::array<COLORREF, 16> acr_custom_color_1;

void plan_choose_color_technical_check(HWND h_window) {
	memset(&choose_color_1, 0, sizeof(choose_color_1));
	
	choose_color_1.lStructSize = sizeof(choose_color_1);
	choose_color_1.hwndOwner = h_window;
	choose_color_1.lpCustColors = acr_custom_color_1.data();
	choose_color_1.rgbResult = rgb_current_1;
	choose_color_1.Flags = CC_FULLOPEN | CC_RGBINIT;
}
#else

#endif