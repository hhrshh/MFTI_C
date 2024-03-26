// E10 ДЗ 3
// Циклический сдвиг массива вправо на 4
// Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента. 

// Данные на входе: 		12 целых чисел через пробел 
// Данные на выходе: 	12 целых чисел через пробел 

// Пример №1
// Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0 5 7 
// Данные на выходе: 	    1  0 5 7 4 -5 3 10 -4 -6 8 -10 

// Пример №2
// Данные на входе: 		1 2  3  4  5 6 7 8 9  10 11 12 
// Данные на выходе: 	    9 10 11 12 1 2 3 4 5  6  7  8 


#include <stdio.h>
#define SIZE 12

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

void shiftRight1(int* arr, int n)
{
int temp = arr[n - 1];
    for (size_t i = n - 1; i > 0; --i)
        arr[i] = arr[i-1];
arr[0] = temp;
}

int main(void)
{
int arr[SIZE];

    arrInput(arr, SIZE);
    shiftRight1(arr, SIZE);
    shiftRight1(arr, SIZE);
    shiftRight1(arr, SIZE);
    shiftRight1(arr, SIZE);
    arrShow(arr, SIZE);
    return 0;
}