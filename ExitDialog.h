#pragma once
#include <windows.h>
#include "Translate.h"

#ifndef exit_dialog_header
#define exit_dialog_header

bool ask_wish_save(HWND h_window) {
	int answer_information = MessageBoxW(
		h_window, 
		translate::string(&translate::index_asking_for_save_before_exit).c_str(),
		translate::string(&translate::index_program_name).c_str(),
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