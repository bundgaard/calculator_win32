#include "../include/common.h"
#include "../include/FlowLayout.h"
#include "../include/Window.h"


static FlowLayout *pFlowLayout = nullptr;

void dockControlToWidth(HWND parent, HWND child)
{

}

void OnCreate(HWND parent)
{
    int x = 51 * 3;
    int y = 51;
    HWND zero, one, two, three, four, five, six, seven, eight, nine, ten, comma;
    HWND plus, minus, multiply, divide, enter, negate;
    HWND mathExpression;
    /* A B C D
     *   / * - A
     * 7 8 9 + B
     * 4 5 6 E C
     * 1 2 3 E D
     * 0 0 , E
    * */

   mathExpression = Tool::CreateText(parent, 0, 0, 1);
    // 1st ROW
    divide = Tool::CreateButton(parent, L"/", x, y, 13);


    x = 0;
    y += 51;
    // 2nd ROW
    seven = Tool::CreateButton(parent, L"7", x, y, 7);
    x += 51;
    eight = Tool::CreateButton(parent, L"8", x, y, 8);
    x += 51;
    nine = Tool::CreateButton(parent, L"9", x, y, 9);
    x += 51;
    multiply = Tool::CreateButton(parent, L"*", x, y, 14);
    x = 0;
    y += 51;
    // 3rd ROW
    four = Tool::CreateButton(parent, L"4", x, y, 4);
    x += 51;
    five = Tool::CreateButton(parent, L"5", x, y, 5);
    x += 51;
    six = Tool::CreateButton(parent, L"6", x, y, 6);
    x += 51;
    minus = Tool::CreateButton(parent, L"-", x, y, 12);
    x = 0;
    y += 51;

    // 4th ROW
    one = Tool::CreateButton(parent, L"1", x, y, 1);
    x += 51;
    two = Tool::CreateButton(parent, L"2", x, y, 2);
    x += 51;
    three = Tool::CreateButton(parent, L"3", x, y, 3);
    x += 51;
    plus = Tool::CreateButton(parent, L"+", x, y, 11);
    x = 0;
    y += 51;

    // 5th ROW
    negate = Tool::CreateButton(parent, L"+/-", x, y, 16);
    x += 51;
    zero = Tool::CreateButton(parent, L"0", x, y, 0);
    x += 51;
    comma = Tool::CreateButton(parent, L",/.", x, y, 15);
    x += 51;
    enter = Tool::CreateButton(parent, L"=", x, y, 17);
    // BUTTONS




}

void OnSize(HWND hwnd)
{

}

void OnActivate(HWND hwnd)
{

}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_ACTIVATE:
            OnActivate(hwnd);
            break;
        case WM_CREATE:
        {
            OnCreate(hwnd);
        }
            break;
        case WM_SIZE:
        {
            OnSize(hwnd);
        }
            break;
        case WM_DESTROY:
        {
            DestroyWindow(hwnd);
            PostQuitMessage(0);
        }
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int main()
{
    Window main(L"Hello, World");


    InitCommonControls();

    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbWndExtra = 0;
    wc.cbClsExtra = 0;
    wc.hCursor = LoadCursor(nullptr, L"IDC_ARROW");
    wc.hIcon = LoadIcon(nullptr, L"IDI_APPLICATION");
    wc.hIconSm = LoadIcon(nullptr, L"IDI_ASTERISK");
    wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(COLOR_WINDOW+1));
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.lpfnWndProc = MainWndProc;
    wc.lpszClassName = lpszClassName;
    wc.lpszMenuName = nullptr;
    wc.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClassEx(&wc))
    {
        return 99;
    }


    HWND hwnd = CreateWindowEx(
            WS_EX_OVERLAPPEDWINDOW,
            lpszClassName,
            L"Regnemaskine",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            width, height,
            nullptr,
            nullptr,
            GetModuleHandleW(nullptr),
            nullptr);
    if (!hwnd)
    {
        return 98;
    }
    UpdateWindow(hwnd);
    ShowWindow(hwnd, SW_SHOW);


    pFlowLayout = new FlowLayout(hwnd);

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    delete pFlowLayout;
    return static_cast<int>(msg.wParam);
}
