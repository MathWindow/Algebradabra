﻿#pragma once
#include <string>
#include <array>
#include <vector>
#include <winnt.h>
#include "Counter.h"
#include "VersionInfo.h"
#include "FileWork.h"

#ifndef macro_header_translate
#define macro_header_translate

namespace translate {
	using language_index = size_t;
	using c_language_index = const language_index;

	c_language_index language_English = put_index_counter<language_index>(0);
	c_language_index language_Russian = put_index_counter<language_index>(continue_counting);
	
	c_language_index language_per_vocabulary = 2;

	variable_file<language_index> language_using = set_value_file<language_index>(language_Russian, 1);

	class string {
	private:
		std::array<std::vector<WCHAR>, language_per_vocabulary> fixed{};

		void fix() {
			if (fixed.at(language_using.value).size() == 0) {
				for (
					size_t index_symbol = 0;
					index_symbol < language_variant.at(language_using.value).size();
					index_symbol++
				) {
					fixed.at(language_using.value).push_back(
						language_variant.at(language_using.value).at(index_symbol)
					);
				}

				fixed.at(language_using.value).push_back(L'\0');
			}
		}
	public:
		std::array<std::wstring, language_per_vocabulary> language_variant{};
			
		std::wstring show() {
			return language_variant.at(language_using.value);
		}

