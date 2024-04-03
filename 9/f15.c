// F15
// Больше по модулю
// Написать функцию и программу, демонстрирующую работу данной функции, которая определяет в массиве, состоящем из положительных и отрицательных чисел, сколько элементов превосходят по модулю максимальный элемент. Прототип функции
// int count_bigger_abs(int n, int a[]);

// Данные на входе: 		Функция получает размер массива и массив целых чисел 
// Данные на выходе: 	Функция возвращает целое число раное количеству элементов превосходящих по модулю максимальный элемент. 

// Пример
// Данные на входе: 		1 -20 3 4 -50 6 7 8 9 10 
// Данные на выходе: 	    2 

#include <stdio.h>
#define SIZE 10

void arrInput(int*, int);
void swap(int*, int*);
int max(int, int);
int min(int, int);
int count_bigger_abs(int, int*);
void arrShow(int*, int);

// <----------------------------------------------------------main

int main(void) 
{
int a[SIZE];
int countr = SIZE;

    arrInput(a, countr);
    printf ("%d\n", count_bigger_abs(countr, a));
    return 0;
}

// <----------------------------------------------------------main

int count_bigger_abs(int n, int a[])
{
int count = 0, tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= 0)
        {
            if (!tmp)
            {
                tmp = a[i];
                continue;
            }
            tmp = tmp > a[i] ? tmp : a[i];
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0 && (a[i] * -1) > tmp)
            ++count;
    } 

    return count;
}

void swap(int* a, int* b)
{
int t;
    t = *a;
    *a = *b;
    *b = t;
}

void arrInput(int* a, int countr)
{
int i = 0;
    while(countr--)
    {
        scanf("%d", &a[i]);
        ++i;
    }
}

void arrShow(int* arr, int countr)
{
    for (int i = 0; i < countr; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}