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
	using language_index = u_char_;
	using c_language_index = const language_index;

	using string_index = size_t;
	using c_string_index = const string_index;

	c_language_index language_per_vocabulary = 2;

	c_language_index language_Russian = put_index_counter<language_index>(0);
	c_language_index language_English = put_index_counter<language_index>(continue_counting);

	// Главное окно
	// Main window

	string_index index_main_window_title = 0;
	string_index index_exit = 0;
	string_index index_whats_new = 0;
	string_index index_thats_new = 0;
	string_index index_program = 0;
	string_index index_algebraic_book = 0;
	string_index index_create = 0;
	string_index index_open = 0;
	string_index index_save = 0;
	string_index index_save_as = 0;
	string_index index_compress = 0;
	string_index index_lock_with_code = 0;
	string_index index_page_add = 0;
	string_index index_coordinate = 0;
	string_index index_circuit = 0;
	string_index index_paint = 0;
	string_index index_file_txt = 0;
	string_index index_edit = 0;
	string_index index_search_command = 0;
	string_index index_search_string = 0;
	string_index index_page_copy = 0;
	string_index index_paste = 0;
	string_index index_cancel = 0;
	string_index index_cancel_last = 0;
	string_index index_undo = 0;
	string_index index_undo_last = 0;
	string_index index_view = 0;
	string_index index_menu_and_toolbar = 0;
	string_index index_cursor = 0;
	string_index index_style = 0;
	string_index index_default_view = 0;
	string_index index_help_settings = 0;
	string_index index_algebraic_book_parameter = 0;
	string_index index_page_parameter = 0;
	string_index index_program_parameter = 0;
	string_index index_language = 0;
	string_index index_window = 0;
	string_index index_technical_windows_check = 0;
	string_index index_main_window = 0;

	string_index index_asking_for_save_before_exit = 0;

	string_index index_opening_file_window = 0;
	string_index index_saving_file_window = 0;
	string_index index_choosing_color_window = 0;
	string_index& index_window_opening_file = index_opening_file_window;
	string_index& index_window_saving_file = index_saving_file_window;
	string_index& index_window_choosing_color = index_choosing_color_window;
	string_index index_open_file = 0;
	string_index index_save_file_as = 0;

	string_index index_open_book = 0;
	string_index index_save_book_as = 0;

	// Window about program
	// Окно о программе
	
	string_index index_testing_dialog_window = 0;
	string_index index_program_author = 0;
	string_index index_program_description = 0;

	// Universal using
	// Универсальное применение

	string_index index_program_name = 0;
	string_index index_cannot_create_class_name = 0;
	string_index index_cannot_create_class_main = 0;

	language_index language_using = language_Russian;

	std::array<std::vector<std::wstring>, language_per_vocabulary> vocabulary{};

	language_index language_choosen_for_install = 0;

	void set_string_in_vocabulary(
		string_index* string_index_input,
		std::wstring string_input
	) {
		size_t index_this = vocabulary.at(language_choosen_for_install).size();

		vocabulary.at(language_choosen_for_install).push_back(string_input);

		*string_index_input = index_this;
	}

	std::wstring already_using_string(string_index index_index_input) {
		return vocabulary.at(language_choosen_for_install).at(index_index_input);
	}

	void set_vocabulary(language_index language_input) {
		language_choosen_for_install = language_input;

		if (language_input == language_Russian) {
			set_string_in_vocabulary(&index_exit, L"Выход");
			set_string_in_vocabulary(&index_whats_new, L"Что нового?");
			set_string_in_vocabulary(&index_thats_new, 
				L"Иконка полностью переделывалась, появились диалоговые окна открытия, сохранения файла и выбора цвета. Появились технические обзоры вышеперечисленных окон."
			);
			set_string_in_vocabulary(&index_program, L"Программа");
			set_string_in_vocabulary(&index_create, L"Создать");
			set_string_in_vocabulary(&index_open, L"Открыть");
			set_string_in_vocabulary(&index_save, L"Сохранить");
			set_string_in_vocabulary(&index_save_as, L"Сохранить как...");
			set_string_in_vocabulary(&index_compress, L"Сжать");
			set_string_in_vocabulary(&index_lock_with_code, L"Заблокировать кодом");
			set_string_in_vocabulary(&index_coordinate, L"Координата");
			set_string_in_vocabulary(&index_circuit, L"Схема");
			set_string_in_vocabulary(&index_paint, L"Рисунок");
			set_string_in_vocabulary(&index_file_txt, L"Файл .txt");
			set_string_in_vocabulary(&index_cancel_last, L"Отменить последнее");
			set_string_in_vocabulary(&index_undo_last, L"Возвращать последнее");
			set_string_in_vocabulary(&index_algebraic_book, L"Книга .alg");
			set_string_in_vocabulary(&index_page_add, L"Добавить страницу");
			set_string_in_vocabulary(&index_search_command, L"Найти команду");
			set_string_in_vocabulary(&index_search_string, L"Найти строку");
			set_string_in_vocabulary(&index_page_copy, L"Копировать страницу");
			set_string_in_vocabulary(&index_paste, L"Вставить");
			set_string_in_vocabulary(&index_cancel, L"Отменить");
			set_string_in_vocabulary(&index_undo, L"Возвращать");
			set_string_in_vocabulary(&index_menu_and_toolbar, L"Меню и панель инструментов");
			set_string_in_vocabulary(&index_cursor, L"Курсор");
			set_string_in_vocabulary(&index_style, L"Стиль");
			set_string_in_vocabulary(&index_default_view, L"Вид по умолчанию");
			set_string_in_vocabulary(&index_algebraic_book_parameter, L"Параметр алгебраической книги");
			set_string_in_vocabulary(&index_page_parameter, L"Параметр страницы");
			set_string_in_vocabulary(&index_program_parameter, L"Параметр программы");
			set_string_in_vocabulary(&index_language, L"Язык");
			set_string_in_vocabulary(&index_edit, L"Правка");
			set_string_in_vocabulary(&index_view, L"Вид");
			set_string_in_vocabulary(&index_help_settings, L"Справка/Настройка");
			set_string_in_vocabulary(&index_cannot_create_class_main, L"Невозможно создать класс главного окна");
			set_string_in_vocabulary(&index_asking_for_save_before_exit, L"Сохранять документы перед выходом из программы?");
			set_string_in_vocabulary(&index_window, L"Окно");
			set_string_in_vocabulary(&index_technical_windows_check, L"Технический обзор окон");
			set_string_in_vocabulary(&index_choosing_color_window, L"Окно выбора цвета");
			set_string_in_vocabulary(&index_saving_file_window, L"Окно сохранения файла");
			set_string_in_vocabulary(&index_opening_file_window, L"Окно открытия файла");
			set_string_in_vocabulary(&index_open_book, L"Открыть книгу...");
			set_string_in_vocabulary(&index_save_book_as, L"Сохранить книгу как...");
			set_string_in_vocabulary(&index_open_file, L"Открыть файл...");
			set_string_in_vocabulary(&index_save_file_as, L"Сохранить файл как...");
			set_string_in_vocabulary(&index_program_name, L"Алгебрадабра " + program_version_family);
			set_string_in_vocabulary(&index_main_window, L"Главное окно");
			set_string_in_vocabulary(&index_testing_dialog_window, L"Тестовое диалоговое окно");
			set_string_in_vocabulary(&index_main_window_title,
				already_using_string(index_program_name)
				+ L" | "
				+ already_using_string(index_main_window)
			);
			set_string_in_vocabulary(&index_program_author, L"Д. М. Чамкин (Transistor, MathWindow)");
			set_string_in_vocabulary(&index_program_description, 
				L"Автор: "
				+ already_using_string(index_program_author)
				+ L";\nВерсия: "
				+ program_version
			);
		}
		else if (language_input == language_English) {
			set_string_in_vocabulary(&index_exit, L"Exit");
			set_string_in_vocabulary(&index_whats_new, L"What's new?");
			set_string_in_vocabulary(&index_thats_new,
				L"Icon was remade fully. Save, open file and choose color window were appeared. Technical window's checking of these windows appeared too."
			);
			set_string_in_vocabulary(&index_program, L"Program");
			set_string_in_vocabulary(&index_create, L"Create");
			set_string_in_vocabulary(&index_open, L"Open");
			set_string_in_vocabulary(&index_save, L"Save");
			set_string_in_vocabulary(&index_save_as, L"Save as...");
			set_string_in_vocabulary(&index_compress, L"Compress");
			set_string_in_vocabulary(&index_lock_with_code, L"Lock file with code");
			set_string_in_vocabulary(&index_coordinate, L"Coordinate");
			set_string_in_vocabulary(&index_circuit, L"Circuit");
			set_string_in_vocabulary(&index_paint, L"Paint");
			set_string_in_vocabulary(&index_file_txt, L"File .txt");
			set_string_in_vocabulary(&index_cancel_last, L"Cancel the last");
			set_string_in_vocabulary(&index_undo_last, L"Undo the last");
			set_string_in_vocabulary(&index_algebraic_book, L"Book .alg");
			set_string_in_vocabulary(&index_page_add, L"Add the page");
			set_string_in_vocabulary(&index_search_command, L"Search command");
			set_string_in_vocabulary(&index_search_string, L"Search string");
			set_string_in_vocabulary(&index_page_copy, L"Copy the page");
			set_string_in_vocabulary(&index_paste, L"Paste");
			set_string_in_vocabulary(&index_cancel, L"Cancel");
			set_string_in_vocabulary(&index_undo, L"Undo");
			set_string_in_vocabulary(&index_menu_and_toolbar, L"Menu and toolbar");
			set_string_in_vocabulary(&index_cursor, L"Cursor");
			set_string_in_vocabulary(&index_style, L"Style");
			set_string_in_vocabulary(&index_default_view, L"Default view");
			set_string_in_vocabulary(&index_algebraic_book_parameter, L"Parameter of algebraic book");
			set_string_in_vocabulary(&index_page_parameter, L"Parameter of page");
			set_string_in_vocabulary(&index_program_parameter, L"Parameter of program");
			set_string_in_vocabulary(&index_language, L"Language");
			set_string_in_vocabulary(&index_edit, L"Edit");
			set_string_in_vocabulary(&index_view, L"View");
			set_string_in_vocabulary(&index_help_settings, L"Help/Settings");
			set_string_in_vocabulary(&index_cannot_create_class_main, L"Cannot create main class");
			set_string_in_vocabulary(&index_asking_for_save_before_exit, L"Would you like to save documents before exit?");
			set_string_in_vocabulary(&index_window, L"Window");
			set_string_in_vocabulary(&index_technical_windows_check, L"Technical window's check");
			set_string_in_vocabulary(&(index_choosing_color_window), L"Choosing color window");
			set_string_in_vocabulary(&index_saving_file_window, L"Saving file window");
			set_string_in_vocabulary(&(index_opening_file_window), L"Opening file window");
			set_string_in_vocabulary(&index_open_book, L"Open book...");
			set_string_in_vocabulary(&index_save_book_as, L"Save book as...");
			set_string_in_vocabulary(&index_open_file, L"Open file...");
			set_string_in_vocabulary(&index_save_file_as, L"Save file as...");
			set_string_in_vocabulary(&index_program_name, L"Algebradabra " + program_version_family);
			set_string_in_vocabulary(&index_main_window, L"Main window");
			set_string_in_vocabulary(&index_testing_dialog_window, L"Testing dialog window");
			set_string_in_vocabulary(&index_main_window_title,
				already_using_string(index_program_name)
				+ L" | "
				+ already_using_string(index_main_window)
			);
			set_string_in_vocabulary(&index_program_author, L"D. M. Chamkin (Transistor, MathWindow)");
			set_string_in_vocabulary(&index_program_description, 
				L"Author: "
				+ already_using_string(index_program_author)
				+ L";\nVersion: "
				+ program_version
			);
		}
	}

	void set_all_vocabulary() {
		static bool is_vocabulary_installed = false;

		if (!is_vocabulary_installed) {
			set_vocabulary(language_Russian);
			set_vocabulary(language_English);

			is_vocabulary_installed = true;
		}
	}

	std::wstring string(string_index index_input) {
		set_all_vocabulary();

		std::wstring string_output =
			vocabulary.at(language_using).at(index_input);

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