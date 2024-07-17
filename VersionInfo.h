#pragma once
#include <string>

#ifndef macro_header_version_info
#define macro_header_version_info

std::wstring program_version_family = L"May";
std::wstring program_version_above = L"v1.2";
std::wstring program_version_publication = L"12build";

std::wstring program_version =
	program_version_family
	+ L" "
	+ program_version_above
	+ L" "
	+ program_version_publication;

#endif