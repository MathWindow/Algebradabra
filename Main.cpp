#include "MainWindow.h"
#include "Menu.h"
#include "Widgets.h"
#include "ExitDialog.h"

LRESULT CALLBACK main_procedure(main_procedure_arguments) {
	switch (message) {
	case WM_CREATE:
		create_menu(h_window); // ������� ���� ������
		create_widgets(h_window); // ������� �������
		break;
	case WM_COMMAND:
		switch (w_param) {
		case command_exit:
			SendMessage(h_window, WM_CLOSE, NULL, NULL);
			break;
		case NULL:
			// ������ ���� �����
			break;
		default:
			
			break;
		}

		break;
	case WM_CLOSE:
		// ����������� WM_CLOSE ������ WM_DESTROY ��� ����������� ������ ������ �� �������� ����� ����������� ����

		if(ask_wish_save(h_window))
			PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(h_window, message, w_param, l_param);
		break;
	}
}