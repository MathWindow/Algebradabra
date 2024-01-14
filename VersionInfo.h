#pragma once
#include <string>

#ifndef version_info_header
#define version_info_header

std::wstring program_version_family = L"May";
std::wstring program_version_above = L"v1.1";
std::wstring program_version_publication = L"65build";

std::wstring program_version =
	program_version_family
	+ L" "
	+ program_version_above
	+ L" "
	+ program_version_publication;

#endif