# include <stdio.h>

// Ввести три числа, найти их сумму. 
// Нужно напечатать сумму трех чисел.
// Данные на входе:       Три целых числа через пробел
// Данные на выходе:    Строка вида %d+%d+%d=%d

int main(void)
{
   int a, b, c, sum;
   scanf("%d%d%d", &a, &b, &c);
   sum = a + b + c;
   printf("%d + %d + %d = %d\n", a, b, c, sum);
  
}