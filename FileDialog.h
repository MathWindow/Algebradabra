#pragma once
#include <windows.h>
#include <array>
#include "ShortTypes.h"
using namespace std;

#ifndef file_dialog_header
#define file_dialog_header

cu_char string_path_max_size = 200;
wchar_t string_path[string_path_max_size]{};

class OPENFILENAMEW_X {
public:
	OPENFILENAMEW save;
	OPENFILENAMEW open;
	OPENFILENAMEW both;

	void zero_memory() {
		ZeroMemory(&save, sizeof(save));
		ZeroMemory(&open, sizeof(open));
		ZeroMemory(&both, sizeof(both));
	}

	BOOL __stdcall open_file_dialog() {
		return GetOpenFileNameW(&open);
	}

	BOOL __stdcall save_file_dialog() {
		return GetSaveFileNameW(&save);
	}
};

OPENFILENAMEW_X ofn_algebraic_book;

void plan_ofn_algebraic_book(HWND h_window) {
	ofn_algebraic_book.zero_memory();

	ofn_algebraic_book.open.hwndOwner = h_window;
	ofn_algebraic_book.open.hInstance = NULL;
	ofn_algebraic_book.open.lStructSize =
		sizeof(ofn_algebraic_book.open);
	ofn_algebraic_book.open.lpstrTitle = L"Открыть книгу...";
	ofn_algebraic_book.open.lpstrFile = string_path;
	ofn_algebraic_book.open.lpstrFile[0] = L'\0';
	ofn_algebraic_book.open.nMaxFile = sizeof(string_path);
	ofn_algebraic_book.open.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

	ofn_algebraic_book.save.hwndOwner = h_window;
	ofn_algebraic_book.save.hInstance = NULL;
	ofn_algebraic_book.save.lStructSize =
		sizeof(ofn_algebraic_book.save);
	ofn_algebraic_book.save.lpstrTitle = L"Сохранить книгу как...";
	ofn_algebraic_book.save.lpstrFile = string_path;
	ofn_algebraic_book.save.lpstrFile[0] = L'\0';
	ofn_algebraic_book.save.nMaxFile = sizeof(string_path);
	ofn_algebraic_book.save.Flags = OFN_PATHMUSTEXIST;
}

#endif