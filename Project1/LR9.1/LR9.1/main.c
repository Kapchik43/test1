#include <stdio.h>
#include <Windows.h>

//9.1.1
long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

//9.1.2
int fn1(int n) {
    if (n > 1) {
        printf("%d ", n);
        return fn1(n - 2);
    }
    printf("%d ", n);
    return n;
}
void fn2(int n) {
    if (n > 1) {
        fn2(n - 2);
    }
    printf("%d ", n);
}
void fn3(int n) {
    printf("%d ", n);
    if (n > 1) {
        fn3(n - 2);
        printf("%d ", n);
    }
}
//9.1.4
void recEGE1(int n) {
    if (n >= 1) {
        printf(" %d", n);
        recEGE1(n - 1);
        recEGE1(n - 1);
    }
}

//9.1.5
void F1_task915(int n) {
    if (n > 2) {
        printf("%d\n", n);
        F1_task915(n - 3);
        F1_task915(n - 4);
    }
}

//9.1.6
void F2_task916(int n) {
    printf("%d\n", n);
    if (n < 5) {
        F2_task916(n + 1);
        F2_task916(n + 3);
    }
}

//9.1.7
void G3_task917(int n);

void F3_task917(int n) {
    if (n > 0) {
        G3_task917(n - 1);
    }
}

void G3_task917(int n) {
    printf("*");
    if (n > 1) {
        F3_task917(n - 3);
    }
}

//9.1.9
void f919_var2(int n) {
    if (n > 0) {
        printf("<");
        f919_var2(n - 1);

        printf("%d", n);
        if (n < 5) {
            printf(">");
        }
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int factN, f1, f2, f3;
    printf("9.1.1\n");
    printf("Введите число: ");
    scanf_s("%d", &factN);
    printf("Факториал %d: %d\n\n", factN, factorial(factN));

    printf("9.1.2\n");
    printf("Введите числа для f1(), f2(), f3()\n");

    printf("f1(): ");
    scanf_s("%d", &f1);
    printf("f2(): ");
    scanf_s("%d", &f2);
    printf("f3(): ");
    scanf_s("%d", &f3);

    printf("\n2.1: ");
    fn1(f1);
    printf("\n2.2: ");
    fn2(f2);
    printf("\n2.3: ");
    fn3(f3);

    printf("\n\n9.1.4\n");
    recEGE1(3);

    printf("\n\n9.1.5\n");
    F1_task915(10);

    printf("\n9.1.6\n");
    F2_task916(1);

    printf("\n9.1.7\n");
    F3_task917(11);

    printf("\n9.1.9\n");
    f919_var2(5);

    return 0;
}