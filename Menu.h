#pragma once
#include <windows.h>
#include <basetsd.h>
#include "Commands.h"
#include "Translate.h"
#include "CodeWork.h"
#include "Debugger.h"

#ifndef macro_header_menu
#define macro_header_menu

void line_element_menu(
	HMENU h_menu,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	debug::append_menu_w(h_menu, MF_SEPARATOR, NULL, NULL, place);
}

void create_menu_main_window(
	HWND h_window,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	// Third floor
	// Третий этаж

	HMENU algebraic_book_menu = debug::create_menu(place);
	HMENU technical_windows_check_menu = debug::create_menu(place);

	// Second floor
	// Второй этаж

	HMENU program_menu = debug::create_menu(place);
	HMENU window_menu = debug::create_menu(place);
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

	debug::append_menu_w(technical_windows_check_menu, MF_STRING, command_open_file, translate::string_check_open_file.show().c_str(), place);
	debug::append_menu_w(technical_windows_check_menu, MF_STRING, command_save_file_as, translate::string_check_save_file_as.show().c_str(), place);
	debug::append_menu_w(technical_windows_check_menu, MF_STRING, command_choose_color, translate::string_check_choose_color.show().c_str(), place);
	debug::append_menu_w(technical_windows_check_menu, MF_STRING, command_testing_dialog_window, translate::string__testing_dialog_box.show().c_str(), place);

	// Second floor
	// Второй этаж

	debug::append_menu_w(program_menu, MF_POPUP, (UINT_PTR)algebraic_book_menu, translate::string__book_alg.show().c_str(), place);
	line_element_menu(program_menu, place);
	debug::append_menu_w(program_menu, MF_STRING, command_exit, translate::string__exit.show().c_str(), place);

	debug::append_menu_w(window_menu, MF_POPUP, (UINT_PTR)technical_windows_check_menu, translate::string__technical_windows_check.show().c_str(), place);

	debug::append_menu_w(help_settings_menu, MF_STRING, command_debugger, translate::string__debugger.show().c_str(), place);
	debug::append_menu_w(help_settings_menu, MF_STRING, command_about, translate::string__about_program.show().c_str(), place);

	debug::append_menu_w(language_menu, MF_STRING, command_translate_English, L"English", place);
	debug::append_menu_w(language_menu, MF_STRING, command_translate_Russian, L"Русский", place);

	// First floor
	// Первый этаж

	debug::append_menu_w(root_menu, MF_POPUP, (UINT_PTR)program_menu, translate::string__program.show().c_str(), place);
	debug::append_menu_w(root_menu, MF_POPUP, (UINT_PTR)window_menu, translate::string__window.show().c_str(), place);
	debug::append_menu_w(root_menu, MF_POPUP, (UINT_PTR)help_settings_menu, translate::string_help_and_settings.show().c_str(), place);
	debug::append_menu_w(root_menu, MF_STRING, command_what_is_new, translate::string_what_is_new.show().c_str(), place);
	debug::append_menu_w(root_menu, MF_POPUP | MF_HELP, (UINT_PTR)language_menu, translate::string__language.show().c_str(), place);

	SetMenu(h_window, root_menu);
}

#endif