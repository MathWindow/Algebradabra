#pragma once
#include <vector>
#include <winnt.h>
#include "typeinfo"
#include "ShortTypes.h"

#ifndef macro_header_counter
#define macro_header_counter

std::vector<LPCSTR> history_of_index_static_type{};

cu_char_ continue_counting = 255;

bool paranormal = false;

template<typename this_type> 
this_type put_index_counter(this_type start_number) {
	static this_type index_static = 0;
	

	history_of_index_static_type.push_back(typeid(index_static).name());

	if (typeid(index_static) != typeid(this_type)) {
		paranormal = true;
	}

	if (start_number != continue_counting) {
		index_static = start_number;
	}
	
	index_static++;

	return index_static - 1;
}

#endif
