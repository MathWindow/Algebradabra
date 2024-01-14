#pragma once
#include <windows.h>
#include "ShortTypes.h"

#ifndef widgets_header
#define widgets_header

svt::u_short x_out = 10;
svt::u_short y_out = x_out;

svt::u_short width_edit_default = 150;
svt::u_short height_edit_default = 20;

HWND edit_main = NULL;

void create_main_widgets(HWND h_window) {
	edit_main = CreateWindowExW(
		0L,
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
		x_out,
		y_out,
		width_edit_default,
		height_edit_default,
		h_window,
		NULL,
		NULL,
		NULL
	);
}

#endif