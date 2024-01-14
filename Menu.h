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
	translate::string_index* title
) {
	return AppendMenuW(h_menu, menu_flag, numberCommand, translate::string(title).c_str());
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

	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, &translate::index_create);
	translating_element_menu(algebraic_book_menu, MF_STRING, command_open_algebraic_book, &translate::index_open);
	translating_element_menu(algebraic_book_menu, MF_STRING, command_save_algebraic_book, &translate::index_save);
	translating_element_menu(algebraic_book_menu, MF_STRING, command_save_algebraic_book_as, &translate::index_save_as);
	line_element_menu(algebraic_book_menu);
	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, &translate::index_compress);
	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, &translate::index_lock_with_code);

	translating_element_menu(add_list_element_menu, MF_STRING, NULL, &translate::index_coordinate);
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, &translate::index_circuit);
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, &translate::index_paint);
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, &translate::index_file_txt);

	translating_element_menu(cancel_menu, MF_STRING, NULL, &translate::index_cancel_last);

	translating_element_menu(undo_menu, MF_STRING, NULL, &translate::index_undo_last);

	AppendMenuW(language_menu, MF_STRING, command_translate_English, L"English");
	AppendMenuW(language_menu, MF_STRING, command_translate_Russian, L"Русский");

	translating_element_menu(technical_windows_check_menu, MF_STRING, command_open_file, &translate::index_opening_file_window);
	translating_element_menu(technical_windows_check_menu, MF_STRING, command_save_file_as, &translate::index_saving_file_window);
	translating_element_menu(technical_windows_check_menu, MF_STRING, command_choose_color, &translate::index_choosing_color_window);
	translating_element_menu(technical_windows_check_menu, MF_STRING, command_testing_dialog_window, &translate::index_testing_dialog_window);

	// Второй этаж

	translating_element_menu(program_menu, MF_POPUP, (UINT_PTR)algebraic_book_menu, &translate::index_algebraic_book);
	translating_element_menu(program_menu, MF_POPUP, (UINT_PTR)add_list_element_menu, &translate::index_page_add);
	line_element_menu(program_menu);
	translating_element_menu(program_menu, MF_STRING, command_exit, &translate::index_exit);

	translating_element_menu(edit_menu, MF_STRING, NULL, &translate::index_search_command);
	translating_element_menu(edit_menu, MF_STRING, NULL, &translate::index_search_string);
	line_element_menu(edit_menu);
	translating_element_menu(edit_menu, MF_STRING, NULL, &translate::index_page_copy);
	translating_element_menu(edit_menu, MF_STRING, NULL, &translate::index_paste);
	line_element_menu(edit_menu);
	translating_element_menu(edit_menu, MF_POPUP, (UINT_PTR)cancel_menu, &translate::index_cancel);
	translating_element_menu(edit_menu, MF_POPUP, (UINT_PTR)undo_menu, &translate::index_undo);

	translating_element_menu(view_menu, MF_STRING, NULL, &translate::index_menu_and_toolbar);
	translating_element_menu(view_menu, MF_STRING, NULL, &translate::index_cursor);
	translating_element_menu(view_menu, MF_STRING, NULL, &translate::index_coordinate);
	translating_element_menu(view_menu, MF_STRING, NULL, &translate::index_style);
	line_element_menu(view_menu);
	translating_element_menu(view_menu, MF_STRING, NULL, &translate::index_default_view);

	translating_element_menu(window_menu, MF_POPUP, (UINT_PTR)technical_windows_check_menu, &translate::index_technical_windows_check);

	translating_element_menu(help_settings_menu, MF_STRING, NULL, &translate::index_algebraic_book_parameter);
	translating_element_menu(help_settings_menu, MF_STRING, NULL, &translate::index_page_parameter);
	line_element_menu(help_settings_menu);
	translating_element_menu(help_settings_menu, MF_STRING, command_about, &translate::index_program_parameter);
	translating_element_menu(help_settings_menu, MF_POPUP, (UINT_PTR)language_menu, &translate::index_language);

	// Первый этаж

	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)program_menu, &translate::index_program);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)edit_menu, &translate::index_edit);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)view_menu, &translate::index_view);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)window_menu, &translate::index_window);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)help_settings_menu, &translate::index_help_settings);

	translating_element_menu(root_menu, MF_STRING, command_whats_new, &translate::index_whats_new);

	SetMenu(h_window, root_menu);

	return true;
}

#endif