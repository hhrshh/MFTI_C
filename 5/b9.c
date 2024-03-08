// Все цифры четные
// Ввести целое число и определить, верно ли, что все его цифры четные. 
// Данные на входе:		Одно целое число 
// Данные на выходе:	YES или NO 

// Пример №1
// Данные на входе:		2684 
// Данные на выходе:	YES 

// Пример №2
// Данные на входе:		2994 
// Данные на выходе:	NO 

#include <stdio.h>
 
int main(void)
{
int long a;
int flag = 0;
scanf("%ld", &a);
	for (; a > 0; a /= 10)
    {
        if (a % 10 % 2 != 0)
            {
                flag = 1;
                break;
            }
    }
printf("%s\n", flag == 1 ? "NO" : "YES");
return 0;
}
