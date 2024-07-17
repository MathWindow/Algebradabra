#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include "Debugger.h"
#include "Coordinate.h"
#include "Commands.h"
#include "VersionInfo.h"
#include "Translate.h"
#include "CodeWork.h"

#ifndef macro_header_widgets
#define macro_header_widgets

coordinate::position_point out = coordinate::set_position_point(10, 10, {});

coordinate::size edit_size_standard = coordinate::set_size(150, 20, {});

coordinate::size listbox_size_standard_1 = coordinate::set_size(150, 150, {});
coordinate::size listbox_size_standard_2 = coordinate::set_size(200, 200, {});

coordinate::size static_size_standard_1 = coordinate::set_size(300, 20, {});
coordinate::size static_size_standard_2 = coordinate::set_size(300, 100, {});
coordinate::size static_size_standard_time = coordinate::set_size(150, 20, {});

class widget_ : public coordinate::size_position {
public:
	HWND h_window = nullptr;

	void create_(
		DWORD style,
		DWORD extra_style,
		LPCWSTR class_name,
		LPCWSTR title,
		HWND h_window_parent,
		command_type command,
		bool move_to_next_horizontal_row,
		bool make_out_vertical,
		bool is_beginning,
		LONG extra_out_height,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);
		
		static coordinate::position_point count_of_out = coordinate::set_position_point(1, 1, place);

		static coordinate::size total_size = coordinate::set_size(0, 0, place);

		static LONG the_most_widget_width_in_row = 0;

		if (is_beginning) {
			count_of_out = coordinate::set_position_point(1, 1, place);

			total_size = coordinate::set_size(0, 0, place);

			the_most_widget_width_in_row = 0;
		}
		else {
			if (move_to_next_horizontal_row) {
				count_of_out.abscissa++;

				total_size.width 
					+= the_most_widget_width_in_row;

				the_most_widget_width_in_row = 0;

				count_of_out.ordinate = 1;
				total_size.height = 0;
			}

			if (make_out_vertical) {
				count_of_out.ordinate++;
			}
		}

		if (the_most_widget_width_in_row < size_.width) {
			the_most_widget_width_in_row = size_.width;
		}

		left_top_point.abscissa
			= out.abscissa * count_of_out.abscissa + total_size.width;

		left_top_point.ordinate
			= out.ordinate * count_of_out.ordinate + total_size.height + extra_out_height;

