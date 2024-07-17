#pragma once
#include <windows.h>

#ifndef macro_header_monitor
#define macro_header_monitor

RECT monitor_information{};
LONG monitor_width = 0;
LONG monitor_height = 0;

void set_window_center_position
(
	LONG* x_position,
	LONG* y_position,
	LONG width,
	LONG height
) {
	static bool has_got_monitor_information = false;

	if (!has_got_monitor_information) {
		has_got_monitor_information 
			= GetClipCursor(&monitor_information);

		monitor_width 
			= monitor_information.right;

		monitor_height 
			= monitor_information.bottom;
	}

	*x_position = (monitor_width - width) / 2;
	*y_position = (monitor_height - height) / 2;
}

#endif