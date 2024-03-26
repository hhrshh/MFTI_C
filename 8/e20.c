// E20 ДЗ *
// Переставить цифры
// Переставить цифры в числе так, чтобы получилось максимальное число. 
// Данные на входе: 		Одно целое не отрицательное число 
// Данные на выходе: 	Целое неотрицательное число 

// Пример №1
// Данные на входе: 		1229 
// Данные на выходе: 	9221 

// Пример №2
// Данные на входе: 		19 
// Данные на выходе: 	91 

#include <stdio.h>
#define SIZE 10

void arrShow(char* arr, int n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%d", arr[i]-'0');
printf("\n");
}
void bubbleSortL(char* arr, int n)
{
    for (size_t j = 0; j < n; ++j)
    {
        for (size_t i = 0; i < n - 1; ++i)
        {
            if (arr[i] < arr[i+1])
            { 
                char t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
            }
        }
    }
}

int main(void)
{
char arr[SIZE];
int n;

    scanf("%s%n", arr, &n);
    bubbleSortL(arr, SIZE);
    arrShow(arr, n);
    return 0;
}