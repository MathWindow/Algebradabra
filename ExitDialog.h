#pragma once
#include <windows.h>
#include "VersionInfo.h"
#include "Translate.h"

#ifndef exit_dialog_header
#define exit_dialog_header

bool ask_wish_save(HWND h_window) {
	int answer_information = MessageBoxW(
		h_window, 
		translate::translating_string(translate::string_asking_for_save_before_exit), 
		program_name, 
		MB_ICONWARNING | MB_YESNOCANCEL
	);

	if (answer_information == IDYES) {
		// Сохранение документов...
	}
	else if (answer_information != IDNO) {
		return false;
	}

	return true;
}

#endif