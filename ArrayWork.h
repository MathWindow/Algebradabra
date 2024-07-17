#pragma once
#include <vector>
#include "CodeWork.h"

#ifndef macro_header_array_work
#define macro_header_array_work

template<typename object_type>
void delete_reversing_element_in_vector(
	std::vector<object_type>* vector_address,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	if (vector_address != nullptr) {
		for (
			size_t index_vector = 0;
			index_vector < (*vector_address).size() - 1;
			index_vector++
		) {
			if ((*vector_address).at(index_vector) == (*vector_address).back()) {
				(*vector_address).pop_back();
			}

			index_vector = 0;
		}
	}
}

template<typename object_type>
std::vector<object_type> convert_from_2d_to_1d(
	std::vector<std::vector<object_type>> argument,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	std::vector<object_type> result{};
	
	for (
		size_t index_1 = 0;
		index_1 < argument.size();
		index_1++
	) {
		for ( 
			size_t index_2 = 0;
			index_2 < argument.at(index_1).size();
			index_2++
		) {
			result.push_back(argument.at(index_1).at(index_2));
		}
	}

	return result;
}

void sort_index_vector( 
	std::vector<size_t>* index_vector_address,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	if (index_vector_address != nullptr) {
		

		std::vector<size_t> sorting_vector{};
	}
}

#endif