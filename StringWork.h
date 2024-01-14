#pragma once
#include <windows.h>
#include <vector>
#include "ShortTypes.h"

// 1

namespace string_work {
	svt::cu_short string_size_operation = (10 * 1024) / 2;

	wchar_t string_operation[string_size_operation]{};

	svt::u_short string_operation_index = 0;

	svt::u_short string_size(LPCWSTR string_input) {
		svt::u_short index_ = 0;
		
		for (; *(string_input + index_) != L'\0'; index_++) {
			;
		}

		return index_;
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

		svt::u_short string_size_1 = string_size(string_1);
		svt::u_short string_size_2 = string_size(string_2);

		svt::u_short string_size_output = string_size_1 + string_size_2;

		for (svt::u_short index = 0; index < string_size_output; index++) {
			if (index < string_size_1) {
				*(string_operation + index + string_operation_index) = *(string_1 + index);
			}
			else {
				*(string_operation + index + string_operation_index) = *(string_2 + index - string_size_1);
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
		string_output = string_union(string_output, string_3);
		string_output = string_union(string_output, string_4);
		string_output = string_union(string_output, string_5);
		string_output = string_union(string_output, string_6);
		
		return string_output;
	}
}

namespace test {
	std::vector<WCHAR> string_server{};

	void put_string_in_server(LPCWSTR string_input) {
		if (
			string_input != L""
			|| string_input != nullptr
		) {
			for (svt::u_int index = 0; *(string_input + index) != L'\0'; index++) {
				string_server.push_back(*(string_input + index));
			}
		}
	}

	LPCWSTR string_union(
		LPCWSTR string_1,
		LPCWSTR string_2
	) {
		svt::u_int begin_string_union = string_server.size();

		put_string_in_server(string_1);
		put_string_in_server(string_2);
		string_server.push_back(L'\0');

		return string_server.data() + begin_string_union;
	}
}