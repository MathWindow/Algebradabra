#pragma once
#include <windows.h>
#include "Naming.h"
#include "Translate.h"

bool ask_wish_save(HWND h_window) {
	int answer_information = MessageBoxW(h_window, L"��������� ��������� ����� ������� �� ���������?", program_name, MB_ICONWARNING | MB_YESNOCANCEL);

	if (answer_information == IDYES) {
		// ���������� ����������...
	}
	else if (answer_information != IDNO) {
		return false;
	}

	return true;
}