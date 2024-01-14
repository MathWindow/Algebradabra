#include "CreateWindow.h"
#include "CreateBookDialog.h"
#include "Menu.h"
#include "Widgets.h"
#include "ExitDialog.h"
#include "Commands.h"
#include "FileDialog.h"
#include "ColorDialog.h"
#include "Translate.h"
#include "StringWork.h"
#include "ClassWindow.h"
#include <commdlg.h>
#include <WinUser.h>
#include <minwindef.h>

// 1

LRESULT CALLBACK main_procedure(procedure_arguments) {
	switch (message) {
	case WM_CREATE:
		create_main_menu(h_window);
		create_main_widgets(h_window);
		plan_ofn_algebraic_book(h_window);
		plan_ofn_technical_check(h_window);
		plan_choose_color_technical_check(h_window);
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
		else if (w_param == command_translate_Russian) {
			MessageBoxW(h_window,
				L"����� ������� ������� � ����, ��������� ����� ������� � ������ �������.",
				translate::translating_string(translate::string_program_name),
				MB_ICONINFORMATION
			);
		}
		else if (w_param == command_translate_English) {
			MessageBoxW(h_window,
				L"User should close and open again to translate this program.",
				translate::translating_string(translate::string_program_name),
				MB_ICONINFORMATION
			);
		}
		else if (w_param == command_whats_new) {
			MessageBoxW(
				h_window, 
				translate::translating_string(translate::string_thats_new),
				translate::translating_string(translate::string_program_name),
				MB_ICONINFORMATION
			);
		}
		else if (w_param == command_about) {
			MessageBoxW(
				h_window,
				translate::translating_string(translate::string_program_description),
				translate::translating_string(translate::string_program_name),
				MB_ICONINFORMATION
			);
		}
		else if (w_param == command_create_algebraic_book) {
			window_algebraic_book_create(h_window);
		}
		else if (w_param == command_open_algebraic_book) {
			ofn_algebraic_book.open_file_dialog();
		}
		else if (w_param == command_save_algebraic_book) {
			SendMessageW(h_window, WM_COMMAND, command_save_algebraic_book_as, NULL);
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
			MessageBoxW(h_window, string_work::string_union(L"������", L" ������"), translate::translating_string(translate::string_program_name), NULL);
			MessageBoxW(h_window, string_work::string_union(L"���-", L"���!"), translate::translating_string(translate::string_program_name), NULL);
			MessageBoxW(h_window, string_work::string_union_multy(L"���-", L"��-", L"��-", L"��-", L"��!"), translate::translating_string(translate::string_program_name), NULL);
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