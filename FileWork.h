#pragma once
#include <Windows.h>
#include <fileapi.h>
#include <string>
#include <handleapi.h>
#include "StringWork.h"

void create_test_file(
	LPCWSTR path
) {
	HANDLE handle = CreateFileW(
		path,
		GENERIC_WRITE,
		NULL,
		NULL,
		CREATE_NEW,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	std::wstring text = L"\t Program is graphic calculator.";

	WriteFile(
		handle,
		text.c_str(),
		text.size() * 2,
		nullptr,
		NULL
	);

	CloseHandle(handle);
}

template<typename object_type>
class variable_file {
private:
	size_t number = 0;
public:
	object_type value = 0;

	void write_file(
		std::wstring loaded_string,
		bool to_save_value
	) {
		HANDLE handle = CreateFileW(
			L"Parameter File.txt",
			GENERIC_WRITE,
			NULL,
			NULL,
			CREATE_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL
		);

		std::wstring string_with_this_parameter 
			= loaded_string +
			(
				to_save_value
				? L"!" + std::to_wstring(number) 
				+ L"|" + std::to_wstring(value)
				: L""
			);

		WriteFile(
			handle, 
			string_with_this_parameter.c_str(), 
			string_with_this_parameter.size() * 2, 
			nullptr, 
			NULL
		);

		CloseHandle(handle);
	}

	bool open_file(
		std::wstring* string_,
		bool to_load_value
	) {
		bool number_was_found = false;

		HANDLE handle = CreateFileW(
			L"Parameter File.txt",
			GENERIC_READ,
			NULL,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL
		);

		if (handle != INVALID_HANDLE_VALUE) {
			DWORD buffer_size = 0;

			buffer_size = GetFileSize(handle, nullptr);

			wchar_t* text = new wchar_t[buffer_size * 2] {};

			ReadFile(handle, text, buffer_size * 2, nullptr, NULL);

			*string_ = text;

			delete[] text;

			if (to_load_value) {
				for (
					size_t index_symbol = 0;
					index_symbol < string_->size();
					index_symbol++
				) {
					if (string_->at(index_symbol) == L'!') {
						index_symbol++;

						if (number == convert_string_to_number<size_t>(*string_, &index_symbol)) {
							number_was_found = true;
						}

						if (string_->at(index_symbol) == L'|' && number_was_found) {
							index_symbol++;

							value = convert_string_to_number<size_t>(*string_, &index_symbol);

							index_symbol = string_->size();
						}
					}
				}
			}

			CloseHandle(handle);
		}

		return number_was_found;
	}

	void set_number(
		size_t argument
	) {
		if (number == 0) {
			number = argument;
		}
	}

	void set_value(
		object_type argument
	) {
		value = argument;

		std::wstring string = L"";
		std::wstring string_result = L"";

		open_file(&string, false);

		bool this_is_this_number = false;

		for (
			size_t index_symbol = 0;
			index_symbol < string.size();
			index_symbol++
		) {
			string_result += string.at(index_symbol);

			if (string.at(index_symbol) == L'!') {
				index_symbol++;

				size_t number_ 
					= convert_string_to_number<size_t>(string, &index_symbol);

				index_symbol--;

				string_result += std::to_wstring(number_);

				if (number == number_) {
					this_is_this_number = true;
				}
			}

			if (string.at(index_symbol) == L'|' && this_is_this_number) {
				string_result += std::to_wstring(value);

				this_is_this_number = false;

				index_symbol++;

				convert_string_to_number<size_t>(string, &index_symbol);

				index_symbol--;
			}
		}

		write_file(string_result, false);
	}
};

template<typename object_type>
variable_file<object_type> set_value_file(
	object_type value,
	size_t number_of_variable
) {
	variable_file<object_type> result{};

	result.set_number(number_of_variable);

	std::wstring string_ = L"";

	if (!result.open_file(&string_, true)) {
		result.value = value;

		result.write_file(string_, true);
	}

	return result;
}

