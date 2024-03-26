// Сумма положительных элементов
// Считать массив из 10 элементов и подсчитать сумму положительных элементов массива. 

// Данные на входе: 		10 целых чисел через пробел 
// Данные на выходе: 	Одно целое число - сумма положительных элементов массива 

// Пример №1
// Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0 
// Данные на выходе: 	26 

// Пример №2
// Данные на входе: 		1 -2 3 -4 5 -6 7 -8 9 0 
// Данные на выходе: 	25 

#include <stdio.h>
#define SIZE 10

void arrShow(int* arr, int n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%d ", arr[i]);
printf("\n");
}

void arrInput(int* arr, int n)
{ 
    for(size_t i = 0; i < n; ++i) 
        scanf("%d", &arr[i]);
}

int sump(int* arr, int n)
{
int resalt = 0;
    for (size_t i = 0; i < n; ++i)
        if (arr[i] >= 0)
            resalt += arr[i];
return resalt;
}

int main(void)
{
int arr[SIZE];

    arrInput(arr, SIZE);
    printf("%d\n", sump(arr, SIZE));
    return 0;
}