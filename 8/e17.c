// E17
// Только один раз
// Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран. 

// Данные на входе: 		10 целых чисел через пробел 
// Данные на выходе: 	Элементы которые встречаются только один раз через пробел 

// Пример
// Данные на входе: 		5 -4 0 1 4 -3 -3 3 0 2 
// Данные на выходе: 	    5 -4 1 4 3 2 




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

void only_one(int* arr, int n)
{
int temp = 0, count = 1, debug = 0;
    for (size_t i = 0; i < n; ++i)
    {    
        for (size_t j = 0; j < n; ++j)
            if (arr[i] != arr[j])
            {
                ++count;
            }
    if (count == n)
        printf("%d ", arr[i]);
    count = 1;
    }
}

int main(void)

{
int arr[SIZE];

    arrInput(arr, SIZE);
    only_one(arr, SIZE);
    return 0;
}