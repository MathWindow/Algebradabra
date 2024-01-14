#pragma once
#include <windows.h>
#include <string>
#include <array>
#include "Counter.h"
#include "AssociationType.h"
#include "Simbols.h"
using namespace std;

#ifndef translate_header
#define translate_header

namespace translate {

}

c_string_param string_per_language = 250;
c_language_param language_per_vocabulary = 6;

c_language_param language_Russian = put_index_running(true);
c_language_param language_English = put_index_running(false);
c_language_param language_German = put_index_running(false);
c_language_param language_French = put_index_running(false);
c_language_param language_Spanish = put_index_running(false);
c_language_param language_Italian = put_index_running(false);

c_string_param string_exit = put_index_running(true);
c_string_param string_whats_new = put_index_running(false);
c_string_param string_program = put_index_running(false);
c_string_param string_algebraic_book = put_index_running(false);
c_string_param string_create = put_index_running(false);
c_string_param string_open = put_index_running(false);
c_string_param string_save = put_index_running(false);
c_string_param string_save_as = put_index_running(false);
c_string_param string_compress = put_index_running(false);
c_string_param string_lock_with_code = put_index_running(false);
c_string_param string_page_add = put_index_running(false);
c_string_param string_coordinate = put_index_running(false);
c_string_param string_circuit = put_index_running(false);
c_string_param string_paint = put_index_running(false);
c_string_param string_file_txt = put_index_running(false);
c_string_param string_edit = put_index_running(false);
c_string_param string_search_command = put_index_running(false);
c_string_param string_search_string = put_index_running(false);
c_string_param string_page_copy = put_index_running(false);
c_string_param string_paste = put_index_running(false);
c_string_param string_cancel = put_index_running(false);
c_string_param string_cancel_last = put_index_running(false);
c_string_param string_undo = put_index_running(false);
c_string_param string_undo_last = put_index_running(false);
c_string_param string_view_ = put_index_running(false);
c_string_param string_menu_and_toolbar = put_index_running(false);
c_string_param string_cursor = put_index_running(false);
c_string_param string_style = put_index_running(false);
c_string_param string_default_view = put_index_running(false);
c_string_param string_help_settings = put_index_running(false);
c_string_param string_algebraic_book_parameter = put_index_running(false);
c_string_param string_page_parameter = put_index_running(false);
c_string_param string_program_parameter = put_index_running(false);
c_string_param string_error_list = put_index_running(false);
c_string_param string_language = put_index_running(false);
c_string_param string_em_dash = put_index_running(false);
c_string_param null_string = string_em_dash;
c_string_param string_null_handle = put_index_running(false);
c_string_param string_null_window_handle = put_index_running(false);
c_string_param string_null_menu_handle = put_index_running(false);
c_string_param string_cannot_create_dialog_window = put_index_running(false);
c_string_param string_cannot_create_edit_widget = put_index_running(false);
c_string_param string_cannot_create_listbox_widget = put_index_running(false);
c_string_param string_cannot_create_button_widget = put_index_running(false);
c_string_param string_cannot_create_static_widget = put_index_running(false);
c_string_param string_cannot_create_unknown_widget = put_index_running(false);
c_string_param string_cannot_create_menu_element = put_index_running(false);
c_string_param string_cannot_create_class_name = put_index_running(false);
c_string_param string_cannot_create_class_main = put_index_running(false);
c_string_param string_cannot_create_class_error_list = put_index_running(false);
c_string_param string_cannot_create_class_create_algebraic_book = put_index_running(false);
c_string_param string_splitting_into_zero = put_index_running(false);
c_string_param string_root_of_negative = put_index_running(false);
c_string_param string_asking_for_save_before_exit = put_index_running(false);
c_string_param string_window = put_index_running(false);
c_string_param string_technical_windows_check = put_index_running(false);
c_string_param string_opening_file_window = put_index_running(false);
c_string_param string_saving_file_window = put_index_running(false);
c_string_param string_choosing_color_window = put_index_running(false);
c_string_param string_window_opening_file = string_opening_file_window;
c_string_param string_window_saving_file = string_saving_file_window;
c_string_param string_window_choosing_color = string_choosing_color_window;

