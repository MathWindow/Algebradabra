#pragma once
#include "ShortTypes.h"

#ifndef counter_header
#define counter_header

svt::u_long index_running_global = 0;

svt::u_long put_index_running(bool reverse, svt::u_long start_number = 0) {
	if (reverse) {
		index_running_global = start_number;
	}

	index_running_global++;

	return index_running_global - 1;
}

#endif