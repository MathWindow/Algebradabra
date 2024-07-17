#pragma once
#include <Windows.h>
#include <basetsd.h>
#include <vector>
#include "Widgets.h"
#include "Menu.h"
#include "VersionInfo.h"
#include "Translate.h"
#include "Coordinate.h"
#include "CodeWork.h"
#include "Commands.h"
#include "Debugger.h"
#include "ClassWindow.h"

coordinate::size_position main_window_position
	= coordinate::set_windows_position_and_size(900, 500, {});

void create_menu_main_window(
	HWND h_window,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	// Third floor
	// Третий этаж

	HMENU algebraic_book_menu = debug::create_menu(place);

	// Second floor
	// Второй этаж

	HMENU program_menu = debug::create_menu(place);
	HMENU language_menu = debug::create_menu(place);
	HMENU help_settings_menu = debug::create_menu(place);

	// First floor
	// Первый этаж

	HMENU root_menu = debug::create_menu(place);

	// Third floor
	// Третий этаж

	debug::append_menu_w(algebraic_book_menu, MF_STRING, command_create_book, translate::string__create.show().c_str(), place);
	debug::append_menu_w(algebraic_book_menu, MF_STRING, command_open_book, translate::string__open.show().c_str(), place);
	debug::append_menu_w(algebraic_book_menu, MF_STRING, command_save_book, translate::string__save.show().c_str(), place);
	debug::append_menu_w(algebraic_book_menu, MF_STRING, command_save_book_as, translate::string__save_as.show().c_str(), place);

	// Second floor
	// Второй этаж

	debug::append_menu_w(program_menu, MF_POPUP, (UINT_PTR)algebraic_book_menu, translate::string__book_alg.show().c_str(), place);
	line_element_menu(program_menu, place);
	debug::append_menu_w(program_menu, MF_STRING, command_exit, translate::string__exit.show().c_str(), place);
#if turn_debugger_on
	debug::append_menu_w(help_settings_menu, MF_STRING, command_debugger, translate::string__debugger.show().c_str(), place);
#endif
	debug::append_menu_w(help_settings_menu, MF_STRING, command_about, translate::string__about_program.show().c_str(), place);

	debug::append_menu_w(language_menu, MF_STRING, command_translate_English, L"English", place);
	debug::append_menu_w(language_menu, MF_STRING, command_translate_Russian, L"Русский", place);

	// First floor
	// Первый этаж

	debug::append_menu_w(root_menu, MF_POPUP, (UINT_PTR)program_menu, translate::string__program.show().c_str(), place);
	debug::append_menu_w(root_menu, MF_POPUP, (UINT_PTR)help_settings_menu, translate::string__help.show().c_str(), place);
	debug::append_menu_w(root_menu, MF_STRING, command_what_is_new, translate::string_what_is_new.show().c_str(), place);
	debug::append_menu_w(root_menu, MF_POPUP | MF_HELP, (UINT_PTR)language_menu, translate::string__language.show().c_str(), place);

	SetMenu(h_window, root_menu);
}

std::vector<widget>edit_expression_vector{
	set_widget(
		coordinate::edit_size_standard,
		widget_class_edit,
		WS_BORDER | ES_AUTOHSCROLL,
		0,
		translate::convert_to_translating(L""),
		translate::convert_to_translating(L""),
		translate::convert_to_translating(L"..."),
		false,
		false,
		true,
		coordinate::edit_size_standard.height,
		{}
	)
};

widget static_result 
	= set_widget(
		coordinate::static_size_standard_1,
		widget_class_static,
		WS_BORDER,
		0,
		translate::convert_to_translating(L""),
		translate::convert_to_translating(L""),
		translate::convert_to_translating(L""),
		false,
		false,
		false,
		0,
		{}
	);

canvas canvas_graphic_function
	= set_canvas(
		coordinate::set_size(201, 201, {}),
		CreateSolidBrush(RGB(255, 255, 255)),
		CreateSolidBrush(RGB(128, 128, 128)),
		true,
		{}
	);

widget static_version
	= set_widget(
		coordinate::static_size_standard_1,
		widget_class_static,
		0,
		0,
		translate::convert_to_translating(program_version),
		translate::convert_to_translating(L""),
		translate::convert_to_translating(L""),
		false,
		false,
		false,
		0,
		{}
	);

void create_widgets_main_window(
	HWND h_window,
	LONG extra_out_height,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	edit_expression_vector.at(0).create(
		h_window,
		coordinate::step_begin_set,
		extra_out_height,
		place
	);

	static_result.create(
		h_window,
		coordinate::step_make_out,
		extra_out_height,
		place
	);

	canvas_graphic_function.set(
		coordinate::step_move_to_next_row,
		extra_out_height,
		place
	);

	canvas_graphic_function.color_helper_vector.push_back(
		CreateSolidBrush(RGB(255, 0, 0))
	);

	static_version.create(
		h_window,
		coordinate::step_make_out,
		extra_out_height,
		place
	);
}