#include <stdio.h>
#include <Windows.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int isLeapYear(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

void task5_1_1() {
    int a, b, c;
    do {
        printf("\n");
        printf("Задача 5.1.1\n");
        printf("Введите 2 целых числа:\n");
        printf("1. Начало анализируемого интервала\n");
        printf("2. Конец анализируемого интервала\n");
        int n = scanf("%d%d", &a, &b);
        c = n;
        if (n != 2) {
            printf("Ввели %d чисел\n", n);
            printf("ОШИБКА: Введены не все данные!\n");
            clear_input_buffer();
        }
    } while (c != 2);

    int num = a;
    do {
        if (isLeapYear(num))
            printf("%d\t", num);
        num++;
    } while (num <= b);
    printf("\n");
    printf("\n");
}

int isPrime(int num) {
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;

    for (int i = 3; i < num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void task5_1_2() {
    int a, b, c;
    do {
        printf("\n");
        printf("Задача 5.1.2\n");
        printf("Введите 2 целых числа:\n");
        printf("1. Начало анализируемого интервала\n");
        printf("2. Конец анализируемого интервала\n");
        int n = scanf("%d%d", &a, &b);
        c = n;
        if (n != 2) {
            printf("Ввели %d чисел\n", n);
            printf("ОШИБКА: Введены не все данные!\n");
            clear_input_buffer();
        }
    } while (c != 2);

    int num = a;
    do {
        if (isPrime(num))
            printf("%d  ", num);
        num++;
    } while (num <= b);
    printf("\n");
    printf("\n");
}

int fine_Poland(int v, int vMax) {
    if (v <= vMax) return 0;
    if (v <= vMax + 10) return 50;
    if (v <= vMax + 20) return 100;
    if (v <= vMax + 30) return 200;
    if (v <= vMax + 40) return 300;
    if (v <= vMax + 50) return 400;
    return 500;
}

void task5_1_4() {
    int a, b, c, d;
    do {
        printf("\n");
        printf("Задача 5.1.4\n");
        printf("Введите 3 целых числа:\n");
        printf("1. Разрешенную скорость\n");
        printf("2. Начало анализируемого интервала\n");
        printf("3. Конец анализируемого интервала\n");

        int n = scanf("%d%d%d", &a, &b, &c);
        d = n;
        if (n != 3) {
            printf("Ввели %d чисел\n", n);
            printf("ОШИБКА: Введены не все данные!\n");
            clear_input_buffer();
        }
    } while (d != 3);

    int vMax = a;
    int v = b;
    do {
        printf("Если вы едете со скоростью %d вместо %d это вам встанет в %d\n",
            v, vMax, fine_Poland(v, vMax));
        v += 1;
    } while (v <= c);
    printf("\n");
    printf("\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int k;
    do {
        printf("Выберите задачу:\n");
        printf("1: 5.1.1\n");
        printf("2: 5.1.2\n");
        printf("3: 5.1.4\n");
        printf("0: Завершить программу\n");
        scanf_s("%d", &k);
        switch (k) {
        case 1:
            task5_1_1();
            break;
        case 2:
            task5_1_2();
            break;
        case 3:
            task5_1_4();
            break;
        case 0:
            break;
        default:
            printf("Неверный выбор! Введите 0, 1, 2 или 3.\n");
            break;
        }
    } while (k != 0);
    return 0;
}