# Домашнее задание по флите
## Цели работы
Изучить и сравнить алгоритмы сортировки массивов сортировкой вставками и сортировкой Шелла. 
Ознакомиться со способами тестирования алгоритмов и с характеристиками алгоритмов (временная и пространственная сложность)
___

Исходный код содержит несколько функций, которые вы можете использовать в зависимости от того, что вы желаете получить, просто подставив вызов функции в main.

```c
typedef struct Array {
    int length;
    int * arr;
}
array;

array GiveData(); // Ввод данных с консоли
array GiveDataF(); // Ввод данных с файла
void GiveRandFile(int number_of_numbers); // Запись рандомных значений в файл для считывания (data.txt)
void Test(); // Функция тестировщик которая замеряет время и записывает результаты в файл test.txt
void ShellSort(int n, int * mass); // Сортировка Шелла
void InsertionSort(int n, int * mass); // Сортировка вставками
void ShowArray(array mass); // Выводит переданный массив

int main() {
    Test();
    return 0;
}
```
