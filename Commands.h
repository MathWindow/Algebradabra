#pragma once
#include <minwindef.h>
#include "Counter.h"

#ifndef macro_header_commands
#define macro_header_commands

using command_type = WPARAM;

// For main window
// ��� �������� ����

command_type command_exit = put_index_counter<command_type>(1);

command_type command_create_book = put_index_counter<command_type>(continue_counting);
command_type command_save_book = put_index_counter<command_type>(continue_counting);
command_type command_save_book_as = put_index_counter<command_type>(continue_counting);
command_type command_open_book = put_index_counter<command_type>(continue_counting);

command_type command_translate_Russian = put_index_counter<command_type>(continue_counting);
command_type command_translate_English = put_index_counter<command_type>(continue_counting);

command_type command_what_is_new = put_index_counter<command_type>(continue_counting);

command_type command_debugger = put_index_counter<command_type>(continue_counting);

command_type command_about = put_index_counter<command_type>(continue_counting);

command_type command_save_file_as = put_index_counter<command_type>(continue_counting);
command_type command_open_file = put_index_counter<command_type>(continue_counting);
command_type command_choose_color = put_index_counter<command_type>(continue_counting);
command_type command_testing_dialog_window = put_index_counter<command_type>(continue_counting);

command_type command_reopen_window = put_index_counter<command_type>(continue_counting);

command_type command_the_last_value = put_index_counter<command_type>(no_counting);

#endif