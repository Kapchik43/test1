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
		if (s1[i] >= '0' & s1[i] <= '9') {
			len++;
		}
	}
	char* s2 = (char*)malloc(len + 1);

	for (i = 0, len = 0; s1[i] != '\0'; i++, len++) {
		s2[len] = s1[i];
		if (s1[i] >= '0' & s1[i] <= '9') {
			len++;
			s2[len] = s1[i];
		}
	}
	s2[len] = '\0';
	return s2;
}