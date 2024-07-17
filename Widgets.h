#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Debugger.h"
#include "Coordinate.h"
#include "Commands.h"
#include "Translate.h"
#include "CodeWork.h"
#include "Algebra.h"
#include "ClassWindow.h"

#ifndef macro_header_widgets
#define macro_header_widgets

class widget_ : public coordinate::size_position {
public:
	HWND h_window = nullptr;

	void create_(
		DWORD style,
		DWORD extra_style,
		std::wstring class_name,
		LPCWSTR title,
		HWND h_window_parent,
		command_type command,
		coordinate::step_index step,
		LONG extra_out_height,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);
		
		left_top_point = coordinate::set_squares_position(
			size_.width,
			size_.height,
			step,
			extra_out_height,
			place
		);

		h_window = debug::create_window_ex_w_modification( 
			extra_style,
			class_name,
			title,
			style,
			left_top_point.abscissa,
			left_top_point.ordinate,
			size_.width,
			size_.height,
			h_window_parent,
			(HMENU)command,
			NULL,
			NULL,
			place
		);
	}
};

widget_ set_widget_(
	coordinate::size size_,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	widget_ result{};

	result.size_ = size_;

	return result;
}

class widget : public widget_ {
public:
	std::wstring class_name = L"";

	DWORD style = WS_VISIBLE | WS_CHILD;
	DWORD extra_style = 0;

	translate::string title = translate::convert_to_translating(L"");
	translate::string label = translate::convert_to_translating(L"");
	translate::string title_button = translate::convert_to_translating(L"");

	bool is_there_label = false;
	bool is_there_button = false;

	command_type command = 0;
	command_type command_button = 0;

	widget_ label_widget{};
	widget_ button_widget{};

	void create(
		HWND h_window_parent,
		coordinate::step_index step,
		LONG extra_out_height,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		if (is_there_label) {
			label_widget.create_(
				WS_VISIBLE | WS_CHILD,
				0,
				widget_class_static,
				label.show_fixed(),
				h_window_parent,
				NULL,
				step,
				extra_out_height,
				place
			);
		}

		create_(
			style,
			extra_style,
			class_name,
			title.show().c_str(),
			h_window_parent,
			command,
			is_there_label ? coordinate::step_set_widget_vertically : step,
			extra_out_height,
			place
		);

		if (is_there_button) {
			button_widget.create_(
				WS_VISIBLE | WS_CHILD | WS_BORDER | BS_NOTIFY,
				0,
				widget_class_button,
				title_button.show().c_str(),
				h_window_parent,
				command_button,
				coordinate::step_set_widget_horizontally,
				extra_out_height,
				place
			);
		}
	}

	std::wstring get_text(
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		int size_buffer = GetWindowTextLengthW(h_window) + 1;

		wchar_t* text_ = new wchar_t[size_buffer]{}; // It is not including as warning event.

		GetWindowTextW(
			h_window,
			text_,
			size_buffer
		);

		std::wstring text_result = text_;

		delete[] text_;

		return text_result;
	}

	void set_string(
		std::wstring text,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		SetWindowTextW(
			h_window,
			text.c_str()
		);
	}

	void add_string_to_listbox(
		std::wstring string,
		size_t index,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		int position = SendMessageW(
			h_window,
			LB_ADDSTRING,
			0,
			(LPARAM)string.c_str()
		);

		SendMessageW(
			h_window,
			LB_SETITEMDATA,
			position,
			index
		);
	}

	size_t get_selected_index(
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		int position = SendMessageW(
			h_window,
			LB_GETCURSEL,
			0,
			0
		);

		return SendMessageW(
			h_window,
			LB_GETITEMDATA,
			position,
			0
		);
	}

	void clear(macro_add_block_argument) {
		macro_add_block_function(place_argument);

		if (class_name == widget_class_listbox) {
			int size = SendMessageW(
				h_window,
				LB_GETCOUNT,
				0,
				0
			);

			for (
				int index = 0;
				index < size;
				index++
			) {
				SendMessageW(
					h_window,
					LB_DELETESTRING,
					0,
					0
				);
			}
		}
		else {
			SetWindowTextW(h_window, L"");
		}
	}
};

widget set_widget( 
	coordinate::size size_,
	std::wstring class_name,
	DWORD style,
	DWORD extra_style,
	translate::string title,
	translate::string label,
	translate::string title_button,
	bool is_there_label,
	bool is_height_of_label_was_multiplied_2,
	bool is_there_button,
	LONG width_button,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	static command_type counter = 1;

	widget result{};

	result.size_ = coordinate::set_size(size_.width - width_button, size_.height, place);
	result.class_name = class_name;
	result.style = style | WS_VISIBLE | WS_CHILD;
	result.extra_style = extra_style;
	result.title = title;
	result.label = label;
	result.title_button = title_button;
	result.is_there_label = is_there_label;
	result.is_there_button = is_there_button;
	result.command = command_the_last_value + counter;

	result.command_button = is_there_button ? command_the_last_value + counter + 1 : 0;

	result.label_widget.size_.width = size_.width;
	result.label_widget.size_.height = coordinate::static_size_standard_1.height * (is_height_of_label_was_multiplied_2 ? 2 : 1);

	result.button_widget.size_.width = width_button;
	result.button_widget.size_.height = size_.height;

	counter += 2;

	return result;
}

class widget_group {
public:
	std::vector<widget*> widgets{};

