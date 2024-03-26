// E13 ДЗ 5
// Вторая с конца ноль 
// Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль. 

// Данные на входе: 		10 целых чисел через пробел. 
// Данные на выходе: 	Целые числа через пробел, у которых вторая с конца цифра - ноль 

// Пример
// Данные на входе: 		40 105 203 1 14 1000 22 33 44 55 
// Данные на выходе: 	    105 203 1 1000 


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

int arr_more1(int* arr, int* arrResult, int n)
{
int t = 0;
    for (size_t i = 0; i < n ; ++i)
    {
        if (0 == (arr[i] / 10) % 10)
        {
            arrResult[t] = arr[i];
            ++t;
        }
    }
return t;
}

int main(void)

{
int arr[SIZE], arrResult[SIZE] = {0};
int s;

    arrInput(arr, SIZE);
    s = arr_more1(arr, arrResult, SIZE);
    arrShow(arrResult, s);
    return 0;
}