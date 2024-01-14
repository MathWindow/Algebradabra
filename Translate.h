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
	using language_param = u_char_;
	using c_language_param = const language_param;

	using string_param = u_short_;
	using c_string_param = const string_param;

	c_string_param string_per_language = 250;
	c_language_param language_per_vocabulary = 2;

	c_language_param language_Russian = put_index_counter<language_param>(0);
	c_language_param language_English = put_index_counter<language_param>(continue_counting);

	// Меню
	// Menu

	c_string_param string_exit = put_index_counter<string_param>(0);
	c_string_param string_whats_new = put_index_counter<string_param>(continue_counting);
	c_string_param string_thats_new = put_index_counter<string_param>(continue_counting);
	c_string_param string_program = put_index_counter<string_param>(continue_counting);
	c_string_param string_algebraic_book = put_index_counter<string_param>(continue_counting);
	c_string_param string_create = put_index_counter<string_param>(continue_counting);
	c_string_param string_open = put_index_counter<string_param>(continue_counting);
	c_string_param string_save = put_index_counter<string_param>(continue_counting);
	c_string_param string_save_as = put_index_counter<string_param>(continue_counting);
	c_string_param string_compress = put_index_counter<string_param>(continue_counting);
	c_string_param string_lock_with_code = put_index_counter<string_param>(continue_counting);
	c_string_param string_page_add = put_index_counter<string_param>(continue_counting);
	c_string_param string_coordinate = put_index_counter<string_param>(continue_counting);
	c_string_param string_circuit = put_index_counter<string_param>(continue_counting);
	c_string_param string_paint = put_index_counter<string_param>(continue_counting);
	c_string_param string_file_txt = put_index_counter<string_param>(continue_counting);
	c_string_param string_edit = put_index_counter<string_param>(continue_counting);
	c_string_param string_search_command = put_index_counter<string_param>(continue_counting);
	c_string_param string_search_string = put_index_counter<string_param>(continue_counting);
	c_string_param string_page_copy = put_index_counter<string_param>(continue_counting);
	c_string_param string_paste = put_index_counter<string_param>(continue_counting);
	c_string_param string_cancel = put_index_counter<string_param>(continue_counting);
	c_string_param string_cancel_last = put_index_counter<string_param>(continue_counting);
	c_string_param string_undo = put_index_counter<string_param>(continue_counting);
	c_string_param string_undo_last = put_index_counter<string_param>(continue_counting);
	c_string_param string_view = put_index_counter<string_param>(continue_counting);
	c_string_param string_menu_and_toolbar = put_index_counter<string_param>(continue_counting);
	c_string_param string_cursor = put_index_counter<string_param>(continue_counting);
	c_string_param string_style = put_index_counter<string_param>(continue_counting);
	c_string_param string_default_view = put_index_counter<string_param>(continue_counting);
	c_string_param string_help_settings = put_index_counter<string_param>(continue_counting);
	c_string_param string_algebraic_book_parameter = put_index_counter<string_param>(continue_counting);
	c_string_param string_page_parameter = put_index_counter<string_param>(continue_counting);
	c_string_param string_program_parameter = put_index_counter<string_param>(continue_counting);
	c_string_param string_language = put_index_counter<string_param>(continue_counting);
	c_string_param string_window = put_index_counter<string_param>(continue_counting);
	c_string_param string_technical_windows_check = put_index_counter<string_param>(continue_counting);

	c_string_param string_em_dash = put_index_counter<string_param>(continue_counting);

	c_string_param string_cannot_create_class_name = put_index_counter<string_param>(continue_counting);
	c_string_param string_cannot_create_class_main = put_index_counter<string_param>(continue_counting);

	c_string_param string_asking_for_save_before_exit = put_index_counter<string_param>(continue_counting);

	c_string_param string_opening_file_window = put_index_counter<string_param>(continue_counting);
	c_string_param string_saving_file_window = put_index_counter<string_param>(continue_counting);
	c_string_param string_choosing_color_window = put_index_counter<string_param>(continue_counting);
	c_string_param string_window_opening_file = string_opening_file_window;
	c_string_param string_window_saving_file = string_saving_file_window;
	c_string_param string_window_choosing_color = string_choosing_color_window;
	c_string_param string_open_file = put_index_counter<string_param>(continue_counting);
	c_string_param string_save_file_as = put_index_counter<string_param>(continue_counting);

	c_string_param string_open_book = put_index_counter<string_param>(continue_counting);
	c_string_param string_save_book_as = put_index_counter<string_param>(continue_counting);

	c_string_param string_program_name = put_index_counter<string_param>(continue_counting);
	c_string_param string_main_window = put_index_counter<string_param>(continue_counting);
	c_string_param string_testing_dialog_window = put_index_counter<string_param>(continue_counting);
	c_string_param string_program_author = put_index_counter<string_param>(continue_counting);
	c_string_param string_program_description = put_index_counter<string_param>(continue_counting);

	c_string_param string_main_window_title = put_index_counter<string_param>(continue_counting);

	bool is_vocabulary_installed = false;

	language_param language_using = language_Russian;

	std::array<std::array<std::wstring, string_per_language>, language_per_vocabulary> vocabulary{};

	language_param language_choosen_for_install = 0;

	void set_string_in_vocabulary(
		string_param string_index_input,
		std::wstring string_input
	) {
		vocabulary.at(language_choosen_for_install).at(string_index_input) =
			string_input;
	}

	std::wstring already_using_string(
		string_param string_index_input
	) {
		return vocabulary.at(language_choosen_for_install).at(string_index_input);
	}

	void set_vocabulary(language_param language_input) {
		language_choosen_for_install = language_input;

		if (language_input == language_Russian) {
			vocabulary.at(language_input).at(string_exit) =
				L"Выход";
			vocabulary.at(language_input).at(string_whats_new) =
				L"Что нового?";
			vocabulary.at(language_input).at(string_thats_new) =
				L"Иконка полностью переделывалась, появились диалоговые окна открытия, сохранения файла и выбора цвета. Появились технические обзоры вышеперечисленных окон.";
			vocabulary.at(language_input).at(string_program) =
				L"Программа";
			vocabulary.at(language_input).at(string_em_dash) =
				symbol_em_dash;
			vocabulary.at(language_input).at(string_create) =
				L"Создать";
			vocabulary.at(language_input).at(string_open) =
				L"Открыть";
			vocabulary.at(language_input).at(string_save) =
				L"Сохранить";
			vocabulary.at(language_input).at(string_save_as) =
				L"Сохранить как...";
			vocabulary.at(language_input).at(string_compress) =
				L"Сжать";
			vocabulary.at(language_input).at(string_lock_with_code) =
				L"Заблокировать кодом";
			vocabulary.at(language_input).at(string_coordinate) =
				L"Координата";
			vocabulary.at(language_input).at(string_circuit) =
				L"Схема";
			vocabulary.at(language_input).at(string_paint) =
				L"Рисунок";
			vocabulary.at(language_input).at(string_file_txt) =
				L"Файл .txt";
			vocabulary.at(language_input).at(string_cancel_last) =
				L"Отменить последнее";
			vocabulary.at(language_input).at(string_undo_last) =
				L"Возвращать последнее";
			vocabulary.at(language_input).at(string_algebraic_book) =
				L"Книга .alg";
			vocabulary.at(language_input).at(string_page_add) =
				L"Добавить страницу";
			vocabulary.at(language_input).at(string_search_command) =
				L"Найти команду";
			vocabulary.at(language_input).at(string_search_string) =
				L"Найти строку";
			vocabulary.at(language_input).at(string_page_copy) =
				L"Копировать страницу";
			vocabulary.at(language_input).at(string_paste) =
				L"Вставить";
			vocabulary.at(language_input).at(string_cancel) =
				L"Отменить";
			vocabulary.at(language_input).at(string_undo) =
				L"Возвращать";
			vocabulary.at(language_input).at(string_menu_and_toolbar) =
				L"Меню и панель инструментов";
			vocabulary.at(language_input).at(string_cursor) =
				L"Курсор";
			vocabulary.at(language_input).at(string_style) =
				L"Стиль";
			vocabulary.at(language_input).at(string_default_view) =
				L"Вид по умолчанию";
			vocabulary.at(language_input).at(string_algebraic_book_parameter) =
				L"Параметр алгебраической книги";
			vocabulary.at(language_input).at(string_page_parameter) =
				L"Параметр страницы";
			vocabulary.at(language_input).at(string_program_parameter) =
				L"Параметр программы";
			vocabulary.at(language_input).at(string_language) =
				L"Язык";
			vocabulary.at(language_input).at(string_edit) =
				L"Правка";
			vocabulary.at(language_input).at(string_view) =
				L"Вид";
			vocabulary.at(language_input).at(string_help_settings) =
				L"Справка/Настройка";
			vocabulary.at(language_input).at(string_cannot_create_class_main) =
				L"Невозможно создать класс главного окна";
			vocabulary.at(language_input).at(string_asking_for_save_before_exit) =
				L"Сохранять документы перед выходом из программы?";
			vocabulary.at(language_input).at(string_window) =
				L"Окно";
			vocabulary.at(language_input).at(string_technical_windows_check) =
				L"Технический обзор окон";
			vocabulary.at(language_input).at(string_choosing_color_window | string_window_choosing_color) =
				L"Окно выбора цвета";
			vocabulary.at(language_input).at(string_saving_file_window | string_window_saving_file) =
				L"Окно сохранения файла";
			vocabulary.at(language_input).at(string_opening_file_window | string_window_opening_file) =
				L"Окно открытия файла";
			vocabulary.at(language_input).at(string_open_book) =
				L"Открыть книгу...";
			vocabulary.at(language_input).at(string_save_book_as) =
				L"Сохранить книгу как...";
			vocabulary.at(language_input).at(string_open_file) =
				L"Открыть файл...";
			vocabulary.at(language_input).at(string_save_file_as) =
				L"Сохранить файл как...";
			vocabulary.at(language_input).at(string_program_name) =
				L"Алгебрадабра " + program_version_family;
			vocabulary.at(language_input).at(string_main_window) =
				L"Главное окно";
			vocabulary.at(language_input).at(string_testing_dialog_window) =
				L"Тестовое диалоговое окно";
			vocabulary.at(language_input).at(string_main_window_title) =
				vocabulary.at(language_input).at(string_program_name)
				+ L" | "
				+ vocabulary.at(language_input).at(string_main_window);
			vocabulary.at(language_input).at(string_program_author) =
				L"Д. М. Чамкин (Transistor, MathWindow)";
			vocabulary.at(language_input).at(string_program_description) =
				L"Автор: "
				+ vocabulary.at(language_input).at(string_program_author)
				+ L";\nВерсия: "
				+ program_version;
		}
		else if (language_input == language_English) {
			vocabulary.at(language_input).at(string_exit) =
				L"Exit";
			vocabulary.at(language_input).at(string_whats_new) =
				L"What's new?";
			vocabulary.at(language_input).at(string_thats_new) =
				L"Icon was remade fully. Save, open file and choose color window were appeared. Technical window's checking of these windows appeared too.";
			vocabulary.at(language_input).at(string_program) =
				L"Program";
			vocabulary.at(language_input).at(string_em_dash) =
				symbol_em_dash;
			vocabulary.at(language_input).at(string_create) =
				L"Create";
			vocabulary.at(language_input).at(string_open) =
				L"Open";
			vocabulary.at(language_input).at(string_save) =
				L"Save";
			vocabulary.at(language_input).at(string_save_as) =
				L"Save as...";
			vocabulary.at(language_input).at(string_compress) =
				L"Compress";
			vocabulary.at(language_input).at(string_lock_with_code) =
				L"Lock file with code";
			vocabulary.at(language_input).at(string_coordinate) =
				L"Coordinate";
			vocabulary.at(language_input).at(string_circuit) =
				L"Circuit";
			vocabulary.at(language_input).at(string_paint) =
				L"Paint";
			vocabulary.at(language_input).at(string_file_txt) =
				L"File .txt";
			vocabulary.at(language_input).at(string_cancel_last) =
				L"Cancel the last";
			vocabulary.at(language_input).at(string_undo_last) =
				L"Undo the last";
			vocabulary.at(language_input).at(string_algebraic_book) =
				L"Book .alg";
			vocabulary.at(language_input).at(string_page_add) =
				L"Add the page";
			vocabulary.at(language_input).at(string_search_command) =
				L"Search command";
			vocabulary.at(language_input).at(string_search_string) =
				L"Search string";
			vocabulary.at(language_input).at(string_page_copy) =
				L"Copy the page";
			vocabulary.at(language_input).at(string_paste) =
				L"Paste";
			vocabulary.at(language_input).at(string_cancel) =
				L"Cancel";
			vocabulary.at(language_input).at(string_undo) =
				L"Undo";
			vocabulary.at(language_input).at(string_menu_and_toolbar) =
				L"Menu and toolbar";
			vocabulary.at(language_input).at(string_cursor) =
				L"Cursor";
			vocabulary.at(language_input).at(string_style) =
				L"Style";
			vocabulary.at(language_input).at(string_default_view) =
				L"Default view";
			vocabulary.at(language_input).at(string_algebraic_book_parameter) =
				L"Parameter of algebraic book";
			vocabulary.at(language_input).at(string_page_parameter) =
				L"Parameter of page";
			vocabulary.at(language_input).at(string_program_parameter) =
				L"Parameter of program";
			vocabulary.at(language_input).at(string_language) =
				L"Language";
			vocabulary.at(language_input).at(string_edit) =
				L"Edit";
			vocabulary.at(language_input).at(string_view) =
				L"View";
			vocabulary.at(language_input).at(string_help_settings) =
				L"Help/Settings";
			vocabulary.at(language_input).at(string_cannot_create_class_main) =
				L"Cannot create main class";
			vocabulary.at(language_input).at(string_asking_for_save_before_exit) =
				L"Would you like to save documents before exit?";
			vocabulary.at(language_input).at(string_window) =
				L"Window";
			vocabulary.at(language_input).at(string_technical_windows_check) =
				L"Technical window's check";
			vocabulary.at(language_input).at(string_choosing_color_window | string_window_choosing_color) =
				L"Choosing color window";
			vocabulary.at(language_input).at(string_saving_file_window | string_window_saving_file) =
				L"Saving file window";
			vocabulary.at(language_input).at(string_opening_file_window | string_window_opening_file) =
				L"Opening file window";
			vocabulary.at(language_input).at(string_open_book) =
				L"Open book...";
			vocabulary.at(language_input).at(string_save_book_as) =
				L"Save book as...";
			vocabulary.at(language_input).at(string_open_file) =
				L"Open file...";
			vocabulary.at(language_input).at(string_save_file_as) =
				L"Save file as...";
			vocabulary.at(language_input).at(string_program_name) =
				L"Algebradabra " + program_version_family;
			vocabulary.at(language_input).at(string_main_window) =
				L"Main window";
			vocabulary.at(language_input).at(string_testing_dialog_window) =
				L"Testing dialog window";
			vocabulary.at(language_input).at(string_main_window_title) =
				vocabulary.at(language_input).at(string_program_name)
				+ L" | "
				+ vocabulary.at(language_input).at(string_main_window);
			vocabulary.at(language_input).at(string_program_author) =
				L"D. M. Chamkin (Transistor, MathWindow)";
			vocabulary.at(language_input).at(string_program_description) =
				L"Author: "
				+ vocabulary.at(language_input).at(string_program_author)
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

		std::wstring string_output =
			vocabulary.at(language_using).at(string_input);

		if (string_output.size() == 0) {
			return symbol_plus_minus;
		}

		return string_output;
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