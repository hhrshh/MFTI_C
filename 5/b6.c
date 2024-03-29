// B6 Урок 5 Практика №2
// Две одинаковые цифры рядом
// Ввести целое число и определить, верно ли, что в его записи есть  две одинаковые цифры, стоящие рядом. 

// Данные на входе:		Одно целое число 
// Данные на выходе:	Единственное слов: YES или NO 

// Пример №1
// Данные на входе:		1232 
// Данные на выходе:	NO 

// Пример №2
// Данные на входе:		1224 
// Данные на выходе:	YES 

#include <stdio.h> 


int main(void) 
{ 
    long long int a, n1, n2 = 0; 
    scanf("%lld", &a);
    while(a > 0)
    {   
        n1 = a % 10;
        if (n1 == n2)
        {
            printf("YES\n"); 
            return 0;  
        }
        n2 = n1;
        a /= 10;
    }
    printf("NO\n");
    return 0; 
}
