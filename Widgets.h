#pragma once
#include <windows.h>
#include <vector>
#include "Naming.h"
#include "HistoryOfError.h"

unsigned short x_out = 10;
unsigned short y_out = x_out;

unsigned short width_edit_default = 150;
unsigned short height_edit_default = 20;

HWND edit_1 = NULL;

void create_widgets(HWND h_window) {
	edit_1 = CreateWindowW(
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
		edit_1,
		L"Средняя серьезность",
		L"create_widgets()",
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