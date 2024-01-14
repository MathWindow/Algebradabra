#pragma once
#include <windows.h>
#include "Translate.h"
#include "ShortTypes.h"
#include <commdlg.h>
using namespace std;

#ifndef file_dialog_header
#define file_dialog_header

cu_char string_path_max_size = 200;
wchar_t string_path[string_path_max_size]{};
wchar_t string_path_technical_check[string_path_max_size]{};

class open_file_name_w_x {
public:
	OPENFILENAMEW save;
	OPENFILENAMEW open;
	OPENFILENAMEW both_;

	void zero_memory() {
		ZeroMemory(&save, sizeof(save));
		ZeroMemory(&open, sizeof(open));
		ZeroMemory(&both_, sizeof(both_));
	}

	BOOL __stdcall open_file_dialog() {
		return GetOpenFileNameW(&open);
	}

	BOOL __stdcall save_file_dialog() {
		return GetSaveFileNameW(&save);
	}

	void continue_planning() {
		if (both_.hwndOwner != NULL) {
			open.hwndOwner = both_.hwndOwner;
			save.hwndOwner = both_.hwndOwner;
		}
	}

	void both_hwndOwner(HWND h_window) {
		open.hwndOwner = h_window;;
		save.hwndOwner = h_window;
		both_.hwndOwner = h_window;
	}
};

open_file_name_w_x ofn_algebraic_book;
open_file_name_w_x ofn_technical_check;

void plan_ofn_algebraic_book(HWND h_window) {
	ofn_algebraic_book.zero_memory();

	ofn_algebraic_book.open.lStructSize =
		sizeof(ofn_algebraic_book.open);
	ofn_algebraic_book.open.lpstrTitle = translate::translating_string(translate::string_open_book);
	ofn_algebraic_book.open.lpstrFile = string_path;
	ofn_algebraic_book.open.lpstrFile[0] = L'\0';
	ofn_algebraic_book.open.nMaxFile = sizeof(string_path);
	ofn_algebraic_book.open.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
	
	ofn_algebraic_book.save.lStructSize =
		sizeof(ofn_algebraic_book.save);
	ofn_algebraic_book.save.lpstrTitle = translate::translating_string(translate::string_save_book_as);
	ofn_algebraic_book.save.lpstrFile = string_path;
	ofn_algebraic_book.save.lpstrFile[0] = L'\0';
	ofn_algebraic_book.save.nMaxFile = sizeof(string_path);
	ofn_algebraic_book.save.Flags = OFN_PATHMUSTEXIST;
	
	ofn_algebraic_book.both_.hwndOwner = h_window;

	ofn_algebraic_book.continue_planning();
}

void plan_ofn_technical_check(HWND h_window) {
	ofn_technical_check.zero_memory();

	ofn_technical_check.open.lStructSize = sizeof(ofn_technical_check.open);
	ofn_technical_check.open.lpstrTitle = translate::translating_string(translate::string_open_file);
	ofn_technical_check.open.lpstrFile = string_path_technical_check;
	ofn_technical_check.open.lpstrFile[0] = L'\0';
	ofn_technical_check.open.nMaxFile = sizeof(string_path_technical_check);
	ofn_technical_check.open.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

	ofn_technical_check.save.lStructSize = sizeof(ofn_technical_check.save);
	ofn_technical_check.save.lpstrTitle = translate::translating_string(translate::string_save_file_as);
	ofn_technical_check.save.lpstrFile = string_path_technical_check;
	ofn_technical_check.save.lpstrFile[0] = L'\0';
	ofn_technical_check.save.nMaxFile = sizeof(string_path_technical_check);
	ofn_technical_check.save.Flags = OFN_PATHMUSTEXIST;

	ofn_technical_check.both_.hwndOwner = h_window;

	ofn_technical_check.continue_planning();
}

#endif