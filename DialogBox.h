#pragma once
#include <windows.h>
#include "Monitor.h"

#ifndef dialog_box_header
#define dialog_box_header

void call_developers_dialog_box (
	LPCWSTR class_name,
	LPCWSTR title,
	DWORD dword_style,
	LONG* x_position,
	LONG* y_position,
	LONG width,
	LONG height,
	HWND h_window
) {
	get_monitor_information();

	if ((dword_style & WS_CHILD) != WS_CHILD) {
		set_window_center_position(
			width, height,
			x_position, y_position
		);
	}

	CreateWindowExW(
		0,
		class_name,
		title,
		dword_style,
		*x_position,
		*y_position,
		width,
		height,
		h_window,
		NULL,
		NULL,
		NULL
	);
}

#endif