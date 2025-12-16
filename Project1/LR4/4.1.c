#include <stdio.h>

void print1_10() {
    int a = 1;
    do {
        printf("%d ", a);
        a += 1;
    } while (a <= 10);
	printf("\n");
}

void print10_1() {
    int a = 10;
    do {
        printf("%d ", a);
        a -= 1;
    } while (a >= 1);
	printf("\n");
}

void print50dds() {
    int a = 1;
    int i = 1;
    do {
        printf("%d ", a);
        a += 2;
        i += 1;
    } while (i <= 5);
	printf("\n");
}

void print100_10_while() {
	int a = 100;
	while (a >= 10) {
		printf("%d ", a);
		a -= 10;
	}
	printf("\n");
}

void print1000_100_while() {
	int a = 1000;
	while (a >= 100) {
		printf("%d ", a);
		a -= 100;
	}
	printf("\n");
}

void print1000_0_while() {
	int a = 1000;
	int n;
	scanf_s("%d", &n);
	while (a >= 0) {
		printf("%d ", a);
		a -= n;
	}
	printf("\n");
}

void laba4_1() {
	int n;
	do {
		printf("\n");
		printf("Выберите нужную вам операцию:\n");
		printf("1: Вывести числа от 1 до 10\n");
		printf("2: Вывести числа от 10 до 1\n");
		printf("3: Вывести 5 первых нечетных чисел начиная с 1\n");
		printf("11: Вывести числа от 100 до 10 с шагом 10\n");
		printf("12: Вывести числа от 1000 до 100 с шагом 100\n");
		printf("20: Вывести числа от 1000 до 0 с шагом n (номер в журнале)\n");
		printf("0: Выйти из программы\n");
		scanf_s("%d", &n);
		printf("\n");
		switch (n) {
		case 1:
			print1_10();
			break;
		case 2:
			print10_1();
			break;
		case 3:
			print50dds();
			break;
		case 11:
			print100_10_while();
			break;
		case 12:
			print1000_100_while();
			break;
		case 20:
			printf("Введите ваш порядковый номер: ");
			print1000_0_while();
			break;
		}
	} while (n != 0);
}