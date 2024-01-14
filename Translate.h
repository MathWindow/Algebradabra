#pragma once
#include <array>
#include <string>
#include "Counter.h"
#include "VersionInfo.h"
#include "Symbols.h"
#include "ShortTypes.h"
#include <vector>
#include <winnt.h>

#ifndef translate_header
#define translate_header

namespace translate {
	using language_param = svt::u_char;
	using c_language_param = const language_param;

	using string_param = svt::u_short;
	using c_string_param = const string_param;

	c_string_param string_per_language = 250;
	c_language_param language_per_vocabulary = 2;

	c_language_param language_Russian = put_index_counter<language_param>(true);
	c_language_param language_English = put_index_counter<language_param>(false);

	c_string_param string_exit = put_index_counter<string_param>(true);
	c_string_param string_whats_new = put_index_counter<string_param>(false);
	c_string_param string_thats_new = put_index_counter<string_param>(false);
	c_string_param string_program = put_index_counter<string_param>(false);
	c_string_param string_algebraic_book = put_index_counter<string_param>(false);
	c_string_param string_create = put_index_counter<string_param>(false);
	c_string_param string_open = put_index_counter<string_param>(false);
	c_string_param string_save = put_index_counter<string_param>(false);
	c_string_param string_save_as = put_index_counter<string_param>(false);
	c_string_param string_compress = put_index_counter<string_param>(false);
	c_string_param string_lock_with_code = put_index_counter<string_param>(false);
	c_string_param string_page_add = put_index_counter<string_param>(false);
	c_string_param string_coordinate = put_index_counter<string_param>(false);
	c_string_param string_circuit = put_index_counter<string_param>(false);
	c_string_param string_paint = put_index_counter<string_param>(false);
	c_string_param string_file_txt = put_index_counter<string_param>(false);
	c_string_param string_edit = put_index_counter<string_param>(false);
	c_string_param string_search_command = put_index_counter<string_param>(false);
	c_string_param string_search_string = put_index_counter<string_param>(false);
	c_string_param string_page_copy = put_index_counter<string_param>(false);
	c_string_param string_paste = put_index_counter<string_param>(false);
	c_string_param string_cancel = put_index_counter<string_param>(false);
	c_string_param string_cancel_last = put_index_counter<string_param>(false);
	c_string_param string_undo = put_index_counter<string_param>(false);
	c_string_param string_undo_last = put_index_counter<string_param>(false);
	c_string_param string_view_ = put_index_counter<string_param>(false);
	c_string_param string_menu_and_toolbar = put_index_counter<string_param>(false);
	c_string_param string_cursor = put_index_counter<string_param>(false);
	c_string_param string_style = put_index_counter<string_param>(false);
	c_string_param string_default_view = put_index_counter<string_param>(false);
	c_string_param string_help_settings = put_index_counter<string_param>(false);
	c_string_param string_algebraic_book_parameter = put_index_counter<string_param>(false);
	c_string_param string_page_parameter = put_index_counter<string_param>(false);
	c_string_param string_program_parameter = put_index_counter<string_param>(false);
	c_string_param string_language = put_index_counter<string_param>(false);
	c_string_param string_em_dash = put_index_counter<string_param>(false);
	c_string_param string_cannot_create_class_name = put_index_counter<string_param>(false);
	c_string_param string_cannot_create_class_main = put_index_counter<string_param>(false);
	c_string_param string_asking_for_save_before_exit = put_index_counter<string_param>(false);
	c_string_param string_window = put_index_counter<string_param>(false);
	c_string_param string_technical_windows_check = put_index_counter<string_param>(false);
	c_string_param string_opening_file_window = put_index_counter<string_param>(false);
	c_string_param string_saving_file_window = put_index_counter<string_param>(false);
	c_string_param string_choosing_color_window = put_index_counter<string_param>(false);
	c_string_param string_window_opening_file = string_opening_file_window;
	c_string_param string_window_saving_file = string_saving_file_window;
	c_string_param string_window_choosing_color = string_choosing_color_window;
	c_string_param string_open_book = put_index_counter<string_param>(false);
	c_string_param string_save_book_as = put_index_counter<string_param>(false);
	c_string_param string_open_file = put_index_counter<string_param>(false);
	c_string_param string_save_file_as = put_index_counter<string_param>(false);
	c_string_param string_program_name = put_index_counter<string_param>(false);
	c_string_param string_main_window = put_index_counter<string_param>(false);
	c_string_param string_errors_list_window = put_index_counter<string_param>(false);
	c_string_param string_create_algebraic_book_window = put_index_counter<string_param>(false);
	c_string_param string_testing_dialog_window = put_index_counter<string_param>(false);
	c_string_param string_program_author = put_index_counter<string_param>(false);
	c_string_param string_program_description = put_index_counter<string_param>(false);

