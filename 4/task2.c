# include <stdio.h>

// Ввести три числа и найти наибольшее из них

// Данные на входе:		Три целых числа через пробел
// Данные на выходе: 	Одно наибольшее целое число





int main(void)
{
   int a, b, c;
   scanf("%d%d%d", &a, &b, &c);
   printf("%d\n", a > b ? (a > c ? a : c) : (b > c ? b : c)); 
   
   
   return 0;
}