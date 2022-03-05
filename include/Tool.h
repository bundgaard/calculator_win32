#pragma once


#include "common.h"


class Tool
{
public:

    static HWND CreateText(HWND parent, int x, int y, int id)
    {
        // https://docs.microsoft.com/en-us/windows/win32/uxguide/ctrl-text-boxes
        return CreateWindow(
                L"Edit",
                L"",
                WS_CHILD |
                WS_VISIBLE |
                WS_BORDER |
                ES_CENTER |
                ES_AUTOHSCROLL,
                x,
                y,
                100,
                25,
                parent,
                (HMENU) 13251 + id,
                GetModuleHandleW(nullptr), nullptr);
    }

    static HWND CreateButton(HWND parent, const std::wstring &title, int x, int y, int id)
    {
        return CreateWindow(L"Button", title.c_str(), WS_CHILD | WS_VISIBLE,
                            x,
                            y,
                            50,
                            50,
                            parent,
                            (HMENU) 13151 + id,
                            GetModuleHandleW(nullptr), nullptr);
    }

};