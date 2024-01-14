#include "MainWindow.h"
#include "Menu.h"
#include "Widgets.h"
#include "ExitDialog.h"

LRESULT CALLBACK main_procedure(main_procedure_arguments) {
	switch (message) {
	case WM_CREATE:
		create_menu(h_window); // Создает меню панель
		create_widgets(h_window); // Создает виджеты
		break;
	case WM_COMMAND:
		switch (w_param) {
		case command_exit:
			SendMessage(h_window, WM_CLOSE, NULL, NULL);
			break;
		case NULL:
			// Должно быть пусто
			break;
		default:
			
			break;
		}

		break;
	case WM_CLOSE:
		// Используйте WM_CLOSE вместо WM_DESTROY для возможности отмены выхода из программ через диалогового окна

		if(ask_wish_save(h_window))
			PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(h_window, message, w_param, l_param);
		break;
	}
}