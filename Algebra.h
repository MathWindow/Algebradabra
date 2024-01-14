#pragma once
#include <windows.h>
#include <cmath>
#include "Counter.h"
#include "AssociationType.h"
#include <complex>
#include <array>
#include <vector>

#ifndef algebra_header
#define algebra_header

namespace math_algebra {


	class variable {
	public:
		bool known = false;
		double value = 0;
		double exponentiation = 0;
	};

	class equation_class {
	public:
		variable x;
		variable y;
		LPCWSTR string = L"xx*x^{2}x=yy^{3}y\0";
		
		void analyze() {
			bool begin_exponentiation = false;

			variable pseudo_variable;
			variable* variable_pointer = &pseudo_variable;

			for (u_int index = 0; *(string + index) != L'\0'; index++) {
				switch (*(string + index)) {
				case L'x':
					(*variable_pointer).exponentiation += 0;

					variable_pointer = &x;
					break;
				case L'y':
					variable_pointer = &y;
					break;
				case L'^':
					begin_exponentiation = true;
					break;
				case L'{':
					if (begin_exponentiation) {
						
					}
					break;
				}
			}
		}
	};
}

#endif