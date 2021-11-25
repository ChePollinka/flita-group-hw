#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct Array {
    int length;
    int * arr;
}
array;

array GiveData(); // Ввод данных с консоли
array GiveDataF(); // Ввод данных с файла
void GiveRandFile(int number_of_numbers); // Запись рандомных значений в файл для считывания
void Test(); // Функция тестировщик которая замеряет время и записывает результаты
void ShellSort(int n, int * mass); // Сортировка Шелла
void InsertionSort(int n, int * mass); // Сортировка вставками
void ShowArray(array mass); // Выводит переданный массив

int main() {
    Test();
    return 0;
}

array GiveData() {
    printf("Enter the data:\n");
    int c, i = 0;
    char k;
    array mass;
    mass.arr = NULL;
    while (scanf("%d%c", & c, & k)) {
        mass.arr = (int * ) realloc(mass.arr, (i + 1) * sizeof(int));
        mass.arr[i] = c;
        i++;
        if (k == '\n')
            break;
    }
    mass.length = i;
    if (k != '\n') {
        printf("The data is not avialable\n");
        exit(-1);
    }
    return mass;
}

void ShellSort(int n, int * mass) {
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++) {
            tmp = mass[i];
            for (j = i; j >= step; j -= step) {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}

void InsertionSort(int n, int * mass) {
    int newElement, location;

    for (int i = 1; i < n; i++) {
        newElement = mass[i];
        location = i - 1;
        while (location >= 0 && mass[location] > newElement) {
            mass[location + 1] = mass[location];
            location = location - 1;
        }
        mass[location + 1] = newElement;
    }
}
void ShowArray(array mass) {
    for (int i = 0; i < mass.length; ++i) {
        printf("%d\n", mass.arr[i]);
    }
}

array GiveDataF() {
    FILE * fp;
    if ((fp = fopen("data.txt", "r")) == NULL) { // Открываем файл и смотрим нормально ли открылось
        char err[] = {
            "Error"
        };
        printf("Не удалось открыть файл\n");
        perror(err);
        exit(-1);
    }
    int c, i = 0;
    char k;
    array mass;
    mass.arr = NULL;
    while (fscanf(fp, "%d%c", & c, & k)) { // Считываем символы для каждого нового символа снова выделяем память
        mass.arr = (int * ) realloc(mass.arr, (i + 1) * sizeof(int));
        mass.arr[i] = c;
        i++;
        if (k == '\n')
            break;
    }
    mass.length = i;
    if (k != '\n') { // Проверка на валидность данных
        printf("The data is not avialable\n");
        exit(-1);
    }
    fclose(fp);
    return mass;
}

void GiveRandFile(int number_of_numbers) {
    FILE * fp;
    if ((fp = fopen("data.txt", "w")) == NULL) {
        char err[] = {
            "Error"
        };
        printf("Не удалось открыть файл\n");
        perror(err);
        exit(-1);
    }
    srand(time(NULL)); // Функция чтоб rand() каждый раз генерировал новые числа
    for (int i = 0; i < number_of_numbers - 1; i++) { // Генерируем и записываем числа в файл 
        fprintf(fp, "%d ", rand() % 100001);
    }
    fprintf(fp, "%d\n", rand() % 100001);
    fclose(fp);
}

void Test() {
    FILE * fp;
    if ((fp = fopen("test.txt", "w")) == NULL) {
        char err[] = {
            "Error"
        };
        printf("Не удалось открыть файл\n");
        perror(err);
        exit(-1);
    }
    array mass;
    int start_time; // Время работы программы замеряем как разницу между временем начала программы и временем её окончания
    int end_time;
    for (int i = 1000; i <= 300000; i = i + 1000) {
        GiveRandFile(i);
        mass = GiveDataF();
        start_time = clock();
        ShellSort(mass.length, mass.arr);
        end_time = clock();
        free(mass.arr);
        fprintf(fp, "%d\n", end_time - start_time);
    }
    fclose(fp);
}
