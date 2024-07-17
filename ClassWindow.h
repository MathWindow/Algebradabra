#pragma once
#include <windows.h>
#include <string>
#include "CodeWork.h"
#include "Debugger.h"

#ifndef macro_header_class_window
#define macro_header_class_window

std::wstring window_class_main = L"Main window class";
std::wstring window_class_debugger = L"Debugger window class";
std::wstring window_class_create_book = L"Create book window class";

std::wstring widget_class_static = L"static";
std::wstring widget_class_edit = L"edit";
std::wstring widget_class_button = L"button";
std::wstring widget_class_listbox = L"listbox";

class window_class {
private:
	std::wstring class_name = L"";
public:
	WNDCLASSW main_structure = { 0 };

	void set_class_name(
		std::wstring argument,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		if (class_name == L"") {
			class_name = argument;
		}
	}

	ATOM __stdcall register_(
		bool have_to_do,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		if (have_to_do) {
			size_t size = class_name.size();
			size_t size_ = size + 1;

			wchar_t* class_name_c_style = new wchar_t[size_]{};

			for (
				size_t index_symbol = 0;
				index_symbol < size_;
				index_symbol++
			) {
				if (index_symbol == size) {
					class_name_c_style[index_symbol] = L'\0';
				}
				else {
					class_name_c_style[index_symbol] = class_name.at(index_symbol);
				}
			}

			main_structure.lpszClassName = class_name_c_style;

			ATOM result = RegisterClassW(&main_structure);

			if (result == FALSE) {
#if turn_debugger_on
				debug::write_event(
					debug::title_cannot_register_class_name,
					place,
					nullptr,
					debug::handle_type_none,
					class_name
				);
#endif
			}

			delete[] class_name_c_style;

			return result;
		}

		return 0;
	}
};

window_class set_window_class(
	bool have_to_do,
	HINSTANCE h_instance,
	HICON icon,
	std::wstring class_string_name,
	WNDPROC main_procedure,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	window_class result{};

	if (have_to_do) {
		result.main_structure.hbrBackground = ( HBRUSH ) COLOR_WINDOW;
		result.main_structure.hInstance = h_instance;
		result.main_structure.hIcon = icon;
		result.main_structure.hCursor = LoadCursorW(NULL, IDC_ARROW);
		result.set_class_name(class_string_name, place);
		result.main_structure.lpfnWndProc = main_procedure;
	}

	return result;
}

#endif
