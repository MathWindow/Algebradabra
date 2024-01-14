#pragma once
#include <vector>
#include <array>
#include <windows.h>
using namespace std;

struct error_event {
	LPCWSTR error_name = L"";
	LPCWSTR details = L"";
	LPCWSTR error_type = L"";
	LPCWSTR function_name = L"";
};

vector <error_event> error_list_program;