#pragma once
#include <windows.h>
#include <corecrt.h>
#include "resource.h"
#include "ClassWindow.h"
#include "Monitor.h"
#include "WindowXY.h"
#include "Translate.h"

// 1

#ifndef create_window_header
#define create_window_header

LRESULT CALLBACK main_procedure(procedure_arguments);

int WINAPI WinMain(HINSTANCE h_instance, HINSTANCE h_preview_instance, LPSTR arguments, int no_command_show) {
	WNDCLASS main_class = main_class_example(
		COLOR_WINDOW, 
		h_instance, 
		main_icon, 
		IDC_ARROW, 
		main_window_class_name, 
		main_procedure
	);

	bool main_class_is_registered = 
		register_class_name (
		&main_class,
		translate::string_cannot_create_class_main,
		__FUNCTIONW__
	);

	if (main_class_is_registered) {
		MSG main_message = { 0 };

		get_monitor_information();

		set_window_center_position(
			main_window_width,
			main_window_height,
			&main_window_x,
			&main_window_y
		);

		CreateWindowW(
			main_window_class_name,
			main_window_name.c_str(),
			WS_VISIBLE | WS_OVERLAPPEDWINDOW,
			main_window_x,
			main_window_y,
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
	}

	return 0;
}

#endif