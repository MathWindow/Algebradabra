#pragma once
#include "AssociationType.h"
#include "Translate.h"
#include "Naming.h"
#include <vector>
#include <array>
#include <windows.h>
using namespace std;

#ifndef history_of_error_header
#define history_of_error_header

const bool error_list_turn_off = true;

cuint_16 string_operation_size = 1000000;

array <wchar_t, string_operation_size> string_operation{};

struct error_event {
	string_param name = 0;
	string_param details = 0;
	LPCWSTR function_name = L"";
	SYSTEMTIME data_time = { 0 };
	long index_value = 0;
	long index_second = 0;
	bool was_in_for = false;
	bool was_catch = false;
	string_param how_may_it_appeared = 0;
	string_param advice = 0;
};

vector <error_event> error_list_program;

#define message_box_arguments HWND h_window = NULL, bool complate = false

bool error_event_write(
	string_param name,
	string_param details,
	LPCWSTR function_name,
	long index_value,
	long index_second,
	bool was_in_for,
	bool was_catch,
	string_param how_may_it_appeared,
	string_param advice,
	message_box_arguments
) {
	uint_32 index_last_event = error_list_program.size();

	error_list_program.push_back({});

	error_list_program.at(index_last_event).name = name;
	error_list_program.at(index_last_event).details = details;
	error_list_program.at(index_last_event).function_name = function_name;
	GetLocalTime(
		&(error_list_program.at(index_last_event).data_time)
	);
	error_list_program.at(index_last_event).index_value = index_value;
	error_list_program.at(index_last_event).index_second = index_second;
	error_list_program.at(index_last_event).was_in_for = was_in_for;
	error_list_program.at(index_last_event).was_catch = was_catch;
	error_list_program.at(index_last_event).how_may_it_appeared = how_may_it_appeared;
	error_list_program.at(index_last_event).advice = advice;

	if (complate) {
		MessageBoxW(h_window, translating_string(details), program_name, MB_ICONERROR);
	}

	return false;
}

bool check_h_window(
	HWND window_output,
	LPCWSTR function_name,
	string_param details,
	long index_value,
	long index_second,
	bool was_in_for,
	bool was_catch,
	message_box_arguments
) {
	if (window_output == NULL) {
		return error_event_write(
			string_null_window_handle,
			details,
			function_name,
			index_value,
			index_second,
			was_in_for,
			was_catch,
			string_em_dash,
			string_em_dash,
			h_window,
			complate
		);
	}

	return true;
}

HWND create_widget_and_check(
	LPCWSTR class_name,
	LPCWSTR title,
	DWORD window_style,
	uint_16 x_position,
	uint_16 y_position,
	uint_16 width,
	uint_16 height,
	HMENU w_param_command,
	LPCWSTR function_name,
	long index_value,
	long index_second,
	bool was_in_for = false,
	bool was_catch = false,
	message_box_arguments
) {
	string_param part_of_details = string_em_dash;

	HWND h_window_checker = CreateWindowExW(
		0,
		class_name,
		title,
		window_style,
		x_position,
		y_position,
		width,
		height,
		h_window,
		w_param_command,
		NULL,
		NULL
	);

	if (class_name == L"edit" || class_name == L"RichEdit") {
		part_of_details = string_cannot_create_edit_widget;
	}
	else if (class_name == L"button") {
		part_of_details = string_cannot_create_button_widget;
	}
	else if (class_name == L"listbox") {
		part_of_details = string_cannot_create_listbox_widget;
	}
	else {
		part_of_details = string_cannot_create_unknown_widget;
	}

	check_h_window(
		h_window_checker, 
		function_name, 
		part_of_details, 
		index_value, 
		index_second, 
		was_in_for, 
		was_catch, 
		h_window, 
		complate
	);

	return h_window_checker;
}

bool check_value(
	double number_output,
	bool is_splitting,
	LPCWSTR function_name,
	long index_value,
	long index_second,
	bool was_in_for,
	bool was_catch,
	message_box_arguments
) {
	error_event reversing_value;

	if (is_splitting) {
		if (number_output == 0) {
			return error_event_write(
				string_splitting_into_zero,
				string_splitting_into_zero,
				function_name,
				index_value,
				index_second,
				was_in_for,
				was_catch,
				string_em_dash,
				string_em_dash,
				h_window,
				complate
			);
		}
	}

	return true;
}

LPCWSTR error_event_output() {
	
}

#endif