#pragma once
#include <math.h>
#include <array>
using namespace std;

#ifndef algebra_header
#define algebra_header

#define prime_table_max_size 256

bool is_prime() {
	return false;
}

class prime_table {
public:
	array <unsigned int, prime_table_max_size> number{};

	bool created = false;

	void create() {
		if (!created) {
			number.at(0) = 2;

			unsigned int value_helper = 3;

			bool may_printed = false;

			for (short index_fulling_number = 1; index_fulling_number < prime_table_max_size; index_fulling_number++) {

				while (!may_printed) {
					may_printed = true;

					for (short index_preview_number = 0; index_preview_number < index_fulling_number; index_preview_number++) {

						if (number.at(index_fulling_number) % number.at(index_preview_number) == 0) {
							value_helper += 2;

							may_printed = false;
						}
					}
				}

				value_helper += 2;
			}

			created = true;
		}
	}
};

template <typename type_name> class number_t {
public:
	type_name value;
	bool imaginary;

	void operation_multy(type_name including_value, bool including_imaginary) {
		value *= including_value;

		if (including_imaginary) {
			imaginary = !inaginary;
			if (imaginary) {
				value = -value;
			}
		}
	}
};

#endif