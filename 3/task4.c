# include <stdio.h>

// Ввести три числа, найти их  среднее арифметическое
// Нужно напечатать среднее арифметическое чисел
// Данные на входе:       Три целых целых числа через пробел
// Данные на выходе:    Вещественное число в формате %.2f



int main(void)
{
   int a, b, c;
   scanf("%d%d%d", &a, &b, &c);
   printf("%d + %d + %d / 3 = %.2f\n", a, b, c, ((double)a+(double)b+(double)c)/3.);
  
}