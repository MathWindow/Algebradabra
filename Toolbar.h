#pragma once
#include <Windows.h>
#include "Widgets.h"
#include "Commands.h"
#include "Coordinate.h"
#include "Debugger.h"
#include "CodeWork.h"
#include "Bitmap.h"

#ifndef macro_header_toolbar
#define macro_header_toolbar

coordinate::size button_size_toolbar = coordinate::set_size(48, 48, {});

void append_button_toolbar(
	HWND h_window,
	HBITMAP h_bitmap,
	command_type command,
	bool continue_,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	static int row = 0;

	if (continue_) {
		row++;
	}
	else {
		row = 1;
	}

	HWND button = debug::create_window_ex_w(
		0,
		L"button",
		L"",
		WS_VISIBLE | WS_CHILD | WS_BORDER | BS_BITMAP,
		out.abscissa * row + button_size_toolbar.width * (row - 1),
		out.ordinate,
		button_size_toolbar.width,
		button_size_toolbar.height,
		h_window,
		(HMENU)command,
		NULL,
		NULL,
		place
	);

	SendMessageW(
		button,
		BM_SETIMAGE,
		IMAGE_BITMAP,
		(LPARAM)h_bitmap
	);
}

LONG create_toolbar(
	HWND h_window,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	append_button_toolbar(
		h_window,
		h_bitmap_coordinate,
		NULL,
		false,
		place
	);

	append_button_toolbar(
		h_window,
		h_bitmap_add_paper,
		NULL,
		true,
		place
	);

	return out.ordinate + button_size_toolbar.height;
}

#endif