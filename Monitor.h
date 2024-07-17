#pragma once
#include <windows.h>
#include "CodeWork.h"

#ifndef macro_header_monitor
#define macro_header_monitor

RECT monitor_information{};
LONG monitor_width = 0;
LONG monitor_height = 0;

LONG get_monitor_width(macro_add_block_argument) {
	macro_add_block_function(place_argument);

	GetClipCursor(&monitor_information);

	monitor_width
		= monitor_information.right;

	return monitor_width;
}

LONG get_monitor_height(macro_add_block_argument) {
	macro_add_block_function(place_argument);

	GetClipCursor(&monitor_information);

	monitor_height
		= monitor_information.bottom;

	return monitor_height;
}

void get_monitor_size(macro_add_block_argument) {
	macro_add_block_function(place_argument);

	static bool has_got_monitor_information = false;

	if (!has_got_monitor_information) {
		has_got_monitor_information
			= GetClipCursor(&monitor_information);

		monitor_width
			= monitor_information.right;

		monitor_height
			= monitor_information.bottom;
	}
}

void set_window_center_position(
	LONG* x_position,
	LONG* y_position,
	LONG width,
	LONG height,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	get_monitor_size(place);

	*x_position = (monitor_width - width) / 2;
	*y_position = (monitor_height - height) / 2;
}

#endif