bool is_vocabulary_installed = false;

language_param language_using = language_Russian;

array<array<LPCWSTR, string_per_language>, language_per_vocabulary> main_vocabulary{};

void set_Russian_vocabulary() {
	main_vocabulary.at(language_Russian).at(string_exit) =
		L"Выход";
	main_vocabulary.at(language_Russian).at(string_whats_new) =
		L"Что нового?";
	main_vocabulary.at(language_Russian).at(string_program) =
		L"Программа";
	main_vocabulary.at(language_Russian).at(string_null_handle) =
		L"Пустой дескриптор";
	main_vocabulary.at(language_Russian).at(string_null_window_handle) =
		L"Пустой дескриптор окна";
	main_vocabulary.at(language_Russian).at(string_null_menu_handle) =
		L"Пустой дескриптор меню";
	main_vocabulary.at(language_Russian).at(string_cannot_create_dialog_window) =
		L"Невозможно создать диалоговое окно";
	main_vocabulary.at(language_Russian).at(string_cannot_create_edit_widget) =
		L"Невозможно создать виджет в виде текстового поля (edit widget)";
	main_vocabulary.at(language_Russian).at(string_cannot_create_listbox_widget) =
		L"Невозможно создать виджет в виде списка (listbox widget)";
	main_vocabulary.at(language_Russian).at(string_cannot_create_button_widget) =
		L"Невозможно создать виджет в виде кнопки (button widget)";
	main_vocabulary.at(language_Russian).at(string_cannot_create_static_widget) =
		L"Невозможно создать виджет в виде надписи (static widget)";
	main_vocabulary.at(language_Russian).at(string_cannot_create_menu_element) =
		L"Невозможно создать элемент меню";
	main_vocabulary.at(language_Russian).at(string_splitting_into_zero) =
		L"Обнаружено деление на ноль";
	main_vocabulary.at(language_Russian).at(string_root_of_negative) =
		L"Обнаружено Корень отрицательного числа";
	main_vocabulary.at(language_Russian).at(string_em_dash | null_string) =
		simbol_em_dash;
	main_vocabulary.at(language_Russian).at(string_create) =
		L"Создать";
	main_vocabulary.at(language_Russian).at(string_open) =
		L"Открыть";
	main_vocabulary.at(language_Russian).at(string_save) =
		L"Сохранить";
	main_vocabulary.at(language_Russian).at(string_save_as) =
		L"Сохранить как...";
	main_vocabulary.at(language_Russian).at(string_compress) =
		L"Сжать";
	main_vocabulary.at(language_Russian).at(string_lock_with_code) =
		L"Заблокировать кодом";
	main_vocabulary.at(language_Russian).at(string_coordinate) =
		L"Координата";
	main_vocabulary.at(language_Russian).at(string_circuit) =
		L"Схема";
	main_vocabulary.at(language_Russian).at(string_paint) =
		L"Рисунок";
	main_vocabulary.at(language_Russian).at(string_file_txt) =
		L"File *.txt";
	main_vocabulary.at(language_Russian).at(string_cancel_last) =
		L"Отменить последнее";
	main_vocabulary.at(language_Russian).at(string_undo_last) =
		L"Возвращать последнее";
	main_vocabulary.at(language_Russian).at(string_algebraic_book) =
		L"Алгебраическая книга";
	main_vocabulary.at(language_Russian).at(string_page_add) =
		L"Добавить страницу";
	main_vocabulary.at(language_Russian).at(string_search_command) =
		L"Найти команду";
	main_vocabulary.at(language_Russian).at(string_search_string) =
		L"Найти строку";
	main_vocabulary.at(language_Russian).at(string_page_copy) =
		L"Копировать страницу";
	main_vocabulary.at(language_Russian).at(string_paste) =
		L"Вставить";
	main_vocabulary.at(language_Russian).at(string_cancel) =
		L"Отменить";
	main_vocabulary.at(language_Russian).at(string_undo) =
		L"Возвращать";
	main_vocabulary.at(language_Russian).at(string_menu_and_toolbar) =
		L"Меню и панель инструментов";
	main_vocabulary.at(language_Russian).at(string_cursor) =
		L"Курсор";
	main_vocabulary.at(language_Russian).at(string_style) =
		L"Стиль";
	main_vocabulary.at(language_Russian).at(string_default_view) =
		L"Вид по умолчанию";
	main_vocabulary.at(language_Russian).at(string_algebraic_book_parameter) =
		L"Параметр алгебраической книги";
	main_vocabulary.at(language_Russian).at(string_page_parameter) =
		L"Параметр страницы";
	main_vocabulary.at(language_Russian).at(string_program_parameter) =
		L"Параметр программы";
	main_vocabulary.at(language_Russian).at(string_error_list) =
		L"Список ошибок";
	main_vocabulary.at(language_Russian).at(string_language) =
		L"Язык";
	main_vocabulary.at(language_Russian).at(string_edit) =
		L"Правка";
	main_vocabulary.at(language_Russian).at(string_view_) =
		L"Вид";
	main_vocabulary.at(language_Russian).at(string_help_settings) =
		L"Справка/Настройка";
	main_vocabulary.at(language_Russian).at(string_cannot_create_class_main) =
		L"Невозможно создать класс главного окна";
	main_vocabulary.at(language_Russian).at(string_cannot_create_class_error_list) =
		L"Невозможно создать класс окна списка ошибок";
	main_vocabulary.at(language_Russian).at(string_cannot_create_class_create_algebraic_book) =
		L"Невозможно создать класс окна создания алгебраической книги";
	main_vocabulary.at(language_Russian).at(string_asking_for_save_before_exit) =
		L"Сохранять документы перед выходом из программы?";
	main_vocabulary.at(language_Russian).at(string_window) =
		L"Окно";
	main_vocabulary.at(language_Russian).at(string_technical_windows_check) =
		L"Технический обзор окон";
	main_vocabulary.at(language_Russian).at(string_choosing_color_window | string_window_choosing_color) =
		L"Окно выбора цвета";
	main_vocabulary.at(language_Russian).at(string_saving_file_window | string_window_saving_file) =
		L"Окно сохранения файла";
	main_vocabulary.at(language_Russian).at(string_opening_file_window | string_window_opening_file) =
		L"Окно открытия файла";
}

