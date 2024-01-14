#pragma once
#include <windows.h>
#include "Naming.h"
#include "ShortTypes.h"

#ifndef monitor_header
#define monitor_header

RECT monitor_information = { 0 };
ushort monitor_width = 0;
ushort monitor_height = 0;

void get_monitor_information() {
	GetClipCursor(&monitor_information);

	monitor_width = 
		monitor_information.right - monitor_information.left;

	monitor_height = 
		monitor_information.bottom - monitor_information.top;
}

void set_window_center_position
(
	ushort width,
	ushort height,
	ushort* x_position,
	ushort* y_position
) {
	*x_position = (monitor_width - width) / 2;
	*y_position = (monitor_height - height) / 2;
}

#endif