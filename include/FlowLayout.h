#pragma once

#include "common.h"

class FlowLayout
{
public:
    explicit FlowLayout(HWND window) : m_hwnd(window)
    {
        GetClientRect(window, &m_windowRect);

    }

    ~FlowLayout()
    = default;

public:
    void Add(HWND child)
    {
        children.emplace_back(child);
        Reposition();
    }

    void Reposition()
    {
        for (auto &child: children)
        {
            RECT rct;
            GetClientRect(child, &rct);
            auto width = GetWidth(rct);
            SetWindowPos(child, HWND_TOPMOST,60, 60, 0, 0, SWP_NOSIZE);
        }
    }

    int GetWidth(RECT rct)
    {
        return rct.right - rct.left;
    }

    int GetHeight(RECT rct)
    {
        return rct.bottom - rct.top;
    }

private:
    HWND m_hwnd;
    RECT m_windowRect = {0};
    std::vector<HWND> children;

};