#pragma once
#include <windows.h>
#include <commdlg.h>
#include "Translate.h"
#include "Menu.h"
#include "Widgets.h"
#include "FileDialog.h"
#include "ColorDialog.h"
#include "Commands.h"
#include "ExitDialog.h"
#include "ClassWindow.h"
#include "Monitor.h"
#include "WindowXY.h"
#include "Debugger.h"

#ifndef macro_header_procedure_window
#define macro_header_procedure_window

LRESULT CALLBACK main_procedure(
	HWND h_window, 
	UINT message, 
	WPARAM w_param, 
	LPARAM l_param
) {
	switch (message) {
	case WM_CREATE:
		create_menu_main_window(h_window);
		create_widgets_main_window(h_window);
		plan_ofn_algebraic_book(h_window);
		plan_ofn_technical_check(h_window);
		plan_choose_color_technical_check(h_window);
		break;
	case WM_COMMAND:
		switch (w_param) {
		case NULL:
			// It must be empty...
			// Должно быть пусто...
			break;
		default:
			
			break;
		}

		if (w_param == command_exit) {
			SendMessage(
				h_window,
				WM_CLOSE,
				NULL,
				NULL
			);
		}
		else if (w_param == command_translate_Russian) {
			MessageBoxW(h_window,
				L"Программа не переводит с одного языка на другого, так как она не пригодна для использования.",
				translate::string_program_name.c_style(),
				MB_ICONWARNING
			);
		}
		else if (w_param == command_translate_English) {
			MessageBoxW(h_window,
				L"Program don't translate from one language to another because it is not able to be used.",
				translate::string_program_name.c_style(),
				MB_ICONWARNING
			);
		}
		else if (w_param == command_whats_new) {
			MessageBoxW(
				h_window,
				translate::string_thats_new.c_style(),
				translate::string_program_name.c_style(),
				MB_ICONINFORMATION
			);
		}
		else if (w_param == command_about) {
			MessageBoxW(
				h_window,
				translate::string_program_description.c_style(),
				translate::string_program_name.c_style(),
				MB_ICONINFORMATION
			);
		}
		else if (w_param == command_open_algebraic_book) {
			ofn_algebraic_book.open_file_dialog();
		}
		else if (w_param == command_save_algebraic_book) {
			SendMessageW(
				h_window, 
				WM_COMMAND, 
				command_save_algebraic_book_as, 
				NULL
			);
		}
		else if (w_param == command_save_algebraic_book_as) {
			ofn_algebraic_book.save_file_dialog();
		}
		else if (w_param == command_choose_color) {
			ChooseColorW(&choose_color_1);
		}
		else if (w_param == command_save_file_as) {
			ofn_technical_check.save_file_dialog();
		}
		else if (w_param == command_open_file) {
			ofn_technical_check.open_file_dialog();
		}
		else if (w_param == command_testing_dialog_window) {
			MessageBoxW(
				h_window,
				translate::string_title_dialog_box_open_file.c_style(),
				translate::string_program_name.c_style(),
				NULL
			);
		}
		else if (w_param == command_debugger) {
			set_window_center_position(
				&debugger_window_x,
				&debugger_window_y,
				debugger_window_width,
				debugger_window_height
			);

			CreateWindowExW(
				0,
				debugger_window_class_name,
				translate::string__debugger.c_style(),
				WS_VISIBLE | WS_OVERLAPPEDWINDOW,
				debugger_window_x,
				debugger_window_y,
				debugger_window_width,
				debugger_window_height,
				NULL,
				NULL,
				NULL,
				NULL
			);
		}
		break;
	case WM_CLOSE:
		// Use WM_CLOSE instead WM_DESTROY
		// Используй(те) WM_CLOSE вместо WM_DESTROY

		if (ask_wish_save(h_window))
			PostQuitMessage(0);
		break;

	default:
		return DefWindowProcW(h_window, message, w_param, l_param);
		break;
	}

	return 0L;
}

LRESULT CALLBACK debugger_procedure(
	HWND h_window,
	UINT message,
	WPARAM w_param,
	LPARAM l_param
) {
	int position = 0;
	int index = 0;

	switch (message) {
	case WM_CREATE:
		create_widgets_debugger_window(h_window);
		create_menu_debugger_window(h_window);
		break;
	case WM_COMMAND:
		if (message == command_look_event) {
			position = (int)SendMessageW(
				listbox_debugger,
				LB_GETCURSEL,
				0,
				0
			);

			index = SendMessageW(
				listbox_debugger,
				LB_GETITEMDATA,
				position,
				0
			);

			if (index >= 0) {
				SetWindowTextW(
					static_details_debugger,
					debug::history_of_event.at(index).show_details().c_style()
				);
			}
		}
		break;
	case WM_DESTROY:
		
		break;
	default:
		return DefWindowProcW(h_window, message, w_param, l_param);
		break;
	}
	
	return 0L;
}

#endif