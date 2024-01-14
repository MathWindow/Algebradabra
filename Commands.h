#pragma once
#include <array>
using namespace std;

#define command_exit 1
#define command_new_bag_document 2
#define command_open_bag_doucument 3
#define command_save_bag_document 4
#define command_save_bag_document_as 5

class command {
public:
	array <wchar_t, 50> command_name = { L"No name" };
	int command_number = 0;
};