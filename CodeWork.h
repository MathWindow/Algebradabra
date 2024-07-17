#pragma once
#include <string>
#include <vector>
#include <corecrt.h>
#include "ShortTypes.h"

#ifndef macro_header_block_code
#define macro_header_block_code

#define macro_add_block_function(i) std::vector<coding::block_information> place = i; \
								place.push_back(coding::set_block_information(coding::block_type_function, __FUNCTIONW__, nullptr, 0))

#define macro_add_block_argument std::vector<coding::block_information> place_argument

#define macro_add_block_argument_address std::vector<coding::block_information>* place_address

#define begin_block {

#define end_block place.pop_back(); }

namespace coding {
	using block_type_index = u_char_;
	using c_block_type_index = const block_type_index;

	c_block_type_index block_type_none = 0;
	c_block_type_index block_type_function = 1;
	c_block_type_index block_type_try_catch = 2;
	c_block_type_index block_type_if = 3;
	c_block_type_index block_type_switch = 4;
	c_block_type_index block_type_while = 5;
	c_block_type_index block_type_for = 6;
	c_block_type_index block_type_class = 7;

	class block_information {
	public:
		block_type_index block_type = block_type_none;

		std::wstring function_name = L"";
		
		void* variable_address = nullptr;

		long_2_ variable_value = 0;

		std::wstring show_block_type() {
			switch (block_type) {
			case block_type_function:
				return L"function";
				break;
			case block_type_if:
				return L"if";
				break;
			case block_type_switch:
				return L"switch";
				break;
			case block_type_while:
				return L"while";
				break;
			case block_type_for:
				return L"for";
				break;
			case block_type_class:
				return L"class";
				break;
			case block_type_try_catch:
				return L"try-catch";
				break;
			case block_type_none:
				return L"none";
				break;
			}
		}

		std::wstring show_function_name() {
			if (block_type == block_type_function) {
				return function_name;
			}
			else {
				return L"";
			}
		}

		std::wstring show_block() {
			return
				show_block_type()
				+ (
					block_type == block_type_function
					? L" \"" + show_function_name() + L"\""
					: L""
				)
				+ (
					block_type == block_type_switch || block_type == block_type_for
					? + L" " + show_variable_value()
					: L""
				);
		}

		std::wstring show_variable_address() {
			if (block_type == block_type_for || block_type == block_type_switch) {
				return std::to_wstring((int)variable_address);
			}
			else {
				return L"";
			}
		}

		std::wstring show_variable_value() {
			if (block_type == block_type_for || block_type == block_type_switch) {
				return std::to_wstring(variable_value);
			}
			else {
				return L"";
			}
		}
	};

	block_information set_block_information(
		block_type_index block_type,
		std::wstring function_name,
		void* variable_address,
		long_2_ variable_value
	) {
		block_information result{};

		result.block_type = block_type;
		result.function_name = function_name;
		result.variable_address = variable_address;
		result.variable_value = variable_value;

		return result;
	}

	long_2_ push_variable_switch_in_block_hierarchy(
		void* variable_address,
		long_2_ variable_value,
		macro_add_block_argument_address
	) {
		(*place_address).push_back(
			set_block_information(
				block_type_switch,
				L"",
				variable_address,
				variable_value
			)
		);

		return variable_value;
	};
}

#endif