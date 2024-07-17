#pragma once
#include <string>
#include "ShortTypes.h"

#ifndef macro_header_block_code
#define macro_header_block_code

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

	class block_information {
	public:
		block_type_index event_type = block_type_function;

		std::wstring name = L"";

		void* variable_address_for = nullptr;
		int variable_value_for = 0;
	};
}

#endif