#include "framework.h"
#include "LR3.h"

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
    LoadStringW(hInstance, IDC_LR3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LR3));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LR3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LR3);
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
//Лаба 5.2
int numImage = 0;
void drawHome(HDC hdc) {
    //Krisha
    MoveToEx(hdc, 150, 350, NULL);
    LineTo(hdc, 275, 250);
    LineTo(hdc, 400, 350);
    //Dom
    LineTo(hdc, 400, 525);
    LineTo(hdc, 150, 525);
    LineTo(hdc, 150, 350);
    LineTo(hdc, 400, 350);
    //Okno
    MoveToEx(hdc, 225, 400, NULL);
    LineTo(hdc, 225, 475);
    LineTo(hdc, 325, 475);
    LineTo(hdc, 325, 400);
    LineTo(hdc, 225, 400);
    //Rama
    MoveToEx(hdc, 275, 400, NULL);
    LineTo(hdc, 275, 475);
    MoveToEx(hdc, 275, 425, NULL);
    LineTo(hdc, 325, 425);
}
void drawCar(HDC hdc) {
    //Машина
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(128, 0, 0));
    SelectObject(hdc, hPen);

    HBRUSH hBrush;
    hBrush = CreateSolidBrush(RGB(255, 128, 67));
    SelectObject(hdc, hBrush);

    Rectangle(hdc, 50, 200, 300, 250);

    MoveToEx(hdc, 100, 200, NULL);
    LineTo(hdc, 150, 150);
    LineTo(hdc, 250, 150);
    LineTo(hdc, 300, 200);

    hPen = CreatePen(PS_SOLID, 7, RGB(0, 0, 128));
    SelectObject(hdc, hPen);

    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(255, 0, 0));
    SelectObject(hdc, hBrush);

    Ellipse(hdc, 75, 225, 125, 275);

    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(0, 255, 0));
    SelectObject(hdc, hBrush);

    Ellipse(hdc, 225, 225, 275, 275);
}
void drawElochka(HDC hdc) {
    //Elochka
    MoveToEx(hdc, 450, 525, NULL);
    LineTo(hdc, 525, 450);
    LineTo(hdc, 600, 525);
    LineTo(hdc, 450, 525);
    MoveToEx(hdc, 475, 450, NULL);
    LineTo(hdc, 575, 450);
    LineTo(hdc, 525, 400);
    LineTo(hdc, 475, 450);
    MoveToEx(hdc, 500, 400, NULL);
    LineTo(hdc, 550, 400);
    LineTo(hdc, 525, 375);
    LineTo(hdc, 500, 400);
}
void drawTree(HDC hdc) {
    //дерево
    HPEN hPen = CreatePen(PS_SOLID, 10, RGB(120, 67, 21));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 75, 525, NULL);
    LineTo(hdc, 75, 350);

    hPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 75, 500, NULL);
    LineTo(hdc, 100, 475);
    MoveToEx(hdc, 75, 490, NULL);
    LineTo(hdc, 25, 450);
    MoveToEx(hdc, 75, 475, NULL);
    LineTo(hdc, 125, 425);
    MoveToEx(hdc, 75, 465, NULL);
    LineTo(hdc, 25, 400);
    MoveToEx(hdc, 75, 450, NULL);
    LineTo(hdc, 125, 375);
    MoveToEx(hdc, 75, 440, NULL);
    LineTo(hdc, 50, 350);
    MoveToEx(hdc, 75, 425, NULL);
    LineTo(hdc, 100, 325);
    MoveToEx(hdc, 75, 415, NULL);
    LineTo(hdc, 55, 300);
    MoveToEx(hdc, 75, 400, NULL);
    LineTo(hdc, 70, 300);
    MoveToEx(hdc, 75, 390, NULL);
    MoveToEx(hdc, 75, 375, NULL);
}
void drawAvtobus(HDC hdc) {
    //avtobus (650, 525)
    //основа
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
    SelectObject(hdc, hBrush);

    Rectangle(hdc, 650, 350, 1000, 500);
    //колеса
    hPen = CreatePen(PS_SOLID, 15, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    hBrush = CreateSolidBrush(RGB(135, 135, 135));
    SelectObject(hdc, hBrush);

    Ellipse(hdc, 675, 475, 725, 525);
    Ellipse(hdc, 900, 475, 950, 525);
    //fari
    hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    hBrush = CreateSolidBrush(RGB(255, 253, 85));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 650, 450, 670, 470);
    hBrush = CreateSolidBrush(RGB(235, 51, 36));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 985, 450, 1000, 470);
    hBrush = CreateSolidBrush(RGB(159, 252, 253));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, 650, 365, 1000, 440);
}
void tasks3_2_13(HDC hdc) {
    //321, 322, 323
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
    SelectObject(hdc, hPen);
    int x1 = 400, y1 = 150;
    int x2 = 500, y2 = 250;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
    } while (x1 <= 600);
    x1 = 0, y1 = 250;
    x2 = 100, y2 = 250;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 -= 10;
    } while (x1 <= 100);
    x1 -= 5;
    y1 += 10;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 += 10;
    } while (x1 <= 200);
}
void drawZabor(HDC hdc) {
    //324
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(120, 67, 21));
    SelectObject(hdc, hPen);
    int x1 = 150, y1 = 0;
    int x2 = 150, y2 = 100;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 25;
        x2 += 25;
    } while (x1 <= 450);
}
void drawTrava(HDC hdc) {
    //325 trava
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(117, 250, 141));
    SelectObject(hdc, hPen);
    int x1 = 0, y1 = 530;
    int x2 = 5, y2 = 520;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 3;
        x2 += 3;
    } while (x1 <= 1500);
}
void drawUzor(HDC hdc) {
    //325 uzor
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(115, 43, 245));
    SelectObject(hdc, hPen);
    int x1 = 375, y1 = 350;
    int x2 = 400, y2 = 375;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        y1 += 25;
        y2 += 25;
    } while (y1 < 525);
    x1 = 400, y1 = 350;
    x2 = 375, y2 = 375;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        y1 += 25;
        y2 += 25;
    } while (y1 < 525);
}
//лаба 5.3
void StClausAuto(HDC hdc, int x, int y) {
    MoveToEx(hdc, x + 20, y + 0, NULL);
    LineTo(hdc, x + 30, y + 20);
    LineTo(hdc, x + 10, y + 20);
    LineTo(hdc, x + 20, y + 0);

    MoveToEx(hdc, x + 20, y + 10, NULL);
    LineTo(hdc, x + 30, y + 40);
    LineTo(hdc, x + 10, y + 40);
    LineTo(hdc, x + 20, y + 10);

    MoveToEx(hdc, x + 20, y + 30, NULL);
    LineTo(hdc, x + 40, y + 80);
    LineTo(hdc, x + 0, y + 80);
    LineTo(hdc, x + 20, y + 30);
}
void drawLogos1(HDC hdc) {
    StClausAuto(hdc, 0, 0);
    StClausAuto(hdc, 200, 200);
    StClausAuto(hdc, 100, 100);
    StClausAuto(hdc, 0, 200);
    StClausAuto(hdc, 200, 0);
}
void drawLogos2(HDC hdc) {
    int x = 0;
    do {
        StClausAuto(hdc, x, 0);
        x += 50;
    } while (x < 400);
}
void drawLogos3(HDC hdc) {
    int y = 0;
    do {
        StClausAuto(hdc, 0, y);
        y += 90;
    } while (y < 300);
}
void drawLogos4(HDC hdc) {
    int x = 0;
    int y = 0;
    do {
        StClausAuto(hdc, x, y);
        x += 40;
        y += 80;
    } while (x < 400 && y < 300);
}
void drawTruck(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 200));
    SelectObject(hdc, hPen);
    Rectangle(hdc, 0 + x, 30 + y, 40 + x, 50 + y);
    Rectangle(hdc, 10 + x, 10 + y, 40 + x, 30 + y);
    Rectangle(hdc, 40 + x, 0 + y, 100 + x, 50 + y);
    hPen = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, 10 + x, 40 + y, 30 + x, 60 + y);
    Ellipse(hdc, 70 + x, 40 + y, 90 + x, 60 + y);
}
void drawTrucks1(HDC hdc) {
    drawTruck(hdc, 10, 10);
    drawTruck(hdc, 310, 10);
    drawTruck(hdc, 10, 310);
    drawTruck(hdc, 310, 310);
    drawTruck(hdc, 160, 160);
}
void drawTrucks2(HDC hdc) {
    int x = 10;
    do {
        drawTruck(hdc, x, 10);
        x += 110;
    } while (x < 600);
}
void drawTrucks3(HDC hdc) {
    int y = 10;
    do {
        drawTruck(hdc, 10, y);
        y += 70;
    } while (y < 400);
}
void drawTrucks4(HDC hdc) {
    int x = 10;
    int y = 10;
    do {
        drawTruck(hdc, x, y);
        x += 110;
        y += 70;
    } while (x < 600 && y < 400);
}
void Logo(HDC hdc, int a, int b, int size) {
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    int x = a + size / 2;
    int y = b + size / 2;
    int r = size / 2 - 2;

    Ellipse(hdc, a, b, a + size, b + size);

    MoveToEx(hdc, x, y, NULL); 
    LineTo(hdc, x, y - r);
    MoveToEx(hdc, x, y, NULL); 
    LineTo(hdc, x - (int)(0.866 * r), y + (int)(0.5 * r));
    MoveToEx(hdc, x, y, NULL); 
    LineTo(hdc, x + (int)(0.866 * r), y + (int)(0.5 * r));

    DeleteObject(hPen);
}
void drawLogo1(HDC hdc) {
    Logo(hdc, 0, 0, 50);
    Logo(hdc, 200, 200, 50);
    Logo(hdc, 100, 100, 50);
    Logo(hdc, 0, 200, 50);
    Logo(hdc, 200, 0, 50);
}
void drawLogo2(HDC hdc) {
    int x = 0;
    do {
        Logo(hdc, x, 0, 50);
        x += 50;
    } while (x < 400);
}
void drawLogo3(HDC hdc) {
    int y = 0;
    do {
        Logo(hdc, 0, y, 50);
        y += 90;
    } while (y < 300);
}
void drawLogo4(HDC hdc) {
    int x = 0;
    int y = 0;
    do {
        Logo(hdc, x, y, 50);
        x += 40;
        y += 80;
    } while (x < 400 && y < 300);
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
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            switch (numImage) {
            //лаба 5.2
            case 0: {
                drawHome(hdc);
                drawCar(hdc);
                drawElochka(hdc);
                drawTree(hdc);
                drawAvtobus(hdc);
                tasks3_2_13(hdc);
                drawZabor(hdc);
                drawTrava(hdc);
                drawUzor(hdc);
                break;
            }
            //лаба5.3
            case 1: drawLogos1(hdc); break;   
            case 2: drawLogos2(hdc); break;
            case 3: drawLogos3(hdc); break;
            case 4: drawLogos4(hdc); break;
            case 5: drawTrucks1(hdc); break;
            case 6: drawTrucks2(hdc); break;
            case 7: drawTrucks3(hdc); break;
            case 8: drawTrucks4(hdc); break;
            case 9: drawLogo1(hdc); break;
            case 10: drawLogo2(hdc); break;
            case 11: drawLogo3(hdc); break;
            case 12: drawLogo4(hdc); break;

            EndPaint(hWnd, &ps);
            }
        }
        break;

    case WM_KEYDOWN:
        numImage = (numImage + 1) % 13;
        InvalidateRect(hWnd, NULL, TRUE);
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
