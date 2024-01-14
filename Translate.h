#pragma once
#include <windows.h>
#include "Simbols.h"

#define vocabulary_size 1000 // Размер словаря в строках каждому языку
#define string_size 50 // Максимальный размер каждой строки словари
#define count_of_language 6 // Максимальный размер каждой строки словари

#define number_language_Russian 0
#define number_language_English 1
#define number_language_German 2
#define number_language_French 3
#define number_language_Spanish 4
#define number_language_Italian 5

double vocabulary_size_info = (vocabulary_size * string_size * count_of_language) / 1024;

struct _language_list {
	LPCWSTR language_name_Russian = L"Русский";
	LPCWSTR language_name_English = L"English";
	LPCWSTR language_name_German = L"Deutsch";
	LPCWSTR language_name_French = simbol_em_dash;
	LPCWSTR language_name_Spanish = L"Español";
	LPCWSTR language_name_Italian = simbol_em_dash;
};

struct _vocabulary {
	_language_list language_list;
};

_vocabulary vocabulary;