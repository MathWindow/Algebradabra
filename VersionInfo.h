#pragma once
#include <windows.h>
#include "StringWork.h"

#ifndef version_info_header
#define version_info_header

LPCWSTR program_version_family = L"May";
LPCWSTR program_version_above = L"v1.1";
LPCWSTR program_version_publication = L"38build";

LPCWSTR program_version = 
	string_work::string_union_multy(
		program_version_family, 
		L" ", 
		program_version_publication, 
		L" ", 
		program_version_above
	);

#endif