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
	translate::string_ title
) {
	return AppendMenuW(h_menu, menu_flag, numberCommand, title.show_c_style());
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

	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, translate::string__create);
	translating_element_menu(algebraic_book_menu, MF_STRING, command_open_algebraic_book, translate::string__open);
	translating_element_menu(algebraic_book_menu, MF_STRING, command_save_algebraic_book, translate::string__save);
	translating_element_menu(algebraic_book_menu, MF_STRING, command_save_algebraic_book_as, translate::string__save_as);
	line_element_menu(algebraic_book_menu);
	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, translate::string__compress);
	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, translate::string__lock_with_password);

	translating_element_menu(add_list_element_menu, MF_STRING, NULL, translate::string__coordinate);
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, translate::string__circuit);
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, translate::string__paint);
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, translate::string__file_txt);

	translating_element_menu(cancel_menu, MF_STRING, NULL, translate::string__cancel_the_last);

	translating_element_menu(undo_menu, MF_STRING, NULL, translate::string__undo_the_last);

	AppendMenuW(language_menu, MF_STRING, command_translate_English, L"English");
	AppendMenuW(language_menu, MF_STRING, command_translate_Russian, L"Русский");

	translating_element_menu(technical_windows_check_menu, MF_STRING, command_open_file, translate::string_check_open_file);
	translating_element_menu(technical_windows_check_menu, MF_STRING, command_save_file_as, translate::string_check_save_file_as);
	translating_element_menu(technical_windows_check_menu, MF_STRING, command_choose_color, translate::string_check_choose_color);
	translating_element_menu(technical_windows_check_menu, MF_STRING, command_testing_dialog_window, translate::string__testing_dialog_box);

	// Второй этаж

	translating_element_menu(program_menu, MF_POPUP, (UINT_PTR)algebraic_book_menu, translate::string_algebraic_book);
	translating_element_menu(program_menu, MF_POPUP, (UINT_PTR)add_list_element_menu, translate::string__page_add);
	line_element_menu(program_menu);
	translating_element_menu(program_menu, MF_STRING, command_exit, translate::string__exit);

	translating_element_menu(edit_menu, MF_STRING, NULL, translate::string__search_command);
	translating_element_menu(edit_menu, MF_STRING, NULL, translate::string__search_string);
	line_element_menu(edit_menu);
	translating_element_menu(edit_menu, MF_STRING, NULL, translate::string_page_copy);
	translating_element_menu(edit_menu, MF_STRING, NULL, translate::string__paste);
	line_element_menu(edit_menu);
	translating_element_menu(edit_menu, MF_POPUP, (UINT_PTR)cancel_menu, translate::string__cancel);
	translating_element_menu(edit_menu, MF_POPUP, (UINT_PTR)undo_menu, translate::string__undo);

	translating_element_menu(view_menu, MF_STRING, NULL, translate::string__menu_and_toolbar);
	translating_element_menu(view_menu, MF_STRING, NULL, translate::string__cursor);
	translating_element_menu(view_menu, MF_STRING, NULL, translate::string__coordinate);
	translating_element_menu(view_menu, MF_STRING, NULL, translate::string__style);
	line_element_menu(view_menu);
	translating_element_menu(view_menu, MF_STRING, NULL, translate::string__default_view);

	translating_element_menu(window_menu, MF_POPUP, (UINT_PTR)technical_windows_check_menu, translate::string__technical_windows_check);

	translating_element_menu(help_settings_menu, MF_STRING, NULL, translate::string__algebraic_books_parameter);
	translating_element_menu(help_settings_menu, MF_STRING, NULL, translate::string__pages_parameter);
	line_element_menu(help_settings_menu);
	translating_element_menu(help_settings_menu, MF_STRING, command_about, translate::string__programs_parameter);
	translating_element_menu(help_settings_menu, MF_POPUP, (UINT_PTR)language_menu, translate::string__language);

	// Первый этаж

	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)program_menu, translate::string__program);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)edit_menu, translate::string__edit);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)view_menu, translate::string__view);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)window_menu, translate::string__window);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)help_settings_menu, translate::string_help_and_settings);

	translating_element_menu(root_menu, MF_STRING, command_whats_new, translate::string__whats_new);

	SetMenu(h_window, root_menu);

	return true;
}

#endif