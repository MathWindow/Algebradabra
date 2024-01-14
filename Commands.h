#pragma once
#include "ShortTypes.h"
#include "Counter.h"
using namespace std;

#ifndef commands_header
#define commands_header

cushort command_exit = put_index_running(true, 1);
cushort command_algebraic_book_create = put_index_running(false);
cushort command_open_bag_document = put_index_running(false);
cushort command_save_bag_document = put_index_running(false);
cushort command_save_bag_document_as = put_index_running(false);
cushort command_error_list = put_index_running(false);
cushort command_translate_Russian = put_index_running(false);
cushort command_translate_English = put_index_running(false);
cushort command_what_new = put_index_running(false);
cushort command_about = put_index_running(false);
cushort command_OFN = put_index_running(false);

#endif