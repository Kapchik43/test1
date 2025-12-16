// LR6.2.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "LR6.2.h"

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
    LoadStringW(hInstance, IDC_LR62, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LR62));

    MSG msg;

    // Цикл основного сообщения:
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LR62));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LR62);
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
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

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



                        //ЛАБОРТАНОРНАЯ РАБОТА 6.2, 6.3


// Перечисление, описывающее возможные режимы
enum Modes {
    START,   // старт
    GAME,    // игра
    FINAL    // Завершение!
};

// Глобальная переменная, хранящая режим
enum Modes mode = START;

struct Image {
    int x;  // координата X
    int y;  // координата Y
    int vx; // изменение координаты X = скорость по X
    int vy; // изменение координаты Y = скорость по Y​
    COLORREF color; // цвет фигуры​
};
typedef struct Image IMAGE;

#define MAX_LIFES 10
#define COLOR_PER_LIFE (255 / MAX_LIFES)
int prey_lifes = MAX_LIFES;

IMAGE hunter = { 100, 100, 0, 0 , RGB(0, 0, 200) };
IMAGE prey = { 300, 300, 0, 0 , RGB(0, 255, 0) };

void Image1(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[4] = {
        {cx, cy - 20},
        {cx + 20, cy + 20},
        {cx - 20, cy + 20},
        {cx, cy - 20}
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
        {cx - 20, cy - 20},
        {cx, cy + 20},
        {cx + 20, cy - 20},
        {cx, cy}
    };

    Polygon(hdc, p, 4);
    DeleteObject(hPen);
}
void Image4(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[7] = {
        {cx - 20, cy - 20},
        {cx - 20, cy + 20},
        {cx - 20, cy - 20},
        {cx + 20, cy - 20},
        {cx, cy - 10},
        {cx + 20, cy},
        {cx - 20, cy}
    };
    Polyline(hdc, p, 7);

    DeleteObject(hPen);
}
void Image5(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[5] = {
        {cx, cy},
        {cx + 20, cy - 20},
        {cx + 20, cy + 20},
        {cx - 20, cy + 20},
        {cx - 20, cy - 20}
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
        {cx - 20, cy - 20},
        {cx - 10, cy}
    };
    Polygon(hdc, p, 7);

    DeleteObject(hPen);
}

//GAME
void DrawGame(HDC hdc) {
    Image6(hdc, hunter.x, hunter.y, hunter.color);

    int rest_lifes = MAX_LIFES - prey_lifes;
    int color = COLOR_PER_LIFE * rest_lifes;

    Image5(hdc, prey.x, prey.y, RGB(color, 255, color));
}
void MoveGameElements() {
    hunter.x += hunter.vx;
    hunter.y += hunter.vy;
    prey.x += prey.vx;
    prey.y += prey.vy;
}
int ImagesAreClose() {
    // если фигуры сблизились достаточно
    if (hunter.x + 20 > prey.x && hunter.x - 20 < prey.x &&
        hunter.y + 20 > prey.y && hunter.y - 20 < prey.y)
        return 1;
    else
        return 0;
}
void ChangeDirection() {
    prey.vx = rand() % 11 - 5;   // (rand() % 6 + 2) дает числа от 2 до 7
    prey.vy = rand() % 6;  // (rand() % 11 - 5) дает числа от -5 до 5
}

