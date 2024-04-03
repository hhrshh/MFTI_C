// F17 
// След матрицы 
// Написать функцию и программу, демонстрирующую работу данной функции, которая находит след матрицы в двумерном массиве. Показать пример ее работы на матрице из 5 на 5 элементов. След матрицы - это сумма элементов на главной диагонали. 

// Данные на входе: 		25 целых чисел через пробел. 
// Данные на выходе: 	Одно целое число. 

// Пример
// Данные на входе: 		1 1 1 1 1 
//                          2 2 2 2 2
//                          3 3 3 3 3 
//                          4 4 4 4 4 
//                          5 5 5 5 5 
// Данные на выходе: 	15 

#include <stdio.h>
#define SIZE 25

void arr_input(int*, int);
void matrix_trace(int*, int);
void arr_show(int*, int);

// <----------------------------------------------------------main

int main(void) 
{
int a[SIZE];
int countr = SIZE;

    arr_input(a, countr);
    matrix_trace(a, countr);

    return 0;
}

// <----------------------------------------------------------main

void matrix_trace(int* a, int n)
{
int sum = 0;
    for (int i = 0; i < n; i = i + 6)
    {
        sum += a[i];
    }
printf("%d\n", sum);
}

void arr_input(int* a, int countr)
{
int i = 0;
    while(countr--)
    {
        scanf("%d", &a[i]);
        ++i;
    }
}

void arr_show(int* arr, int countr)
{
    for (int i = 0; i < countr; i = i + 6)
        printf("%d ", arr[i]);
    printf("\n");
}