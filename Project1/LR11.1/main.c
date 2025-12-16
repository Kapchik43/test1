#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <ctype.h>

int isDigitMy(char c) {
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    char ch;
    char s[100];
    int i, cnt;

    do {
        printf("\nВыберите номер задачи:\n");
        printf("1. Задача 11.1.1 CH+19\n");
        printf("2. Задача 11.1.2 CH-29\n");
        printf("3. Задача 11.1.3 Подсчет пробелов\n");
        printf("4. Задача 11.1.4 Замена пробелов на #\n");
        printf("5. Задача 11.1.5.1 Замена цифр на $ через isdigit\n");
        printf("6. Задача 11.1.5.2 Замена цифр на $ через isDigitMy\n");
        printf("7. Задача 11.1.6.1 Латиница в верхний регистр\n");
        printf("8. Задача 11.1.9 Замена латиницы на &\n");
		printf("0. Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);
        cleanBuffer();

        printf("\n");

        switch (choice) {
        case 1:
            printf("Введите символ: ");
            ch = getchar();
            cleanBuffer();
            for (int c = ch; c <= ch + 19; c++) {
                printf("'%c' (%d)\n", c, c);
            }
            break;

        case 2:
            printf("Введите символ: ");
            ch = getchar();
            cleanBuffer();
            for (int c = ch; c >= ch - 29; c--) {
                printf("'%c' (%d)\n", c, c);
            }
            break;

        case 3:
            printf("Введите строку: ");
            fgets(s, sizeof(s), stdin);
            s[strcspn(s, "\n")] = 0;

            printf("Вы ввели строку s = \"%s\"\n", s);

            cnt = 0;
            for (i = 0; i < strlen(s); i++) {
                if (s[i] == ' ') cnt++;
            }
            printf("В ней %d пробелов\n", cnt);
            break;

        case 4:
            printf("Введите строку: ");
            fgets(s, sizeof(s), stdin);
            s[strcspn(s, "\n")] = 0;

            printf("Вы ввели строку = \"%s\"\n", s);

            for (i = 0; s[i] != '\0'; i++) {
                if (s[i] == ' ') s[i] = '#';
            }
            printf("Строка после обработки = \"%s\"\n", s);
            break;

        case 5:
            printf("Введите строку: ");
            fgets(s, sizeof(s), stdin);
            s[strcspn(s, "\n")] = 0;

            printf("Вы ввели строку = \"%s\"\n", s);

            for (i = 0; s[i] != '\0'; i++) {
                if (isdigit(s[i])) {
                    s[i] = '$';
                }
            }
            printf("Строка после обработки = \"%s\"\n", s);
            break;

        case 6:
            printf("Введите строку: ");
            fgets(s, sizeof(s), stdin);
            s[strcspn(s, "\n")] = 0;

            printf("Вы ввели строку = \"%s\"\n", s);

            for (i = 0; s[i] != '\0'; i++) {
                if (isDigitMy(s[i])) {
                    s[i] = '$';
                }
            }
            printf("Строка после обработки = \"%s\"\n", s);
            break;

        case 7:
            printf("Введите строку: ");
            fgets(s, sizeof(s), stdin);
            s[strcspn(s, "\n")] = 0;

            printf("Вы ввели строку = \"%s\"\n", s);

            for (i = 0; s[i] != '\0'; i++) {
                s[i] = toupper(s[i]);
            }
            printf("Строка после обработки = \"%s\"\n", s);
            break;

        case 8:
            printf("Введите строку: ");
            fgets(s, sizeof(s), stdin);
            s[strcspn(s, "\n")] = 0;

            printf("Вы ввели строку = \"%s\"\n", s);

            for (i = 0; s[i] != '\0'; i++) {
                if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
                    s[i] = '&';
                }
            }
            printf("Строка после обработки = \"%s\"\n", s);
            break;

        case 0:
            break;

        default:
            printf("Неверный номер задачи.\n");
        }

    } while (choice != 0);

    return 0;
}