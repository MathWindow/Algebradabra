#pragma once
#include <windows.h>

#ifndef naming_header
#define naming_header

#define turn_macro_off 0

#if turn_macro_off == 0

#define program_version_abovepublic L"v1.1"
#define program_version_publication L"15build"
#define program_version_family L"May"
#define program_version program_version_family L" " program_version_publication L" " program_version_abovepublic

#define program_name L"Algebradabra " program_version_family
#define program_author L"Ä. Ì. ×àìêèí"

#define main_window_class_name L"Main window"
#define main_window_name program_name L" — main window"

#define error_list_window_class_name L"Error list window"
#define error_list_window_name program_name L" — Error list"

#define algebraic_book_create_window_class_name L"Algebraic book create window"
#define algebraic_book_create_name program_name L" — create algebraic book"

#define program_helpers L""
#define program_that_used_to_help L""

#else
LPCWSTR program_name = L"Algebradabra";
#endif

#endif