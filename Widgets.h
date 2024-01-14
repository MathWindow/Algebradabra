#pragma once
#include <windows.h>
#include "Edit.h"

void create_widgets(HWND h_window) {
	edit1 = create_edit(TEXT("¬ведите выражение"), 10, 10, 150, 20, h_window, NULL, WS_BORDER | ES_AUTOHSCROLL);
	//edit2 = create_edit(TEXT("¬ведите выражение"), 10, 30, 150, 20, h_window, NULL, WS_BORDER | ES_AUTOHSCROLL);
}