#pragma once
#include "ShortTypes.h"

#ifndef macro_header_counter
#define macro_header_counter

cu_char_ continue_counting = 255U;
cu_char_ no_counting = 254U;

template<typename this_type> 
const this_type put_index_counter(this_type start_number) {
	static this_type index_static = 0;

	if (start_number != continue_counting) {
		index_static = start_number;
	}

	if (start_number != no_counting) {
		index_static++;
	}

	return index_static - 1;
}

#endif
