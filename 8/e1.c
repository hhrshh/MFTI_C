// E1 ДЗ 1
// Среднее арифметическое чисел
// Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива. 

// Данные на входе: 		5 целых ненулевых чисел через пробел 
// Данные на выходе: 	Одно число в формате "%.3f" 

// Пример №1
// Данные на входе: 		4 15 3 10 14 
// Данные на выходе: 	9.200 

// Пример №2
// Данные на входе: 		1 2 3 4 5 
// Данные на выходе: 	3.000 

#include <stdio.h>
#define SIZE 5

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

float arrAverage(int* arr, int n)
{
int resalt = 0;
    for (size_t i = 0; i < n; ++i)
        resalt += arr[i];
return (float)resalt / n;
}

int main(void)
{
int arr[SIZE];

    arrInput(arr, SIZE);
    printf("%.3f\n", arrAverage(arr, SIZE));
    return 0;
}