void set_English_vocabulary() {
	main_vocabulary.at(language_English).at(string_exit) =
		L"Exit";
	main_vocabulary.at(language_English).at(string_whats_new) =
		L"What's new?";
	main_vocabulary.at(language_English).at(string_program) =
		L"Program";
	main_vocabulary.at(language_English).at(string_null_handle) =
		L"Null handle";
	main_vocabulary.at(language_English).at(string_null_window_handle) =
		L"Null window handle";
	main_vocabulary.at(language_English).at(string_null_menu_handle) =
		L"Null menu handle";
	main_vocabulary.at(language_English).at(string_cannot_create_dialog_window) =
		L"Cannot create dialog window";
	main_vocabulary.at(language_English).at(string_cannot_create_edit_widget) =
		L"Cannot create edit widget";
	main_vocabulary.at(language_English).at(string_cannot_create_listbox_widget) =
		L"Cannot create listbox widget";
	main_vocabulary.at(language_English).at(string_cannot_create_button_widget) =
		L"Cannot create button widget";
	main_vocabulary.at(language_English).at(string_cannot_create_static_widget) =
		L"Cannot create static widget";
	main_vocabulary.at(language_English).at(string_cannot_create_menu_element) =
		L"Cannot create menu element";
	main_vocabulary.at(language_English).at(string_splitting_into_zero) =
		L"Splitting into zero was detected";
	main_vocabulary.at(language_English).at(string_root_of_negative) =
		L"Root of negative number was detected";
	main_vocabulary.at(language_English).at(string_em_dash | null_string) =
		simbol_em_dash;
	main_vocabulary.at(language_English).at(string_create) =
		L"Create";
	main_vocabulary.at(language_English).at(string_open) =
		L"Open";
	main_vocabulary.at(language_English).at(string_save) =
		L"Save";
	main_vocabulary.at(language_English).at(string_save_as) =
		L"Save as...";
	main_vocabulary.at(language_English).at(string_compress) =
		L"Compress";
	main_vocabulary.at(language_English).at(string_lock_with_code) =
		L"Lock file with code";
	main_vocabulary.at(language_English).at(string_coordinate) =
		L"Coordinate";
	main_vocabulary.at(language_English).at(string_circuit) =
		L"Circuit";
	main_vocabulary.at(language_English).at(string_paint) =
		L"Paint";
	main_vocabulary.at(language_English).at(string_file_txt) =
		L"File *.txt";
	main_vocabulary.at(language_English).at(string_cancel_last) =
		L"Cancel the last";
	main_vocabulary.at(language_English).at(string_undo_last) =
		L"Undo the last";
	main_vocabulary.at(language_English).at(string_algebraic_book) =
		L"Algebraic book";
	main_vocabulary.at(language_English).at(string_page_add) =
		L"Add the page";
	main_vocabulary.at(language_English).at(string_search_command) =
		L"Search command";
	main_vocabulary.at(language_English).at(string_search_string) =
		L"Search string";
	main_vocabulary.at(language_English).at(string_page_copy) =
		L"Copy the page";
	main_vocabulary.at(language_English).at(string_paste) =
		L"Paste";
	main_vocabulary.at(language_English).at(string_cancel) =
		L"Cancel";
	main_vocabulary.at(language_English).at(string_undo) =
		L"Undo";
	main_vocabulary.at(language_English).at(string_menu_and_toolbar) =
		L"Menu and toolbar";
	main_vocabulary.at(language_English).at(string_cursor) =
		L"Cursor";
	main_vocabulary.at(language_English).at(string_style) =
		L"Style";
	main_vocabulary.at(language_English).at(string_default_view) =
		L"Default view";
	main_vocabulary.at(language_English).at(string_algebraic_book_parameter) =
		L"Parameter of algebraic book";
	main_vocabulary.at(language_English).at(string_page_parameter) =
		L"Parameter of page";
	main_vocabulary.at(language_English).at(string_program_parameter) =
		L"Parameter of program";
	main_vocabulary.at(language_English).at(string_error_list) =
		L"Error list";
	main_vocabulary.at(language_English).at(string_language) =
		L"Language";
	main_vocabulary.at(language_English).at(string_edit) =
		L"Edit";
	main_vocabulary.at(language_English).at(string_view_) =
		L"View";
	main_vocabulary.at(language_English).at(string_help_settings) =
		L"Help/Settings";
	main_vocabulary.at(language_English).at(string_cannot_create_class_main) =
		L"Cannot create main class";
	main_vocabulary.at(language_English).at(string_cannot_create_class_error_list) =
		L"Cannot create class of error's list";
	main_vocabulary.at(language_English).at(string_cannot_create_class_create_algebraic_book) =
		L"Cannot create class of creating algebraic book";
	main_vocabulary.at(language_English).at(string_asking_for_save_before_exit) =
		L"Would you like to save documents before exit?";
	main_vocabulary.at(language_English).at(string_window) =
		L"Window";
	main_vocabulary.at(language_English).at(string_technical_windows_check) =
		L"Technical window's check";
	main_vocabulary.at(language_English).at(string_choosing_color_window | string_window_choosing_color) =
		L"Choosing color window";
	main_vocabulary.at(language_English).at(string_saving_file_window | string_window_saving_file) =
		L"Saving file window";
	main_vocabulary.at(language_English).at(string_opening_file_window | string_window_opening_file) =
		L"Opening file window";
}

void set_all_vocabulary() {
	if (!is_vocabulary_installed) {
		set_Russian_vocabulary();
		set_English_vocabulary();

		is_vocabulary_installed = true;
	}
}

LPCWSTR translating_string(string_param string_index_input) {
	set_all_vocabulary();

	LPCWSTR string_checking = 
		main_vocabulary.at(language_using).at(string_index_input);

	if (string_checking == nullptr) {
		return simbol_em_dash;
	}

	return string_checking;
}

#endif