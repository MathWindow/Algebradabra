#pragma once
#include <windows.h>
#include <commdlg.h>
#include <vector>
#include "Translate.h"
#include "ShortTypes.h"

#ifndef file_dialog_header
#define file_dialog_header

svt::cu_char string_path_max_size = 200;
WCHAR string_path[string_path_max_size]{};
WCHAR string_path_technical_check[string_path_max_size]{};

std::vector<WCHAR> string_open_book_fixer{};
std::vector<WCHAR> string_save_book_as_fixer{};
std::vector<WCHAR> string_open_file_fixer{};
std::vector<WCHAR> string_save_file_as_fixer{};

LPCWSTR string_save_book_pointer = string_open_book_fixer.data();
LPCWSTR string_open_book_pointer = string_save_book_as_fixer.data();
LPCWSTR string_open_file_pointer = string_open_file_fixer.data();
LPCWSTR string_save_file_pointer = string_save_file_as_fixer.data();

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

	void prepare_string_fixing() {
		translate::string_fix(
			translate::string(translate::string_open_book),
			&string_open_book_fixer
		);

		translate::string_fix(
			translate::string(translate::string_save_book_as),
			&string_save_book_as_fixer
		);

		translate::string_fix(
			translate::string(translate::string_open_file),
			&string_open_file_fixer
		);

		translate::string_fix(
			translate::string(translate::string_save_file_as),
			&string_save_file_as_fixer
		);
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
		open.hwndOwner = h_window;
		save.hwndOwner = h_window;
		both_.hwndOwner = h_window;
	}
};

open_file_name_w_x ofn_algebraic_book;
open_file_name_w_x ofn_technical_check;

void plan_ofn_algebraic_book(HWND h_window) {
	ofn_algebraic_book.zero_memory();

	ofn_algebraic_book.prepare_string_fixing();

	ofn_algebraic_book.open.lStructSize =
		sizeof(ofn_algebraic_book.open);
	ofn_algebraic_book.open.lpstrTitle = string_save_book_pointer;
	ofn_algebraic_book.open.lpstrFile = string_path;
	ofn_algebraic_book.open.lpstrFile[0] = L'\0';
	ofn_algebraic_book.open.nMaxFile = sizeof(string_path);
	ofn_algebraic_book.open.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
	
	ofn_algebraic_book.save.lStructSize =
		sizeof(ofn_algebraic_book.save);
	ofn_algebraic_book.save.lpstrTitle = string_open_book_pointer;
	ofn_algebraic_book.save.lpstrFile = string_path;
	ofn_algebraic_book.save.lpstrFile[0] = L'\0';
	ofn_algebraic_book.save.nMaxFile = sizeof(string_path);
	ofn_algebraic_book.save.Flags = OFN_PATHMUSTEXIST;
	
	ofn_algebraic_book.both_hwndOwner(h_window);
}

void plan_ofn_technical_check(HWND h_window) {
	ofn_technical_check.zero_memory();

	ofn_technical_check.prepare_string_fixing();

	ofn_technical_check.open.lStructSize = sizeof(ofn_technical_check.open);
	ofn_technical_check.open.lpstrTitle = string_open_file_pointer;
	ofn_technical_check.open.lpstrFile = string_path_technical_check;
	ofn_technical_check.open.lpstrFile[0] = L'\0';
	ofn_technical_check.open.nMaxFile = sizeof(string_path_technical_check);
	ofn_technical_check.open.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

	ofn_technical_check.save.lStructSize = sizeof(ofn_technical_check.save);
	ofn_technical_check.save.lpstrTitle = string_save_file_pointer;
	ofn_technical_check.save.lpstrFile = string_path_technical_check;
	ofn_technical_check.save.lpstrFile[0] = L'\0';
	ofn_technical_check.save.nMaxFile = sizeof(string_path_technical_check);
	ofn_technical_check.save.Flags = OFN_PATHMUSTEXIST;

	ofn_technical_check.both_hwndOwner(h_window);
}

#endif