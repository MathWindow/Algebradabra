#pragma once
#include "ShortTypes.h"
#include "Counter.h"
using namespace std;

#ifndef commands_header
#define commands_header

cuint_16 command_exit = put_index_running(true, 1);
cuint_16 command_algebraic_book_create = put_index_running(false, 0);
cuint_16 command_open_bag_document = put_index_running(false, 0);
cuint_16 command_save_bag_document = put_index_running(false, 0);
cuint_16 command_save_bag_document_as = put_index_running(false, 0);
cuint_16 command_error_list = put_index_running(false, 0);
cuint_16 command_translate = put_index_running(false, 0);
cuint_16 command_what_new = put_index_running(false, 0);
cuint_16 command_about = put_index_running(false, 0);
cuint_16 command_1 = put_index_running(false, 0);

#endif