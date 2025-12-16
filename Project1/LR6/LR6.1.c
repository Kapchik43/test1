#include "framework.h"
#include "LR6.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

int numImage = 0;

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LR6, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);


    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LR6));

    MSG msg;


    while (GetMessage(&msg, NULL,0,0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);


    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LR6));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LR6);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;


   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void Image1(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4] = {
        {cx, cy -20},
        {cx +20, cy +20},
        {cx -20, cy +20},
        {cx, cy -20}
    };

    Polyline(hdc, p, 4);
    DeleteObject(hPen);
}
void Image2(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4] = {
        {cx, cy - 20},
        {cx + 20, cy},
        {cx, cy + 20},
        {cx - 20, cy}
    };

    Polygon(hdc, p, 4);
    DeleteObject(hPen);
}
void Image3(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4] = {
        {cx -20, cy -20},
        {cx, cy +20},
        {cx +20, cy -20},
        {cx, cy}
    };

    Polygon(hdc, p, 4);
    DeleteObject(hPen);
}
void Image4(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID,2, color);
    SelectObject(hdc, hPen);

    POINT p[7] = {
        {cx -20, cy -20},
        {cx -20, cy +20},
        {cx -20, cy -20},
        {cx +20, cy -20},
        {cx, cy -10},
        {cx +20, cy},
        {cx -20, cy}
    };
    Polyline(hdc, p,7);

    DeleteObject(hPen);
}
void Image5(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[5] = {
		{cx, cy},
        {cx + 20, cy - 20},
        {cx +20, cy + 20},
        {cx - 20, cy + 20},
        {cx -20, cy -20}
    };

    Polygon(hdc, p, 5);
    DeleteObject(hPen);
}
void Image6(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[7] = {
        {cx, cy - 20},
        {cx + 10, cy},
        {cx + 20, cy - 20},
        {cx + 15, cy + 20},
        {cx - 15, cy + 20},
        {cx - 20, cy -20},
        {cx - 10, cy}
    };
    Polygon(hdc, p, 7);

    DeleteObject(hPen);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            switch (numImage) {
            case 0:
                Image1(hdc,40,40, RGB(255,0,0));
                Image1(hdc,140,40, RGB(0,255,0));
                Image1(hdc,240,40, RGB(0,0,255));
                Image1(hdc,240,240, RGB(255,255,0));
                Image1(hdc,40,240, RGB(255,0,255));
                break;
            case 1:
                Image2(hdc,40,40, RGB(255,0,0));
                Image2(hdc,140,40, RGB(0,255,0));
                Image2(hdc,240,40, RGB(0,0,255));
                Image2(hdc,240,240, RGB(255,255,0));
                Image2(hdc,40,240, RGB(255,0,255));
                break;
            case 2:
                Image3(hdc, 40, 40, RGB(255, 0, 0));
                Image3(hdc, 140, 40, RGB(0, 255, 0));
                Image3(hdc, 240, 40, RGB(0, 0, 255));
                Image3(hdc, 240, 240, RGB(255, 255, 0));
                Image3(hdc, 40, 240, RGB(255, 0, 255));
                break;
            case 3:
                Image4(hdc, 40, 40, RGB(255, 0, 0));
                Image4(hdc, 140, 40, RGB(0, 255, 0));
                Image4(hdc, 240, 40, RGB(0, 0, 255));
                Image4(hdc, 240, 240, RGB(255, 255, 0));
                Image4(hdc, 40, 240, RGB(255, 0, 255));
                break;
            case 4:
                Image5(hdc, 40, 40, RGB(255, 0, 0));
                Image5(hdc, 140, 40, RGB(0, 255, 0));
                Image5(hdc, 240, 40, RGB(0, 0, 255));
                Image5(hdc, 240, 240, RGB(255, 255, 0));
                Image5(hdc, 40, 240, RGB(255, 0, 255));
                break;
            case 5:
                Image6(hdc, 40, 40, RGB(255, 0, 0));
                Image6(hdc, 140, 40, RGB(0, 255, 0));
                Image6(hdc, 240, 40, RGB(0, 0, 255));
                Image6(hdc, 240, 240, RGB(255, 255, 0));
                Image6(hdc, 40, 240, RGB(255, 0, 255));
                break;
            }

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        if (wParam == VK_SPACE) {
            numImage = (numImage +1) %6;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
