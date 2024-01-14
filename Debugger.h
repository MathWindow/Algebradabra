#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include <minwinbase.h>
#include "ShortTypes.h"
#include "Counter.h"

#ifndef macro_header_debugger
#define macro_header_debugger

std::vector<std::wstring> title_array{};
std::vector<std::wstring> details_array{};
std::vector<std::wstring> reason_array{};
std::vector<std::wstring> advance_array{};

using event_type_index = u_char_;
using c_event_type_index = const event_type_index;

c_event_type_index event_type_message =
	put_index_counter<event_type_index>(0);
c_event_type_index event_type_question =
	put_index_counter<event_type_index>(continue_counting);
c_event_type_index event_type_warning =
	put_index_counter<event_type_index>(continue_counting);
c_event_type_index event_type_error =
	put_index_counter<event_type_index>(continue_counting);

using block_type_index = u_char_;
using c_block_type_index = const block_type_index;

c_block_type_index block_type_function =
	put_index_counter<block_type_index>(0);
c_block_type_index block_type_try_catch =
	put_index_counter<block_type_index>(continue_counting);
c_block_type_index block_type_if =
	put_index_counter<block_type_index>(continue_counting);
c_block_type_index block_type_switch =
	put_index_counter<block_type_index>(continue_counting);
c_block_type_index block_type_while =
	put_index_counter<block_type_index>(continue_counting);
c_block_type_index block_type_for =
	put_index_counter<block_type_index>(continue_counting);

class block_information {
	block_type_index type = block_type_function;

	std::wstring name = L"";

	void* address = nullptr;
};

class event_information {
public:
	event_type_index type = event_type_message;
	bool critical = false;
	bool dangerous = false;
	bool logical = false;
	bool algebraic = false;

	size_t title_index = 0;
	size_t details_index = 0;
	size_t reason_index = 0;
	size_t advance_index = 0;

	std::vector<block_information> block_array{};

	SYSTEMTIME time_system{};
	SYSTEMTIME time_local{};
};

std::vector<event_information> history_of_event{};

#endif