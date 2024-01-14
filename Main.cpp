#include "CreateWindow.h"
#include "UpdatedMenu.h"
#include "Widgets.h"
#include "ExitDialog.h"
#include "DialogWindow.h"
#include "Commands.h"
#include "HistoryOfError.h"
#include <windowsx.h>

LRESULT CALLBACK main_procedure(procedure_arguments) {
	switch (message) {
	case WM_CREATE:
		create_main_menu(h_window);
		create_main_widgets(h_window);

		// Тестовая ошибка

		error_event_write(
			L"Ошибка 1",
			L"...",
			L"Эта ошибка ложна",
			(LPCWSTR)__func__,
			0,
			0,
			false,
			false,
			L"Да никак не могло появиться!",
			L"Устранять эту лжеошибку не надо, только если вам не раздражает",
			NULL,
			NULL,
			false
		);

		error_event_write(
			L"Ошибка 2021",
			L"...",
			L"Эта ошибка ложна",
			L"2",
			0,
			0,
			false,
			false,
			L"Ты кто такой?! Я тебе не звал, идите к ЧЕРТУ!",
			L"...",
			NULL,
			NULL,
			false
		);
		break;
	case WM_COMMAND:
		switch (w_param) {
		case command_exit:
			SendMessage(
				h_window, 
				WM_CLOSE, 
				NULL, 
				NULL
			);
			break;
		case command_error_list:
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
			break;
		case NULL:
			// It must be empty...
			break;
		default:
			
			break;
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
	LRESULT position_1 = 0;

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
			ListBox_GetSel(listbox_error_list, position_1);

			if (position_1 > LB_ERR) {
				SetWindowTextA(
					static_error_list,
					(LPCSTR)error_list_program.at(position_1).function_name
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