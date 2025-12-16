#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

//7.1.1
void printElements() {
    if (n == 0) {
        printf("< >");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
void keyboardInput() {
    printf("n = ");
    scanf_s("%d", &n);

    printf("input %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }
}
void oddsX10() {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 1) {
            arr[i] = arr[i] * 10;
        }
    }
}
int findMin() {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

//7.1.2
void bolshe10() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 10) {
            count++;
        }
    }
    printf("%d элементов больше чем 10\n", count);
}

//7.1.3
int findLastEven() {
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] % 2 == 0) {
            return i;
        }
    }
    return -1;
}

//7.1.4
int findIndexMin() {
    if (n == 0) {
        return -1;
    }
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

//7.1.7
void evenTimesMinusOne() {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] *= -1;
        }
    }
}

//7.1.8
void replaceLessThan4With4() {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 4) {
            arr[i] = 4;
        }
    }
}

//7.1.9
void replaceOddsWith1() {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            arr[i] = 1;
        }
    }
}

//7.2.1
void deleteElement(int index) {
    if (index < 0 || index >= n) {
        printf("Некорректный индекс!\n");
        return;
    }
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

//7.2.2; 7.2.4
void insertElement(int index, int value) {
    if (n >= NUM_ELEMENTS || index < 0 || index > n) {
        printf("Некорректный индекс или массив переполнен!\n");
        return;
    }
    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    n++;
}

//7.2.3
void deleteMinElement() {
    int indexMin = findIndexMin();
    if (indexMin >= 0) {
        deleteElement(indexMin);
        printf("Минимальный элемент удалён\n");
    }
    else {
        printf("Массив пуст\n");
    }
}

//7.2.9
void deleteLastEvenElement() {
    int index = findLastEven();
    if (index >= 0) {
        deleteElement(index);
        printf("Последний чётный элемент удалён\n");
    }
    else {
        printf("Чётных элементов нет\n");
    }
}


void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int item;
    do {
        printf("\n");
        printf("------------------------------\n");
        printf("Содержимое массива:");
        printElements();
        printf("\n");
        printf("Выберите нужную вам операцию:\n");
        printf("1: Ввести с клавиатуры массив\n");
        printf("2: x10 для всех нечетных элементов\n");
        printf("3: Найти минимальный элемент\n");
        printf("4: Сколько элементов > 10\n");
        printf("5: Х2 для последнего четного\n");
        printf("6: Сколько четных левее минимального\n");
        printf("7: Все четные элементы массива умножить на -1\n");
        printf("8: Все элементы < 4 заменить на 4\n");
        printf("9: Все нечетные элементы заменить на 1\n");
        printf("11: Удалить заданный элемент\n");
        printf("12: Вставить новый элемент в заданное место\n");
        printf("13: Удалить минимальный элемент\n");
        printf("14: Перед минимальным элементом вставить 0\n");
        printf("15: Удалить последний из чётных элементов\n");
        printf("\n");
        printf("0: Выйти из программы\n");
        printf("Выбранная операция >>>>>> ");
        scanf_s("%d", &item);
        switch (item) {
        case 1:
            keyboardInput();
            break;
        case 2:
            oddsX10();
            break;
        case 3:
        {
            int min = findMin();
            printf("min = %d\n", min);
        }
        break;
        case 4:
            bolshe10();
            break;
        case 5:
        {
            int index = findLastEven();
            if (index >= 0) {
                arr[index] *= 2;
            }
        }
        break;
        case 6:
        {
            int index = findIndexMin();
            printf("Индекс минимального элемента = %d\n", index);

            int cnt = 0;
            for (int i = 0; i < index; i++) {
                if (arr[i] % 2 == 0) {
                    cnt++;
                }
            }
            printf("Левее минимального %d четных элементов\n", cnt);
        }
        break;
        case 7:
            evenTimesMinusOne();
            break;
        case 8:
            replaceLessThan4With4();
            break;
        case 9:
            replaceOddsWith1();
            break;
        case 11:
        {
            printf("Индекс удаляемого элемента = ");
            int index;
            scanf_s("%d", &index);
            deleteElement(index);
        }
        break;
        case 12:
        {
            printf("Перед каким элементом нужно вставить новый? Индекс = ");
            int index;
            scanf_s("%d", &index);
            printf("Значение, которое нужно вставить = ");
            int value;
            scanf_s("%d", &value);
            insertElement(index, value);
        }
        break;
        case 13:
            deleteMinElement();
            break;
        case 14:
        {
            int indexMin = findIndexMin();
            printf("Индекс минимального элемента = %d\n", indexMin);
            insertElement(indexMin, 0);
        }
        break;
        case 15:
            deleteLastEvenElement();
            break;
        }
    } while (item != 0);
}