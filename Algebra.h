#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include "StringWork.h"
#include "CodeWork.h"
#include "Debugger.h"

namespace algebra {
	class fraction {
	public:
		int number = 0;
		int splitter = 1;

		void check_splitter(
			bool* math_mistake,
			macro_add_block_argument
		) {
			macro_add_block_function(place);

			if (splitter == 0)
				*math_mistake = true;
		}

		void make_simple(
			bool* math_mistake,
			macro_add_block_argument
		) {
			macro_add_block_function(place_argument);

			bool math_mistake_ = false;

			if (math_mistake == nullptr) {
				math_mistake = &math_mistake_;
			}

			check_splitter(
				math_mistake,
				place
			);

			if (!*math_mistake) {
				int index = 2;

				while (index < number && index < splitter) {
					if (abs(number) % index == 0 && abs(splitter) % index == 0) {
						number /= index;
						splitter /= index;
					}
					else {
						index++;
					}
				}
			}
		}

		double convert_to_double(
			bool* math_mistake,
			macro_add_block_argument
		) {
			macro_add_block_function(place_argument);

			bool boolean_was_not_pointed = false;

			bool math_mistake_ = false;

			if (math_mistake == nullptr) {
				boolean_was_not_pointed = true;

				math_mistake = &math_mistake_;
			}

			check_splitter(
				math_mistake,
				place
			);

			if (!*math_mistake) {
				return (double)number / (double)splitter;
			}
			else if (boolean_was_not_pointed) {
#if turn_debugger_on
				debug::write_event(
					debug::title_split_by_zero,
					place,
					nullptr,
					0,
					L""
				);
#endif
			}

			return 0;
		}

		void operator +=(fraction argument) {
			fraction result{};

			result.splitter = splitter * argument.splitter;

			result.number 
				= number * argument.splitter 
				+ splitter * argument.number;

			*this = result;
		}

		void operator *=(fraction argument) {
			number *= argument.number;
			splitter *= argument.splitter;
		}

		void operator /=(fraction argument) {
			splitter *= argument.number;
			number *= argument.splitter;
		}
	};

	class variable {
	public:
		wchar_t letter = 0;
		fraction value{};
	};

	std::vector<variable> variable_list{
		{L'a', {}},
		{L'b', {}},
		{L'c', {}},
		{L'd', {}},
		{L'f', {}},
		{L'g', {}},
		{L'h', {}},
		{L'j', {}},
		{L'k', {}},
		{L'l', {}},
		{L'm', {}},
		{L'n', {}},
		{L'o', {}},
		{L'p', {}},
		{L'q', {}},
		{L'r', {}},
		{L's', {}},
		{L't', {}},
		{L'u', {}},
		{L'v', {}},
		{L'w', {}},
		{L'x', {}},
		{L'y', {}},
		{L'z', {}},
	};

	variable* get_pointer_of_variable_from_letter(
		wchar_t argument,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);

		for (
			size_t index_vector = 0;
			index_vector < variable_list.size();
			index_vector++
		) {
			if (argument == variable_list.at(index_vector).letter) {
				return &variable_list.at(index_vector);
			}
		}

