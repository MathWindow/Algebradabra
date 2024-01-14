#pragma once
#include <windows.h>
#include "StringWork.h"

#ifndef naming_header
#define naming_header

#define turn_macro_off 1

#if turn_macro_off == 0

#define program_version_abovepublic L"v1.1"
#define program_version_publication L"29build"
#define program_version_family L"May"
#define program_version program_version_family L" " program_version_publication L" " program_version_abovepublic

#else

LPCWSTR program_version_abovepublic = L"v1.1";
LPCWSTR program_version_publication = L"29build";
LPCWSTR program_version_family = L"May";
LPCWSTR program_version = string_work::string_union_multy(program_version_family, L" ", program_version_publication, L" ", program_version_abovepublic);

#endif

#endif