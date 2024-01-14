#pragma once
#include <windows.h>
#include "Debugger.h"
#include "ShortTypes.h"

#ifndef macro_header_widgets
#define macro_header_widgets

LONG x_out = 10;
LONG y_out = x_out;

LONG edit_width_default = 150;
LONG edit_height_default = 20;

LONG listbox_width_default = 200;
LONG listbox_height_default = 200;

LONG static_width_event_type = 300;
LONG static_height_event_type = 20;

LONG static_width_details = 300;
LONG static_height_details = 40;

HWND edit_main = nullptr;

void create_widgets_main_window(HWND h_window) {
	edit_main = CreateWindowExW(
		0,
		L"edit",
		L"Эта программа не готова к использованию :-(",
		WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
		x_out,
		y_out,
		edit_width_default,
		edit_height_default,
		h_window,
		NULL,
		NULL,
		NULL
	);

	debug::write_event(
		debug::event_type_message,
		debug::characteristic_none,
		debug::title_index_just_message,
		debug::details_index_it_is_a_test,
		{},
		{},
		{}
	);

	debug::write_event(
		debug::event_type_error,
		debug::characteristic_critical,
		debug::title_index_cannot_register_class_name,
		debug::details_index_cannot_register_debugger_class_name,
		{},
		{},
		{}
	);
}

HWND listbox_debugger = nullptr;
HWND static_event_type_debugger = nullptr;
HWND static_details_debugger = nullptr;

void create_widgets_debugger_window(HWND h_window) {
	listbox_debugger = CreateWindowExW(
		0,
		L"listbox",
		L"",
		WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOVSCROLL | WS_HSCROLL,
		x_out,
		y_out,
		listbox_width_default,
		listbox_height_default,
		h_window,
		NULL,
		NULL,
		NULL
	);

	static_event_type_debugger = CreateWindowExW(
		0,
		L"static",
		L"",
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		x_out * 2 + listbox_width_default,
		y_out,
		static_width_event_type,
		static_height_event_type,
		h_window,
		NULL,
		NULL,
		NULL
	);

	static_details_debugger = CreateWindowExW(
		0,
		L"static",
		L"",
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		x_out * 2 + listbox_width_default,
		y_out * 2 + static_height_event_type,
		static_width_details,
		static_height_details,
		h_window,
		NULL,
		NULL,
		NULL
	);

	for (
		u_int_ index = 0;
		index < debug::history_of_event.size();
		index++
	) {
		int position = SendMessageW(
			listbox_debugger, 
			LB_ADDSTRING,
			index,
			(LPARAM)debug::history_of_event.at(index).show_title().c_style()
		);

		SendMessageW(
			listbox_debugger,
			LB_SETITEMDATA,
			position,
			index
		);
	}
}

#endif