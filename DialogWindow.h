#pragma once
#include <windows.h>
#include "Naming.h"
#include "Monitor.h"
#include "HistoryOfError.h"

using int8b = char;

void call_dialog_window (
	LPCWSTR class_name,
	LPCWSTR title,
	DWORD dword_style,
	unsigned short* x_position,
	unsigned short* y_position,
	unsigned short width,
	unsigned short height,
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
		((dword_style & WS_CHILD) == WS_CHILD ? h_window : NULL),
		NULL,
		NULL,
		NULL,
	);

	check_h_window(
		ghost_h_dialog_window,
		L"Средняя серьезность",
		L"call_dialog_window()",
		L"Не удалось создать диалоговое окно",
		0,
		0,
		false,
		false,
		h_window,
		program_name,
		true
	);
}