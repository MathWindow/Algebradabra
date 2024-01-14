#pragma once
#include <windows.h>

#ifndef macro_header_widgets
#define macro_header_widgets

LONG x_out = 10;
LONG y_out = x_out;

LONG width_edit_default = 150;
LONG height_edit_default = 20;

HWND edit_main = nullptr;

void create_main_widgets(HWND h_window) {
	edit_main = CreateWindowExW(
		0,
		L"edit",
		L"Эта программа не готова к использованию :-(",
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