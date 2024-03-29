// Сумма цифр равна 10
// Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10. 

// Данные на входе:		Натуральное число 
// Данные на выходе:	YES или NO 

// Пример №1
// Данные на входе:		1234 
// Данные на выходе:	YES 

// Пример №2
// Данные на входе:		1233 
// Данные на выходе:	NO 


#include <stdio.h>
 
int main()
{
unsigned int a, sum;
    scanf("%d", &a);
    for (;a > 0; a /= 10)
        sum += a % 10;
    printf("%s\n", sum == 10 ? "YES" : "NO"); 
    return 0;
}
