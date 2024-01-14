#pragma once
#include <windows.h>

#ifndef macro_header_widgets
#define macro_header_widgets

LONG x_out = 10;
LONG y_out = x_out;

LONG width_edit_default = 150;
LONG height_edit_default = 20;

HWND edit_main = nullptr;

void create_widgets_main_window(HWND h_window) {
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

HWND listbox_debugger = nullptr;

void create_widgets_debugger_window(HWND h_window) {
	listbox_debugger = CreateWindowExW(
		0,
		L"listbox",
		L"",
		WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL,
		x_out,
		y_out,
		150,
		200,
		h_window,
		NULL,
		NULL,
		NULL
	);
}

#endif