// E7 Практик 2
// Инверсия половинок
// Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива.
// Необходимо изменить считанный массив и напечатать его одним циклом. 

// Данные на входе: 		10 целых элементов массива через пробел. 
// Данные на выходе: 	10 целых элементов массива через пробел. 

// Пример №1
// Данные на входе: 		4 -5 3 10 -4 -6 8 -10 1 0 
// Данные на выходе: 	-4 10 3 -5 4 0 1 -10 8 -6 

// Пример №2
// Данные на входе: 		1 2 3 4 5 6 7 8 9 10 
// Данные на выходе: 	    5 4 3 2 1 10 9 8 7 6 
//1 - 5  6 - 10
//2 - 3  7 - 9


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

void arrReverse(int* arr, int n)
{
int temp = 0;
    for (size_t i = 0, j = n - 1; i < j; ++i, --j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main(void)
{
int arr[SIZE];

    arrInput(arr, SIZE);
    for(int i=0; i < 2;i++)
        arrReverse(arr+i*SIZE/2, SIZE/2);
    arrShow(arr, SIZE);
    return 0;
}