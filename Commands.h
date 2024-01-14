#pragma once
#include "ShortTypes.h"
#include "Counter.h"
using namespace std;

#ifndef commands_header
#define commands_header

cu_short command_exit = put_index_running(true, 1);

cu_short command_create_algebraic_book = put_index_running(false);
cu_short command_save_algebraic_book = put_index_running(false);
cu_short command_save_algebraic_book_as = put_index_running(false);
cu_short command_open_algebraic_book = put_index_running(false);

cu_short command_create_page = put_index_running(false);

cu_short command_error_list = put_index_running(false);

cu_short command_translate_Russian = put_index_running(false);
cu_short command_translate_English = put_index_running(false);

cu_short command_whats_new = put_index_running(false);

cu_short command_about = put_index_running(false);

cu_short command_save_file_as = put_index_running(false);
cu_short command_open_file = put_index_running(false);
cu_short command_choose_color = put_index_running(false);

#endif