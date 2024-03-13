// C9 Практ 2
// Факториал
// Составить функцию вычисления N!. Использовать ее при вычислении факториала
// int factorial(int n)

// Данные на входе: 		Целое положительное число не больше 20 
// Данные на выходе: 	Целое положительное число 

// Пример №1
// Данные на входе: 		5 
// Данные на выходе: 	120 

#include <stdio.h>


int factorial(int n)
{
if (n == 0) return 1;
    for (size_t i = n, n = 1; i >= 1; --i)
    {
        n *= i;
        if (i == 1) return n;
    }
}
int main(void)
{
int n;

    scanf("%d",&n);

    printf("%d\n",factorial(n));
    return 0;
}
