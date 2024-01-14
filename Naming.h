#pragma once

#ifndef naming_header
#define naming_header

#define program_name L"Algebradabra"
#define program_version L"1.0a"
#define program_author L"Д. М. Чамкин"
#define main_window_class_name L"Main window"
#define error_list_window_class_name L"Error list window"
#define program_helpers L""
#define program_that_used_to_help L""
#define to_wstring_this_function (LPCWSTR)__func__

using uint_8 = unsigned char;
using uint_16 = unsigned short;
using uint_v = unsigned int;
using uint_32 = unsigned long;
using uint_64 = unsigned long long;

#endif