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
#include "Window-main.h"
#include "Window-debugger.h"

int WINAPI wWinMain(
	HINSTANCE h_instance,
	HINSTANCE h_instance_unused,
	LPWSTR arguments,
	int number_command_show
) {
	macro_add_block_function({});
#if turn_debugger_on
	debug::write_event(
		debug::title_main_function_was_called,
		place,
		nullptr,
		0,
		L""
	);
#endif
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

	window_class main_class = set_window_class(
		true,
		h_instance,
		h_icon_main_window,
		window_class_main,
		main_procedure,
		place
	);

	window_class debugger_class = set_window_class(
		turn_debugger_on,
		h_instance,
		h_icon_main_window,
		window_class_debugger,
		debugger_procedure,
		place
	);

	window_class create_book_class = set_window_class(
		true,
		h_instance,
		h_icon_main_window,
		window_class_create_book,
		create_book_procedure,
		place
	);

	ATOM main_class_is_registered 
		= main_class.register_(true, place);

	ATOM debugger_class_is_registered 
		= debugger_class.register_(turn_debugger_on, place);

	create_book_class.register_(true, place);

	HWND h_window_main = nullptr;
	HWND h_window_debugger = nullptr;

	do {
		reopen_window = false;

		if (main_class_is_registered == FALSE) {
#if turn_debugger_on
			if (debugger_class_is_registered != FALSE) {

				h_window_debugger = debug::create_window_ex_w_modification(
					0,
					window_class_debugger,
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
				else {
					MessageBoxW(
						nullptr,
						L"h_window_debugger == nullptr",
						translate::string_program_name.show().c_str(),
						NULL
					);
				}
			}
#endif
		}
		else {
			h_window_main = debug::create_window_ex_w_modification(
				0,
				window_class_main,
				translate::string_title_main_window.show().c_str(),
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
			else {
				MessageBoxW(
					nullptr,
					L"h_window_main == nullptr",
					translate::string_program_name.show().c_str(),
					NULL
				);
			}
		}

		MSG message_ = { 0 };

		bool debugger_was_created_successfully
			= (debugger_class_is_registered && h_window_debugger != nullptr);

		if (
			(main_class_is_registered && h_window_main != nullptr)
			|| debugger_was_created_successfully
		) {
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
	} while (reopen_window);

	return 0;
}