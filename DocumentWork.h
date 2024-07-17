#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include "CodeWork.h"
#include "ShortTypes.h"
#include "Translate.h"
#include "Counter.h"
#include "Commands.h"

using shape_form_index = u_char_;
using c_shape_form_index = const shape_form_index;

c_shape_form_index shape_form_none
	= put_index_counter<shape_form_index>(0);
c_shape_form_index shape_form_solid
	= put_index_counter<shape_form_index>(continue_counting);
c_shape_form_index shape_form_points
	= put_index_counter<shape_form_index>(continue_counting);

class expression_document {
public:
	std::wstring string = L"";

	HBRUSH color = CreateSolidBrush(RGB(0, 0, 0));
	shape_form_index shape_form = shape_form_none;

	command_type command = 0;
};

using page_type_index = u_char_;
using c_page_type_index = const page_type_index;

c_page_type_index page_type_none
	= put_index_counter<page_type_index>(0);
c_page_type_index page_type_first
	= put_index_counter<page_type_index>(no_counting);
c_page_type_index page_type_calculator
	= put_index_counter<page_type_index>(continue_counting);
c_page_type_index page_type_coordinate
	= put_index_counter<page_type_index>(continue_counting);
c_page_type_index page_type_circuit
	= put_index_counter<page_type_index>(continue_counting);
c_page_type_index page_type_text
	= put_index_counter<page_type_index>(continue_counting);
c_page_type_index page_type_picture
	= put_index_counter<page_type_index>(continue_counting);
c_page_type_index page_type_last
	= put_index_counter<page_type_index>(no_counting);

translate::string convert_page_type_index_to_string(
	page_type_index argument,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	if (argument == page_type_calculator) {
		return translate::string__calculator;
	}
	else if (argument == page_type_coordinate) {
		return translate::string__coordinate;
	}
	else if (argument == page_type_circuit) {
		return translate::string__circuit;
	}
	else if (argument == page_type_text) {
		return translate::string__text;
	}
	else if (argument == page_type_picture) {
		return translate::string__picture;
	}

	return translate::string__none;
}

class page {
public:
	page_type_index type = page_type_none;

	std::vector<expression_document> expression_vector{};
};

class book {
public:
	u_int_ code_cipher = 0;

	std::vector<page> page_vector{};
};

std::vector<book> book_vector{};