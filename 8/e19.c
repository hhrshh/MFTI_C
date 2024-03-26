
// E19 ДЗ *
// Цифры по порядку
// Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N. 

// Данные на входе: 		Одно натуральное число N 
// Данные на выходе: 	Цифры через пробел 

// Пример
// Данные на входе: 		54412 
// Данные на выходе: 	5 4 4 1 2 



#include <stdio.h>

void delimiter(int n)
{
    if (n > 0)
    {
        delimiter(n / 10);  
        printf("%d ", n % 10);
    }
}

int main()
{
int n;
scanf("%d", &n);
delimiter(n);
printf("\n");
return 0;
}
