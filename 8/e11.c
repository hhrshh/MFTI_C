// E11 ДЗ 4
// Отсортировать по последней цифре
// Считать массив из 10 элементов и отсортировать его по последней цифре. 

// Данные на входе: 		10 целых чисел через пробел 
// Этот же массив отсортированный по последней цифре 

// Пример №1
// Данные на входе: 		14 25 13 30 76 58 32 11 41 97 
// Данные на выходе: 	    30 11 41 32 13 14 25 76 97 58 

// Пример №2
// Данные на входе: 		109 118 100 51 62 73 1007 16 4 555 
// Данные на выходе: 	    100 51 62 73 4 555 16 1007 118 109


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

void bubbleSortL(int* arr, int n)
{
    for (size_t j = 0; j < n; ++j)
    {
        for (size_t i = 0, t; i < n - 1; ++i)
        {
            if (arr[i] % 10 > arr[i+1] % 10)
            {
                t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
            }
        }
    }
}

int main(void)
{
int arr[SIZE];

    arrInput(arr, SIZE);
    bubbleSortL(arr, SIZE);
    arrShow(arr, SIZE);
    return 0;
}