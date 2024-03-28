// По убыванию и по возрастанию
// Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию. 

// Данные на входе: 		10 целых чисел через пробел 
// Данные на выходе: 	Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию. 

// Пример №1
// Данные на входе: 		14 25 13 30 76 58 32 11 41 97 
// Данные на выходе: 	13 14 25 30 76 97 58 41 32 11 

// Пример №2
// Данные на входе: 		5 4 3 2 1 6 7 8 9 10 
// Данные на выходе: 	1 2 3 4 5 10 9 8 7 6 


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

void dfg(int* arr, int n, int upDown)
{
    for (size_t j = 0; j < n; ++j)
    {
        for (size_t i = 0, t; i < n - 1; ++i)
        {
            if (upDown ? arr[i] > arr[i+1] : arr[i] < arr[i+1])
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
    dfg(arr, SIZE / 2, 1);
    dfg(arr+5, SIZE / 2, 0);
    arrShow(arr, SIZE);
    return 0;
}