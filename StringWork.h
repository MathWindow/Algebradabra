#pragma once
#include <vector>
#include <string>
#include "ShortTypes.h"

#ifndef macro_header_string_work
#define macro_header_string_work

std::wstring string_diapason(
	std::wstring string_argument,
	size_t index_begin,
	size_t size
) {
	std::wstring result = L"";

	if (string_argument.size() >= index_begin + size) {
		for (
			size_t index_symbol = index_begin;
			index_symbol < index_begin + size;
			index_symbol++
		) {
			result += string_argument.at(index_symbol);
		}
	}

	return result;
}

std::vector<size_t> show_indexes_from_vector_searching(
	std::wstring string_searcher,
	std::vector<std::vector<std::wstring>> string_2d_vector_argument,
	std::vector<std::wstring> string_member_instead_null
) {
	for (
		size_t index_list = 0;
		index_list < string_2d_vector_argument.size();
		index_list++
	) {
		for (
			size_t index_member = 0;
			index_member < string_2d_vector_argument.at(index_list).size();
			index_member++
		) {
			if (string_2d_vector_argument.at(index_list).at(index_member) == L"") {
				string_2d_vector_argument.at(index_list).at(index_member)
					= string_member_instead_null.at(index_member);
			}
		}
	}

	std::vector<size_t> result;

	for ( 
		size_t index_list = 0;
		index_list < string_2d_vector_argument.size();
		index_list++
	) {
		for ( 
			size_t index_member = 0;
			index_member < string_2d_vector_argument.at(index_list).size();
			index_member++
		) {
			for (
				size_t index_symbol = 0;
				index_symbol < string_searcher.size();
				index_symbol++
			) {
				if (
					string_diapason(
						string_searcher,
						index_symbol,
						string_2d_vector_argument.at(index_list).at(index_member).size()
					)
					== string_2d_vector_argument.at(index_list).at(index_member)
				) {
					result.push_back(index_list);

					index_symbol = string_searcher.size( );
					index_member = string_2d_vector_argument.at(index_list).size( );
				}
			}
		}
	}

	return result;
}

std::wstring auto_adding_zero(
	u_int_ number_argument
) {
	std::wstring result = L"";

	if (number_argument < 10) {
		result += L'0';
	}

	result += std::to_wstring(number_argument);

	return result;
}

template<typename integer_type>
integer_type convert_string_to_number(
	std::wstring string,
	size_t* index_begin
) {
	integer_type result = 0;

	for (
		;
		(*index_begin < string.size());
		(*index_begin)++
	) {
		result *= 10;

		if (string.at(*index_begin) == L'1') {
			result += 1;
		}
		else if (string.at(*index_begin) == L'2') {
			result += 2;
		}
		else if (string.at(*index_begin) == L'3') {
			result += 3;
		}
		else if (string.at(*index_begin) == L'4') {
			result += 4;
		}
		else if (string.at(*index_begin) == L'5') {
			result += 5;
		}
		else if (string.at(*index_begin) == L'6') {
			result += 6;
		}
		else if (string.at(*index_begin) == L'7') {
			result += 7;
		}
		else if (string.at(*index_begin) == L'8') {
			result += 8;
		}
		else if (string.at(*index_begin) == L'9') {
			result += 9;
		}
		else if (string.at(*index_begin) != L'0') {
			result /= 10;

			return result;
		}
	}

	return result;
}

#endif