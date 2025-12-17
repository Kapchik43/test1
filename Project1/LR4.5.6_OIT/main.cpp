#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

char* CreateNewString(char* s1);

void main() {

	char s1[100];

	printf("s1=");
	fgets(s1, _countof(s1), stdin);

	char* s2;

	s2 = CreateNewString(s1);

	printf("s1=%s\n", s1);
	printf("s2=%s\n", s2);

	free(s2);
}

char* CreateNewString(char* s1) {
	int len, i;
	for (i = 0, len = 0; s1[i] != '\0'; i++, len++) {
		if (s1[i] >= 'A' & s1[i] <= 'Z') {
			len++;
		}
	}
	char* s2 = (char*)malloc(len + 1);

	for (i = 0, len = 0; s1[i] != '\0'; i++, len++) {
		s2[len] = s1[i];
		if (s1[i] >= 'A' & s1[i] <= 'Z') {
			len++;
			s2[len] = s1[i];
		}
	}
	s2[len] = '\0';
	return s2;
}
#include <stdio.h>

int n, m, a[10][10];

void InputArray() {
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
}

void PrintArray() {
	printf("\n%d %d\n", n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
}

void DoingSomething() {
	int min = a[0][0], mini = 0, minj = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] < min) {
				min = a[i][j];
				mini = i;
				minj = j;
			}

		}
	}

	for (int i = mini + 1; i < n; i++) {
		for (int j = minj + 1; j < m; j++) {
			if (a[i][j] % 10 == 0) {
				a[i][j] /= 10;
			}
		}
	}
}
void main() {
	InputArray();
	PrintArray();
	DoingSomething();
	PrintArray();
}