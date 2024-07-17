#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include "Widgets.h"
#include "Coordinate.h"
#include "Translate.h"
#include "Debugger.h"
#include "CodeWork.h"
#include "ClassWindow.h"

#if turn_debugger_on

coordinate::size_position debugger_window_position
	= coordinate::set_windows_position_and_size(850, 520, {});

widget edit_searcher
	= set_widget(
		coordinate::set_size(
			coordinate::listbox_size_standard_2.width,
			coordinate::edit_size_standard.height,
			{}
		),
		widget_class_edit,
		WS_BORDER | ES_AUTOHSCROLL,
		0,
		translate::convert_to_translating(L""),
		translate::string__searcher,
		translate::convert_to_translating(L""),
		true,
		true,
		false,
		0,
		{}
	);

widget listbox_event_list
	= set_widget(
		coordinate::listbox_size_standard_2,
		widget_class_listbox,
		WS_BORDER | WS_VSCROLL | LBS_NOTIFY,
		0,
		translate::convert_to_translating(L""),
		translate::string_event_list,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget static_time_local
	= set_widget(
		coordinate::static_size_standard_time,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string__local_time,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget static_time_system
	= set_widget(
		coordinate::static_size_standard_time,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string__system_time,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget static_event_title
	= set_widget(
		coordinate::static_size_standard_2,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_event_title,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget static_event_type
	= set_widget(
		coordinate::static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_event_type,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget static_extra_title
	= set_widget(
		coordinate::static_size_standard_3,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_event_extra_title,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget static_handle_value
	= set_widget(
		coordinate::static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_handle_value,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget static_handle_type
	= set_widget(
		coordinate::static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_handle_type,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget static_window_class
	= set_widget(
		coordinate::static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_window_or_widget_class,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget listbox_block_hierarchy
	= set_widget(
		coordinate::listbox_size_standard_2,
		widget_class_listbox,
		WS_BORDER | WS_VSCROLL | LBS_NOTIFY,
		0,
		translate::convert_to_translating(L""),
		translate::string_block_hierarchy,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget static_block_type
	= set_widget(
		coordinate::static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_block_type,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget static_function_name
	= set_widget(
		coordinate::static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_function_name,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget static_variable_address
	= set_widget(
		coordinate::static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_variable_address,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
		{}
	);

widget static_variable_value
	= set_widget(
		coordinate::static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::string_variable_value,
		translate::convert_to_translating(L""),
		true,
		false,
		false,
		0,
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
			&static_variable_address,
			&static_variable_value
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
			std::to_wstring(index) + L" | " + debug::list_of_event.at(index).show_title(false).show().c_str(),
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
		coordinate::step_begin_set,
		0,
		place
	);

	listbox_event_list.create(
		h_window,
		coordinate::step_make_out,
		0,
		place
	);

	add_event_list_to_listbox(place);

	static_time_local.create(
		h_window,
		coordinate::step_make_out,
		0,
		place
	);

	static_time_system.create(
		h_window,
		coordinate::step_make_out,
		0,
		place
	);

	static_event_title.create(
		h_window,
		coordinate::step_move_to_next_row,
		0,
		place
	);

	static_event_type.create(
		h_window,
		coordinate::step_make_out,
		0,
		place
	);

	static_extra_title.create(
		h_window,
		coordinate::step_make_out,
		0,
		place
	);

	static_handle_type.create(
		h_window,
		coordinate::step_make_out,
		0,
		place
	);

	static_handle_value.create(
		h_window,
		coordinate::step_make_out,
		0,
		place
	);

	static_window_class.create(
		h_window,
		coordinate::step_make_out,
		0,
		place
	);

	listbox_block_hierarchy.create(
		h_window,
		coordinate::step_move_to_next_row,
		0,
		place
	);

	static_block_type.create(
		h_window,
		coordinate::step_make_out,
		0,
		place
	);

	static_function_name.create(
		h_window,
		coordinate::step_make_out,
		0,
		place
	);

	static_variable_address.create(
		h_window,
		coordinate::step_make_out,
		0,
		place
	);

	static_variable_value.create(
		h_window,
		coordinate::step_make_out,
		0,
		place
	);
}

#endif