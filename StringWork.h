#pragma once
#include <windows.h>
#include "ShortTypes.h"

namespace string_work {
	cu_short string_size_operation = (1 * 1024) / 2;

	// 1 ����� = 1024 ����;
	// ��� 1 ������ = 2 �����: 1 ���� = 0.5 �������;

	wchar_t string_operation[string_size_operation]{};

	u_short string_operation_index = 0;

	u_short string_size(LPCWSTR string_input) {
		u_short index = 0;

		for (; *(string_input + index) != '\0'; index++) {
			;
		}

		return index;
	}

	LPCWSTR string_union(
		LPCWSTR string_1,
		LPCWSTR string_2
	) {
		if (string_1 == nullptr) {
			string_1 = L"";
		}
		else if (string_2 == nullptr){
			string_2 = L"";
		}

		LPCWSTR string_output = string_operation + string_operation_index;

		u_short string_size_1 = string_size(string_1);
		u_short string_size_2 = string_size(string_2);

		u_short string_size_output = string_size_1 + string_size_2;

		for (u_short index = 0; index < string_size_output; index++) {
			if (index < string_size_1 + string_size_output) {
				*(string_operation + index) = *(string_1 + index);
			}
			else {
				*(string_operation + index) = *(string_2 + index - string_size_1);
			}
		}

		string_operation_index += string_size_output + 1;

		return string_output;
	}

	LPCWSTR string_union_multy(
		LPCWSTR string_1,
		LPCWSTR string_2,
		LPCWSTR string_3 = nullptr,
		LPCWSTR string_4 = nullptr,
		LPCWSTR string_5 = nullptr,
		LPCWSTR string_6 = nullptr

	) {
		LPCWSTR string_output = nullptr;

		string_output = string_union(string_1, string_2);
	}
}