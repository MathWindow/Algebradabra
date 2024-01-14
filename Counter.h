#pragma once

#ifndef counter_header
#define counter_header

template<typename this_type> this_type put_index_counter(bool reverse, this_type start_number = 0) {
	static this_type index_global = 0;

	if (reverse) {
		index_global = start_number;
	}

	index_global++;

	return index_global - 1;
}

#endif