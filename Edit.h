#pragma once
#include <windows.h>

HWND edit1 = NULL;
//HWND edit2 = NULL;

HWND create_edit(
	LPCWSTR title, 
	int x_position, 
	int y_position, 
	int width, 
	int height, 
	HWND h_window, 
	int command_number, 
	DWORD style, 
	DWORD ex_style = 0
) {
	return CreateWindowExW(
		ex_style, 
		L"edit", 
		title, 
		WS_VISIBLE | WS_CHILD | style, 
		x_position, 
		y_position, 
		width, 
		height, 
		h_window, 
		(HMENU)command_number, 
		NULL, 
		NULL
	);
}