#pragma once
#include <windows.h>
#include <commdlg.h>
#include <vector>
#include <string>
#include "Translate.h"
#include "Menu.h"
#include "Widgets.h"
#include "FileDialog.h"
#include "ColorDialog.h"
#include "Commands.h"
#include "ExitDialog.h"
#include "ClassWindow.h"
#include "Coordinate.h"
#include "Debugger.h"
#include "FileWork.h"
#include "Toolbar.h"
#include "CodeWork.h"
#include "StringWork.h"
#include "Algebra.h"

#ifndef macro_header_procedure_window
#define macro_header_procedure_window

bool reopen_window = false;

LRESULT CALLBACK main_procedure(
	HWND h_window,
	UINT message,
	WPARAM w_param,
	LPARAM l_param
) {
	macro_add_block_function({});

	LONG extra_out_height = 0;

	switch (coding::push_variable_switch_in_block_hierarchy(&message, message, &place)) begin_block
	case WM_CREATE:
		create_menu_main_window(h_window, place);
		extra_out_height = create_toolbar(
			h_window,
			place
		);
		create_widgets_main_window(h_window, extra_out_height, place);
		plan_ofn_algebraic_book(h_window, place);
		plan_ofn_technical_check(h_window,place);
		plan_choose_color_technical_check(h_window, place);
		break;
	case WM_PAINT:
		canvas_graphic_function.draw(
			h_window,
			{edit_expression_vector.at(0).get_text(place)},
			place
		);
		break;
	case WM_COMMAND:
		if (w_param == command_exit) {
			SendMessageW(
				h_window,
				WM_CLOSE,
				NULL,
				NULL
			);
		}
		else if (w_param == command_translate_Russian) {
			if (translate::language_using.value != translate::language_Russian) {
				translate::language_using.set_value(translate::language_Russian);

				SendMessageW(
					h_window,
					WM_COMMAND,
					command_reopen_window,
					0
				);
			}
		}
		else if (w_param == command_translate_English) {
			if (translate::language_using.value != translate::language_English) {
				translate::language_using.set_value(translate::language_English);

				SendMessageW(
					h_window,
					WM_COMMAND,
					command_reopen_window,
					0
				);
			}
		}
		else if (w_param == command_what_is_new) {
			MessageBoxW(
				h_window,
				translate::string_that_is_new.show().c_str(),
				translate::string_program_name.show().c_str(),
				MB_ICONINFORMATION
			);
		}
		else if (w_param == command_about) {
			MessageBoxW(
				h_window,
				translate::string_program_description.show().c_str(),
				translate::string_program_name.show().c_str(),
				MB_ICONINFORMATION
			);
		}
		else if (w_param == command_create_book) {
			debug::create_window_ex_w(
				0,
				create_book_window_class_name,
				translate::string_title_create_book_window.show().c_str(),
				WS_VISIBLE | WS_POPUPWINDOW | WS_CAPTION,
				create_book_window_position.left_top_point.abscissa,
				create_book_window_position.left_top_point.ordinate,
				create_book_window_position.size_.width,
				create_book_window_position.size_.height,
				h_window,
				NULL,
				NULL,
				NULL,
				place
			);
		}
		else if (w_param == command_open_book) {
			ofn_algebraic_book.open_file_dialog(place);
		}
		else if (w_param == command_save_book) {
			SendMessageW(
				h_window,
				WM_COMMAND,
				command_save_book_as,
				NULL
			);
		}
		else if (w_param == command_save_book_as) {
			if (ofn_algebraic_book.save_file_dialog(place)) {
				create_test_file(string_path);
			}
		}
		else if (w_param == command_choose_color) {
			ChooseColorW(&choose_color_1);
		}
		else if (w_param == command_save_file_as) {
			ofn_technical_check.save_file_dialog(place);
		}
		else if (w_param == command_open_file) {
			ofn_technical_check.open_file_dialog(place);
		}
		else if (w_param == command_testing_dialog_window) {
			MessageBoxW(
				h_window,
				translate::string_title_dialog_box_open_file.show().c_str(),
				translate::string_program_name.show().c_str(),
				NULL
			);
		}
		else if (w_param == command_debugger) {
			debug::create_window_ex_w(
				0,
				debugger_window_class_name,
				translate::string_title_debugger_window.show().c_str(),
				WS_VISIBLE | WS_POPUPWINDOW | WS_CAPTION,
				debugger_window_position.left_top_point.abscissa,
				debugger_window_position.left_top_point.ordinate,
				debugger_window_position.size_.width,
				debugger_window_position.size_.height,
				h_window,
				NULL,
				NULL,
				NULL,
				place
			);
		}
		else if (w_param == command_reopen_window) {
			reopen_window = true;

			PostQuitMessage(0);
		}
		else if ( 
			LOWORD(w_param) == edit_expression_vector.at(0).command
			|| HIWORD(w_param) == EN_CHANGE
		) {
			algebra::variable* x_pointer
				= algebra::get_pointer_of_variable_from_letter(L'x', place);
			algebra::variable* y_pointer
				= algebra::get_pointer_of_variable_from_letter(L'y', place);

			bool stop_calculating = false;

			algebra::formula formula_of_y = algebra::find_variable_from_equation(
				edit_expression_vector.at(0).get_text(place),
				y_pointer,
				x_pointer,
				&stop_calculating,
				place
			);

			x_pointer->value.number = 11;

			formula_of_y.find_variable(
				&stop_calculating,
				place
			);

			if (stop_calculating) {
				static_result.set_string(
					L"!",
					place
				);
			}
			else {
				static_result.set_string(
					std::to_wstring(y_pointer->value.convert_to_double(
						nullptr,
						place
					)).c_str(),
					place
				);
			}

			RedrawWindow(
				h_window,
				nullptr,
				nullptr,
				RDW_INVALIDATE | RDW_UPDATENOW
			);
		}
		break;
	case WM_CLOSE:
		// Use WM_CLOSE instead WM_DESTROY

		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(h_window, message, w_param, l_param);
		break;

	end_block

	return 0L;
}

