#pragma once
#include <string>

#ifndef macro_header_version_info
#define macro_header_version_info

std::wstring program_version_family = L"November";
std::wstring program_version_above = L"v1.3.1";
std::wstring program_version_publication = L"18build_f";

std::wstring program_version
	= program_version_family
	+ L" "
	+ program_version_above
	+ L" "
	+ program_version_publication;

#endif