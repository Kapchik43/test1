# include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_N 10

void Task_10_1_1_static() {
	printf("<Task 1 static>		Cортированный статический массив\n");

	int arr[MAX_N];
	int n;
	int temp;

	printf("n=");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	printf("Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	printf("Sorted Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("</Task 1 static>\n");
}

void Task_10_1_1_dynamic() {
	printf("\n<Task 1 dynamic>	Сортированный динамический массив\n");

	int n;
	int* arr;
	int temp;

	printf("n=");
	scanf_s("%d", &n);

	arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("Ошибка выделения памяти!\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	printf("Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	printf("Sorted Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);

	printf("</Task 1 dynamic>\n");
}

void Task_10_1_2() {
	printf("\n<Task 2>	Новый массив из четных элементов\n");

	int n;
	int* arr;

	printf("n=");
	scanf_s("%d", &n);

	arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) return;

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	printf("Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	int n2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			n2++;
		}
	}

	int* arr2;
	arr2 = (int*)malloc(n2 * sizeof(int));
	if (arr2 == NULL) {
		free(arr);
		return;
	}

	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr2[j++] = arr[i];
		}
	}

	printf("Array 2: ");
	for (int i = 0; i < n2; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");

	free(arr);
	free(arr2);

	printf("</Task 2>\n");
}

void Task_10_1_3() {
	printf("\n<Task 3>	Новый массив из нечетных элементов после минимального\n");

	int n;
	int* arr;

	printf("n=");
	scanf_s("%d", &n);

	arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) return;

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	int mini = 0, min = arr[0];
	printf("Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
		if (arr[i] < min) {
			min = arr[i];
			mini = i;
		}
	}
	printf("\n");

	int n2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0 && i > mini) {
			n2++;
		}
	}

	int* arr2;
	arr2 = (int*)malloc(n2 * sizeof(int));
	if (arr2 == NULL) {
		free(arr);
		return;
	}

	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0 && i > mini) {
			arr2[j++] = arr[i];
		}
	}

	printf("Array 2: ");
	for (int i = 0; i < n2; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");

	free(arr);
	free(arr2);

	printf("</Task 3>\n");
}


void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Task_10_1_1_static();
	Task_10_1_1_dynamic();
	Task_10_1_2();
	Task_10_1_3();
}