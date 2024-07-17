#pragma once
#include <windows.h>
#include "CodeWork.h"

#ifndef macro_header_class_window
#define macro_header_class_window

LPCWSTR main_window_class_name = L"Main window class";
LPCWSTR debugger_window_class_name = L"Debugger window class";
LPCWSTR create_book_window_class_name = L"Create book window class";

WNDCLASSW set_window_class(
	HINSTANCE h_instance,
	HICON icon,
	LPCWSTR class_string_name,
	WNDPROC main_procedure,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	WNDCLASSW result = { 0 };

	result.hbrBackground = (HBRUSH)COLOR_WINDOW;
	result.hInstance = h_instance;
	result.hIcon = icon;
	result.hCursor = LoadCursorW(NULL, IDC_ARROW);
	result.lpszClassName = class_string_name;
	result.lpfnWndProc = main_procedure;

	return result;
}

#endif
