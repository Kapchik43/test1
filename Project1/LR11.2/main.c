#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

int strlen_arr(char s[]) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

int strcmp_ptr(char* s1, char* s2) {
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

void strcpy_arr(char s1[], char s2[]) {
	int i = 0;
	while (s2[i] != '\0') {
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

void strcat_ptr(char* dest, char* src) {
	while (*dest) dest++;
	while (*dest++ = *src++);
}

char* strchr_arr(char s[], int c) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == (char)c) {
			return &s[i];
		}
		i++;
	}
	if ((char)c == '\0') return &s[i];
	return NULL;
}

char* CreateNewString(char* s1) {
	int hasDigit = 0;
	int len = 0;

	for (int i = 0; s1[i] != '\0'; i++) {
		if (s1[i] == '\n') continue;
		if (isdigit((unsigned char)s1[i])) {
			hasDigit = 1;
		}
		len++;
	}

	char* newStr;

	if (hasDigit) {
		newStr = (char*)malloc(len + 3 + 1);
		if (newStr == NULL) return NULL;

		int k = 0;
		newStr[k++] = '+'; newStr[k++] = '+'; newStr[k++] = '+';

		for (int i = 0; s1[i] != '\0'; i++) {
			if (s1[i] != '\n') {
				newStr[k++] = s1[i];
			}
		}
		newStr[k] = '\0';
	}
	else {
		newStr = (char*)malloc(len + 2 + 1);
		if (newStr == NULL) return NULL;

		int k = 0;
		for (int i = 0; s1[i] != '\0'; i++) {
			if (s1[i] != '\n') {
				newStr[k++] = s1[i];
			}
		}
		newStr[k++] = '*'; newStr[k++] = '*';
		newStr[k] = '\0';
	}

	return newStr;
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char str[100];

	printf("11.2.1 strlen()\n");
	printf("Введите строку: ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = 0;
	printf("Строка: '%s', Длина: %d\n\n", str, strlen_arr(str));

	printf("11.2.2 strcmp()\n");
	printf("Введите строку 1: ");
	char str1[100];
	fgets(str1, sizeof(str1), stdin);
	str1[strcspn(str1, "\n")] = 0;
	printf("Введите строку 2: ");
	char str2[100];
	fgets(str2, sizeof(str2), stdin);
	str2[strcspn(str2, "\n")] = 0;
	int cmpResult = strcmp_ptr(str1, str2);
	printf("'%s' vs '%s': %d\n", str1, str2, cmpResult);
	printf("\n");

	printf("11.2.3 strcpy()\n");
	char src_cpy[] = "Button";
	char dest_cpy[20];
	strcpy_arr(dest_cpy, src_cpy);
	printf("Строка 1: %s, Строка 2: %s\n\n", src_cpy, dest_cpy);

	printf("11.2.4 strcat()\n");
	printf("Введите строку 1: ");
	char destCat[200];
	fgets(destCat, sizeof(destCat), stdin);
	destCat[strcspn(destCat, "\n")] = 0;

	printf("Введите строку 2: ");
	char srcCat[100];
	fgets(srcCat, sizeof(srcCat), stdin);
	srcCat[strcspn(srcCat, "\n")] = 0;
	printf("До: '%s'\n", destCat);
	strcat_ptr(destCat, srcCat);
	printf("После: '%s'\n\n", destCat);

	printf("11.2.5 strchr()\n");
	printf("Введите строку: ");
	char strSearch[100];
	fgets(strSearch, sizeof(strSearch), stdin);
	strSearch[strcspn(strSearch, "\n")] = 0;
	printf("Что нужно найти: ");
	char charInput[10];
	fgets(charInput, sizeof(charInput), stdin);
	char targetChar = charInput[0];
	char* result = strchr_arr(strSearch, targetChar);
	if (result) {
		printf("'%c' на позиции: %ld\n\n", targetChar, result - strSearch);
	}
	else {
		printf("'%c' не найден\n\n", targetChar);
	}
	
	printf("11.2.6 CreateNewString() +++ в начало, если есть цифры; ** в конец, если цифр нет\n");
	printf("Введите строку: ");
	char s1[100];
	fgets(s1, sizeof(s1), stdin);

	char* s2 = CreateNewString(s1);

	s1[strcspn(s1, "\n")] = 0;

	printf("Строка:  '%s'\n", s1);
	printf("Новая строка: '%s'\n\n", s2);

	free(s2);

	return 0;
}