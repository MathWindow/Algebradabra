#pragma once
#include <windows.h>
#include <vector>
#include "Naming.h"
#include "Listbox.h"
#include "HistoryOfError.h"
#include "Translate.h"

#ifndef widgets_header
#define widgets_header

u_short x_out = 10;
u_short y_out = x_out;

u_short width_edit_default = 150;
u_short height_edit_default = 20;

u_short width_listbox_default = 200;
u_short height_listbox_default = 300;

u_short width_static_error_list = 300;
u_short height_static_error_list = 300;

HWND edit_main = NULL;

HWND listbox_error_list = NULL;
HWND static_error_list = NULL;

void create_main_widgets(HWND h_window) {
	edit_main = create_widget_and_check(
		L"edit",
		L"",
		WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
		x_out,
		y_out,
		width_edit_default,
		height_edit_default,
		NULL,
		__FUNCTIONW__,
		0,
		0,
		false,
		false,
		h_window,
		true
	);
}

void create_error_list_widgets(HWND h_window) {
	listbox_error_list = create_widget_and_check(
		L"listbox",
		L"",
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		x_out,
		y_out,
		width_listbox_default,
		height_listbox_default,
		NULL,
		__FUNCTIONW__,
		0,
		0,
		false,
		false,
		h_window
	);

	if (listbox_error_list != NULL) {
		for (
			u_short index_running = 0;
			index_running < error_list_program.size();
			index_running++
		) {
			listbox_error_list_position =
				add_string(
					listbox_error_list,
					translating_string(error_list_program.at(index_running).name),
					index_running
				);
		}
	}

	static_error_list = create_widget_and_check(
		L"static",
		L"Здесь вы сможете посмотреть подробности об событиях ошибки, просто нажмите на строку из списка.",
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		x_out * 2 + width_listbox_default,
		y_out,
		width_static_error_list,
		height_static_error_list,
		NULL,
		__FUNCTIONW__,
		0,
		0,
		false,
		false,
		h_window,
		false
	);
}

#endif