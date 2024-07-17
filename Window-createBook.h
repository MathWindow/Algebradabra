#pragma once
#include <Windows.h>
#include "Widgets.h"
#include "Translate.h"
#include "Coordinate.h"
#include "DocumentWork.h"
#include "CodeWork.h"
#include "ShortTypes.h"
#include "ClassWindow.h"

coordinate::size_position create_book_window_position
	= coordinate::set_windows_position_and_size(200, 400, {});

widget listbox_start_page_type_list
	= set_widget(
		coordinate::listbox_size_standard_1,
		widget_class_listbox,
		WS_BORDER | LBS_NOTIFY,
		0,
		translate::convert_to_translating(L""),
		translate::string_start_page_type,
		translate::convert_to_translating(L""),
		true,
		true,
		false,
		0,
		{}
	);

widget edit_path
	= set_widget(
		coordinate::edit_size_standard,
		widget_class_edit,
		WS_BORDER | ES_AUTOHSCROLL,
		0,
		translate::convert_to_translating(L""),
		translate::string_path_with_file_name,
		translate::convert_to_translating(L"..."),
		true,
		false,
		true,
		coordinate::edit_size_standard.height,
		{}
	);

widget button_create
	= set_widget(
		coordinate::button_size_standard,
		widget_class_button,
		WS_BORDER,
		0,
		translate::string__create,
		translate::convert_to_translating(L""),
		translate::convert_to_translating(L""),
		false,
		false,
		false,
		0,
		{}
	);

void create_widgets_create_book_window(
	HWND h_window_parent,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	listbox_start_page_type_list.create(
		h_window_parent,
		coordinate::step_begin_set,
		0,
		place
	);

	for (
		u_int_ index = page_type_first + 1;
		index < page_type_last + 1;
		index++
	) {
		listbox_start_page_type_list.add_string_to_listbox(
			convert_page_type_index_to_string(index, place).show(),
			index,
			place
		);
	}

	edit_path.create(
		h_window_parent,
		coordinate::step_make_out,
		0,
		place
	);

	button_create.create(
		h_window_parent,
		coordinate::step_make_out,
		0,
		place
	);
}