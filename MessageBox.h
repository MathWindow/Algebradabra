#pragma once
#include <windows.h>
#include "Naming.h"

#define message_box_type_error 0
#define message_box_type_question_yes_no 1
#define message_box_type_question_yes_no_cancel 2
#define message_box_type_nope 3

UINT translate_message_box_type(int message_type) {
	if (message_type == message_box_type_error) {
		return MB_ICONERROR;
	}
	else if (message_type == message_box_type_question_yes_no) {
		return MB_ICONQUESTION | MB_YESNO;
	}
	else if (message_type == message_box_type_question_yes_no_cancel) {
		return MB_ICONQUESTION | MB_YESNOCANCEL;
	}
	else if (message_type == message_box_type_nope) {
		return NULL;
	}

	return NULL;
}

char message_box(HWND h_window, LPCWSTR details, int message_type) {
	MessageBoxW(h_window, L"", program_name, NULL);
}