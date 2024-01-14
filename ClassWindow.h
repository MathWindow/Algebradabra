#pragma once
#include <windows.h>
#include "Translate.h"

#ifndef class_window_header
#define class_window_header

LPCWSTR main_window_class_name = L"Main window class";

WNDCLASSW main_class_example(
	int background_color,
	HINSTANCE h_instance,
	int icon,
	LPCWSTR cursor,
	LPCWSTR class_string_name,
	WNDPROC main_procedure
) {
	WNDCLASSW class_bringer = { 0 };

	class_bringer.hbrBackground = (HBRUSH)background_color;
	class_bringer.hInstance = h_instance;
	class_bringer.hIcon = LoadIconW(h_instance, MAKEINTRESOURCEW(icon));
	class_bringer.hCursor = LoadCursorW(NULL, cursor);
	class_bringer.lpszClassName = class_string_name;
	class_bringer.lpfnWndProc = main_procedure;

	return class_bringer;
}

bool register_class_name(
	WNDCLASSW* class_window_input,
	translate::string_ details
) {
	if (!RegisterClassW(class_window_input)) {
		MessageBoxW(
			NULL, 
			details.show_fixed(),
			translate::string_program_name.show_fixed(),
			MB_ICONERROR
		);

		return false;
	}
	else {
		return true;
	}
}

#endif
