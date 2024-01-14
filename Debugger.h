#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include <minwinbase.h>
#include <sysinfoapi.h>
#include "ShortTypes.h"
#include "Counter.h"
#include "Translate.h"

#ifndef macro_header_debugger
#define macro_header_debugger

namespace debug {
	using characteristic_parameter
		= booleam_parameter_char;

	using c_characteristic_parameter
		= const characteristic_parameter;

	c_characteristic_parameter characteristic_critical
		= ~(1 << put_index_counter<characteristic_parameter>(0));
	c_characteristic_parameter characteristic_dangerous
		= ~(1 << put_index_counter<characteristic_parameter>(continue_counting));
	c_characteristic_parameter characteristic_logical
		= ~(1 << put_index_counter<characteristic_parameter>(continue_counting));
	c_characteristic_parameter characteristic_algebraic
		= ~(1 << put_index_counter<characteristic_parameter>(continue_counting));

	using event_type_index = u_char_;
	using c_event_type_index = const event_type_index;

	c_event_type_index event_type_message
		= put_index_counter<event_type_index>(0);
	c_event_type_index event_type_question
		= put_index_counter<event_type_index>(continue_counting);
	c_event_type_index event_type_warning
		= put_index_counter<event_type_index>(continue_counting);
	c_event_type_index event_type_error
		= put_index_counter<event_type_index>(continue_counting);
	
	using block_type_index = u_char_;
	using c_block_type_index = const block_type_index;

	c_block_type_index block_type_function
		= put_index_counter<block_type_index>(0);
	c_block_type_index block_type_try_catch
		= put_index_counter<block_type_index>(continue_counting);
	c_block_type_index block_type_if
		= put_index_counter<block_type_index>(continue_counting);
	c_block_type_index block_type_switch
		= put_index_counter<block_type_index>(continue_counting);
	c_block_type_index block_type_while
		= put_index_counter<block_type_index>(continue_counting);
	c_block_type_index block_type_for
		= put_index_counter<block_type_index>(continue_counting);

	class block_information {
	public:
		block_type_index type = block_type_function;

		std::wstring name = L"";

		void* variable_address = nullptr;
		int variable_value = 0;
	};

	class event_information {
	public:
		event_type_index type = event_type_message;
		characteristic_parameter characteristic = ~0;

		size_t title_index = 0;
		size_t details_index = 0;
		std::vector<std::size_t> reason_index_list{};
		std::vector<std::size_t> advance_index_list{};

		std::vector<block_information> block_array{};

		SYSTEMTIME time_system{};
		SYSTEMTIME time_local{};
	};

	std::vector<event_information> history_of_event{};

	void write_event(
		event_type_index type,
		characteristic_parameter characteristic,
		size_t title_index,
		size_t details_index,
		std::vector<std::size_t> reason_index_list,
		std::vector<std::size_t> advance_index_list,
		std::vector<block_information> block_array
	) {
		history_of_event.push_back(
			{
				type,
				characteristic,
				title_index,
				details_index,
				reason_index_list,
				advance_index_list,
				block_array
			}
		);

		GetSystemTime(&history_of_event.back().time_system);
		GetLocalTime(&history_of_event.back().time_local);
	}
}

#endif