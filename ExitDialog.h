#pragma once
#include <windows.h>
#include "Translate.h"

#ifndef macro_header_exit_dialog
#define macro_header_exit_dialog

bool ask_wish_save(HWND h_window) {
	int answer_information = MessageBoxW(
		h_window, 
		translate::string_asking_for_save_before_exit.c_style(),
		translate::string_program_name.c_style(),
		MB_ICONWARNING | MB_YESNOCANCEL
	);

	if (answer_information == IDYES) {
		// Saving documents...
		// Сохранение документов...
	}
	else if (answer_information != IDNO) {
		return false;
	}

	return true;
}

#endif