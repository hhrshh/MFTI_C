// F11 Практ 3
// Сумма минимальна
// Написать функцию и программу, демонстрирующую работу данной функции.
// Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения помещающиеся в int. Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, сумма которых минимальна. 

// Данные на входе: 		Последовательность из 30 целых чисел через пробел 
// Данные на выходе: 	Два целых числа через пробел 

// Пример
// Данные на входе: 		1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 
// Данные на выходе: 	    0 1 

#include <stdio.h>
#define SIZE 30

void arrInput(int*, int);
void swap(int*, int*);
int minOrEqual(int, int);
void minSum(int, int*);
void arrShow(int*, int);

// <----------------------------------------------------------main

int main(void) 
{
int a[SIZE];
int countr = SIZE;

    arrInput(a, countr);
    minSum(countr, a);
    return 0;
}

// <----------------------------------------------------------main

void minSum(int countr, int a[])
{
int flag1 = a[0] <= a[1] ? 0 : 1;
int flag2 = a[0] <= a[1] ? 1 : 0;
    for (int i = 2; i < countr; ++i)
    {
        if (a[flag1] >= a[i])
        {
            flag2 = flag1;
            flag1 = i;
            continue;
        }

        if (a[flag2] >= a[i])
            flag2 = i;
    }
    printf("%d %d\n", flag1 < flag2 ? flag1 : flag2,  flag1 > flag2 ? flag1 : flag2);
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

int minOrEqual(int a, int b)
{
    return a <= b ? a : b;
}