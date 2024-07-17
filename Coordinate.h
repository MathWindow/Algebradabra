#pragma once
#include <winnt.h>
#include "Monitor.h"
#include "CodeWork.h"

#ifndef macro_header_coordinate
#define macro_header_coordinate

namespace coordinate {
	class position_point {
	public:
		LONG abscissa = 0;
		LONG ordinate = 0;
	};

	position_point set_position_point(
		LONG x,
		LONG y,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		position_point result{};

		result.abscissa = x;
		result.ordinate = y;

		return result;
	}

	class size {
	public:
		LONG width = 0;
		LONG height = 0;
	};

	size set_size(
		LONG width,
		LONG height,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		size result{};
		
		result.width = width;
		result.height = height;

		return result;
	}

	class size_position {
	public:
		size size_;
		position_point left_top_point{};
	};

	size_position set_windows_position_and_size(
		LONG width,
		LONG height,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		size_position result{};

		result.size_.width = width;
		result.size_.height = height;

		result.size_ = set_size(width, height, place);

		set_window_center_position(
			&(result.left_top_point.abscissa),
			&(result.left_top_point.ordinate),
			result.size_.width,
			result.size_.height,
			place
		);

		return result;
	}
}

coordinate::size_position main_window_position 
	= coordinate::set_windows_position_and_size(900, 500, {});

coordinate::size_position debugger_window_position
	= coordinate::set_windows_position_and_size(850, 500, {});

#endif