#pragma once
#include <vector>
#include <array>
#include <stdarg.h>
#include <windows.h>
using namespace std;

#ifndef history_of_error
#define history_of_error

#define string_operation_size 1000000

array <wchar_t, string_operation_size> string_operation{};

LPCWSTR string_error_event_arguments = L"ssssTiibbss";

struct error_event {
	LPCWSTR name = L"";
	LPCWSTR type = L"";
	LPCWSTR details = L"";
	LPCWSTR function_name = L"";
	SYSTEMTIME data_time = { 0 };
	int index_first = 0;
	int index_second = 0;
	bool was_in_for = false;
	bool was_catch = false;
	LPCWSTR how_may_it_appeared = L"";
	LPCWSTR advice = L"";
};

vector <error_event> error_list_program;

unsigned short defend_type(va_list variable_list) {
	
}

#define message_box_arguments HWND h_window = NULL, LPCWSTR message_box_title = L"", bool explain = false

bool error_event_write(
	LPCWSTR name,
	LPCWSTR type,
	LPCWSTR details,
	LPCWSTR function_name,
	int index_first,
	int index_second,
	bool was_in_for,
	bool was_catch,
	LPCWSTR how_may_it_appeared,
	LPCWSTR advice,
	message_box_arguments
) {
	unsigned int index_last_event = error_list_program.size();

	error_list_program.push_back({});

	error_list_program.at(index_last_event).name = name;
	error_list_program.at(index_last_event).type = type;
	error_list_program.at(index_last_event).details = details;
	error_list_program.at(index_last_event).function_name = function_name;
	GetLocalTime(
		&(error_list_program.at(index_last_event).data_time)
	);
	error_list_program.at(index_last_event).index_first = index_first;
	error_list_program.at(index_last_event).index_second = index_second;
	error_list_program.at(index_last_event).was_in_for = was_in_for;
	error_list_program.at(index_last_event).was_catch = was_catch;
	error_list_program.at(index_last_event).how_may_it_appeared = how_may_it_appeared;
	error_list_program.at(index_last_event).advice = advice;

	if (explain) {
		MessageBoxW(h_window, details, message_box_title, MB_ICONERROR);
	}

	return false;
}

// Проверка дескриптора окна

bool check_h_window(
	HWND window_output,
	LPCWSTR type,
	LPCWSTR function_name,
	LPCWSTR details,
	int index_first,
	int index_second,
	bool was_in_for,
	bool was_catch,
	message_box_arguments
) {
	if (window_output == NULL) {
		return error_event_write(
			L"Пустой дескриптор окна",
			type,
			details,
			function_name,
			index_first,
			index_second,
			was_in_for,
			was_catch,

			L"Неправильно введены аргументы CreateWindowEx(); \
			если введенный дескриптор окна — и есть дескриптор родительского окна, \
			то аргумент типа HWND (HWND__*), той функции, структура которой записана ошибка, \
			имеет нулевое значение, что так и не должно быть",

			L"Эта программная ошибка, записанная через error_event_write, может быть ложна; \
			смотрите внимательно как введены аргументы функции CreateWindowExW(), \
			а также той функции, структура которой записана ошибка",

			h_window,
			message_box_title,
			explain
		);
	}

	return true;
}

bool check_value(
	double number_output,
	bool is_splitting,
	LPCWSTR function_name,
	int index_first,
	int index_second,
	bool was_in_for,
	bool was_catch,
	message_box_arguments
) {
	error_event reversing_value;

	if (is_splitting) {
		if (number_output == 0) {
			return error_event_write(
				L"Обнаружена деление на ноль",
				L"Низкая серьезность",
				L"Обнаружена деление на ноль, которое запрещено по задумки разработчика(ов)",
				function_name,
				index_first,
				index_second,
				was_in_for,
				was_catch,

				L"Проверенную переменную так и не удалось приобрести нулевое значение",

				L"",

				h_window,
				message_box_title,
				explain
			);
		}
	}

	return true;
}

//LPCWSTR error_list_program_output() {
//	for (int index = 0; index < error_list_program.size(); index++) {
//		
//	}
//}

#endif