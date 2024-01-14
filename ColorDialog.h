#pragma once
#include <windows.h>
#include <commdlg.h>

#ifndef color_dialog_header
#define color_dialog_header

CHOOSECOLOR choose_color_1;
static DWORD rgb_current;

void plan_choose_color_dialog(HWND h_window) {
	ZeroMemory(&choose_color_1, sizeof(choose_color_1));
	
	choose_color_1.hwndOwner = h_window;
	choose_color_1.lStructSize = sizeof(choose_color_1);
	choose_color_1.Flags = CC_FULLOPEN | CC_RGBINIT;
	choose_color_1.rgbResult = rgb_current;
}

#endif