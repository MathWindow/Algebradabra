#pragma once
#include <windows.h>
#include "Monitor.h"
#include "HistoryOfError.h"
#include "Translate.h"

#ifndef dialog_window_header
#define dialog_window_header

void call_dialog_window (
	LPCWSTR class_name,
	LPCWSTR title,
	DWORD dword_style,
	u_short* x_position,
	u_short* y_position,
	u_short width,
	u_short height,
	HWND h_window
) {
	HWND ghost_h_dialog_window = NULL;

	get_monitor_information();

	if ((dword_style & WS_CHILD) != WS_CHILD) {
		set_window_center_position(
			width, height,
			x_position, y_position
		);
	}

	ghost_h_dialog_window = CreateWindowW(
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
		NULL,
	);

	check_h_window(
		ghost_h_dialog_window,
		__FUNCTIONW__,
		translate::string_cannot_create_dialog_window,
		0,
		0,
		false,
		false,
		h_window,
		true
	);
}

#endif