LRESULT CALLBACK debugger_procedure(
	HWND h_window,
	UINT message,
	WPARAM w_param,
	LPARAM l_param
) {
	macro_add_block_function({});

	static size_t index_selected_event_list = 0;
	static size_t index_selected_block_hierarchy = 0;

	switch (coding::push_variable_switch_in_block_hierarchy(&message, message, &place)) begin_block
	case WM_CREATE:
		create_widgets_debugger_window(h_window, place);
		break;
	case WM_COMMAND:
		if (LOWORD(w_param) == listbox_event_list.command && HIWORD(w_param) == LBN_SELCHANGE) {
			bool selected_the_same_event = false;

			if (index_selected_event_list == listbox_event_list.get_selected_index(place)) {
				selected_the_same_event = true;
			}

			index_selected_event_list = listbox_event_list.get_selected_index(place);

			group_event_parameter.set_text(
				{
					debug::list_of_event.at(index_selected_event_list).show_time(true),
					debug::list_of_event.at(index_selected_event_list).show_time(false),
					debug::list_of_event.at(index_selected_event_list).show_title().show(),
					debug::list_of_event.at(index_selected_event_list).show_type().show(),
					debug::list_of_event.at(index_selected_event_list).show_extra_title().show(),
					debug::list_of_event.at(index_selected_event_list).show_handle_type().show(),
					debug::list_of_event.at(index_selected_event_list).show_handle_value(),
					debug::list_of_event.at(index_selected_event_list).window_class_name,
					debug::list_of_event.at(index_selected_event_list).show_index_about_other_event()
				},
				place
			);

			listbox_block_hierarchy.clear(place);

			for (
				size_t index_block_hierarchy = 0;
				index_block_hierarchy < debug::list_of_event.at(index_selected_event_list).block_hierarchy.size();
				index_block_hierarchy++
			) {
				listbox_block_hierarchy.add_string_to_listbox(
					debug::list_of_event.at(index_selected_event_list)
					.block_hierarchy.at(index_block_hierarchy).show_block(),
					index_block_hierarchy,
					place
				);
			}

			if (!selected_the_same_event) {
				group_block_parameter.clear(place);
			}
		}
		else if (LOWORD(w_param) == listbox_block_hierarchy.command && HIWORD(w_param) == LBN_SELCHANGE) {
			index_selected_event_list = listbox_event_list.get_selected_index(place);
			index_selected_block_hierarchy = listbox_block_hierarchy.get_selected_index(place);

			group_block_parameter.set_text(
				{
					debug::list_of_event.at(index_selected_event_list)
					.block_hierarchy.at(index_selected_block_hierarchy).show_block_type().c_str(),
					debug::list_of_event.at(index_selected_event_list)
					.block_hierarchy.at(index_selected_block_hierarchy).show_function_name().c_str(),
					debug::list_of_event.at(index_selected_event_list)
					.block_hierarchy.at(index_selected_block_hierarchy).show_variable_address().c_str(),
					debug::list_of_event.at(index_selected_event_list)
					.block_hierarchy.at(index_selected_block_hierarchy).show_variable_value().c_str()
				},
				place
			);
		}
		else if (LOWORD(w_param) == edit_searcher.command && HIWORD(w_param) == EN_CHANGE) {
			std::wstring text = edit_searcher.get_text(place);

			listbox_event_list.clear(place);

			if (text.size() == 0) {
				add_event_list_to_listbox(place);

				SetWindowTextW(
					edit_searcher.label_widget.h_window,
					translate::string__searcher.show().c_str()
				);
			}
			else {
				std::vector<size_t> index_vector
					= show_indexes_from_vector_searching(
						text,
						debug::show_2d_string_list_of_event(),
						{ 
							translate::set_string(L"Without type", L"Без типа").show(),
							translate::set_string(L"Without title", L"Без заголовка").show(),
							translate::set_string(L"Without extra title", L"Без дополненного заголовка").show(),
							translate::set_string(L"Without handle's value", L"Без значения дескриптора").show(),
							translate::set_string(L"Without handle's type", L"Без типа дескриптора").show(),
							translate::set_string(L"Without name of class of window", L"Без имени класса окна").show(),
							translate::set_string(L"Without index about other event", L"Без индекса о другом событии").show(),
							translate::set_string(L"Without local time", L"Без локальной времени").show(),
							translate::set_string(L"Without system tine", L"Без системной времени").show()
						}
					);

				if (index_vector.size() == 0) {
					SetWindowTextW(
						edit_searcher.label_widget.h_window,
						translate::string__no_any_event_was_found.show().c_str()
					);
				}
				else if (index_vector.size() == 1) {
					SetWindowTextW(
						edit_searcher.label_widget.h_window,
						(L"1" + translate::string_n_event_was_found.show()).c_str()
					);
				}
				else {
					SetWindowTextW(
						edit_searcher.label_widget.h_window,
						(std::to_wstring(index_vector.size()) + translate::string_n_events_were_found.show()).c_str()
					);
				}

				for (
					size_t index = 0;
					index < index_vector.size();
					index++
				) {
					listbox_event_list.add_string_to_listbox(
						std::to_wstring(index_vector.at(index)) + L" | " 
						+ debug::list_of_event.at(index_vector.at(index)).show_title().show().c_str(),
						index_vector.at(index),
						place
					);
				}
			}

			group_event_parameter.clear(place);
		}
		break;
	case WM_DESTROY:
		
		break;
	default:
		return DefWindowProcW(h_window, message, w_param, l_param);
		break;
	
	end_block
	
	return 0L;
}

LRESULT CALLBACK create_book_procedure(
	HWND h_window,
	UINT message,
	WPARAM w_parameter,
	LPARAM l_parameter
) {
	macro_add_block_function({});

	switch (coding::push_variable_switch_in_block_hierarchy(&message, message, &place)) begin_block
	case WM_CREATE:
		create_widgets_create_book_window(h_window, place);
		break;
	case WM_COMMAND:
		if (w_parameter == edit_path.command_button) {
			if (ofn_algebraic_book.save_file_dialog(place)) {
				edit_path.set_string(string_path, place);
			}
		}
		else if (w_parameter == button_create.command) {
			DestroyWindow(h_window);
		}
		break;
	case WM_DESTROY:

		break;
	default:
		return DefWindowProcW(
			h_window,
			message,
			w_parameter,
			l_parameter
		);
		break;

	end_block

	return 0;
}

#endif