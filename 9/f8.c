// Пропущенное число
// Написать функцию и программу, демонстрирующую работу данной функции.
// В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1) в произвольном порядке, но одно из чисел пропущено (остальные встречаются ровно по одному разу). N не превосходит 1000. Последовательность заканчивается числом 0. Определить пропущенное число. 

// Данные на входе: 		Последовательность целых чисел от M до N. M, N не превосходит 1000. 
// Данные на выходе: 	Одно целое число 

// Пример №1
// Данные на входе: 		2 3 1 4 7 6 9 8 10 0 
// Данные на выходе: 	    5 

// Пример №2
// Данные на входе: 		41 40 39 38 37 36 34 33 32 31 50 49 48 47 46 45 44 43 42 30 0 
// Данные на выходе: 	    35 

#include <stdio.h>
#define SIZE 1001

void arrInput(int*, int*);
int finderMissingNumber(int*, int);
int min(int, int);
int max(int, int);
void swap(int*, int*);
void arrShow(int*, int);

// <----------------------------------------------------------main

int main(void) 
{
int arr[SIZE];
int countr = 0;

    arrInput(arr, &countr);
    printf("%d\n", finderMissingNumber(arr, countr));
    return 0;
}

// <----------------------------------------------------------main


void arrInput(int* arr, int* counter)
{
int i = 0;
    while(1)
    {
        scanf("%d", &arr[i]);
        if (!arr[i])
            break;
        ++*(counter);
        ++i;
    }
}

int min(int a, int b)
{
int resault;
    resault = a < b ? a : b;
    return resault;
}

int max(int a, int b)
{
int resault;
    resault = a > b ? a : b;
    return resault;
}

void swap(int* a, int* b)
{
int t;
    t = *a;
    *a = *b;
    *b = t;
}

int finderMissingNumber(int* arr, int counter)
{
int resault = arr[0];
    for (int i = 1; i < counter; ++i)
        resault = max(resault, arr[i]);
    for (int i = 0; i < counter; ++i)
        for (int j = 0; j <= counter; ++j)
        {
            if (resault - 1 == arr[j])
            {
                --resault;
                break;
            }
            if (j >= counter)
                return --resault;
        }   
}

void arrShow(int* arr, int counter)
{
    for (int i = 0; i < counter; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