	void clear(macro_add_block_argument) {
		macro_add_block_function(place_argument);

		for (
			size_t index = 0;
			index < widgets.size();
			index++
		) {
			(*widgets.at(index)).clear(place);
		}
	}

	void set_text(
		std::vector<std::wstring> text_list,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		for (
			size_t index = 0;
			index < text_list.size();
			index++
		) {
			(*widgets.at(index)).set_string(
				text_list.at(text_list.size() == 1 ? 0 : index),
				place
			);
		}
	}
};

widget_group set_widget_group(
	std::vector<widget*> list,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	widget_group result;

	result.widgets = list;

	return result;
}

class canvas : public coordinate::size_position {
private:
	RECT rectangle{};
	
public:
	PAINTSTRUCT struct_of_paint{};
	HBRUSH color_main = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH color_second = CreateSolidBrush(RGB(0, 0, 0));

	std::vector<HBRUSH> color_helper_vector{};

	bool show_cross = false;

	void set(
		coordinate::step_index step,
		LONG extra_out_height,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		left_top_point = coordinate::set_squares_position(
			size_.width,
			size_.height,
			step,
			extra_out_height,
			place
		);

		rectangle = coordinate::convert_size_position_to_RECT(
			size_,
			left_top_point,
			{}
		);
	}
	
	void draw(
		HWND h_window_parent,
		std::vector<std::wstring> equation_string_vector,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		BeginPaint(
			h_window_parent,
			&struct_of_paint
		);

		FillRect(
			struct_of_paint.hdc,
			&rectangle,
			color_main
		);

		for (
			size_t index_vector = 0;
			index_vector < equation_string_vector.size();
			index_vector++
		) {
			algebra::variable* x_pointer
				= algebra::get_pointer_of_variable_from_letter(L'x', place);
			algebra::variable* y_pointer
				= algebra::get_pointer_of_variable_from_letter(L'y', place);

			algebra::formula formula_of_y = algebra::find_variable_from_equation(
				equation_string_vector.at(index_vector),
				y_pointer,
				x_pointer,
				nullptr,
				place
			);

			coordinate::position_point center_point
				= this->get_center_point(place);

			if (show_cross) {
				RECT rectangle_vertical_line
					= coordinate::convert_size_position_to_RECT(
						coordinate::set_size(1, size_.height, place),
						coordinate::set_position_point(
							center_point.abscissa,
							left_top_point.ordinate,
							place
						),
						place
					);

				FillRect(
					struct_of_paint.hdc,
					&rectangle_vertical_line,
					color_second
				);

				RECT rectangle_horizontal_line
					= coordinate::convert_size_position_to_RECT(
						coordinate::set_size(size_.width, 1, place),
						coordinate::set_position_point(
							left_top_point.abscissa,
							center_point.ordinate,
							place
						),
						place
					);

				FillRect(
					struct_of_paint.hdc,
					&rectangle_horizontal_line,
					color_second
				);
			}

			x_pointer->value.number = (1 - size_.width) / 2;

			while (x_pointer->value.number * 2 <= size_.width - 1) {
				bool do_not_paint = false;

				formula_of_y.find_variable(
					&do_not_paint,
					place
				);

				y_pointer->value.number
					= round(y_pointer->value.convert_to_double(
						&do_not_paint,
						place
					));

				y_pointer->value.splitter = 1;

				RECT rectangle_pixel
					= coordinate::convert_size_position_to_RECT(
						coordinate::set_size(1, 1, place),
						coordinate::set_position_point(
							center_point.abscissa + x_pointer->value.number,
							center_point.ordinate - y_pointer->value.number,
							place
						),
						place
					);

				if (
					abs(y_pointer->value.number * 2) <= size_.height - 1
					&& !do_not_paint
				) {
					FillRect(
						struct_of_paint.hdc,
						&rectangle_pixel,
						color_helper_vector.at(0)
					);
				}

				x_pointer->value.number++;
			}

			algebra::formula formula_of_x = algebra::find_variable_from_equation(
				equation_string_vector.at(index_vector),
				x_pointer,
				y_pointer,
				nullptr,
				place
			);

			y_pointer->value.number = (size_.height - 1) / 2;

			while (abs(y_pointer->value.number * 2) <= size_.height - 1) {
				bool do_not_paint = false;
				
				formula_of_x.find_variable(
					&do_not_paint, 
					place
				);

				x_pointer->value.number
					= round(x_pointer->value.convert_to_double(
						&do_not_paint, 
						place
					));

				x_pointer->value.splitter = 1;

				RECT rectangle_pixel
					= coordinate::convert_size_position_to_RECT(
						coordinate::set_size(1, 1, place),
						coordinate::set_position_point(
							center_point.abscissa + x_pointer->value.number,
							center_point.ordinate - y_pointer->value.number,
							place
						),
						place
					);

				if (
					abs(x_pointer->value.number * 2) <= size_.width - 1
					&& !do_not_paint
				) {
					FillRect(
						struct_of_paint.hdc,
						&rectangle_pixel,
						color_helper_vector.at(0)
					);
				}

				y_pointer->value.number--;
			}
		}
		
		EndPaint(
			h_window_parent,
			&struct_of_paint
		);
	}
};

canvas set_canvas(
	coordinate::size size_,
	HBRUSH color_main,
	HBRUSH color_second,
	bool show_cross,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	canvas result{};

	result.size_ = size_;
	result.color_main = color_main;
	result.color_second = color_second;
	result.show_cross = show_cross;
	
	return result;
};

#endif