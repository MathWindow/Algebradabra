#pragma once
#include <windows.h>
#include "CodeWork.h"
#include "Debugger.h"

#ifndef macro_header_menu
#define macro_header_menu

void line_element_menu(
	HMENU h_menu,
	macro_add_block_argument
) {
	macro_add_block_function(place_argument);

	debug::append_menu_w(h_menu, MF_SEPARATOR, NULL, NULL, place);
}

#endif