#pragma once
#include <windows.h>
#include "Translate.h"
#include "CodeWork.h"

#ifndef macro_header_exit_dialog
#define macro_header_exit_dialog

bool ask_wish_save(
	HWND h_window,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	int answer_information = MessageBoxW(
		h_window, 
		translate::string_asking_for_save_before_exit.show().c_str(),
		translate::string_program_name.show().c_str(),
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