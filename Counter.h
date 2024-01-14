#pragma once
#include "ShortTypes.h"

#ifndef counter_header
#define counter_header

cu_char_ continue_counting = 255;

template<typename this_type> 
this_type put_index_counter(this_type start_number) {
	static this_type index_static = 0;

	if (start_number != continue_counting) {
		index_static = start_number;
	}

	index_static++;

	return index_static - 1;
}

#endif