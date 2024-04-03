// реднее арифметическое массива
// Считать массив из 12 элементов и подсчитать среднее арифметическое элементов массива. 

// Данные на входе: 		12 целых чисел через пробел 
// Данные на выходе: 	Среднее арифметическое в формате "%.2f" 

// Пример №1
// Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0 5 7 
// Данные на выходе: 	1.08 

// Пример №2
// Данные на входе: 		1 2 3 4 5 6 7 8 9 10 11 12 
// Данные на выходе: 	6.50

#include <stdio.h>
#define SIZE 12

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

double average(int* arr, int n)
{
int resalt = 0;
    for (size_t i = 0; i < n; ++i)
            resalt += arr[i];
return (double)resalt / n;
}

int main(void)
{
int arr[SIZE];

    arrInput1(arr, SIZE);

    printf("%.2f\n", average(arr, SIZE));
    return 0;
}