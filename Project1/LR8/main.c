#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 8
#define MAX_M 10

int arr[MAX_N][MAX_M] = {
    {0, 1, 222, 3},
    {10, 11, 12, 13},
    {20, 21, 22, 23}
};
int n = 3;
int m = 4;

void fillIx10() {
    printf("!!!! fillIx10() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = i * 10 + j;
        }
    }
}

void fillZeros() {
    printf("!!!! fillZeros() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = 0;
        }
    }
}

void fillRandom() {
    printf("!!!! fillRandom() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void oddTimes10() {
    printf("!!!! odd*10() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 2 != 0)
                arr[i][j] *= 10;
        }
    }
}

void div10Div10() {
    printf("!!!! div10/10() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 10 == 0 && arr[i][j] != 0)
                arr[i][j] /= 10;
        }
    }
}

void printArr() {
    printf("!!!! print() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

// 8.1.5: Ввод массива с клавиатуры
void inputArr() {
    printf("Введите количество строк (1-%d): ", MAX_N);
    scanf_s("%d", &n);
    if (n < 1) n = 1; if (n > MAX_N) n = MAX_N;
    printf("Введите количество столбцов (1-%d): ", MAX_M);
    scanf_s("%d", &m);
    if (m < 1) m = 1; if (m > MAX_M) m = MAX_M;
    printf("Введите элементы массива (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("[%d][%d]=", i, j);
            scanf_s("%d", &arr[i][j]);
        }
    }
}

// 8.1.6: Сохранение/загрузка массива в текстовом файле
void saveArrTxt(const char* fname) {
    FILE* f;
    fopen_s(&f, fname, "w");
    if (!f) { printf("Ошибка открытия файла!\n"); return; }
    fprintf(f, "%d %d\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(f, "%d ", arr[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    printf("Массив сохранён в %s\n", fname);
}
void loadArrTxt(const char* fname) {
    FILE* f;
    fopen_s(&f, fname, "r");
    if (!f) { printf("Ошибка открытия файла!\n"); return; }
    fscanf_s(f, "%d %d", &n, &m);
    if (n < 1) n = 1; if (n > MAX_N) n = MAX_N;
    if (m < 1) m = 1; if (m > MAX_M) m = MAX_M;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf_s(f, "%d", &arr[i][j]);
    fclose(f);
    printf("Массив загружен из %s\n", fname);
}


// 8.1.8: Удалить заданную строку
void removeRow(int row) {
    if (row < 0 || row >= n) { printf("Некорректный номер строки!\n"); return; }
    for (int i = row; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = arr[i + 1][j];
    n--;
    printf("Строка %d удалена\n", row);
}

// 8.1.9: Продублировать заданный столбец
void duplicateCol(int col) {
    if (col < 0 || col >= m || m >= MAX_M) { printf("Некорректный номер столбца!\n"); return; }
    for (int i = 0; i < n; i++) {
        for (int j = m; j > col + 1; j--) {
            arr[i][j] = arr[i][j - 1];
        }
        arr[i][col + 1] = arr[i][col];
    }
    m++;
    printf("Столбец %d продублирован\n", col);
}

// 8.1.10: вариант A2
void task_8_1_10_A2() {
    printf("!!!!8.1.10 A2 !!!!\n");
    // Найти максимальный элемент и его позицию
    int maxVal = arr[0][0], maxI = 0, maxJ = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }
    // min и max последнего столбца
    int minLast = arr[0][m - 1], maxLast = arr[0][m - 1];
    for (int i = 1; i < n; i++) {
        if (arr[i][m - 1] < minLast) minLast = arr[i][m - 1];
        if (arr[i][m - 1] > maxLast) maxLast = arr[i][m - 1];
    }
    double avg = (minLast + maxLast) / 2.0;
    // Заменить все элементы ниже и левее максимального
    for (int i = maxI + 1; i < n; i++) {
        for (int j = 0; j < maxJ; j++) {
            arr[i][j] = avg;
        }
    }
}

// 8.1.11: вариант B2
void task_8_1_11_B2() {
    printf("!!!!8.1.11 B2 !!!!\n");
    int i = 0;
    while (i < n) {
        if (i < m && arr[i][i] % 2 == 0) {
            // Удалить строку i
            for (int k = i; k < n - 1; k++) {
                for (int j = 0; j < m; j++) {
                    arr[k][j] = arr[k + 1][j];
                }
            }
            n--;
        }
        else {
            i++;
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    int op = 0;
    char fname[100];
    int idx;
    while (1) {
        printArr();
        printf("====================================\n");
        printf("Выберите нужную вам операцию:\n");
        printf("1: заполнить значениями i * 10 + j\n");
        printf("2: заполнить нулями\n");
        printf("3: заполнить случайными значениями\n");
        printf("4: все нечетные увеличить в 10 раз\n");
        printf("5: все кратные 10 уменьшить в 10 раз\n");
        printf("6: Ввести массив с клавиатуры\n");
        printf("7: Сохранить массив в текстовый файл\n");
        printf("8: Загрузить массив из текстового файла\n");
        printf("9: Удалить заданную строку\n");
        printf("10: Продублировать заданный столбец\n");
        printf("11: 8.1.10 вариант A2\n");
        printf("12: 8.1.11 вариант B2\n");
        printf("-1: Выйти из программы\n");
        printf("Выбранная операция >>>>> ");
        scanf_s("%d", &op);

        if (op == -1) break;

        switch (op) {
        case 1:
            fillIx10();
            break;
        case 2:
            fillZeros();
            break;
        case 3:
            fillRandom();
            break;
        case 4:
            oddTimes10();
            break;
        case 5:
            div10Div10();
            break;
        case 6:
            inputArr();
            break;
        case 7:
            printf("Имя файла для сохранения: ");
            scanf_s("%s", fname, (unsigned)_countof(fname));
            saveArrTxt(fname);
            break;
        case 8:
            printf("Имя файла для загрузки: ");
            scanf_s("%s", fname, (unsigned)_countof(fname));
            loadArrTxt(fname);
            break;
        case 9:
            printf("Введите номер строки для удаления: ");
            scanf_s("%d", &idx);
            removeRow(idx);
            break;
        case 10:
            printf("Введите номер столбца для дублирования: ");
            scanf_s("%d", &idx);
            duplicateCol(idx);
            break;
        case 11:
            task_8_1_10_A2();
            break;
        case 12:
            task_8_1_11_B2();
            break;
        default:
            printf("Некорректная операция!\n");
        }
    }
    return 0;
}