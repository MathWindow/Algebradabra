#include "MainWindow.h"
#include "Naming.h"
#include "UpdatedMenu.h"
#include "Widgets.h"
#include "ExitDialog.h"
#include "DialogWindow.h"
#include "Commands.h"
#include "HistoryOfError.h"

unsigned short error_list_window_width = 200;
unsigned short error_list_window_height = 250;
unsigned short error_list_x_position = 30;
unsigned short error_list_y_position = 50;

LRESULT CALLBACK main_procedure(procedure_arguments) {
	switch (message) {
	case WM_CREATE:
		create_menu(h_window); // Creates menu
		create_widgets(h_window); // Creates widgets
		break;
	case WM_COMMAND:
		switch (w_param) {
		case command_exit:
			SendMessage(h_window, WM_CLOSE, NULL, NULL);
			break;
		case command_error_list:
			call_dialog_window(
				error_list_window_class_name,
				L"История ошибки", 
				WS_VISIBLE | WS_OVERLAPPEDWINDOW | WS_CHILD, 
				&error_list_x_position, 
				&error_list_y_position, 
				error_list_window_width, 
				error_list_window_width, 
				h_window
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
	switch (message) {
	case WM_CREATE:

		break;
	case WM_COMMAND:
		switch (w_param) {
		case command_exit:
			SendMessage(h_window, WM_CLOSE, NULL, NULL);
			break;
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