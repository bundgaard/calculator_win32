#pragma once

// Windows
#include <Windows.h>
#include <CommCtrl.h>
// Std
#include <iostream>
#include <string>
#include <vector>

#include "Tool.h"


#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")


constexpr wchar_t lpszClassName[] = L"Tretton63Calc";

constexpr int width = 512;
constexpr int height = 512;

constexpr int columns = width / 4;
constexpr int rows = height / 5;


