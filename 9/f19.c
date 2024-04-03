// F19 ДЗ 6 
// Больше среднего
// Написать функцию и программу, демонстрирующую работу данной функции.
// Определить количество положительных элементов квадратной матрицы, превышающих по величине среднее арифметическое всех элементов главной диагонали. Реализовать функцию среднее арифметическое главной диагонали. 

// Данные на входе: 		5 строк по 5 целых чисел через пробел 
// Данные на выходе: 	Одно целое число 

// Пример
// Данные на входе: 		1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5 
// Данные на выходе: 	10  

#include <stdio.h>
#define M 5
#define N 5
#define SIZE M * N

void arr_input(int*, int);
int matrix_avarage(int*, int);
void arr_show(int*, int);
void more_than(int, int, int*);

// <----------------------------------------------------------main

int main(void) 
{
int a[SIZE];
int countr = SIZE;

    arr_input(a, countr);
    more_than(matrix_avarage(a, countr), countr, a);

    return 0;
}

// <----------------------------------------------------------main



int matrix_avarage(int* a, int n)
{
int sum = 0;
    for (int i = 0; i < n; i = i + 6)
    {
        sum += a[i];
    }
return sum / N;
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

void more_than(int n, int s, int* a)
{
int count = 0;
    for (int i = 0; i < s ; ++i)
    {
    
        if (a[i] > 0 && a[i] > n)
            count++;
    }
    printf("%d\n", count);
}