#pragma once
#include <windows.h>
#include "Commands.h"
#include "Translate.h"
#include "HistoryOfError.h"

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
	return AppendMenuW(h_menu, menu_flag, numberCommand, translating_string(title));
}

// Третий этаж

HMENU algebraic_book_menu = CreateMenu();
HMENU add_list_element_menu = CreateMenu();
HMENU cancel_menu = CreateMenu();
HMENU undo_menu = CreateMenu();
HMENU language_menu = CreateMenu();

// Второй этаж

HMENU program_menu = CreateMenu();
HMENU edit_menu = CreateMenu();
HMENU view_menu = CreateMenu();
HMENU help_settings_menu = CreateMenu();

// Первый этаж

HMENU root_menu = CreateMenu();

bool create_main_menu(HWND h_window) {
	// Третий этаж

	translating_element_menu(algebraic_book_menu, MF_STRING, command_algebraic_book_create, string_create);
	translating_element_menu(algebraic_book_menu, MF_STRING, command_open_algebraic_book, string_open);
	translating_element_menu(algebraic_book_menu, MF_STRING, command_save_algebraic_book, string_save);
	translating_element_menu(algebraic_book_menu, MF_STRING, command_save_algebraic_book_as, string_save_as);
	line_element_menu(algebraic_book_menu);
	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, string_compress);
	translating_element_menu(algebraic_book_menu, MF_STRING, NULL, string_lock);

	translating_element_menu(add_list_element_menu, MF_STRING, NULL, string_coordinate);
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, string_circuit);
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, string_paint);
	translating_element_menu(add_list_element_menu, MF_STRING, NULL, string_file_txt);

	translating_element_menu(cancel_menu, MF_STRING, NULL, string_cancel_last);

	translating_element_menu(undo_menu, MF_STRING, NULL, string_undo_last);

	AppendMenuW(language_menu, MF_STRING, command_translate_English, L"English");
	AppendMenuW(language_menu, MF_STRING, command_translate_Russian, L"Русский");

	// Второй этаж

	translating_element_menu(program_menu, MF_POPUP, (UINT_PTR)algebraic_book_menu, string_algebraic_book);
	line_element_menu(program_menu);
	translating_element_menu(program_menu, MF_STRING, NULL, string_chapter_add);
	translating_element_menu(program_menu, MF_POPUP, (UINT_PTR)add_list_element_menu, string_page_add);
	line_element_menu(program_menu);
	translating_element_menu(program_menu, MF_STRING, command_exit, string_exit);

	translating_element_menu(edit_menu, MF_STRING, NULL, string_search_command);
	translating_element_menu(edit_menu, MF_STRING, NULL, string_search_string);
	line_element_menu(edit_menu);
	translating_element_menu(edit_menu, MF_STRING, NULL, string_chapter_copy);
	translating_element_menu(edit_menu, MF_STRING, NULL, string_page_copy);
	translating_element_menu(edit_menu, MF_STRING, NULL, string_paste);
	line_element_menu(edit_menu);
	translating_element_menu(edit_menu, MF_POPUP, (UINT_PTR)cancel_menu, string_cancel);
	translating_element_menu(edit_menu, MF_POPUP, (UINT_PTR)undo_menu, string_undo);

	translating_element_menu(view_menu, MF_STRING, NULL, string_menu_and_toolbar);
	translating_element_menu(view_menu, MF_STRING, NULL, string_cursor);
	translating_element_menu(view_menu, MF_STRING, NULL, string_coordinate);
	translating_element_menu(view_menu, MF_STRING, NULL, string_style);
	line_element_menu(view_menu);
	translating_element_menu(view_menu, MF_STRING, NULL, string_default_view);

	translating_element_menu(help_settings_menu, MF_STRING, NULL, string_algebraic_book_parameter);
	translating_element_menu(help_settings_menu, MF_STRING, NULL, string_chapter_parameter);
	translating_element_menu(help_settings_menu, MF_STRING, NULL, string_page_parameter);
	line_element_menu(help_settings_menu);
	translating_element_menu(help_settings_menu, MF_STRING, command_about, string_program_parameter);
	translating_element_menu(help_settings_menu, MF_STRING, command_error_list, string_error_list);
	translating_element_menu(help_settings_menu, MF_POPUP, (UINT_PTR)language_menu, string_language);

	// Первый этаж

	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)program_menu, string_program);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)edit_menu, string_edit);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)view_menu, string_view_);
	translating_element_menu(root_menu, MF_POPUP, (UINT_PTR)help_settings_menu, string_help_settings);

	translating_element_menu(root_menu, MF_STRING, command_what_new, string_whats_new);

	SetMenu(h_window, root_menu);

	return true;
}

#endif