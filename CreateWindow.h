#pragma once
#include <windows.h>
#include "resource.h"
#include "ClassWindow.h"
#include "Monitor.h"
#include "ShortTypes.h"
#include "WindowXY.h"
#include "Translate.h"
using namespace std;

#ifndef create_window_header
#define create_window_header

/*

error_list_window_width = 
	x_out * 3 + width_listbox_default + width_static_error_list + 10;

error_list_window_height = 
	y_out * 2 + height_static_error_list + 20;

*/

LRESULT CALLBACK main_procedure(procedure_arguments);
LRESULT CALLBACK error_list_procedure(procedure_arguments);
LRESULT CALLBACK algebraic_book_create_procedure(procedure_arguments);

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

	WNDCLASS algebraic_book_create_class = main_class_example(
		COLOR_WINDOW,
		h_instance,
		main_icon,
		IDC_ARROW,
		algebraic_book_create_window_class_name,
		algebraic_book_create_procedure
	);

	bool main_class_is_registered = false;

	main_class_is_registered = 
		register_class_name(
			&main_class, 
			translate::string_cannot_create_class_main,
			__FUNCTIONW__
		);

	register_class_name(
		&error_list_class, 
		translate::string_cannot_create_class_error_list,
		__FUNCTIONW__
	);

	register_class_name(
		&algebraic_book_create_class,
		translate::string_cannot_create_class_create_algebraic_book,
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
			main_window_name,
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