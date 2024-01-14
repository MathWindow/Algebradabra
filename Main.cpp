#include "CreateWindow.h"
#include "CreateBookDialog.h"
#include "Menu.h"
#include "Widgets.h"
#include "ExitDialog.h"
#include "DialogWindow.h"
#include "Commands.h"
#include "HistoryOfError.h"
#include <windowsx.h>
#include "FileDialog.h"

LRESULT CALLBACK main_procedure(procedure_arguments) {
	switch (message) {
	case WM_CREATE:
		create_main_menu(h_window);
		create_main_widgets(h_window);
		plan_ofn_algebraic_book(h_window);

		// Тестовая ошибка

		error_event_write(
			string_em_dash,
			string_em_dash,
			__FUNCTIONW__,
			0,
			0,
			false,
			false,
			string_em_dash,
			string_em_dash,
			NULL,
			false
		);

		error_event_write(
			string_em_dash,
			string_em_dash,
			__FUNCTIONW__,
			0,
			0,
			false,
			false,
			string_em_dash,
			string_em_dash,
			NULL,
			false
		);
		break;
	case WM_COMMAND:
		switch (w_param) {
		case NULL:
			// It must be empty...
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
		else if (w_param == command_error_list) {
			if (!error_list_turn_off) {
				call_dialog_window(
					error_list_window_class_name,
					L"Список ошибок",
					WS_VISIBLE | WS_OVERLAPPEDWINDOW,
					&error_list_x_position,
					&error_list_y_position,
					error_list_window_width,
					error_list_window_height,
					NULL
				);
			}
		}
		else if (w_param == command_translate_Russian) {
			MessageBoxW(h_window,
				L"Чтобы перевод вступил в силу, программу нужно закрыть и заново открыть.",
				program_name,
				MB_ICONINFORMATION
			);
		}
		else if (w_param == command_translate_English) {
			MessageBoxW(h_window,
				L"User should close and open again to translate this program.",
				program_name,
				MB_ICONINFORMATION
			);
		}
		else if (w_param == command_what_new) {
			MessageBoxW(
				h_window, 
				L"Переделка иконки.", 
				program_name, 
				MB_ICONINFORMATION
			);
		}
		else if (w_param == command_about) {
			MessageBoxW(
				h_window, 
				L"Автор: " program_author L";\nВерсия: " program_version L".",
				program_name, 
				MB_ICONINFORMATION
			);
		}
		else if (w_param == command_algebraic_book_create) {
			window_algebraic_book_create(h_window);
		}
		else if (w_param == command_open_algebraic_book) {
			ofn_algebraic_book.open_file_dialog();
		}
		break;
	case WM_CLOSE:
		// Use WM_CLOSE instead WM_DESTROY

		if(ask_wish_save(h_window))
			PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(h_window, message, w_param, l_param);
		break;
	}
}

LRESULT CALLBACK error_list_procedure(procedure_arguments) {
	LRESULT position_1 = 1;
	LRESULT position_2 = 0;

	switch (message) {
	case WM_CREATE:
		create_error_list_widgets(h_window);
		break;
	case WM_COMMAND:
		switch (w_param) {
		case NULL:
			// It must be empty...
			break;
		default:
			position_2 = ListBox_GetSel(listbox_error_list, position_1);

			if (position_2 != LB_ERR) {
				SetWindowTextW(
					static_error_list,
					error_list_program.at(position_2).function_name
				);
			}
			else {
				SetWindowTextA(
					static_error_list,
					"East"
				);
			}
			break;
		}

		break;
	case WM_DESTROY:
		
		break;
	default:
		return DefWindowProc(h_window, message, w_param, l_param);
		break;
	}
}

LRESULT CALLBACK algebraic_book_create_procedure(procedure_arguments) {
	switch (message) {
	case WM_CREATE:
		
		break;
	case WM_COMMAND:
		switch (w_param) {
		case NULL:
			// It must be empty...
			break;
		default:
			
			break;
		}

		break;
	case WM_DESTROY:

		break;
	default:
		return DefWindowProc(h_window, message, w_param, l_param);
		break;
	}
}