#pragma once
#include <windows.h>
#include <commdlg.h>
#include <cstring>
#include "Translate.h"
#include "ShortTypes.h"
#include "CodeWork.h"

#ifndef macro_header_file_dialog
#define macro_header_file_dialog

cu_char_ string_path_max_size = 200;
WCHAR string_path[string_path_max_size]{};
WCHAR string_path_technical_check[string_path_max_size]{};

class open_file_name_w_x {
public:
	OPENFILENAMEW save;
	OPENFILENAMEW open;

	void zero_memory(
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		memset(&save, 0, sizeof(save));
		memset(&open, 0, sizeof(open));
	}

	BOOL __stdcall open_file_dialog(
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		return GetOpenFileNameW(&open);
	}

	BOOL __stdcall save_file_dialog(
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		return GetSaveFileNameW(&save);
	}

	void both_h_window_owner(
		HWND h_window,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		open.hwndOwner = h_window;
		save.hwndOwner = h_window;
	}
};

open_file_name_w_x ofn_algebraic_book;
open_file_name_w_x ofn_technical_check;

void plan_ofn_algebraic_book(
	HWND h_window,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	ofn_algebraic_book.zero_memory(place);

	ofn_algebraic_book.open.lStructSize = sizeof(ofn_algebraic_book.open);
	ofn_algebraic_book.open.lpstrTitle = translate::string_title_dialog_box_open_book.show_fixed();
	ofn_algebraic_book.open.lpstrFile = string_path;
	ofn_algebraic_book.open.lpstrFile[0] = L'\0';
	ofn_algebraic_book.open.nMaxFile = sizeof(string_path);
	ofn_algebraic_book.open.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
	
	ofn_algebraic_book.save.lStructSize = sizeof(ofn_algebraic_book.save);
	ofn_algebraic_book.save.lpstrTitle = translate::string_title_dialog_box_save_book_as.show_fixed();
	ofn_algebraic_book.save.lpstrFile = string_path;
	ofn_algebraic_book.save.lpstrFile[0] = L'\0';
	ofn_algebraic_book.save.nMaxFile = sizeof(string_path);
	ofn_algebraic_book.save.Flags = OFN_PATHMUSTEXIST;
	
	ofn_algebraic_book.both_h_window_owner(h_window, place);
}

void plan_ofn_technical_check(
	HWND h_window,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	ofn_technical_check.zero_memory(place);

	ofn_technical_check.open.lStructSize = sizeof(ofn_technical_check.open);
	ofn_technical_check.open.lpstrTitle = translate::string_title_dialog_box_open_file.show_fixed();
	ofn_technical_check.open.lpstrFile = string_path_technical_check;
	ofn_technical_check.open.lpstrFile[0] = L'\0';
	ofn_technical_check.open.nMaxFile = sizeof(string_path_technical_check);
	ofn_technical_check.open.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

	ofn_technical_check.save.lStructSize = sizeof(ofn_technical_check.save);
	ofn_technical_check.save.lpstrTitle = translate::string_title_dialog_box_save_file_as.show_fixed();
	ofn_technical_check.save.lpstrFile = string_path_technical_check;
	ofn_technical_check.save.lpstrFile[0] = L'\0';
	ofn_technical_check.save.nMaxFile = sizeof(string_path_technical_check);
	ofn_technical_check.save.Flags = OFN_PATHMUSTEXIST;

	ofn_technical_check.both_h_window_owner(h_window, place);
}

#endif