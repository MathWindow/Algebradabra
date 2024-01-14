#pragma once
#include <windows.h>
#include <vector>
#include "ShortTypes.h"

// 1

namespace string_work {
	std::vector<WCHAR> string_server{};

	void put_string_in_server(LPCWSTR string_input) {
		if (
			string_input != L""
			&& string_input != nullptr
		) {
			for (svt::u_int index = 0; *(string_input + index) != L'\0'; index++) {
				string_server.push_back(*(string_input + index));
			}
		}
	}

	LPCWSTR string_union(
		LPCWSTR string_1,
		LPCWSTR string_2,
		LPCWSTR string_3 = nullptr,
		LPCWSTR string_4 = nullptr,
		LPCWSTR string_5 = nullptr,
		LPCWSTR string_6 = nullptr
	) {
		svt::u_int begin_string_union = string_server.size();

		put_string_in_server(string_1);
		put_string_in_server(string_2);
		put_string_in_server(string_3);
		put_string_in_server(string_4);
		put_string_in_server(string_5);
		put_string_in_server(string_6);
		string_server.push_back(L'\0');

		return string_server.data() + begin_string_union;
	}
}