#include <Windows.h>
#include <WinUser.h>
#include <minwindef.h>
#include <winnt.h>
#include "Translate.h"
#include "ClassWindow.h"
#include "resource.h"
#include "Monitor.h"
#include "WindowXY.h"
#include "ProcedureWindow.h"
#include "Counter.h"

int WINAPI wWinMain(
	HINSTANCE h_instance, 
	HINSTANCE h_instance_unused, 
	LPWSTR arguments, 
	int number_command_show
) {
	WNDCLASSW main_class = main_class_example(
		COLOR_WINDOW,
		h_instance,
		macro_icon_main_window,
		IDC_ARROW,
		main_window_class_name,
		main_procedure
	);

	WNDCLASSW debugger_class = main_class_example(
		COLOR_WINDOW,
		h_instance,
		macro_icon_main_window,
		IDC_ARROW,
		debugger_window_class_name,
		debugger_procedure
	);

	bool main_class_is_registered =
		register_class_name(
			&main_class,
			translate::string_cannot_create_class_main.c_style()
		);

	register_class_name(
		&debugger_class,
		translate::string_cannot_create_class_name.c_style()
	);

	if (main_class_is_registered) {
		if (paranormal) {
			MessageBoxW(
				NULL,
				L"���������� �������������� �������!",
				translate::string_program_name.c_style(),
				MB_ICONWARNING
			);
		}

		MSG main_message = { 0 };

		set_window_center_position(
			&main_window_x,
			&main_window_y,
			main_window_width,
			main_window_height
		);

		HWND h_window_main = CreateWindowExW(
			0,
			main_window_class_name,
			translate::string_title_main_window.c_style(),
			WS_OVERLAPPEDWINDOW,
			main_window_x,
			main_window_y,
			main_window_width,
			main_window_height,
			NULL,
			NULL,
			NULL,
			NULL
		);

		if (h_window_main != nullptr) {
			ShowWindow(
				h_window_main,
				number_command_show
			);

			while (GetMessageW(&main_message, NULL, NULL, NULL)) {
				TranslateMessage(&main_message);
				DispatchMessageW(&main_message);
			}
		}
		else {
			MessageBoxW(
				NULL,
				translate::string_cannot_create_main_window.c_style(),
				translate::string_program_name.c_style(),
				MB_ICONERROR
			);
		}
	}

	return 0;
}