//START
void Picture1(HDC hdc) {
    Image1(hdc, 20, 20, RGB(255, 255, 128));
    Image1(hdc, 120, 20, RGB(0xCC, 0, 0xCC));
    Image1(hdc, 20, 120, RGB(0x33, 0xCC, 0x33));
    Image1(hdc, 120, 120, RGB(0xFF, 0x00, 0x66));
    Image1(hdc, 70, 70, RGB(0x00, 0xFF, 0xFF));
}
void Picture2(HDC hdc) {
    Image2(hdc, 180, 20, RGB(255, 255, 128));
    Image2(hdc, 280, 20, RGB(0xCC, 0, 0xCC));
    Image2(hdc, 180, 120, RGB(0x33, 0xCC, 0x33));
    Image2(hdc, 280, 120, RGB(0xFF, 0x00, 0x66));
    Image2(hdc, 230, 70, RGB(0x00, 0xFF, 0xFF));
}
void Picture3(HDC hdc) {
    Image3(hdc, 340, 20, RGB(255, 255, 128));
    Image3(hdc, 440, 20, RGB(0xCC, 0, 0xCC));
    Image3(hdc, 340, 120, RGB(0x33, 0xCC, 0x33));
    Image3(hdc, 440, 120, RGB(0xFF, 0x00, 0x66));
    Image3(hdc, 390, 70, RGB(0x00, 0xFF, 0xFF));
}
void Picture4(HDC hdc) {
    Image4(hdc, 20, 180, RGB(255, 255, 128));
    Image4(hdc, 120, 180, RGB(0xCC, 0, 0xCC));
    Image4(hdc, 20, 280, RGB(0x33, 0xCC, 0x33));
    Image4(hdc, 120, 280, RGB(0xFF, 0x00, 0x66));
    Image4(hdc, 70, 230, RGB(0x00, 0xFF, 0xFF));
}
void Picture5(HDC hdc) {
    Image5(hdc, 180, 180, RGB(255, 255, 128));
    Image5(hdc, 280, 180, RGB(0xCC, 0, 0xCC));
    Image5(hdc, 180, 280, RGB(0x33, 0xCC, 0x33));
    Image5(hdc, 280, 280, RGB(0xFF, 0x00, 0x66));
    Image5(hdc, 230, 230, RGB(0x00, 0xFF, 0xFF));
}
void Picture6(HDC hdc) {
    Image6(hdc, 340, 180, RGB(255, 255, 128));
    Image6(hdc, 440, 180, RGB(0xCC, 0, 0xCC));
    Image6(hdc, 340, 280, RGB(0x33, 0xCC, 0x33));
    Image6(hdc, 440, 280, RGB(0xFF, 0x00, 0x66));
    Image6(hdc, 390, 230, RGB(0x00, 0xFF, 0xFF));
}
void DrawStart(HDC hdc) {
    Picture1(hdc);
    Picture2(hdc);
    Picture3(hdc);
    Picture4(hdc);
    Picture5(hdc);
    Picture6(hdc);
}

//FINAL
#define NUM_IM_A 9
#define NUM_IM_B 9
#define NUM_IM_C 9
#define NUM_IM_D 9
#define NUM_IM_E 9

IMAGE imA[NUM_IM_A] = {
    {400, 250, 10, 0, RGB(255, 0, 255)}, {410, 255, 9, 4, RGB(255, 30, 255)}, {420, 260, 7, 7, RGB(255, 60, 255)},
    {430, 265, 4, 9, RGB(255, 90, 255)}, {440, 270, 0, 10, RGB(255, 120, 255)}, {430, 275, -4, 9, RGB(255, 150, 255)},
    {420, 280, -7, 7, RGB(255, 180, 255)}, {410, 285, -9, 4, RGB(255, 210, 255)}, {400, 290, -10, 0, RGB(255, 240, 255)}
};

IMAGE imB[NUM_IM_B] = {
    {350, 200, 10, 0, RGB(0, 255, 255)}, {360, 205, 9, 4, RGB(30, 255, 255)}, {370, 210, 7, 7, RGB(60, 255, 255)},
    {380, 215, 4, 9, RGB(90, 255, 255)}, {390, 220, 0, 10, RGB(120, 255, 255)}, {380, 225, -4, 9, RGB(150, 255, 255)},
    {370, 230, -7, 7, RGB(180, 255, 255)}, {360, 235, -9, 4, RGB(210, 255, 255)}, {350, 240, -10, 0, RGB(240, 255, 255)}
};

IMAGE imC[NUM_IM_C] = {
    {450, 300, 10, 0, RGB(255, 255, 0)}, {460, 305, 9, 4, RGB(255, 255, 30)}, {470, 310, 7, 7, RGB(255, 255, 60)},
    {480, 315, 4, 9, RGB(255, 255, 90)}, {490, 320, 0, 10, RGB(255, 255, 120)}, {480, 325, -4, 9, RGB(255, 255, 150)},
    {470, 330, -7, 7, RGB(255, 255, 180)}, {460, 335, -9, 4, RGB(255, 255, 210)}, {450, 340, -10, 0, RGB(255, 255, 240)}
};

