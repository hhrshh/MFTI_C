// Четные и нечетные
// Написать функцию и программу, демонстрирующую работу данной функции.
// Дан целочисленный массив из 10 элементов. Необходимо определить количество четных и нечетных чисел. Если количество чётных чисел больше, чем количество нечётных, заменить каждое нечетное число на произведение нечетных цифр в его десятичной записи. Если количество нечётных чисел больше или равно количеству чётных, заменить каждое чётное число на произведение чётных цифр в его десятичной записи. 

// Данные на входе: 		10 целых чисел через пробел 
// Данные на выходе: 	10 целых чисел через пробел 

// Пример №1
// Данные на входе: 		48 31 20 61 97 12 18 100 200 123 
// Данные на выходе: 	48 3 20 1 63 12 18 100 200 3 

// Пример №2
// Данные на входе: 		48 25 57 34 23 91 90 85 30 79 
// Данные на выходе: 	32 25 57 4 23 91 0 85 0 79 

#include <stdio.h>
#define SIZE 10

void arrShow(int* a, int n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

void arrInput(int* a, int n)
{ 
    for(size_t i = 0; i < n; ++i) 
        scanf("%d", &a[i]);
}

int odd_or_even(int n, int a[])
{
int count = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (!(a[i] % 2))
            count++;
    }
    return (n / 2) >= count;
}

int multiply_even(int number)
{
int resault = 1;
    for (; number > 0; number /= 10)
        if ((number % 10) % 2 == 0)
            resault *= number % 10;
    return resault;
}

int multiply_odd(int number)
{
int resault = 1;
    for (; number > 0; number /= 10)
        if ((number % 10) % 2 != 0)
            resault *= number % 10;
    return resault;
}
// <----------------------------------------------------------main
int main(void)
{
int a[SIZE];

    arrInput(a, SIZE);
    if(odd_or_even(SIZE, a))
    {
        for (int i = 0; i < SIZE; ++i)
            if ((a[i] % 2) == 0)
                a[i] = multiply_even(a[i]);
    }
    else
    {
        for (int i = 0; i < SIZE; ++i)
            if ((a[i] % 2) != 0)
                a[i] = multiply_odd(a[i]);
    }
    arrShow(a, SIZE);
    return 0;
}
// <----------------------------------------------------------main