#pragma once
#include "ShortTypes.h"
#include "Counter.h"

#ifndef commands_header
#define commands_header

svt::cu_short command_exit = put_index_running(true, 1);

svt::cu_short command_save_algebraic_book = put_index_running(false);
svt::cu_short command_save_algebraic_book_as = put_index_running(false);
svt::cu_short command_open_algebraic_book = put_index_running(false);

svt::cu_short command_translate_Russian = put_index_running(false);
svt::cu_short command_translate_English = put_index_running(false);

svt::cu_short command_whats_new = put_index_running(false);

svt::cu_short command_about = put_index_running(false);

svt::cu_short command_save_file_as = put_index_running(false);
svt::cu_short command_open_file = put_index_running(false);
svt::cu_short command_choose_color = put_index_running(false);
svt::cu_short command_testing_dialog_window = put_index_running(false);

#endif