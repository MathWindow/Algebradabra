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

����� ������ ���� � ���������� ������� �������
Tree's circuit menu with hot key's tip

���������
	�������� ��������
		������� ctrl + N
		������� ctrl + O
		��������� ctrl + S
		��������� ���... ctrl + shift + S
		-
		������� F6
		������������� �������
	-
	�������� ���� ctrl + E
	�������� ������� �����
		���������� E
		�����
		�������
		���� rtf
	-
	����� alt + F4
������
	����� ������ ctrl + shift + F
	����� ��������� ���������� ctrl + F
	-
	���������� ���� ctrl + shift + C
	���������� ������� ����� ctrl + C
	�������� ctrl + V
	-
	��������
		�������� ��������� ctrl + Z
		<������ ����������� ��������>
	����������
		���������� ��������� ctrl + Y
		<������ ���������� ��������>
���
	���� � ������ ������������
	������
	����������
	�����
	-
	�������� ������������� F5
�������� / ���������
	�������� ��������� ���������
	�������� �����
	�������� �������� �����
	-
	�������� ��������� F1
	����
		English
		�������

*/

// ������ ����

HMENU bag_document_menu = CreateMenu();
HMENU add_list_element_menu = CreateMenu();
HMENU cancel_menu = CreateMenu();
HMENU undo_menu = CreateMenu();
HMENU language_menu = CreateMenu();

// ������ ����

HMENU program_menu = CreateMenu();
HMENU edit_menu = CreateMenu();
HMENU view_menu = CreateMenu();
HMENU information_settings_menu = CreateMenu();

// ������ ����

HMENU root_menu = CreateMenu();

//array <TCHAR, 20> exit_string = { L"����� alt + F4" };

bool create_menu(HWND h_window) {
	// ������ ����

	string_element_menu(bag_document_menu, NULL, L"������� ctrl + N");
	string_element_menu(bag_document_menu, NULL, L"������� ctrl + O");
	string_element_menu(bag_document_menu, NULL, L"��������� ctrl + S");
	string_element_menu(bag_document_menu, NULL, L"��������� ���... ctrl + shift + S");
	line_element_menu(bag_document_menu);
	string_element_menu(bag_document_menu, NULL, L"������� F6");
	string_element_menu(bag_document_menu, NULL, L"������������� �������");

	string_element_menu(add_list_element_menu, NULL, L"����������");
	string_element_menu(add_list_element_menu, NULL, L"�����");
	string_element_menu(add_list_element_menu, NULL, L"�������");
	string_element_menu(add_list_element_menu, NULL, L"���� rtf");

	string_element_menu(cancel_menu, NULL, L"�������� ���������");

	string_element_menu(undo_menu, NULL, L"���������� ���������");

	string_element_menu(language_menu, NULL, L"English");
	string_element_menu(language_menu, NULL, L"�������");

	// ������ ����

	popup_element_menu(program_menu, bag_document_menu, L"�������� ��������");
	line_element_menu(program_menu);
	string_element_menu(program_menu, NULL, L"�������� ����");
	popup_element_menu(program_menu, add_list_element_menu, L"�������� ������� �����");
	line_element_menu(program_menu);
	string_element_menu(program_menu, command_exit, L"����� alt + F4");

	string_element_menu(edit_menu, NULL, L"����� ������ ctrl + shift + F");
	string_element_menu(edit_menu, NULL, L"������������ ����� ctrl + F");
	line_element_menu(edit_menu);
	string_element_menu(edit_menu, NULL, L"���������� ���� ctrl + shift + C");
	string_element_menu(edit_menu, NULL, L"���������� ������� �����");
	string_element_menu(edit_menu, NULL, L"��������");
	line_element_menu(edit_menu);
	popup_element_menu(edit_menu, cancel_menu, L"��������");
	popup_element_menu(edit_menu, undo_menu, L"����������");

	string_element_menu(view_menu, NULL, L"���� � ������ ������������");
	string_element_menu(view_menu, NULL, L"������");
	string_element_menu(view_menu, NULL, L"����������");
	string_element_menu(view_menu, NULL, L"�����");
	line_element_menu(view_menu);
	string_element_menu(view_menu, NULL, L"�������� �������������");

	string_element_menu(information_settings_menu, NULL, L"�������� ��������� ���������");
	string_element_menu(information_settings_menu, NULL, L"�������� �����");
	string_element_menu(information_settings_menu, NULL, L"�������� �������� �����");
	line_element_menu(information_settings_menu);
	string_element_menu(information_settings_menu, NULL, L"�������� ��������� F1");
	popup_element_menu(information_settings_menu, language_menu, L"����");

	// ������ ����

	popup_element_menu(root_menu, program_menu, L"���������");
	popup_element_menu(root_menu, edit_menu, L"������");
	popup_element_menu(root_menu, view_menu, L"���");
	line_element_menu(root_menu);
	popup_element_menu(root_menu, information_settings_menu, L"�������� / ���������");

	SetMenu(h_window, root_menu);

	return true;
}