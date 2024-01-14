#pragma once
#include "ShortTypes.h"
#include "Counter.h"
using namespace std;

#ifndef commands_header
#define commands_header

cu_short command_exit = put_index_running(true, 1);
cu_short command_algebraic_book_create = put_index_running(false);
cu_short command_open_bag_document = put_index_running(false);
cu_short command_save_bag_document = put_index_running(false);
cu_short command_save_bag_document_as = put_index_running(false);
cu_short command_error_list = put_index_running(false);
cu_short command_translate_Russian = put_index_running(false);
cu_short command_translate_English = put_index_running(false);
cu_short command_what_new = put_index_running(false);
cu_short command_about = put_index_running(false);
cu_short command_save_algebraic_book = put_index_running(false);
cu_short command_save_algebraic_book_as = put_index_running(false);
cu_short command_open_algebraic_book = put_index_running(false);

#endif