#pragma once
#include "Counter.h"
#include <minwindef.h>

#ifndef macro_header_commands
#define macro_header_commands

WPARAM command_exit = put_index_counter<WPARAM>(1);

WPARAM command_save_algebraic_book = put_index_counter<WPARAM>(continue_counting);
WPARAM command_save_algebraic_book_as = put_index_counter<WPARAM>(continue_counting);
WPARAM command_open_algebraic_book = put_index_counter<WPARAM>(continue_counting);

WPARAM command_translate_Russian = put_index_counter<WPARAM>(continue_counting);
WPARAM command_translate_English = put_index_counter<WPARAM>(continue_counting);

WPARAM command_whats_new = put_index_counter<WPARAM>(continue_counting);

WPARAM command_about = put_index_counter<WPARAM>(continue_counting);

WPARAM command_save_file_as = put_index_counter<WPARAM>(continue_counting);
WPARAM command_open_file = put_index_counter<WPARAM>(continue_counting);
WPARAM command_choose_color = put_index_counter<WPARAM>(continue_counting);
WPARAM command_testing_dialog_window = put_index_counter<WPARAM>(continue_counting);

#endif