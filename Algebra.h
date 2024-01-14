#pragma once
#include <windows.h>
#include <cmath>
#include "Counter.h"
#include "AssociationType.h"
#include <complex>
#include <array>
#include <vector>
using namespace std;

#ifndef algebra_header
#define algebra_header

namespace m_alg_old {
	struct uint_128 {
		u_long_2 forward;
		u_long_2 back;

		uint_128 operator + (uint_128 right_value) {

		};
	};

	using cuint_128 = const uint_128;

#define prime_table_max_size 256

	class number_list {
	public:
		array <u_long, prime_table_max_size> number{};

		bool created = false;

		void create() {
			if (!created) {
				number.at(0) = 2;

				u_long value_helper = 3;

				bool may_printed = false;

				for (
					u_short index_fulling_number = 1;
					index_fulling_number < prime_table_max_size;
					index_fulling_number++
				) {

					while (!may_printed) {
						may_printed = true;

						for (
							u_short index_preview_number = 0;
							index_preview_number < index_fulling_number;
							index_preview_number++
						) {

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

	number_list main_prime_list;

	bool is_prime(u_long number_input) {
		main_prime_list.create();

		u_short index_running = 0;

		for (
			index_running = 0;
			main_prime_list.number.at(index_running) < number_input;
			index_running++
		);

		return
			main_prime_list.number.at(index_running) == number_input;
	}

	c_alg_oper_param no_operation = put_index_running(true);
	c_alg_oper_param summation = put_index_running(false);
	c_alg_oper_param subtraction = put_index_running(false);
	c_alg_oper_param multiplication = put_index_running(false);
	c_alg_oper_param division = put_index_running(false);
	c_alg_oper_param logarithm = put_index_running(false);
	c_alg_oper_param exponentiation = put_index_running(false);
	c_alg_oper_param root = put_index_running(false);
	c_alg_oper_param sine_function = put_index_running(false);
	c_alg_oper_param cosine_function = put_index_running(false);

	struct mononomial {
		vector<wchar_t> variable{};
		complex<double> coefficient = 1;
	};

	struct operation_information {
		alg_oper_param operation_type = no_operation;
		vector<mononomial> mononomial_list{};
	};

	c_alg_string_bool_param has_imaginary = 0b0001 << put_index_running(true);
	c_alg_string_bool_param has_real = 0b0001 << put_index_running(false);
	c_alg_string_bool_param may_split_by_zero = 0b0001 << put_index_running(false);
	c_alg_string_bool_param splits_by_zero = 0b0001 << put_index_running(false);
	c_alg_string_bool_param square_root_of_negative = 0b0001 << put_index_running(false);

	void algebraic_string_analyze(
		LPCWSTR string_input,
		alg_string_bool_param* parameter_output
	) {
		vector<operation_information> operation_list{};

		for (
			u_short index_running = 0;
			*(string_input + index_running) != 0;
			index_running++
		) {

		}
	}

	c_alg_action_param no_action = put_index_running(true);
	c_alg_action_param ease_string = put_index_running(false);
	c_alg_action_param polynomial = put_index_running(false);
	c_alg_action_param turn_to_standard = put_index_running(false);
	c_alg_action_param find_variable = put_index_running(false);
	c_alg_action_param draw_graphic = put_index_running(false);

	void algebraic_string_work(
		LPCWSTR string_input,
		LPCWSTR string_output,
		alg_action_param action,
		wchar_t finding_variable = L'\0',
		alg_string_bool_param* string_parameter_output
	) {
		algebraic_string_analyze(
			string_input,
			string_parameter_output
		);
	}
}

namespace m_alg {

}

#endif