// Сумма цифр равна произведению

// Составить логическую функцию, которая определяет, верно ли, что в данном числе сумма цифр равна произведению.

// int is_happy_number(int n)

// Данные на входе: 		Целое не отрицательное число 
// Данные на выходе: 	YES или NO 

// Пример №1
// Данные на входе: 		123 
// Данные на выходе: 	YES 

// Пример №2
// Данные на входе: 		528 
// Данные на выходе: 	NO


#include <stdio.h>

int grow_up(int a)
{
int resalt1 = 1, resalt2 = 0;
    for (; a > 0; a /= 10)
    {
        resalt1 *= a % 10;
        resalt2 += a % 10;
    }
    return resalt1 == resalt2 ? 0 : 1;
}
int main(void)
{
unsigned int a;

    scanf("%d", &a);

    grow_up(a) ? puts("NO") : puts("YES");
    return 0;
}
