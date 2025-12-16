#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

#define MAX_LEN_WORD 80

int isalpha_my(unsigned char ch);
int getNextDelim(FILE* fp, char token[]);
int getNextWord(FILE* fp, char token[], int maxLen);
int isCategory1(char* word);
int isCategory2(char* word);

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char filenameIn[] = "C:\\Users\\publi\\source\\repos\\Project1\\LR12.2\\text2.txt";
    char filenameOut[] = "C:\\Users\\publi\\source\\repos\\Project1\\LR12.2\\text2_out.html";

    FILE* fin = fopen(filenameIn, "rt");
    if (fin == NULL) {
        printf("File %s not found.\n", filenameIn);
        return;
    }

    FILE* fout = fopen(filenameOut, "wt");
    if (fout == NULL) {
        printf("Cannot create file %s.\n", filenameOut);
        fclose(fin);
        return;
    }

    fprintf(fout, "<!DOCTYPE html>\n");
    fprintf(fout, "<html>\n<head>\n");
    fprintf(fout, "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1251\" />\n");
    fprintf(fout, "<title>Task 12.2.2 Variant 2</title>\n");
    fprintf(fout, "</head>\n<body>\n");

    char token[MAX_LEN_WORD];

    while (!feof(fin)) {
        while (getNextDelim(fin, token)) {
            if (strcmp(token, "\n") == 0) {
                fprintf(fout, "<br>\n");
            }
            else if (strcmp(token, "<") == 0) {
                fprintf(fout, "&lt;");
            }
            else if (strcmp(token, ">") == 0) {
                fprintf(fout, "&gt;");
            }
            else {
                fprintf(fout, "%s", token);
            }
        }

        if (getNextWord(fin, token, MAX_LEN_WORD)) {
            if (isCategory1(token)) {
                fprintf(fout, "<b>%s</b>", token);
            }
            else if (isCategory2(token)) {
                fprintf(fout, "<i>%s</i>", token);
            }
            else {
                fprintf(fout, "%s", token);
            }
        }
    }

    fprintf(fout, "\n</body>\n</html>");

    fclose(fin);
    fclose(fout);
}

int isCategory1(char* word) {
    if (word[0] == '\0' || word[1] == '\0') return 0;

    if (!islower((unsigned char)word[0])) return 0;

    for (int i = 1; word[i] != '\0'; i++) {
        if (!isupper((unsigned char)word[i])) return 0;
    }
    return 1;
}

int isCategory2(char* word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (!islower((unsigned char)word[i])) return 0;
    }
    return 1;
}

int getNextDelim(FILE* fp, char token[]) {
    int ch = getc(fp);
    if (ch == EOF) return 0;

    if (isalpha_my((unsigned char)ch)) {
        ungetc(ch, fp);
        return 0;
    }
    token[0] = (unsigned char)ch;
    token[1] = '\0';
    return 1;
}

int getNextWord(FILE* fp, char token[], int maxLen) {
    int i = 0;
    int ch;
    while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
        if (!isalpha_my((unsigned char)ch)) {
            ungetc(ch, fp);
            break;
        }
        token[i++] = ch;
    }
    token[i] = '\0';
    return (i > 0);
}

int isalpha_my(unsigned char ch) {
    if (isalpha(ch)) return 1;
    if (ch >= 192 && ch <= 255) return 1;
    if (ch == 168 || ch == 184) return 1;
    return 0;
}