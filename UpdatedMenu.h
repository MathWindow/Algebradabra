#pragma once
#include <windows.h>
#include "Commands.h"

BOOL _stdcall line_element_menu(HMENU h_menu) {
	return AppendMenuW(h_menu, MF_SEPARATOR, NULL, NULL);
}

BOOL _stdcall popup_element_menu(HMENU h_menu, HMENU next_menu, LPCWSTR title) {
	return AppendMenuW(h_menu, MF_POPUP, (UINT_PTR)next_menu, title);
}

BOOL _stdcall popup_help_element_menu(HMENU h_menu, HMENU next_menu, LPCWSTR title) {
	return AppendMenuW(h_menu, MF_POPUP | MF_HELP, (UINT_PTR)next_menu, title);
}

BOOL _stdcall string_element_menu(HMENU h_menu, UINT_PTR numberCommand, LPCWSTR title) {
	return AppendMenuW(h_menu, MF_STRING, numberCommand, title);
}

/*

Схема дерева меню с подсказкой горячей клавиши
Tree's circuit menu with hot key's tip

Программа
	Пакетный документ
		Создать ctrl + N
		Открыть ctrl + O
		Сохранить ctrl + S
		Сохранить как... ctrl + shift + S
		-
		Сжимать F6
		Заблокировать паролем
	-
	Добавить лист ctrl + E
	Добавить элемент листа
		Координата E
		Схема
		Рисунок
		Файл rtf
	-
	Выход alt + F4
Правка
	Поиск команд ctrl + shift + F
	Поиск текстовых фрагментов ctrl + F
	-
	Копировать лист ctrl + shift + C
	Копировать элемент листа ctrl + C
	Вставить ctrl + V
	-
	Отменить
		Отменить последнее ctrl + Z
		<Список выполненных действии>
	Возвращать
		Возвращать последнее ctrl + Y
		<Список отмененных действии>
Вид
	Меню и панель инструментов
	Курсор
	Координата
	Стиль
	-
	Сбросить представление F5
Сведение / Настройки
	Свойство пакетного документа
	Свойство листа
	Свойство элемента листа
	-
	Свойство программы F1
	Язык
		English
		Русский

*/

// Третий этаж

HMENU bag_document_menu = CreateMenu();
HMENU add_list_element_menu = CreateMenu();
HMENU cancel_menu = CreateMenu();
HMENU undo_menu = CreateMenu();
HMENU language_menu = CreateMenu();

// Второй этаж

HMENU program_menu = CreateMenu();
HMENU edit_menu = CreateMenu();
HMENU view_menu = CreateMenu();
HMENU information_settings_menu = CreateMenu();

// Первый этаж

HMENU root_menu = CreateMenu();

//array <TCHAR, 20> exit_string = { L"Выход alt + F4" };

bool create_menu(HWND h_window) {
	// Третий этаж

	string_element_menu(bag_document_menu, NULL, L"Создать ctrl + N");
	string_element_menu(bag_document_menu, NULL, L"Открыть ctrl + O");
	string_element_menu(bag_document_menu, NULL, L"Сохранить ctrl + S");
	string_element_menu(bag_document_menu, NULL, L"Сохранить как... ctrl + shift + S");
	line_element_menu(bag_document_menu);
	string_element_menu(bag_document_menu, NULL, L"Сжимать F6");
	string_element_menu(bag_document_menu, NULL, L"Заблокировать паролем");

	string_element_menu(add_list_element_menu, NULL, L"Координата");
	string_element_menu(add_list_element_menu, NULL, L"Схема");
	string_element_menu(add_list_element_menu, NULL, L"Рисунок");
	string_element_menu(add_list_element_menu, NULL, L"Файл rtf");

	string_element_menu(cancel_menu, NULL, L"Отменить последнее");

	string_element_menu(undo_menu, NULL, L"Возвращать последнее");

	string_element_menu(language_menu, NULL, L"English");
	string_element_menu(language_menu, NULL, L"Русский");

	// Второй этаж

	popup_element_menu(program_menu, bag_document_menu, L"Пакетный документ");
	line_element_menu(program_menu);
	string_element_menu(program_menu, NULL, L"Добавить лист");
	popup_element_menu(program_menu, add_list_element_menu, L"Добавить элемент листа");
	line_element_menu(program_menu);
	string_element_menu(program_menu, command_exit, L"Выход alt + F4");

	string_element_menu(edit_menu, NULL, L"Поиск команд ctrl + shift + F");
	string_element_menu(edit_menu, NULL, L"Литературный поиск ctrl + F");
	line_element_menu(edit_menu);
	string_element_menu(edit_menu, NULL, L"Копировать лист ctrl + shift + C");
	string_element_menu(edit_menu, NULL, L"Копировать элемент листа");
	string_element_menu(edit_menu, NULL, L"Вставить");
	line_element_menu(edit_menu);
	popup_element_menu(edit_menu, cancel_menu, L"Отменить");
	popup_element_menu(edit_menu, undo_menu, L"Возвращать");

	string_element_menu(view_menu, NULL, L"Меню и панель инструментов");
	string_element_menu(view_menu, NULL, L"Курсор");
	string_element_menu(view_menu, NULL, L"Координата");
	string_element_menu(view_menu, NULL, L"Стиль");
	line_element_menu(view_menu);
	string_element_menu(view_menu, NULL, L"Сбросить представление");

	string_element_menu(information_settings_menu, NULL, L"Свойство пакетного документа");
	string_element_menu(information_settings_menu, NULL, L"Свойство листа");
	string_element_menu(information_settings_menu, NULL, L"Свойство элемента листа");
	line_element_menu(information_settings_menu);
	string_element_menu(information_settings_menu, NULL, L"Свойство программы F1");
	popup_element_menu(information_settings_menu, language_menu, L"Язык");

	// Первый этаж

	popup_element_menu(root_menu, program_menu, L"Программа");
	popup_element_menu(root_menu, edit_menu, L"Правка");
	popup_element_menu(root_menu, view_menu, L"Вид");
	line_element_menu(root_menu);
	popup_element_menu(root_menu, information_settings_menu, L"Сведение / Настройки");

	SetMenu(h_window, root_menu);

	return true;
}