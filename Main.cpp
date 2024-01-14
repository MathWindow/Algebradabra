#include <Windows.h>
#include <WinUser.h>
#include <minwindef.h>
#include <winnt.h>
#include <string>
#include "Translate.h"
#include "ClassWindow.h"
#include "resource.h"
#include "Monitor.h"
#include "WindowXY.h"
#include "ProcedureWindow.h"

int WINAPI wWinMain(
	HINSTANCE h_instance, 
	HINSTANCE h_instance_unused, 
	LPWSTR arguments, 
	int number_command_show
) {
	WNDCLASSW main_class = main_class_example(
		COLOR_WINDOW,
		h_instance,
		main_icon,
		IDC_ARROW,
		main_window_class_name,
		main_procedure
	);

	bool main_class_is_registered =
		register_class_name(
			&main_class,
			translate::index_cannot_create_class_main
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

		CreateWindowExW(
			0UL,
			main_window_class_name,
			translate::string(translate::index_main_window_title).c_str(),
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