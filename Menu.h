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

Ñõåìà äåðåâà ìåíþ ñ ïîäñêàçêîé ãîðÿ÷åé êëàâèøè
Tree's circuit menu with hot key's tip

Ïðîãðàììà
	Ïàêåòíûé äîêóìåíò
		Ñîçäàòü ctrl + N
		Îòêðûòü ctrl + O
		Ñîõðàíèòü ctrl + S
		Ñîõðàíèòü êàê... ctrl + shift + S
		-
		Ñæèìàòü F6
		Çàáëîêèðîâàòü ïàðîëåì
	-
	Äîáàâèòü ëèñò ctrl + E
	Äîáàâèòü ýëåìåíò ëèñòà
		Êîîðäèíàòà E
		Ñõåìà
		Ðèñóíîê
		Ôàéë rtf
	-
	Âûõîä alt + F4
Ïðàâêà
	Ïîèñê êîìàíä ctrl + shift + F
	Ïîèñê òåêñòîâûõ ôðàãìåíòîâ ctrl + F
	-
	Êîïèðîâàòü ëèñò ctrl + shift + C
	Êîïèðîâàòü ýëåìåíò ëèñòà ctrl + C
	Âñòàâèòü ctrl + V
	-
	Îòìåíèòü
		Îòìåíèòü ïîñëåäíåå ctrl + Z
		<Ñïèñîê âûïîëíåííûõ äåéñòâèè>
	Âîçâðàùàòü
		Âîçâðàùàòü ïîñëåäíåå ctrl + Y
		<Ñïèñîê îòìåíåííûõ äåéñòâèè>
Âèä
	Ìåíþ è ïàíåëü èíñòðóìåíòîâ
	Êóðñîð
	Êîîðäèíàòà
	Ñòèëü
	-
	Ñáðîñèòü ïðåäñòàâëåíèå F5
Ñâåäåíèå / Íàñòðîéêè
	Ñâîéñòâî ïàêåòíîãî äîêóìåíòà
	Ñâîéñòâî ëèñòà
	Ñâîéñòâî ýëåìåíòà ëèñòà
	-
	Ñâîéñòâî ïðîãðàììû F1
	ßçûê
		English
		Ðóññêèé

*/

// Òðåòèé ýòàæ

HMENU bag_document_menu = CreateMenu();
HMENU add_list_element_menu = CreateMenu();
HMENU cancel_menu = CreateMenu();
HMENU undo_menu = CreateMenu();
HMENU language_menu = CreateMenu();

// Âòîðîé ýòàæ

HMENU program_menu = CreateMenu();
HMENU edit_menu = CreateMenu();
HMENU view_menu = CreateMenu();
HMENU information_settings_menu = CreateMenu();

// Ïåðâûé ýòàæ

HMENU root_menu = CreateMenu();

bool create_menu(HWND h_window) {
	// Òðåòèé ýòàæ

	string_element_menu(bag_document_menu, NULL, L"Ñîçäàòü ctrl + N");
	string_element_menu(bag_document_menu, NULL, L"Îòêðûòü ctrl + O");
	string_element_menu(bag_document_menu, NULL, L"Ñîõðàíèòü ctrl + S");
	string_element_menu(bag_document_menu, NULL, L"Ñîõðàíèòü êàê... ctrl + shift + S");
	line_element_menu(bag_document_menu);
	string_element_menu(bag_document_menu, NULL, L"Ñæèìàòü F6");
	string_element_menu(bag_document_menu, NULL, L"Çàáëîêèðîâàòü ïàðîëåì");

	string_element_menu(add_list_element_menu, NULL, L"Êîîðäèíàòà");
	string_element_menu(add_list_element_menu, NULL, L"Ñõåìà");
	string_element_menu(add_list_element_menu, NULL, L"Ðèñóíîê");
	string_element_menu(add_list_element_menu, NULL, L"Ôàéë rtf");

	string_element_menu(cancel_menu, NULL, L"Îòìåíèòü ïîñëåäíåå");

	string_element_menu(undo_menu, NULL, L"Âîçâðàùàòü ïîñëåäíåå");

	string_element_menu(language_menu, NULL, L"English");
	string_element_menu(language_menu, NULL, L"Ðóññêèé");

	// Âòîðîé ýòàæ

	popup_element_menu(program_menu, bag_document_menu, L"Ïàêåòíûé äîêóìåíò");
	line_element_menu(program_menu);
	string_element_menu(program_menu, NULL, L"Äîáàâèòü ëèñò");
	popup_element_menu(program_menu, add_list_element_menu, L"Äîáàâèòü ýëåìåíò ëèñòà");
	line_element_menu(program_menu);
	string_element_menu(program_menu, command_exit, L"Âûõîä alt + F4");

	string_element_menu(edit_menu, NULL, L"Ïîèñê êîìàíä ctrl + shift + F");
	string_element_menu(edit_menu, NULL, L"Ëèòåðàòóðíûé ïîèñê ctrl + F");
	line_element_menu(edit_menu);
	string_element_menu(edit_menu, NULL, L"Êîïèðîâàòü ëèñò ctrl + shift + C");
	string_element_menu(edit_menu, NULL, L"Êîïèðîâàòü ýëåìåíò ëèñòà");
	string_element_menu(edit_menu, NULL, L"Âñòàâèòü");
	line_element_menu(edit_menu);
	popup_element_menu(edit_menu, cancel_menu, L"Îòìåíèòü");
	popup_element_menu(edit_menu, undo_menu, L"Âîçâðàùàòü");

	string_element_menu(view_menu, NULL, L"Ìåíþ è ïàíåëü èíñòðóìåíòîâ");
	string_element_menu(view_menu, NULL, L"Êóðñîð");
	string_element_menu(view_menu, NULL, L"Êîîðäèíàòà");
	string_element_menu(view_menu, NULL, L"Ñòèëü");
	line_element_menu(view_menu);
	string_element_menu(view_menu, NULL, L"Ñáðîñèòü ïðåäñòàâëåíèå");
	
	string_element_menu(information_settings_menu, NULL, L"Ñâîéñòâî ïàêåòíîãî äîêóìåíòà");
	string_element_menu(information_settings_menu, NULL, L"Ñâîéñòâî ëèñòà");
	string_element_menu(information_settings_menu, NULL, L"Ñâîéñòâî ýëåìåíòà ëèñòà");
	line_element_menu(information_settings_menu);
	string_element_menu(information_settings_menu, NULL, L"Ñâîéñòâî ïðîãðàììû F1");
	popup_element_menu(information_settings_menu, language_menu, L"ßçûê");

	// Ïåðâûé ýòàæ

	popup_element_menu(root_menu, program_menu, L"Ïðîãðàììà");
	popup_element_menu(root_menu, edit_menu, L"Ïðàâêà");
	popup_element_menu(root_menu, view_menu, L"Âèä");
	line_element_menu(root_menu);
	popup_element_menu(root_menu, information_settings_menu, L"Ñâåäåíèå / Íàñòðîéêè");

	SetMenu(h_window, root_menu);

	return true;
}
