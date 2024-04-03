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
#define SIZE 5

void arrShow(int* arr, int n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%d ", arr[i]);
printf("\n");
}

void arrInput1(int* arr, int n)
{ 
    for(size_t i = 0; i < n; ++i) 
        scanf("%d", &arr[i]);
}

int min(int* arr, int n)
{
    for (size_t i = 1; i < n; ++i)
        if (arr[0] > arr[i])
            arr[0] = arr[i];
return arr[0];
}

int main(void)
{
int arr[SIZE];

    arrInput1(arr, SIZE);
    printf("%d\n", min(arr, SIZE));
    return 0;
}