IMAGE imD[NUM_IM_D] = {
    {400, 350, 10, 0, RGB(0, 255, 0)}, {410, 355, 9, 4, RGB(30, 255, 0)}, {420, 360, 7, 7, RGB(60, 255, 0)},
    {430, 365, 4, 9, RGB(90, 255, 0)}, {440, 370, 0, 10, RGB(120, 255, 0)}, {430, 375, -4, 9, RGB(150, 255, 0)},
    {420, 380, -7, 7, RGB(180, 255, 0)}, {410, 385, -9, 4, RGB(210, 255, 0)}, {400, 390, -10, 0, RGB(240, 255, 0)}
};

IMAGE imE[NUM_IM_E] = {
    {350, 300, 10, 0, RGB(0, 0, 255)}, {360, 305, 9, 4, RGB(0, 30, 255)}, {370, 310, 7, 7, RGB(0, 60, 255)},
    {380, 315, 4, 9, RGB(0, 90, 255)}, {390, 320, 0, 10, RGB(0, 120, 255)}, {380, 325, -4, 9, RGB(0, 150, 255)},
    {370, 330, -7, 7, RGB(0, 180, 255)}, {360, 335, -9, 4, RGB(0, 210, 255)}, {350, 340, -10, 0, RGB(0, 240, 255)}
};

void DrawStars(HDC hdc) {
    int i = 0;
    while (i < NUM_IM_A) {
        Image5(hdc, imA[i].x, imA[i].y, imA[i].color);
        i += 1;
    }
    i = 0;
    while (i < NUM_IM_B) {
        Image1(hdc, imB[i].x, imB[i].y, imB[i].color);
        i += 1;
    }
    i = 0;
    while (i < NUM_IM_C) {
        Image2(hdc, imC[i].x, imC[i].y, imC[i].color);
        i += 1;
    }
    i = 0;
    while (i < NUM_IM_D) {
        Image3(hdc, imD[i].x, imD[i].y, imD[i].color);
        i += 1;
    }
    i = 0;
    while (i < NUM_IM_E) {
        Image4(hdc, imE[i].x, imE[i].y, imE[i].color);
        i += 1;
    }
}

void Movestars() {
    int i = 0;
    while (i < NUM_IM_A) {
        imA[i].x += imA[i].vx;
        imA[i].y += imA[i].vy;
        i += 1;
    }
    i = 0;
    while (i < NUM_IM_B) {
        imB[i].x -= imB[i].vx;
        imB[i].y -= imB[i].vy;
        i += 1;
    }
    i = 0;
    while (i < NUM_IM_C) {
        imC[i].x -= imC[i].vx;
        imC[i].y += imC[i].vy;
        i += 1;
    }
    i = 0;
    while (i < NUM_IM_D) {
        imD[i].x += imD[i].vx;
        imD[i].y -= imD[i].vy;
        i += 1;
    }
    i = 0;
    while (i < NUM_IM_E) {
        imE[i].x += imE[i].vx;
        imE[i].y += imE[i].vy;
        i += 1;
    }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        // Перезапуск генератора случайных чисел
        // функция time() объявлена в time.h
        srand(time(NULL));

        SetTimer(hWnd, 1, 500, 0);
        SetTimer(hWnd, 2, 5000, 0);
        break;

    case WM_TIMER:
    {
        if (wParam == 1) {
            MoveGameElements();
            if (mode == FINAL)
				Movestars();
        }
        if (wParam == 2) {
            ChangeDirection();
		}
        if (ImagesAreClose()) {
			prey_lifes--;
            if (prey_lifes == 0) {
				mode = FINAL;
            }
        }
        InvalidateRect(hWnd, NULL, TRUE);
    }
    break;

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
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            if (mode == START)
                DrawStart(hdc);
            if (mode == GAME)
                DrawGame(hdc);
            if (mode == FINAL)
                DrawStars(hdc);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            hunter.vx = -20;
            hunter.vy = 0;
            break;
        case VK_RIGHT:
            hunter.vx = +20;
            hunter.vy = 0;
            break;
        case VK_DOWN:
            hunter.vx = 0;
            hunter.vy = +20;
            break;
        case VK_UP:
            hunter.vx = 0;
            hunter.vy = -20;
            break;
        case VK_SPACE:
            if (mode == FINAL)
                PostQuitMessage(0);
            if (mode == GAME)
                mode = FINAL;
            if (mode == START)
                mode = GAME;
            break;
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
