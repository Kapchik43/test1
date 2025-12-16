#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->next = first;
	newNode->data = value;
	first = newNode;
}

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d) -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

int deleteFromHead() {
	if (first == NULL) {
		printf("Error: List is empty, cannot delete from head.\n");
		return -1;
	}

	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}

int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL) {
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int sum() {
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		s += ptr->data;
		ptr = ptr->next;
	}
	return s;
}

int evenCount() {
	struct Node* ptr = first;
	int count = 0;
	while (ptr != NULL) {
		if (ptr->data % 2 == 0) {
			count++;
		}
		ptr = ptr->next;
	}
	return count;
}

void oddsX10() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 != 0) {
			ptr->data *= 10;
		}
		ptr = ptr->next;
	}
}

void elementIx100(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index == i) {
			ptr->data *= 100;
			return;
		}
		ptr = ptr->next;
		index++;
	}
}

void elementLeftIx10(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index < i) {
			ptr->data *= 10;
		}
		else {
			return;
		}
		ptr = ptr->next;
		index++;
	}
}

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//10.2.1 Демонстрация всех функций
	first = NULL;
	printf("10.2.1 Демонстрация всех функций\n");
	printList();

	printf("\naddToHead()\n");
	addToHead(10);
	printList();
	addToHead(20);
	printList();
	addToHead(30);
	printList();

	printf("\ndeleteFromHead()\n");
	int x1 = deleteFromHead();
	printf("x1 = %d\n", x1);
	printList();

	int x2 = deleteFromHead();
	printf("x2 = %d\n", x2);
	printList();
	clearList();

	printf("\ncontains()\n");
	addToHead(400);
	addToHead(300);
	addToHead(200);
	addToHead(100);
	printList();
	printf("contains(100) = %d\n", contains(100));
	printf("contains(150) = %d\n", contains(150));
	printf("contains(200) = %d\n", contains(200));

	printf("\nclearList()\n");
	clearList();
	printList();
	printf("contains(100) = %d\n", contains(100));
	printf("contains(150) = %d\n", contains(150));
	printf("contains(200) = %d\n", contains(200));


	//Задачи 10.2.2 - 10.2.6
	printf("\n\nЗадачи 10.2.2 - 10.2.6\n");
	printf("\n10.2.2: <Сумма элементов> sum()\n");
	clearList();
	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(9);
	printList();
	printf("sum = %d\n", sum());
	clearList();

	printf("\n10.2.3: <Количество четных элементов> evenCount()\n");
	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();
	printf("Четных элементов = %d\n", evenCount());

	printf("\n10.2.4: <Нечетные х10> oddsX10()\n");
	printList();
	oddsX10();
	printList();

	printf("\n10.2.5: <i элемент х100> elementIx100()\n");
	int i1, i2;
	printList();
	printf("Введите i: ");
	scanf_s("%d", &i1);
	elementIx100(i1);
	printList();
	clearList();


	printf("\n10.2.6: <Все элементы левее i увеличить х10> elementLeftIx10()\n");
	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();
	printf("Введите i: ");
	scanf_s("%d", &i2);
	elementLeftIx10(i2);
	printList();

	clearList();
	printList();
}