		return nullptr;
	}

	class monomial {
	public:
		std::vector<variable*> variable_vector{};

		fraction coefficient{};

		bool there_is_finding_variable = false;
		bool this_monomial_has_minus_sign = false;
		bool after_equal_sign = false;
		bool number_was_pointed = false;

		void clear(
			macro_add_block_argument
		) {
			macro_add_block_function(place_argument);

			variable_vector.clear();

			coefficient.number = 0;
			coefficient.splitter = 1;

			there_is_finding_variable = false;
			this_monomial_has_minus_sign = false;
			after_equal_sign = false;
			number_was_pointed = false;
		}

		fraction calculate(
			bool* math_mistake,
			macro_add_block_argument
		) {
			macro_add_block_function(place_argument);

			fraction result{1, 1};

			for (
				size_t index_vector = 0;
				index_vector < variable_vector.size();
				index_vector++
			) {
				variable_vector.at(index_vector)->value.check_splitter(
					math_mistake,
					place
				);

				result 
					*= variable_vector.at(index_vector)->value;
			}

			result *= coefficient;

			return result;
		}
	};

	class polynomial {
	public:
		std::vector<monomial> monomial_table{};

		void add(
			monomial argument,
			macro_add_block_argument
		) {
			macro_add_block_function(place_argument);

			if (!argument.number_was_pointed) {
				argument.coefficient.number
					= argument.variable_vector.size() == 0
					&& !argument.there_is_finding_variable
					? 0
					: 1;
			}

			if (argument.this_monomial_has_minus_sign) {
				argument.coefficient.number *= -1;
			}

			if (argument.there_is_finding_variable) {
				argument.coefficient.number *= -1;
			}

			if (argument.after_equal_sign) {
				argument.coefficient.number *= -1;
			}

			bool this_monomial_is_here = false;

			for (
				size_t index_vector = 0;
				index_vector < monomial_table.size();
				index_vector++
			) {
				if (
					argument.variable_vector 
					== monomial_table.at(index_vector).variable_vector
				) {
					this_monomial_is_here = true;

					monomial_table.at(index_vector).coefficient += argument.coefficient;

					index_vector = monomial_table.size();
				}
			}

			if (!this_monomial_is_here) {
				monomial_table.push_back(argument);
			}
		}

		fraction calculate( 
			bool* math_mistake,
			macro_add_block_argument
		) {
			macro_add_block_function(place_argument);

			fraction result{};

			for (
				size_t index_vector = 0;
				index_vector < monomial_table.size();
				index_vector++
			) {
				result += monomial_table.at(index_vector).calculate(
					math_mistake,
					place
				);
			}

			return result;
		}
	};

	class function {
	public:
		polynomial polynomial_number{};
		polynomial polynomial_splitter{};

		variable* finding_variable = nullptr;
		variable* variable_as_argument = nullptr;

		void find_variable(
			bool* math_mistake,
			macro_add_block_argument
		) {
			macro_add_block_function(place_argument);

			fraction fraction_polynomial_number = polynomial_number.calculate(
				math_mistake,
				place
			);

			fraction fraction_polynomial_splitter = polynomial_splitter.calculate(
				math_mistake,
				place
			);

			finding_variable->value.number
				= fraction_polynomial_number.number
				* fraction_polynomial_splitter.splitter;

			finding_variable->value.splitter
				= fraction_polynomial_number.splitter
				* fraction_polynomial_splitter.number;
		}
	};

	using formula = function;

	formula find_variable_from_equation(
		std::wstring equation_string,
		variable* finding_variable,
		variable* variable_as_argument,
		bool* math_mistake,
		macro_add_block_argument
	) {
		macro_add_block_function(place_argument);
		
		formula result{};

		monomial monomial_this{};

		bool after_equal_sign = false;

		equation_string += L' ';

		for (
			size_t index_symbol = 0;
			index_symbol < equation_string.size();
			index_symbol++
		) {
			size_t index_past = index_symbol;

			int number_this = convert_string_to_number<int>(
				equation_string, 
				&index_symbol
			);
			
			if (index_symbol != index_past) {
				monomial_this.coefficient.number = number_this;

				monomial_this.number_was_pointed = true;
			}

			if (index_symbol < equation_string.size()) {
				if (
					(
						equation_string.at(index_symbol) == L'.'
						|| equation_string.at(index_symbol) == L','
					)
					&& index_symbol != index_past
				) {
					index_symbol++;

					fraction tail{};

					size_t index_past_ = index_symbol;

					tail.number = convert_string_to_number<int>(
						equation_string,
						&index_symbol
					);

					tail.splitter = pow(10, index_symbol - index_past_);

					monomial_this.coefficient += tail;
				}
			}

			if (index_symbol < equation_string.size()) {
				if (
					equation_string.at(index_symbol) == L'+'
					|| equation_string.at(index_symbol) == L'-'
					|| equation_string.at(index_symbol) == L'='
					|| (
						equation_string.at(index_symbol) == L' '
						&& index_symbol + 1 == equation_string.size()
					)
				) {
					monomial_this.coefficient.make_simple(
						math_mistake,
						place
					);

					if (monomial_this.there_is_finding_variable)
						result.polynomial_splitter.add(monomial_this, place);
					else
						result.polynomial_number.add(monomial_this, place);

					monomial_this.clear(place);

					if (equation_string.at(index_symbol) == L'-')
						monomial_this.this_monomial_has_minus_sign = true;
					else if (equation_string.at(index_symbol) == L'=')
						after_equal_sign = true;

					monomial_this.after_equal_sign = after_equal_sign;
				}
				else {
					for (
						size_t index_vector = 0;
						index_vector < variable_list.size();
						index_vector++
					) {
						if (equation_string.at(index_symbol) == (*finding_variable).letter) {
							monomial_this.there_is_finding_variable = true;
						}
						else if (equation_string.at(index_symbol) == variable_list.at(index_vector).letter) {
							monomial_this.variable_vector.push_back(&variable_list.at(index_vector));

							index_vector = variable_list.size();
						}
					}
				}
			}
		}

		result.finding_variable = finding_variable;
		result.variable_as_argument = variable_as_argument;

		return result;
	}
}