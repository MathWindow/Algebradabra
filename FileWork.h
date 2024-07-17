#pragma once
#include <Windows.h>
#include <fileapi.h>
#include <string>

void create_file(
	LPCWSTR path
) {
	HANDLE handle = CreateFileW(
		path,
		GENERIC_WRITE,
		NULL,
		NULL,
		CREATE_NEW,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	DWORD size = 0;

	std::wstring text = L"\tProgram will be graphic calculator.";

	WriteFile(
		handle, 
		text.c_str(), 
		text.size(), 
		&size, 
		NULL
	);
}