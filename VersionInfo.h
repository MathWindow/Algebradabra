#pragma once
#include <windows.h>
#include "StringWork.h"

#ifndef naming_header
#define naming_header

#define turn_macro_off 0

#if turn_macro_off == 0

#define program_version_abovepublic L"v1.1"
#define program_version_publication L"28build"
#define program_version_family L"May"
#define program_version program_version_family L" " program_version_publication L" " program_version_abovepublic

#else

LPCWSTR program_name = L"Algebradabra";
LPCWSTR program_verstion_abovepublic = L"v1.1"
LPCWSTR program_version_publication = L"";
LPCWSTR program_version_family = L"May";
LPCWSTR program_version = string_union_x(program_version_family, L" ", program_version_publication, L" ", program_version_abovepublic);

#endif

#endif