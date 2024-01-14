#pragma once
#include "ShortTypes.h"

#ifndef counter_header
#define counter_header

uint_32 index_running_global = 0;

uint_32 put_index_running(bool reverse, uint_32 start_number = 0) {
	if (reverse) {
		index_running_global = start_number;
	}

	index_running_global++;

	return index_running_global - 1;
}

#endif