	bool is_vocabulary_installed = false;

	language_param language_using = language_Russian;

	std::array<std::array<std::wstring, string_per_language>, language_per_vocabulary> main_vocabulary{};

	void set_vocabulary(language_param language_input) {
		if (language_input == language_Russian) {
			main_vocabulary.at(language_input).at(string_exit) =
				L"Выход";
			main_vocabulary.at(language_input).at(string_whats_new) =
				L"Что нового?";
			main_vocabulary.at(language_input).at(string_thats_new) =
				L"Иконка полностью переделывалась, появились диалоговые окна открытия, сохранения файла и выбора цвета. Появились технические обзоры вышеперечисленных окон.";
			main_vocabulary.at(language_input).at(string_program) =
				L"Программа";
			main_vocabulary.at(language_input).at(string_em_dash) =
				symbol_em_dash;
			main_vocabulary.at(language_input).at(string_create) =
				L"Создать";
			main_vocabulary.at(language_input).at(string_open) =
				L"Открыть";
			main_vocabulary.at(language_input).at(string_save) =
				L"Сохранить";
			main_vocabulary.at(language_input).at(string_save_as) =
				L"Сохранить как...";
			main_vocabulary.at(language_input).at(string_compress) =
				L"Сжать";
			main_vocabulary.at(language_input).at(string_lock_with_code) =
				L"Заблокировать кодом";
			main_vocabulary.at(language_input).at(string_coordinate) =
				L"Координата";
			main_vocabulary.at(language_input).at(string_circuit) =
				L"Схема";
			main_vocabulary.at(language_input).at(string_paint) =
				L"Рисунок";
			main_vocabulary.at(language_input).at(string_file_txt) =
				L"Файл .txt";
			main_vocabulary.at(language_input).at(string_cancel_last) =
				L"Отменить последнее";
			main_vocabulary.at(language_input).at(string_undo_last) =
				L"Возвращать последнее";
			main_vocabulary.at(language_input).at(string_algebraic_book) =
				L"Книга .alg";
			main_vocabulary.at(language_input).at(string_page_add) =
				L"Добавить страницу";
			main_vocabulary.at(language_input).at(string_search_command) =
				L"Найти команду";
			main_vocabulary.at(language_input).at(string_search_string) =
				L"Найти строку";
			main_vocabulary.at(language_input).at(string_page_copy) =
				L"Копировать страницу";
			main_vocabulary.at(language_input).at(string_paste) =
				L"Вставить";
			main_vocabulary.at(language_input).at(string_cancel) =
				L"Отменить";
			main_vocabulary.at(language_input).at(string_undo) =
				L"Возвращать";
			main_vocabulary.at(language_input).at(string_menu_and_toolbar) =
				L"Меню и панель инструментов";
			main_vocabulary.at(language_input).at(string_cursor) =
				L"Курсор";
			main_vocabulary.at(language_input).at(string_style) =
				L"Стиль";
			main_vocabulary.at(language_input).at(string_default_view) =
				L"Вид по умолчанию";
			main_vocabulary.at(language_input).at(string_algebraic_book_parameter) =
				L"Параметр алгебраической книги";
			main_vocabulary.at(language_input).at(string_page_parameter) =
				L"Параметр страницы";
			main_vocabulary.at(language_input).at(string_program_parameter) =
				L"Параметр программы";
			main_vocabulary.at(language_input).at(string_language) =
				L"Язык";
			main_vocabulary.at(language_input).at(string_edit) =
				L"Правка";
			main_vocabulary.at(language_input).at(string_view_) =
				L"Вид";
			main_vocabulary.at(language_input).at(string_help_settings) =
				L"Справка/Настройка";
			main_vocabulary.at(language_input).at(string_cannot_create_class_main) =
				L"Невозможно создать класс главного окна";
			main_vocabulary.at(language_input).at(string_asking_for_save_before_exit) =
				L"Сохранять документы перед выходом из программы?";
			main_vocabulary.at(language_input).at(string_window) =
				L"Окно";
			main_vocabulary.at(language_input).at(string_technical_windows_check) =
				L"Технический обзор окон";
			main_vocabulary.at(language_input).at(string_choosing_color_window | string_window_choosing_color) =
				L"Окно выбора цвета";
			main_vocabulary.at(language_input).at(string_saving_file_window | string_window_saving_file) =
				L"Окно сохранения файла";
			main_vocabulary.at(language_input).at(string_opening_file_window | string_window_opening_file) =
				L"Окно открытия файла";
			main_vocabulary.at(language_input).at(string_open_book) =
				L"Открыть книгу...";
			main_vocabulary.at(language_input).at(string_save_book_as) =
				L"Сохранить книгу как...";
			main_vocabulary.at(language_input).at(string_open_file) =
				L"Открыть файл...";
			main_vocabulary.at(language_input).at(string_save_file_as) =
				L"Сохранить файл как...";
			main_vocabulary.at(language_input).at(string_program_name) =
				L"Алгебрадабра " + program_version_family;
			main_vocabulary.at(language_input).at(string_main_window) =
				L"Главное окно";
			main_vocabulary.at(language_input).at(string_errors_list_window) =
				L"Список ошибок";
			main_vocabulary.at(language_input).at(string_create_algebraic_book_window) =
				L"Создать книгу";
			main_vocabulary.at(language_input).at(string_testing_dialog_window) =
				L"Тестовое диалоговое окно";
			main_vocabulary.at(language_input).at(string_program_author) =
				L"Д. М. Чамкин (Transistor, MathWindow)";
			main_vocabulary.at(language_input).at(string_program_description) =
				L"Автор: "
				+ main_vocabulary.at(language_input).at(string_program_author)
				+ L";\nВерсия: "
				+ program_version;
		}
		else if (language_input == language_English) {
			main_vocabulary.at(language_input).at(string_exit) =
				L"Exit";
			main_vocabulary.at(language_input).at(string_whats_new) =
				L"What's new?";
			main_vocabulary.at(language_input).at(string_thats_new) =
				L"Icon was remade fully. Save, open file and choose color window were appeared. Technical window's checking of these windows appeared too.";
			main_vocabulary.at(language_input).at(string_program) =
				L"Program";
			main_vocabulary.at(language_input).at(string_em_dash) =
				symbol_em_dash;
			main_vocabulary.at(language_input).at(string_create) =
				L"Create";
			main_vocabulary.at(language_input).at(string_open) =
				L"Open";
			main_vocabulary.at(language_input).at(string_save) =
				L"Save";
			main_vocabulary.at(language_input).at(string_save_as) =
				L"Save as...";
			main_vocabulary.at(language_input).at(string_compress) =
				L"Compress";
			main_vocabulary.at(language_input).at(string_lock_with_code) =
				L"Lock file with code";
			main_vocabulary.at(language_input).at(string_coordinate) =
				L"Coordinate";
			main_vocabulary.at(language_input).at(string_circuit) =
				L"Circuit";
			main_vocabulary.at(language_input).at(string_paint) =
				L"Paint";
			main_vocabulary.at(language_input).at(string_file_txt) =
				L"File .txt";
			main_vocabulary.at(language_input).at(string_cancel_last) =
				L"Cancel the last";
			main_vocabulary.at(language_input).at(string_undo_last) =
				L"Undo the last";
			main_vocabulary.at(language_input).at(string_algebraic_book) =
				L"Book .alg";
			main_vocabulary.at(language_input).at(string_page_add) =
				L"Add the page";
			main_vocabulary.at(language_input).at(string_search_command) =
				L"Search command";
			main_vocabulary.at(language_input).at(string_search_string) =
				L"Search string";
			main_vocabulary.at(language_input).at(string_page_copy) =
				L"Copy the page";
			main_vocabulary.at(language_input).at(string_paste) =
				L"Paste";
			main_vocabulary.at(language_input).at(string_cancel) =
				L"Cancel";
			main_vocabulary.at(language_input).at(string_undo) =
				L"Undo";
			main_vocabulary.at(language_input).at(string_menu_and_toolbar) =
				L"Menu and toolbar";
			main_vocabulary.at(language_input).at(string_cursor) =
				L"Cursor";
			main_vocabulary.at(language_input).at(string_style) =
				L"Style";
			main_vocabulary.at(language_input).at(string_default_view) =
				L"Default view";
			main_vocabulary.at(language_input).at(string_algebraic_book_parameter) =
				L"Parameter of algebraic book";
			main_vocabulary.at(language_input).at(string_page_parameter) =
				L"Parameter of page";
			main_vocabulary.at(language_input).at(string_program_parameter) =
				L"Parameter of program";
			main_vocabulary.at(language_input).at(string_language) =
				L"Language";
			main_vocabulary.at(language_input).at(string_edit) =
				L"Edit";
			main_vocabulary.at(language_input).at(string_view_) =
				L"View";
			main_vocabulary.at(language_input).at(string_help_settings) =
				L"Help/Settings";
			main_vocabulary.at(language_input).at(string_cannot_create_class_main) =
				L"Cannot create main class";
			main_vocabulary.at(language_input).at(string_asking_for_save_before_exit) =
				L"Would you like to save documents before exit?";
			main_vocabulary.at(language_input).at(string_window) =
				L"Window";
			main_vocabulary.at(language_input).at(string_technical_windows_check) =
				L"Technical window's check";
			main_vocabulary.at(language_input).at(string_choosing_color_window | string_window_choosing_color) =
				L"Choosing color window";
			main_vocabulary.at(language_input).at(string_saving_file_window | string_window_saving_file) =
				L"Saving file window";
			main_vocabulary.at(language_input).at(string_opening_file_window | string_window_opening_file) =
				L"Opening file window";
			main_vocabulary.at(language_input).at(string_open_book) =
				L"Open book...";
			main_vocabulary.at(language_input).at(string_save_book_as) =
				L"Save book as...";
			main_vocabulary.at(language_input).at(string_open_file) =
				L"Open file...";
			main_vocabulary.at(language_input).at(string_save_file_as) =
				L"Save file as...";
			main_vocabulary.at(language_input).at(string_program_name) =
				L"Algebradabra " + program_version_family;
			main_vocabulary.at(language_input).at(string_main_window) =
				L"Main window";
			main_vocabulary.at(language_input).at(string_errors_list_window) =
				L"List of error";
			main_vocabulary.at(language_input).at(string_create_algebraic_book_window) =
				L"Create book";
			main_vocabulary.at(language_input).at(string_testing_dialog_window) =
				L"Testing dialog window";
			main_vocabulary.at(language_input).at(string_program_author) =
				L"D. M. Chamkin (Transistor, MathWindow)";
			main_vocabulary.at(language_input).at(string_program_description) =
				main_vocabulary.at(language_input).at(string_program_description) =
				L"Author: "
				+ main_vocabulary.at(language_input).at(string_program_author)
				+ L";\nVersion: "
				+ program_version;
		}
	}

	void set_all_vocabulary() {
		if (!is_vocabulary_installed) {
			set_vocabulary(language_Russian);
			set_vocabulary(language_English);

			is_vocabulary_installed = true;
		}
	}

	std::wstring string(string_param string_input) {
		set_all_vocabulary();

		if (main_vocabulary.at(language_using).at(string_input).size() == 0) {
			return symbol_plus_minus;
		}

		return main_vocabulary.at(language_using).at(string_input);
	}

	void string_fix(
		std::wstring string_input,
		std::vector<WCHAR>* string_fixing_input
	) {
		for (size_t index = 0; index < string_input.size(); index++) {
			(*string_fixing_input).push_back(
				*(string_input.c_str() + index)
			);
		}

		(*string_fixing_input).push_back(L'\0');
	}
}

#endif