#pragma once
#include <windows.h>
#include <vector>
#include "Naming.h"
#include "Listbox.h"
#include "HistoryOfError.h"

#ifndef widgets_header
#define widgets_header

uint_16 x_out = 10;
uint_16 y_out = x_out;

uint_16 width_edit_default = 150;
uint_16 height_edit_default = 20;

uint_16 width_listbox_default = 200;
uint_16 height_listbox_default = 300;

uint_16 width_static_error_list = 300;
uint_16 height_static_error_list = 300;

HWND edit_main = NULL;

HWND listbox_error_list = NULL;
HWND static_error_list = NULL;

void create_main_widgets(HWND h_window) {
	edit_main = CreateWindowW(
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

	check_h_window(
		edit_main,
		L"Средняя серьезность",
		(LPCWSTR)__func__,
		L"Не удалось создать виджет в виде поля",
		0,
		0,
		false,
		false,
		h_window,
		program_name,
		true
	);
}

void create_error_list_widgets(HWND h_window) {
	listbox_error_list = CreateWindowW(
		L"listbox",
		L"",
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		x_out,
		y_out,
		width_listbox_default,
		height_listbox_default,
		h_window,
		NULL,
		NULL,
		NULL
	);

	for (
		uint_16 index_running = 0; 
		index_running < error_list_program.size(); 
		index_running++
	) {
		listbox_error_list_position = 
			add_string(
				listbox_error_list, 
				error_list_program.at(index_running).name,
				index_running
			);
	}

	static_error_list = CreateWindowW(
		L"static",
		L"Здесь вы сможете посмотреть подробностии об событиях ошибкии",
		WS_VISIBLE | WS_CHILD | WS_BORDER,
		x_out * 2 + width_listbox_default,
		y_out,
		width_static_error_list,
		height_static_error_list,
		h_window,
		NULL,
		NULL,
		NULL
	);

	check_h_window(
		listbox_error_list,
		L"Средняя серьезность",
		(LPCWSTR)__func__,
		L"Не удалось создать виджет в виде списка",
		0,
		0,
		false,
		false,
		h_window,
		program_name,
		true
	);

	check_h_window(
		static_error_list,
		L"Средняя серьезность",
		(LPCWSTR)__func__,
		L"Не удалось создать виджет в виде текстового блока",
		0,
		0,
		false,
		false,
		h_window,
		program_name,
		true
	);
}

#endif