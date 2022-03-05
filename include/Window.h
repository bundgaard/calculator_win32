#pragma once

#include "common.h"

class Window
{
public:
    explicit Window(const std::wstring &title) : m_title(title)
    {
        DoRegisterClass();
        DoCreateWindow();

    }

    ~Window() = default;

public:
    virtual LRESULT OnMessage(UINT msg, WPARAM wParam, LPARAM lParam)
    {
        return 0;
    }

    bool DoCreateWindow()
    {
        HWND hwnd = CreateWindowEx(
                WS_EX_OVERLAPPEDWINDOW,
                lpszClassName,
                m_title.c_str(),
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT, CW_USEDEFAULT,
                width, height,
                nullptr,
                nullptr,
                GetModuleHandleW(nullptr),
                nullptr);
        if (!hwnd)
        {
            return false;
        }
        UpdateWindow(hwnd);
        ShowWindow(hwnd, SW_SHOW);
        return true;
    }

    bool DoRegisterClass()
    {
        InitCommonControls();

        WNDCLASSEX wc = {0};
        wc.cbSize = sizeof(WNDCLASSEX);
        wc.cbWndExtra = 0;
        wc.cbClsExtra = 0;
        wc.hCursor = LoadCursor(nullptr, L"IDC_ARROW");
        wc.hIcon = LoadIcon(nullptr, L"IDI_APPLICATION");
        wc.hIconSm = LoadIcon(nullptr, L"IDI_ASTERISK");
        wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(COLOR_WINDOW + 1));
        wc.hInstance = GetModuleHandleW(nullptr);
        wc.lpfnWndProc = WindowProc;
        wc.lpszClassName = lpszClassName;
        wc.lpszMenuName = nullptr;
        wc.style = CS_HREDRAW | CS_VREDRAW;

        if (!RegisterClassEx(&wc))
        {
            return false;
        }

        return true;
    }

private:


    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        Window *pWindow = nullptr;
        if (msg == WM_NCCREATE)
        {
            auto lpcreatestruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
            pWindow = static_cast<Window *>(lpcreatestruct->lpCreateParams);
            pWindow->m_hwnd = hwnd;
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));

        } else
        {
            pWindow = reinterpret_cast<Window *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        }

        if (pWindow != nullptr)
        {
            return pWindow->OnMessage(msg, wParam, lParam);
        }
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    HWND m_hwnd = nullptr;

    std::wstring m_title;
};