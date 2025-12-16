#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <ctype.h>

#define MAX_LEN 80
char s[MAX_LEN];

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE* fin = fopen("C:\\Users\\publi\\Desktop\\text1.txt", "rt");
    FILE* fout = fopen("C:\\Users\\publi\\Desktop\\out1.txt", "wt");

    if (fin == NULL || fout == NULL) {
        printf("Ошибка открытия файлов");
        return;
    }

    while (!feof(fin)) {
        if (fgets(s, MAX_LEN, fin) != NULL) {
            for (int i = 0; s[i]  != '\0'; i++) {
                //if (s[i] == '\t') s[i] = '%'; // 12.1.1 
                //if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 32; //12.2.2
                if (isalpha(s[i])) s[i] = '&'; //12q.1.4 #2
            }
            fprintf(fout, "%s", s);
        }
    }

    fclose(fin);
    fclose(fout);
}