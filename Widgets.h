#pragma once
#include <windows.h>
#include "ShortTypes.h"

#ifndef widgets_header
#define widgets_header

svt::u_short x_out = 10;
svt::u_short y_out = x_out;

svt::u_short width_edit_default = 150;
svt::u_short height_edit_default = 20;

svt::u_short width_listbox_default = 200;
svt::u_short height_listbox_default = 300;

svt::u_short width_static_error_list = 300;
svt::u_short height_static_error_list = 300;

HWND edit_main = NULL;

HWND listbox_error_list = NULL;
HWND static_error_list = NULL;

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

void create_error_list_widgets(HWND h_window) {
	
}

#endif