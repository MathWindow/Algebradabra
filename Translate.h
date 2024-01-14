#pragma once
#include <array>
#include <string>
#include "Counter.h"
#include "VersionInfo.h"
#include <vector>
#include <winnt.h>

#ifndef macro_header_translate
#define macro_header_translate

namespace translate {
	using language_index = size_t;
	using c_language_index = const language_index;

	c_language_index language_per_vocabulary = 2;

	c_language_index language_English = put_index_counter<language_index>(0);
	c_language_index language_Russian = put_index_counter<language_index>(continue_counting);
	
	language_index language_using = language_Russian;

	class string {
	private:
		std::array<std::vector<WCHAR>, language_per_vocabulary> fixed{};

		void fix() {
			if (fixed.at(language_using).size() == 0) {
				for (size_t index_language = 0; index_language < language_per_vocabulary; index_language++) {
					for (size_t index = 0; index < language_variant.at(index_language).size(); index++) {
						fixed.at(index_language).push_back(
							*(language_variant.at(language_using).c_str() + index)
						);
					}

					fixed.at(index_language).push_back(L'\0');
				}
			}
		}
	public:
		std::array<std::wstring, language_per_vocabulary> language_variant{};

		LPCWSTR c_style() {
			fix();

			return fixed.at(language_using).data();
		}
	};
	
	string set_string(
		std::wstring string_English,
		std::wstring string_Russian
	) {
		string string_bringer;

		string_bringer.language_variant.at(language_English) = string_English;
		string_bringer.language_variant.at(language_Russian) = string_Russian;

		return string_bringer;
	}

	// Universal using
	// Универсальное применение

	string string_program_name = set_string(
		L"Algebradabra " + program_version_family,
		L"Алгебрадабра " + program_version_family
	);

	// Dialog boxes about errors in program
	// Диалоговые окна об ошибках в программе

	string string_cannot_create_class_name = set_string(
		L"Cannot create name of class", 
		L"Невозможно создать имя класса"
	);

	string string_cannot_create_class_main = set_string(
		L"Cannot create name of class for main window", 
		L"Невозможно создать имя класса к главному окну"
	);

	string string_cannot_create_main_window = set_string(
		L"Cannot create main window",
		L"Невозможно создать главное окно"
	);

	// Главное окно
	// Main window
	
	string string__exit = set_string(L"Exit", L"Выход");
	string string__whats_new = set_string(L"What's new?", L"Что нового?");

	string string_thats_new = set_string(
		L"Иконка полностью переделывалась, появились диалоговые окна открытия и сохранения файла. \
Появились технические обзоры вышеперечисленных окон, а также технический обзор выбора цвета.", 
		L"Icon was remade fully. \
Save & open file dialog boxes were appeared. \
Technical window's checking of these dialog boxes & color choice were appeared too."
	);

	string string__program = set_string(L"Program", L"Программа");
	string string__book_alg = set_string(L"Book .alg", L"Книга .alg");
	string string__create = set_string(L"Create", L"Создать");
	string string__open = set_string(L"Open", L"Открыть");
	string string__save = set_string(L"Save", L"Сохранить");
	string string__save_as = set_string(L"Save as", L"Сохранить как");
	string string__compress = set_string(L"Compress", L"Сжать");
	string string__lock_with_password = set_string(L"Lock with password", L"Заблокировать паролем");
	string string__page_add = set_string(L"Add the page", L"Добавить страницу");
	string string__coordinate = set_string(L"Coordinate", L"Координата");
	string string__circuit = set_string(L"Circuit", L"Схема");
	string string__paint = set_string(L"Paint", L"Рисунок");
	string string__file_txt = set_string(L"File .txt", L"Файл .txt");
	string string__edit = set_string(L"Edit", L"Правка");
	string string__search_command = set_string(L"Search command", L"Найти команду");
	string string__search_string = set_string(L"Search string", L"Найти строку");
	string string_page_copy = set_string(L"Copy this page", L"Копировать страницу");
	string string__paste = set_string(L"Paste", L"Вставить");
	string string__cancel = set_string(L"Cancel", L"Отменить");
	string string__cancel_the_last = set_string(L"Cancel the last", L"Отменить последнее");
	string string__undo = set_string(L"Undo", L"Возвратить");
	string string__undo_the_last = set_string(L"Undo the last", L"Возвратить последнее");
	string string__view = set_string(L"View", L"Вид");
	string string__menu_and_toolbar = set_string(L"Menu & toolbar", L"Меню и панель инструментов");
	string string__cursor = set_string(L"Cursor", L"Курсор");
	string string__style = set_string(L"Style", L"Стиль");
	string string__default_view = set_string(L"Default view", L"Вид по умолчанию");
	string string_help_and_settings = set_string(L"Help/Settings", L"Настройки/Справка");
	string string__algebraic_books_parameter = set_string(L"Book's parameter", L"Параметр книги");
	string string__pages_parameter = set_string(L"Page's parameter", L"Параметр страницы");
	string string__programs_parameter = set_string(L"Program's parameter", L"Параметр программы");
	string string__language = set_string(L"Language", L"Язык");
	string string__window = set_string(L"Window", L"Окно");
	string string__technical_windows_check = set_string(L"Technical window's check", L"Технический обзор окон");
	string string__main_window = set_string(L"Main window", L"Главное окно");

	string string_title_main_window = set_string(
		string_program_name.language_variant.at(language_English)
		+ L" | "
		+ string__main_window.language_variant.at(language_English),
		string_program_name.language_variant.at(language_Russian)
		+ L" | "
		+ string__main_window.language_variant.at(language_Russian)
		);

	string string_asking_for_save_before_exit = set_string(
		L"Would you like saving document before exit?", 
		L"Сохранить документы перед выходом?"
		);
	
	string string_check_open_file = set_string(L"\"Open file\"", L"\"Открыть файл\"");
	string string_check_save_file_as = set_string(L"\"Save file as\"", L"\"Сохранить файл как\"");
	string string_check_choose_color = set_string(L"\"Choose color\"", L"\"Выбрать цвет\"");

	// Dialog boxes as technical checkers
	// Диалоговые окна как технические обзоры
	
	string string_title_dialog_box_open_file = set_string(L"Opening file...", L"Открыть файл...");
	string string_title_dialog_box_save_file_as = set_string(L"Saving file as...", L"Сохранить файл как...");

	// Dialog boxes for saving & opening book
	// Диалоговые окна для сохранения и открытия файла

	string string_title_dialog_box_open_book = set_string(L"Opening book...", L"Открыть книгу...");
	string string_title_dialog_box_save_book_as = set_string(L"Saving book as...", L"Сохранить книгу как...");

	// Window about program
	// Окно о программе
	
	string string__testing_dialog_box = set_string(
		L"Testing dialog box", 
		L"Тестовое диалоговое окно"
	);

	string string_program_author = set_string(
		L"D. M. Chamkin (Transistor, MathWindow)", 
		L"Д. М. Чамкин (Transistor, MathWindow)"
	);

	string string_program_description = set_string(
		L"Author: "
		+ string_program_author.language_variant.at(language_English)
		+ L";\nVersion:"
		+ program_version
		+ L".",
		L"Автор: "
		+ string_program_author.language_variant.at(language_Russian)
		+ L";\nВерсия: "
		+ program_version
		+ L"."
	);
}

#endif