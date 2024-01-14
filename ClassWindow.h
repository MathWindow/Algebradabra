#pragma once
#include <windows.h>
#include "resource.h"
#include "HistoryOfError.h"
#include "Translate.h"
#include "AssociationType.h"
#include "VersionInfo.h"

#ifndef class_window_header
#define class_window_header

#define program_author L"Ä. Ì. ×àìêèí"

#define main_window_name program_name L" — main window"
#define error_list_window_name program_name L" — error list"
#define algebraic_book_create_name program_name L" — create algebraic book"

LPCWSTR main_window_class_name = L"Main window";
LPCWSTR error_list_window_class_name = L"Error list window";
LPCWSTR algebraic_book_create_window_class_name = L"Algebraic book create window";

#define class_example_arguments int background_color, HINSTANCE h_instance, int icon, LPCWSTR cursor, LPCWSTR class_string_name, WNDPROC main_procedure
#define procedure_arguments HWND h_window, UINT message, WPARAM w_param, LPARAM l_param

WNDCLASS main_class_example(class_example_arguments) {
	WNDCLASS class_inside = { 0 };

	class_inside.hbrBackground = (HBRUSH)background_color;
	class_inside.hInstance = h_instance;
	class_inside.hIcon = LoadIconW(h_instance, MAKEINTRESOURCE(icon));

	if (cursor == L"From resource")
		class_inside.hCursor = LoadCursor(h_instance, MAKEINTRESOURCE(IDC_POINTER));
	else {
		class_inside.hCursor = LoadCursor(NULL, cursor);
	}

	class_inside.lpszClassName = class_string_name;
	class_inside.lpfnWndProc = main_procedure;

	return class_inside;
}

bool register_class_name(
	WNDCLASS* class_window_input,
	string_param details,
	LPCWSTR function_name
) {
	if (
		!RegisterClassW(class_window_input)
	) {
		error_event_write(
			translate::string_cannot_create_class_name,
			details,
			function_name,
			0,
			0,
			false,
			false,
			translate::string_em_dash,
			translate::string_em_dash,
			NULL,
			true
		);

		return false;
	}
	else {
		return true;
	}
}

#endif