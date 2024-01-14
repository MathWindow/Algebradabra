#pragma once
#include <windows.h>
#include "Naming.h"

#ifndef monitor_header
#define monitor_header

RECT monitor_information = { 0 };
uint_16 monitor_width = 0;
uint_16 monitor_height = 0;

void get_monitor_information() {
	GetClipCursor(&monitor_information);

	monitor_width = 
		monitor_information.right - monitor_information.left;

	monitor_height = 
		monitor_information.bottom - monitor_information.top;
}

void set_window_center_position
(
	uint_16 width,
	uint_16 height,
	uint_16* x_position,
	uint_16* y_position
) {
	*x_position = (monitor_width - width) / 2;
	*y_position = (monitor_height - height) / 2;
}

#endif