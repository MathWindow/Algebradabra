#pragma once
#include <windows.h>
#include <string>
#include "resource.h"
#include "Naming.h"
#include "ClassWindow.h"
using namespace std;

RECT monitor_information = { 0 };
int monitor_width = 0;
int monitor_height = 0;

const int main_window_width = 900;
const int main_window_height = 500;
int main_window_x_position = 0;
int main_window_y_position = 0;

LRESULT CALLBACK main_procedure(main_procedure_arguments);

int WINAPI WinMain(HINSTANCE h_instance, HINSTANCE h_preview_instance, LPSTR arguments, int no_command_show) {
	WNDCLASS main_class = main_class_example(COLOR_WINDOW, h_instance, main_icon, IDC_ARROW, L"Main window", main_procedure);

	if (!RegisterClassW(&main_class)) {
		MessageBoxW(NULL, L"Произошла ошибка во время загрузки ПО", program_name, MB_ICONERROR);

		return -1;
	}

	MSG main_message = { 0 };

	GetClipCursor(&monitor_information);
	monitor_width = monitor_information.right;
	monitor_height = monitor_information.bottom;

	main_window_x_position = (monitor_width - main_window_width) / 2;
	main_window_y_position = (monitor_height - main_window_height) / 2;

	CreateWindowW(
		L"Main window", 
		program_name, 
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		main_window_x_position, 
		main_window_y_position, 
		main_window_width, 
		main_window_height, 
		NULL, 
		NULL, 
		NULL, 
		NULL
	);

	while (GetMessage(&main_message, NULL, NULL, NULL)) {
		TranslateMessage(&main_message);
		DispatchMessage(&main_message);
	}

	return 0;
}