// F9
// Поменять местами
// Написать функцию и программу, демонстрирующую работу данной функции, которая в массиве находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива. Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. Если отрицательных элементов нет - массив не менять.

// Прототип функции:
// void swap_negmax_last(int size, int a[])

// Данные на входе: 		Функция принимает на вход размер массива и указатель на начало массива. Массив состоит из целых чисел. 

// Пример
// Данные на входе: 		1 -2 -3 -4 5 6 7 8 9 10 
// Данные на выходе: 	    1 10 -3 -4 5 6 7 8 9 -2

#include <stdio.h>
#define SIZE 10

void arrInput1(int*, int);
void swap(int*, int*);
void swap_negmax_last(int, int*);
void arrShow(int*, int);

// <----------------------------------------------------------main

int main(void) 
{
int a[SIZE];
int countr = SIZE;

     arrInput1(a, countr);
     swap_negmax_last(countr, a);
     arrShow(a, countr);
    return 0;
}

// <----------------------------------------------------------main

void swap_negmax_last(int countr, int a[])
{
int tmp = 0, flag = -1;
    for (int i = 0; i < countr; ++i)
        if (a[i] < 0)
        {
            if (!tmp)
            {
                tmp = a[i];
                flag = i;
                continue;
            }

            if (a[i] > tmp) 
            {
               tmp= a[i];
                flag = i;
            }
        }
    if (flag >= 0)
        swap(&a[flag], &a[countr -1]);
}

void swap(int* a, int* b)
{
int t;
    t = *a;
    *a = *b;
    *b = t;
}

void arrInput1(int* a, int countr)
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