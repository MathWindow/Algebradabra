#pragma once
#include <winnt.h>
#include "Monitor.h"
#include "CodeWork.h"
#include "Counter.h"
#include "ShortTypes.h"
#include <windef.h>

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

		position_point get_center_point(
			macro_add_block_argument
		) {
			macro_add_block_function(place_argument);

			position_point result{};

			result.abscissa 
				= left_top_point.abscissa + size_.width / 2;

			result.ordinate
				= left_top_point.ordinate + size_.height / 2;

			return result;
		}
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

	RECT convert_size_position_to_RECT(
		size size_,
		position_point left_top_point,
		macro_add_block_argument
	) {
		RECT result{};

		result.left 
			= left_top_point.abscissa;
		result.right 
			= left_top_point.abscissa + size_.width;
		result.top 
			= left_top_point.ordinate;
		result.bottom 
			= left_top_point.ordinate + size_.height;
		
		return result;
	}

	position_point out = set_position_point(10, 10, {});

	size edit_size_standard = set_size(150, 20, {});

	size listbox_size_standard_1 = set_size(150, 150, {});
	size listbox_size_standard_2 = set_size(200, 200, {});

	size static_size_standard_1 = set_size(300, 20, {});
	size static_size_standard_2 = set_size(300, 40, {});
	size static_size_standard_3 = set_size(300, 100, {});
	size static_size_standard_time = set_size(150, 20, {});

	size button_size_standard = set_size(90, 30, {});

	using step_index = u_int_;
	using c_step_index = const step_index;

	c_step_index step_move_to_next_row
		= put_index_counter<step_index>(0);
	c_step_index step_make_out
		= put_index_counter<step_index>(continue_counting);
	c_step_index step_set_widget_vertically
		= put_index_counter<step_index>(continue_counting);
	c_step_index step_set_widget_horizontally
		= put_index_counter<step_index>(continue_counting);
	c_step_index step_begin_set
		= put_index_counter<step_index>(continue_counting);

	position_point set_squares_position(
		LONG width,
		LONG height,
		step_index step,
		LONG extra_out_height,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		position_point result{};

		static coordinate::position_point count_of_out 
			= coordinate::set_position_point(1, 1, place);

		static coordinate::size total_size = coordinate::set_size(0, 0, place);

		static LONG the_most_widget_width_in_row = 0;

		static LONG width_in_this_place = width;

		static LONG height_of_past_widget = 0;

		if (step == step_begin_set) {
			count_of_out = coordinate::set_position_point(1, 1, place);

			total_size = coordinate::set_size(0, 0, place);

			the_most_widget_width_in_row = 0;

			width_in_this_place = width;

			height_of_past_widget = 0;
		}
		else if (step == step_move_to_next_row) {
			total_size.width += the_most_widget_width_in_row;
			total_size.height = 0;

			the_most_widget_width_in_row = 0;

			count_of_out.abscissa += 1;
			count_of_out.ordinate = 1;
		}
		else if (step == step_make_out) {
			count_of_out.ordinate += 1;
		}

		if (step == step_set_widget_horizontally) {
			width_in_this_place += width;
		}
		else {
			width_in_this_place = width;
		}

		if (width_in_this_place > the_most_widget_width_in_row) {
			the_most_widget_width_in_row = width_in_this_place;
		}

		result.abscissa
			= total_size.width
			+ count_of_out.abscissa * out.abscissa
			+ width_in_this_place - width;
		result.ordinate
			= total_size.height
			+ count_of_out.ordinate * out.ordinate
			+ extra_out_height
			- (step == step_set_widget_horizontally ? height_of_past_widget : 0);

		if (step != step_set_widget_horizontally) {
			total_size.height += height;
		}

		height_of_past_widget = height;

		return result;
	}
}

#endif