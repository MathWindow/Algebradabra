#pragma once
#include <windows.h>
#include <basetsd.h>
#include "Commands.h"
#include "Translate.h"

// 1

#ifndef menu_header
#define menu_header

BOOL _stdcall line_element_menu(HMENU h_menu) {
	return AppendMenuW(h_menu, MF_SEPARATOR, NULL, NULL);
}

BOOL _stdcall translating_element_menu(
	HMENU h_menu, 
	UINT menu_flag, 
	UINT_PTR numberCommand, 
	LPCWSTR title
) {
	return AppendMenuW(h_menu, menu_flag, numberCommand, title);
}

// Третий этаж

HMENU algebraic_book_menu = CreateMenu();
HMENU add_list_element_menu = CreateMenu();
HMENU cancel_menu = CreateMenu();
HMENU undo_menu = CreateMenu();
HMENU language_menu = CreateMenu();
HMENU technical_windows_check_menu = CreateMenu();

// Второй этаж

HMENU program_menu = CreateMenu();
HMENU edit_menu = CreateMenu();
HMENU view_menu = CreateMenu();
HMENU window_menu = CreateMenu();
HMENU help_settings_menu = CreateMenu();

// Первый этаж

HMENU root_menu = CreateMenu();

bool create_main_menu(HWND h_window) {
	// Третий этаж

	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, translate::string__create.c_style());
	translating_element_menu(algebraic_book_menu, MF_STRING, command_open_algebraic_book, translate::string__open.c_style());
	translating_element_menu(algebraic_book_menu, MF_STRING, command_save_algebraic_book, translate::string__save.c_style());
	translating_element_menu(algebraic_book_menu, MF_STRING, command_save_algebraic_book_as, translate::string__save_as.c_style());
	line_element_menu(algebraic_book_menu);
	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, translate::string__compress.c_style());
	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, translate::string__lock_with_password.c_style());

	translating_element_menu(add_list_element_menu, MF_STRING, NULL, translate::string__coordinate.c_style());
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, translate::string__circuit.c_style());
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, translate::string__paint.c_style());
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, translate::string__file_txt.c_style());

	translating_element_menu(cancel_menu, MF_STRING, NULL, translate::string__cancel_the_last.c_style());

	translating_element_menu(undo_menu, MF_STRING, NULL, translate::string__undo_the_last.c_style());

	AppendMenuW(language_menu, MF_STRING, command_translate_English, L"English");
	AppendMenuW(language_menu, MF_STRING, command_translate_Russian, L"Русский");

	translating_element_menu(technical_windows_check_menu, MF_STRING, command_open_file, translate::string_check_open_file.c_style());
	translating_element_menu(technical_windows_check_menu, MF_STRING, command_save_file_as, translate::string_check_save_file_as.c_style());
	translating_element_menu(technical_windows_check_menu, MF_STRING, command_choose_color, translate::string_check_choose_color.c_style());
	translating_element_menu(technical_windows_check_menu, MF_STRING, command_testing_dialog_window, translate::string__testing_dialog_box.c_style());

	// Второй этаж

	translating_element_menu(program_menu, MF_POPUP, (UINT_PTR)algebraic_book_menu, translate::string__book_alg.c_style());
	translating_element_menu(program_menu, MF_POPUP, (UINT_PTR)add_list_element_menu, translate::string__page_add.c_style());
	line_element_menu(program_menu);
	translating_element_menu(program_menu, MF_STRING, command_exit, translate::string__exit.c_style());

	translating_element_menu(edit_menu, MF_STRING, NULL, translate::string__search_command.c_style());
	translating_element_menu(edit_menu, MF_STRING, NULL, translate::string__search_string.c_style());
	line_element_menu(edit_menu);
	translating_element_menu(edit_menu, MF_STRING, NULL, translate::string_page_copy.c_style());
	translating_element_menu(edit_menu, MF_STRING, NULL, translate::string__paste.c_style());
	line_element_menu(edit_menu);
	translating_element_menu(edit_menu, MF_POPUP, (UINT_PTR)cancel_menu, translate::string__cancel.c_style());
	translating_element_menu(edit_menu, MF_POPUP, (UINT_PTR)undo_menu, translate::string__undo.c_style());

	translating_element_menu(view_menu, MF_STRING, NULL, translate::string__menu_and_toolbar.c_style());
	translating_element_menu(view_menu, MF_STRING, NULL, translate::string__cursor.c_style());
	translating_element_menu(view_menu, MF_STRING, NULL, translate::string__coordinate.c_style());
	translating_element_menu(view_menu, MF_STRING, NULL, translate::string__style.c_style());
	line_element_menu(view_menu);
	translating_element_menu(view_menu, MF_STRING, NULL, translate::string__default_view.c_style());

	translating_element_menu(window_menu, MF_POPUP, (UINT_PTR)technical_windows_check_menu, translate::string__technical_windows_check.c_style());

	translating_element_menu(help_settings_menu, MF_STRING, NULL, translate::string__algebraic_books_parameter.c_style());
	translating_element_menu(help_settings_menu, MF_STRING, NULL, translate::string__pages_parameter.c_style());
	line_element_menu(help_settings_menu);
	translating_element_menu(help_settings_menu, MF_STRING, command_about, translate::string__programs_parameter.c_style());
	translating_element_menu(help_settings_menu, MF_POPUP, (UINT_PTR)language_menu, translate::string__language.c_style());

	// Первый этаж

	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)program_menu, translate::string__program.c_style());
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)edit_menu, translate::string__edit.c_style());
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)view_menu, translate::string__view.c_style());
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)window_menu, translate::string__window.c_style());
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)help_settings_menu, translate::string_help_and_settings.c_style());

	translating_element_menu(root_menu, MF_STRING, command_whats_new, translate::string__whats_new.c_style());

	SetMenu(h_window, root_menu);

	return true;
}

#endif