		LPCWSTR show_fixed() {
			fix();

			return fixed.at(language_using.value).data();
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

	string convert_to_translating(
		std::wstring string_argument
	) {
		return set_string(
			string_argument,
			string_argument
		);
	}

	// Universal using
	// Универсальное применение

	string string_program_name = set_string(
		L"Algebradabra " + program_version_family,
		L"Алгебрадабра " + program_version_family
	);

	// Главное окно
	// Main window
	
	string string__exit = set_string(
		L"Exit", 
		L"Выход"
	);

	string string_what_is_new = set_string(
		L"What's new?", 
		L"Что нового?"
	);

	string string_that_is_new = set_string(
		L"Window \"Debugger\" came, you can analyze of event and search it. You also can also install language with help of menu bar(Russian or English).",
		L"Окно \"Отладчик\" пришел, вы можете анализировать событие и найти его. Также вы можете установить язык с помощью панель меню (Русский или Английский)."
	);

	string string__program = set_string(
		L"Program", 
		L"Программа"
	);

	string string__book_alg = set_string(
		L"Book .alg",
		L"Книга .alg"
	);

	string string__create = set_string(
		L"Create", 
		L"Создать"
	);

	string string__open = set_string(
		L"Open", 
		L"Открыть"
	);

	string string__save = set_string(
		L"Save", 
		L"Сохранить"
	);

	string string__save_as = set_string(
		L"Save as", 
		L"Сохранить как"
	);

	string string__compress = set_string(
		L"Compress", 
		L"Сжать"
	);

	string string__lock_with_password = set_string(
		L"Lock with password", 
		L"Заблокировать паролем"
	);

	string string__page_add = set_string(
		L"Add the page", 
		L"Добавить страницу"
	);

	string string__coordinate = set_string(
		L"Coordinate", 
		L"Координата"
	);

	string string__circuit = set_string(
		L"Circuit",
		L"Схема"
	);

	string string__paint = set_string(
		L"Paint", 
		L"Рисунок"
	);

	string string__file_txt = set_string(
		L"File .txt", 
		L"Файл .txt"
	);

	string string__edit = set_string(
		L"Edit", 
		L"Правка"
	);

	string string__search_command = set_string(
		L"Search command", 
		L"Найти команду"
	);

	string string__search_string = set_string(
		L"Search string", 
		L"Найти строку"
	);

	string string_page_copy = set_string(
		L"Copy this page", 
		L"Копировать страницу"
	);

	string string__paste = set_string(
		L"Paste", 
		L"Вставить"
	);

	string string__cancel = set_string(
		L"Cancel", 
		L"Отменить"
	);

	string string__cancel_the_last = set_string(
		L"Cancel the last", 
		L"Отменить последнее"
	);

	string string__undo = set_string(
		L"Undo", 
		L"Возвратить"
	);

	string string__undo_the_last = set_string(
		L"Undo the last", 
		L"Возвратить последнее"
	);

	string string__view = set_string(
		L"View", 
		L"Вид"
	);

	string string__menu_and_toolbar = set_string(
		L"Menu & toolbar", 
		L"Меню и панель инструментов"
	);

	string string__cursor = set_string(
		L"Cursor", 
		L"Курсор"
	);

	string string__style = set_string(
		L"Style", 
		L"Стиль"
	);

	string string__default_view = set_string(
		L"Default view", 
		L"Вид по умолчанию"
	);

	string string_help_and_settings = set_string(
		L"Help/Settings", 
		L"Настройки/Справка"
	);

	string string__algebraic_books_parameter = set_string(
		L"Book's parameter", 
		L"Параметр книги"
	);

	string string__pages_parameter = set_string(
		L"Page's parameter", 
		L"Параметр страницы"
	);

	string string__programs_parameter = set_string(
		L"Program's parameter", 
		L"Параметр программы"
	);

	string string__about_program = set_string(
		L"About program",
		L"О программе"
	);

	string string__language = set_string(
		L"Language", 
		L"Язык"
	);

	string string__window = set_string(
		L"Window", 
		L"Окно"
	);

	string string__technical_windows_check = set_string(
		L"Technical window's check", 
		L"Технический обзор окон"
	);

	string string__main_window = set_string(
		L"Main window", 
		L"Главное окно"
	);

	string string__debugger = set_string(
		L"Debugger",
		L"Отладчик"
	);

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
	
	string string_check_open_file = set_string(
		L"\"Open file\"", 
		L"\"Открыть файл\""
	);

	string string_check_save_file_as = set_string(
		L"\"Save file as\"", 
		L"\"Сохранить файл как\""
	);

	string string_check_choose_color = set_string(
		L"\"Choose color\"", 
		L"\"Выбрать цвет\""
	);

	// Dialog boxes as technical checkers
	// Диалоговые окна как технические обзоры
	
	string string_title_dialog_box_open_file = set_string(
		L"Opening file...", 
		L"Открыть файл..."
	);

	string string_title_dialog_box_save_file_as = set_string(
		L"Saving file as...", 
		L"Сохранить файл как..."
	);

	string string__testing_dialog_box = set_string(
		L"Testing dialog box",
		L"Тестовое диалоговое окно"
	);

	// Dialog boxes for saving & opening book
	// Диалоговые окна для сохранения и открытия файла

	string string_title_dialog_box_open_book = set_string(
		L"Opening book...", 
		L"Открыть книгу..."
	);

	string string_title_dialog_box_save_book_as = set_string(
		L"Saving book as...", 
		L"Сохранить книгу как..."
	);

	// Window about program
	// Окно о программе

	string string_program_author = set_string(
		L"D. M. Chamkin (Transistor, MathWindow)", 
		L"Д. М. Чамкин (Transistor, MathWindow)"
	);

	string string_program_description = set_string(
		L"Author: "
		+ string_program_author.language_variant.at(language_English)
		+ L";\nVersion: "
		+ program_version
		+ L".",
		L"Автор: "
		+ string_program_author.language_variant.at(language_Russian)
		+ L";\nВерсия: "
		+ program_version
		+ L"."
	);

	// Window as debugger
	// Окно как отладчик

	string string_title_debugger_window = set_string(
		string_program_name.language_variant.at(language_English)
		+ L" | "
		+ string__debugger.language_variant.at(language_English),
		string_program_name.language_variant.at(language_Russian)
		+ L" | "
		+ string__debugger.language_variant.at(language_Russian)
	);

	string string_event_list = set_string(
		L"Events' list",
		L"Список событии"
	);

	string string_block_hierarchy = set_string(
		L"Block's hierarchy",
		L"Иерархия блока"
	);

	string string_event_title = set_string(
		L"Event's title",
		L"Заголовок события"
	);

	string string_event_extra_title = set_string(
		L"Event's extra title",
		L"Дополненный заголовок события"
	);

	string string_event_type = set_string(
		L"Event's type",
		L"Тип события"
	);

	string string_handle_value = set_string(
		L"Handle's value",
		L"Значение дескриптора"
	);

	string string_handle_type = set_string(
		L"Handle's type",
		L"Тип дескриптора"
	);

	string string_window_or_widget_class = set_string(
		L"Name of window's or widget's class",
		L"Имя класса виджета или окна"
	);

	string string_index_about_other_event = set_string(
		L"Index about other event",
		L"Индекс другого события"
	);
	
	string string__local_time = set_string(
		L"Local time",
		L"Локальное время"
	);
	
	string string__system_time = set_string(
		L"System time",
		L"Системное время"
	);

	string string_block_type = set_string(
		L"Block's type",
		L"Тип блока"
	);

	string string_function_name = set_string(
		L"Function's name",
		L"Имя функции"
	);

	string string_variable_address = set_string(
		L"Variable's address",
		L"Адрес переменной"
	);

	string string_variable_value = set_string(
		L"Variable's value",
		L"Значение переменной"
	);

	string string__searcher = set_string(
		L"Searcher",
		L"Поисковик"
	);

	string string_n_event_was_found = set_string(
		L" event was found",
		L" событие было найдено"
	);

	string string_n_events_were_found = set_string(
		L" events were found",
		L" событи(я/и) были найдены"
	);

	string string__no_any_event_was_found = set_string(
		L"No any event was found",
		L"Ни одно событие не было найдено"
	);
}

#endif