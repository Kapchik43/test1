#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"
#include "LR9.2.h"
#include <cstdio>
#include <cstring>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LR92, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LR92));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LR92));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LR92);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//

int displayMode = 1;
int totalModes = 13;
int counter = 0;

void Image1(HDC hdc, int cx, int cy, int size) {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, hPen);

	MoveToEx(hdc, cx, cy + size, NULL);
	LineTo(hdc, cx + size, cy - size);
	LineTo(hdc, cx - size, cy - size);
	LineTo(hdc, cx, cy + size);

	counter++;
	char strC[10];
	sprintf(strC, "%d", counter);
	
	TextOutA(hdc, cx - 5, cy - 10, strC, strlen(strC));

	DeleteObject(hPen);
}

void Function1_1(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	Function1_1(hdc, cx - size, cy - size, size / 2);
	Function1_1(hdc, cx + size, cy - size, size / 2);
}

void Function1_2(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	Function1_2(hdc, cx, cy + size, size / 2);
	Function1_2(hdc, cx - size, cy - size, size / 2);
}

void Function1_3(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	Function1_3(hdc, cx, cy + size, size / 2);
	Function1_3(hdc, cx - size, cy - size, size / 2);
	Function1_3(hdc, cx + size, cy - size, size / 2);
}

void Image2(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size / 2;
    int y1 = cy - size;
    int x2 = cx + size / 2;
    int y2 = cy - size;
    int x3 = cx - size;
    int y3 = cy + size;
    int x4 = cx + size;
    int y4 = cy + size;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void Function2_1(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    Function2_1(hdc, cx - size / 2, cy - size, size / 2);
}
void Function2_2(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    Function2_2(hdc, cx - size / 2, cy - size, size / 2);
    Function2_2(hdc, cx + size / 2, cy - size, size / 2);
}
void Function2_3(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    Function2_3(hdc, cx - size / 2, cy - size, size / 2);
    Function2_3(hdc, cx - size, cy + size, size / 2);
	Function2_3(hdc, cx + size / 2, cy - size, size / 2);
	Function2_3(hdc, cx + size, cy + size, size / 2);

}

void Image3(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy - size;
    int x2 = cx + size;
    int y2 = cy;
    int x3 = cx;
    int y3 = cy + size;
    int x4 = cx - size;
    int y4 = cy;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void Function3_1(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    Function3_1(hdc, cx + size, cy, size / 2);
	Function3_1(hdc, cx - size, cy, size / 2);
}
void Function3_2(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    Function3_2(hdc, cx + size, cy, size / 2);
    Function3_2(hdc, cx - size, cy, size / 2);
    Function3_2(hdc, cx, cy + size, size / 2);
}
void Function3_3(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    Function3_3(hdc, cx + size, cy, size / 2);
    Function3_3(hdc, cx - size, cy, size / 2);
    Function3_3(hdc, cx, cy - size, size / 2);
}
void Function3_4(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    Function3_4(hdc, cx + size, cy, size / 2);
    Function3_4(hdc, cx - size, cy, size / 2);
    Function3_4(hdc, cx, cy + size, size / 2);
    Function3_4(hdc, cx, cy - size, size / 2);
}

void Image4(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy - size;

    int x2 = cx + size / 4;
    int y2 = cy - size / 4;

    int x3 = cx + size;
    int y3 = cy;

    int x4 = cx + size / 4;
    int y4 = cy + size / 4;

    int x5 = cx;
    int y5 = cy + size;

    int x6 = cx - size / 4;
    int y6 = cy + size / 4;

    int x7 = cx - size;
    int y7 = cy;

    int x8 = cx - size / 4;
    int y8 = cy - size / 4;

    int r_g = 0, g_g = 0, b_g = 255;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(r_g, g_g, b_g));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x7, y7);
    LineTo(hdc, x8, y8);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}

void Function4_1(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    Function4_1(hdc, cx + size, cy, size / 2);
    Function4_1(hdc, cx - size, cy, size / 2);
}
void Function4_2(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    Function4_2(hdc, cx, cy + size, size / 2);
    Function4_2(hdc, cx, cy - size, size / 2);
}
void Function4_3(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    Function4_3(hdc, cx, cy + size, size / 2);
    Function4_3(hdc, cx, cy - size, size / 2);
	Function4_3(hdc, cx - size, cy, size / 2);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
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

			counter = 0;

            switch (displayMode) {
            case 1:
                Function1_1(hdc, 400, 360, 80);
                break;
            case 2:
                Function1_2(hdc, 400, 360, 80);
                break;
            case 3:
                Function1_3(hdc, 400, 360, 80);
                break;
            case 4:
                Function2_1(hdc, 400, 360, 80);
				break;
            case 5:
				Function2_2(hdc, 400, 360, 80);
				break;
			case 6:
				Function2_3(hdc, 400, 360, 80);
				break;
			case 7:
				Function3_1(hdc, 400, 360, 80);
				break;
			case 8:
				Function3_2(hdc, 400, 360, 80);
				break;
			case 9:
				Function3_3(hdc, 400, 360, 80);
				break;
            case 10:
				Function3_4(hdc, 400, 360, 80);
				break;
            case 11:
                Function4_1(hdc, 400, 360, 80);
				break;
			case 12:
				Function4_2(hdc, 400, 360, 80);
				break;
			case 13:
				Function4_3(hdc, 400, 360, 80);
				break;
            }

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        {
            displayMode++;
            if (displayMode > totalModes) {
                displayMode = 1;
            }
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

// Обработчик сообщений для окна "О программе".
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
