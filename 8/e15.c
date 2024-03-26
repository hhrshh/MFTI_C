// E15 Практик 3
// Положительные и отрицательные
// Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, во второй - только отрицательные. Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов. 

// Данные на входе: 		10 целых чисел через пробел. 
// Данные на выходе: 	Сперва положительные числа, потом отрицательыне числа, через пробел. 

// Пример
// Данные на входе: 		5 -4 0 1 4 -3 -3 3 0 2 
// Данные на выходе: 	    5 1 4 3 2 -4 -3 -3 


#include <stdio.h>
#define SIZE 10

void arrShow(int* arr, int n)
{
    for (size_t i = 0; i < n; ++i)
        if (arr[i])
            printf("%d ", arr[i]);
}

void arrInput(int* arr1, int* arr2, int n)
{

    for(int i = 0, tmp; i < n; ++i) 
    {    
        scanf("%d", &tmp);
        if (tmp > 0)
            arr1[i] = tmp;
        else if (tmp < 0)
            arr2[i] = tmp;    
    }
}

int main(void)
{
int arr1[SIZE] = {0}, arr2[SIZE] = {0};

    arrInput(arr1, arr2, SIZE);
    arrShow(arr1, SIZE);
    arrShow(arr2, SIZE);
    return 0;
}