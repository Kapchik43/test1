#include <stdio.h>

void task4_2_1() {
	int n, m;
	printf("Таблица размерностью m*n:\n");
	printf("n=");
	scanf_s("%d", &n);
	printf("m=");
	scanf_s("%d", &m);
	printf("\n");
	int i = 1;
	do {
		int j = 1;
		do {
			printf("%d%d ", i, j);
			j++;
		} while (j <= m);
		printf("\n");
		i++;
	} while (i <= n);
}

void task4_2_2() {
	printf("Таблица Пифагора:\n");
	int i = 1;
	int j;
	while (i <= 10) {
		j = 1;
		while (j <= 10) {
			printf("%d ", i * j);
			j++;
		}
		printf("\n");
		i++;
	}
}
void task4_2_3() {
	printf("Рисунок числами, вариант 2:\n");
	int i = 1;
	while (i <= 10) {
		int j = 1;
		while (j <= i) {
			printf("%d ", j);
			j++;
		}
		printf("\n");
		i++;
	}
}

void laba4_2() {
	int(n);
	do {
		printf("Выберите задание:\n");
		printf("1: Выполнить задание 4.2.1\n");
		printf("2: Выполнить задание 4.2.2\n");
		printf("3: Выполнить задание 4.2.3\n");
		printf("0: Выйти из программы\n");
		scanf_s("%d", &n);
		printf("\n");
		switch (n) {
		case 1:
			task4_2_1();
			break;
		case 2:
			task4_2_2();
			break;
		case 3:
			task4_2_3();
			break;
		}
		printf("\n");
	} while (n != 0);
}