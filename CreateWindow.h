#pragma once
#include <windows.h>
#include "resource.h"
#include "ClassWindow.h"
#include "Widgets.h"
#include "Monitor.h"
using namespace std;

#ifndef create_window_header
#define create_window_header

const uint_16 main_window_width = 900;
const uint_16 main_window_height = 500;
uint_16 main_window_x_position = 0;
uint_16 main_window_y_position = 0;

const uint_16 error_list_window_width = 
	x_out * 3 + width_listbox_default + width_static_error_list + 10;

const uint_16 error_list_window_height = 
	y_out * 2 + height_static_error_list + 20;

uint_16 error_list_x_position = 30;
uint_16 error_list_y_position = 50;

LRESULT CALLBACK main_procedure(procedure_arguments);
LRESULT CALLBACK error_list_procedure(procedure_arguments);

int WINAPI WinMain(HINSTANCE h_instance, HINSTANCE h_preview_instance, LPSTR arguments, int no_command_show) {
	WNDCLASS main_class = main_class_example(
		COLOR_WINDOW, 
		h_instance, 
		main_icon, 
		IDC_ARROW, 
		main_window_class_name, 
		main_procedure
	);

	WNDCLASS error_list_class = main_class_example(
		COLOR_WINDOW,
		h_instance,
		main_icon,
		IDC_ARROW,
		error_list_window_class_name,
		error_list_procedure
	);

	if (!RegisterClassW(&main_class)) {
		MessageBoxW(NULL, L"��������� ������ �� ����� �������� ��", program_name, MB_ICONERROR);

		return -1;
	}

	if (!RegisterClassW(&error_list_class)) {
		MessageBoxW(NULL, L"��������� ������ �� ����� �������� ��", program_name, MB_ICONERROR);
	}

	MSG main_message = { 0 };

	get_monitor_information();

	set_window_center_position(
		main_window_width, 
		main_window_height, 
		&main_window_x_position, 
		&main_window_y_position
	);

	CreateWindowW(
		main_window_class_name, 
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

#endif