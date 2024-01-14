#pragma once
#include "ShortTypes.h"

#ifndef counter_header
#define counter_header

ulong index_running_global = 0;

ulong put_index_running(bool reverse, ulong start_number = 0) {
	if (reverse) {
		index_running_global = start_number;
	}

	index_running_global++;

	return index_running_global - 1;
}

#endif