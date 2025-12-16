#include <stdio.h>
#include <Windows.h>

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int(n);
	printf("Выберите нужную вам лабораторную:\n");
	printf("1: Выполнить лабораторную 4.1\n");
	printf("2: Выполнить лабораторную 4.2\n");
	scanf_s("%d", &n);
	switch (n) {
	case 1:
		laba4_1();
		break;
	case 2:
		laba4_2();
		break;
	}
}