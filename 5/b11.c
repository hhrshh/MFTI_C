// Перевернуть число
// Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д. 

// Данные на входе:		Целое неотрицательное число 
// Данные на выходе:	Целое неотрицательное число наоборот 

// Пример №1
// Данные на входе:		1234 
// Данные на выходе:	4321 

// Пример №2
// Данные на входе:		782 
// Данные на выходе:	287 

#include <stdio.h>
 
int main(void)
{
unsigned long int a, deg = 1, res = 0;
int n;
    scanf("%ld%n", &a, &n);
    for (; a > 0; a /= 10, --n)
    {   
        
        for (int i = n; i > 0; --i)
            {
                    
                if (i == 1) 
                {
                    deg *= a % 10;
                    break;
                }
                deg *= 10; 
            }
    res += deg;
    deg = 1;
    }
printf("%ld\n", res);
return 0;
}

