#include <Windows.h>
#include <WinUser.h>
#include <minwindef.h>
#include <winnt.h>
#include <cstring>
#include "Translate.h"
#include "ClassWindow.h"
#include "resource.h"
#include "Coordinate.h"
#include "ProcedureWindow.h"
#include "Icon.h"
#include "Bitmap.h"
#include "Debugger.h"
#include "CodeWork.h"

int WINAPI wWinMain(
	HINSTANCE h_instance,
	HINSTANCE h_instance_unused,
	LPWSTR arguments,
	int number_command_show
) {
	macro_add_block_function({});

	debug::write_event(
		debug::event_type_message,
		debug::title_index_main_function_was_called,
		debug::extra_title_index_main_function_was_called,
		place,
		nullptr,
		0,
		L""
	);
	
	h_bitmap_coordinate = debug::load_bitmap_w(
		h_instance, 
		MAKEINTRESOURCEW(IDB_BITMAP4),
		place
	);

	h_bitmap_add_paper = debug::load_bitmap_w(
		h_instance, 
		MAKEINTRESOURCEW(IDB_BITMAP5),
		place
	);

	h_icon_main_window = debug::load_icon_w(
		h_instance, 
		MAKEINTRESOURCEW(macro_icon_main_window),
		place
	);

	WNDCLASSW main_class = set_window_class(
		h_instance,
		h_icon_main_window,
		main_window_class_name,
		main_procedure,
		place
	);
	
	WNDCLASSW debugger_class = set_window_class(
		h_instance,
		h_icon_main_window,
		debugger_window_class_name,
		debugger_procedure,
		place
	);

	WNDCLASS create_book_class = set_window_class(
		h_instance,
		h_icon_main_window,
		create_book_window_class_name,
		create_book_procedure,
		place
	);

	ATOM main_class_is_registered = RegisterClassW(&main_class);
	ATOM debugger_class_is_registered = RegisterClassW(&debugger_class);
	RegisterClassW(&create_book_class);

	HWND h_window_main = nullptr;

	MSG message_ = { 0 };

	reopen_window = true;

	while (reopen_window) {
		reopen_window = false;

		if (!main_class_is_registered) {
			if (debugger_class_is_registered) {
				HWND h_window_debugger = debug::create_window_ex_w(
					0,
					debugger_window_class_name,
					translate::string_title_debugger_window.show().c_str(),
					WS_OVERLAPPEDWINDOW,
					debugger_window_position.left_top_point.abscissa,
					debugger_window_position.left_top_point.ordinate,
					debugger_window_position.size_.width,
					debugger_window_position.size_.height,
					NULL,
					NULL,
					NULL,
					NULL,
					place
				);

				if (h_window_debugger != nullptr) {
					ShowWindow(
						h_window_debugger,
						number_command_show
					);
				}
			}
		}
		else {
			h_window_main = debug::create_window_ex_w(
				0,
				main_window_class_name,
				translate::string_title_main_window.show( ).c_str( ),
				WS_OVERLAPPEDWINDOW,
				main_window_position.left_top_point.abscissa,
				main_window_position.left_top_point.ordinate,
				main_window_position.size_.width,
				main_window_position.size_.height,
				NULL,
				NULL,
				NULL,
				NULL,
				place
			);

			if (h_window_main != nullptr) {
				ShowWindow(
					h_window_main,
					number_command_show
				);
			}
		}

		if (main_class_is_registered || debugger_class_is_registered) {
			while (GetMessageW(&message_, NULL, NULL, NULL)) {
				TranslateMessage(&message_);
				DispatchMessageW(&message_);
			}
		}

		if (reopen_window) {
			memset(&message_, 0, sizeof(message_));

			if (h_window_main != nullptr) {
				DestroyWindow(h_window_main);
			}
		}
	}

	return 0;
}