		h_window = debug::create_window_ex_w( 
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

		total_size.height += size_.height;
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

std::wstring widget_class_static = L"static";
std::wstring widget_class_edit = L"edit";
std::wstring widget_class_button = L"button";
std::wstring widget_class_listbox = L"listbox";

class widget : public widget_ {
public:
	std::wstring class_name = L"";

	DWORD style = WS_VISIBLE | WS_CHILD;
	DWORD extra_style = 0;

	translate::string title = translate::convert_to_translating(L"");
	translate::string label = translate::convert_to_translating(L"");
	bool is_there_label = false;

	command_type command = 0;

	widget_ label_widget{};

	void create(
		HWND h_window_parent,
		bool move_to_next_horizontal_row,
		bool make_out_vertical,
		bool is_beginning,
		LONG extra_out_height,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		if (is_there_label) {
			label_widget.create_(
				WS_VISIBLE | WS_CHILD,
				0,
				L"static",
				label.show_fixed(),
				h_window_parent,
				NULL,
				move_to_next_horizontal_row,
				make_out_vertical,
				is_beginning,
				extra_out_height,
				place
			);
		}

		create_(
			style,
			extra_style,
			class_name.c_str(),
			title.show().c_str(),
			h_window_parent,
			command,
			move_to_next_horizontal_row && !is_there_label,
			make_out_vertical && !is_there_label,
			is_beginning && !is_there_label,
			extra_out_height,
			place
		);
	}

	std::wstring get_text(
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		int size_buffer = GetWindowTextLengthW(h_window) + 1;

		wchar_t* text_ = new wchar_t[size_buffer]; // It is not including as warning event.

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
	bool is_there_label,
	bool is_height_of_label_was_multiplied_2,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	static command_type counter = 1;

	widget result{};

	result.size_ = size_;
	result.class_name = class_name;
	result.style = style | WS_VISIBLE | WS_CHILD;
	result.extra_style = extra_style;
	result.title = title;
	result.label = label;
	result.is_there_label = is_there_label;
	result.command = command_the_last_value + counter;

	result.label_widget.size_.width = size_.width;
	result.label_widget.size_.height = static_size_standard_1.height * (is_height_of_label_was_multiplied_2 ? 2 : 1);

	counter++;

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
	widget_group result;

	result.widgets = list;

	return result;
}

// Главное окно
// Main window

widget edit_version = set_widget(
	edit_size_standard,
	widget_class_edit,
	WS_BORDER | ES_AUTOHSCROLL,
	0,
	translate::convert_to_translating(program_version),
	translate::convert_to_translating(L""),
	false,
	false,
	{}
);

void create_widgets_main_window(
	HWND h_window,
	LONG extra_out_height,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	edit_version.create(
		h_window,
		false,
		false,
		true,
		extra_out_height,
		place
	);
}

// Отладчик
// Debugger

widget edit_searcher
	= set_widget(
		coordinate::set_size(listbox_size_standard_2.width, edit_size_standard.height, {}),
		widget_class_edit,
		WS_BORDER | ES_AUTOHSCROLL,
		0,
		translate::convert_to_translating(L""),
		translate::string__searcher,
		true,
		true,
		{}
	);

widget listbox_event_list
	= set_widget(
		listbox_size_standard_2,
		widget_class_listbox,
		WS_BORDER | WS_VSCROLL | LBS_NOTIFY,
		0,
		translate::convert_to_translating(L""),
		translate::string_event_list,
		true,
		false,
		{}
	);

widget static_time_local
	= set_widget(
		static_size_standard_time,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string__local_time,
		true,
		false,
		{}
	);

widget static_time_system
	= set_widget(
		static_size_standard_time,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string__system_time,
		true,
		false,
		{}
	);

widget static_event_title
	= set_widget(
		static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_event_title,
		true,
		false,
		{}
	);

widget static_event_type
	= set_widget(
		static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_event_type,
		true,
		false,
		{}
	);

widget static_extra_title
	= set_widget(
		static_size_standard_2,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_event_extra_title,
		true,
		false,
		{}
	);

widget static_handle_value
	= set_widget(
		static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_handle_value,
		true,
		false,
		{}
	);

widget static_handle_type
	= set_widget(
		static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_handle_type,
		true,
		false,
		{}
	);

widget static_window_class
	= set_widget(
		static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_window_or_widget_class,
		true,
		false,
		{}
	);

widget static_index_about_other_event
	= set_widget(
		static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_index_about_other_event,
		true,
		false,
		{}
	);

widget listbox_block_hierarchy
	= set_widget(
		listbox_size_standard_2,
		widget_class_listbox,
		WS_BORDER | WS_VSCROLL | LBS_NOTIFY,
		0,
		translate::convert_to_translating(L""),
		translate::string_block_hierarchy,
		true,
		false,
		{}
	);

widget static_block_type
	= set_widget(
		static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_block_type,
		true,
		false,
		{}
	);

widget static_function_name
	= set_widget(
		static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_function_name,
		true,
		false,
		{}
	);

widget static_variable_address
	= set_widget(
		static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_variable_address,
		true,
		false,
		{}
	);

widget static_variable_value
	= set_widget(
		static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_variable_value,
		true,
		false,
		{}
	);

widget_group group_event_parameter 
	= set_widget_group(
		{
			&static_time_local,
			&static_time_system,
			&static_event_title,
			&static_event_type,
			&static_extra_title,
			&static_handle_type,
			&static_handle_value,
			&static_window_class,
			&static_index_about_other_event,
			&listbox_block_hierarchy,
			&static_block_type,
			&static_function_name,
			&static_variable_value,
			&static_variable_address
		},
		{}
	);

widget_group group_block_parameter
	= set_widget_group(
		{
			&static_block_type,
			&static_function_name,
			&static_variable_value,
			&static_variable_address
		},
		{}
	);

void add_event_list_to_listbox(
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	for (
		size_t index = 0;
		index < debug::list_of_event.size();
		index++
	) {
		listbox_event_list.add_string_to_listbox(
			std::to_wstring(index) + L" | " + debug::list_of_event.at(index).show_title().show().c_str(),
			index,
			place
		);
	}
}

void create_widgets_debugger_window(
	HWND h_window,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	edit_searcher.create(
		h_window,
		false,
		false,
		true,
		0,
		place
	);
	
	listbox_event_list.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);

	add_event_list_to_listbox(place);
	
	static_time_local.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);

	static_time_system.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);

	static_event_title.create(
		h_window,
		true,
		false,
		false,
		0,
		place
	);

	static_event_type.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);

	static_extra_title.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);

	static_handle_type.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);

	static_handle_value.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);

	static_window_class.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);

	static_index_about_other_event.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);

	listbox_block_hierarchy.create(
		h_window,
		true,
		false,
		false,
		0,
		place
	);

	static_block_type.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);
	
	static_function_name.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);
	
	static_variable_address.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);
	
	static_variable_value.create(
		h_window,
		false,
		true,
		false,
		0,
		place
	);
}

#endif