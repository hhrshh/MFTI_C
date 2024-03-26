// E16 Д3 6
// Чаще других
// Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1. 

// Данные на входе: 		10 целых числе через пробел 
// Данные на выходе: 	Одно число, которое встречается чаще других. 

// Пример
// Данные на входе: 		4 1 2 1 11 2 34 11 0 11 
// Данные на выходе: 	    11 


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

int arr_more1(int* arr, int n)
{
int count_big = 0, count_low = 0, temp = 0, flag = 1;
    for (size_t i = 0; i < n; ++i)
    {    
        for (size_t j = i + 1; j < n; ++j)
            if (arr[i] == arr[j])
            {
                if (flag && !temp)
                    temp = arr[i];

                if (flag)
                    ++count_big;
                else
                    ++count_low;
            }
    if (count_low > count_big)
    {
        temp = arr[i];
        count_big = count_low;
    }
    flag = 0;
    count_low = 0;
    }       
return temp;
}

int main(void)

{
int arr[SIZE];

    arrInput(arr, SIZE);
    printf("%d\n", arr_more1(arr, SIZE));
    return 0;
}