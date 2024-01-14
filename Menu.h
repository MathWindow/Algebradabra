#pragma once
#include <windows.h>
#include <basetsd.h>
#include "Commands.h"
#include "Translate.h"
#include "AssociationType.h"

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
	string_param title
) {
	return AppendMenuW(h_menu, menu_flag, numberCommand, translate::translating_string(title));
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

	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, translate::string_create);
	translating_element_menu(algebraic_book_menu, MF_STRING, command_open_algebraic_book, translate::string_open);
	translating_element_menu(algebraic_book_menu, MF_STRING, command_save_algebraic_book, translate::string_save);
	translating_element_menu(algebraic_book_menu, MF_STRING, command_save_algebraic_book_as, translate::string_save_as);
	line_element_menu(algebraic_book_menu);
	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, translate::string_compress);
	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, translate::string_lock_with_code);

	translating_element_menu(add_list_element_menu, MF_STRING, NULL, translate::string_coordinate);
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, translate::string_circuit);
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, translate::string_paint);
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, translate::string_file_txt);

	translating_element_menu(cancel_menu, MF_STRING, NULL, translate::string_cancel_last);

	translating_element_menu(undo_menu, MF_STRING, NULL, translate::string_undo_last);

	AppendMenuW(language_menu, MF_STRING, command_translate_English, L"English");
	AppendMenuW(language_menu, MF_STRING, command_translate_Russian, L"Русский");

	translating_element_menu(technical_windows_check_menu, MF_STRING, command_open_file, translate::string_opening_file_window);
	translating_element_menu(technical_windows_check_menu, MF_STRING, command_save_file_as, translate::string_saving_file_window);
	translating_element_menu(technical_windows_check_menu, MF_STRING, command_choose_color, translate::string_choosing_color_window);
	translating_element_menu(technical_windows_check_menu, MF_STRING, command_testing_dialog_window, translate::string_testing_dialog_window);

	// Второй этаж

	translating_element_menu(program_menu, MF_POPUP, (UINT_PTR)algebraic_book_menu, translate::string_algebraic_book);
	translating_element_menu(program_menu, MF_POPUP, (UINT_PTR)add_list_element_menu, translate::string_page_add);
	line_element_menu(program_menu);
	translating_element_menu(program_menu, MF_STRING, command_exit, translate::string_exit);

	translating_element_menu(edit_menu, MF_STRING, NULL, translate::string_search_command);
	translating_element_menu(edit_menu, MF_STRING, NULL, translate::string_search_string);
	line_element_menu(edit_menu);
	translating_element_menu(edit_menu, MF_STRING, NULL, translate::string_page_copy);
	translating_element_menu(edit_menu, MF_STRING, NULL, translate::string_paste);
	line_element_menu(edit_menu);
	translating_element_menu(edit_menu, MF_POPUP, (UINT_PTR)cancel_menu, translate::string_cancel);
	translating_element_menu(edit_menu, MF_POPUP, (UINT_PTR)undo_menu, translate::string_undo);

	translating_element_menu(view_menu, MF_STRING, NULL, translate::string_menu_and_toolbar);
	translating_element_menu(view_menu, MF_STRING, NULL, translate::string_cursor);
	translating_element_menu(view_menu, MF_STRING, NULL, translate::string_coordinate);
	translating_element_menu(view_menu, MF_STRING, NULL, translate::string_style);
	line_element_menu(view_menu);
	translating_element_menu(view_menu, MF_STRING, NULL, translate::string_default_view);

	translating_element_menu(window_menu, MF_POPUP, (UINT_PTR)technical_windows_check_menu, translate::string_technical_windows_check);

	translating_element_menu(help_settings_menu, MF_STRING, NULL, translate::string_algebraic_book_parameter);
	translating_element_menu(help_settings_menu, MF_STRING, NULL, translate::string_page_parameter);
	line_element_menu(help_settings_menu);
	translating_element_menu(help_settings_menu, MF_STRING, command_about, translate::string_program_parameter);
	translating_element_menu(help_settings_menu, MF_STRING, NULL, translate::string_errors_list_window);
	translating_element_menu(help_settings_menu, MF_POPUP, (UINT_PTR)language_menu, translate::string_language);

	// Первый этаж

	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)program_menu, translate::string_program);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)edit_menu, translate::string_edit);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)view_menu, translate::string_view_);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)window_menu, translate::string_window);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)help_settings_menu, translate::string_help_settings);

	translating_element_menu(root_menu, MF_STRING, command_whats_new, translate::string_whats_new);

	SetMenu(h_window, root_menu);

	return true;
}

#endif