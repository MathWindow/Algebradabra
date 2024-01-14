#pragma once
#include <windows.h>
#include "DialogWindow.h"
#include "HistoryOfError.h"
#include "Translate.h"
#include "WindowXY.h"

void window_algebraic_book_create(
	HWND h_window
) {
	call_dialog_window(
		algebraic_book_create_class_name,
		algebraic_book_create_name,
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		&algebraic_book_create_window_x,
		&algebraic_book_create_window_y,
		400,
		400,
		h_window
	);
}