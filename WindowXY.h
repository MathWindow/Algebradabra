#pragma once
#include <winnt.h>
#include <windef.h>
#include "Monitor.h"

#ifndef macro_header_window_xy
#define macro_header_window_xy

namespace xy {
	class position_point {
	public:
		LONG x = 0;
		LONG y = 0;
	};

	class size_position {
	public:
		LONG width = 0;
		LONG height = 0;
		position_point left_top_point{};

		void set(
			LONG width_argument,
			LONG height_argument
		) {
			width = width_argument;
			height = height_argument;

			set_window_center_position(
				&(left_top_point.x),
				&(left_top_point.y),
				width,
				height
			);
		}
	};

	RECT size_position_to_RECT(size_position argument) {
		RECT result{};

		result.left = argument.left_top_point.x;
		result.top = argument.left_top_point.y;

		result.right = argument.left_top_point.x + argument.width;
		result.bottom = argument.left_top_point.y + argument.height;

		return result;
	}

	size_position RECT_to_size_position(RECT argument) {
		size_position result{};


	}
}

const LONG main_window_width = monitor_width / 3 * 2;
const LONG main_window_height = monitor_height / 3 * 2;
LONG main_window_x = 0;
LONG main_window_y = 0;

const LONG debugger_window_width = 700;
const LONG debugger_window_height = 400;
LONG debugger_window_x = 0;
LONG debugger_window_y = 0;

#endif