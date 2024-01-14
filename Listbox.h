#pragma once
#include <windows.h>

LRESULT listbox_error_list_position = 0;

LRESULT add_string(
	HWND listbox_input, 
	LPCWSTR string_input,
	uint_16 index_input
) {
	listbox_error_list_position =
		SendMessageW(
			listbox_input,
			LB_ADDSTRING,
			0,
			(LPARAM)string_input
		);

	SendMessageW(
		listbox_input,
		LB_SETITEMDATA,
		listbox_error_list_position,
		(LPARAM)index_input
	);

	return listbox_error_list_position;
}