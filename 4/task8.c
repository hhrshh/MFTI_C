# include <stdio.h>

// Ввести пять чисел и  вывести наименьшее из них 
// Нужно напечатать наименьшее число

// Данные на входе:       Пять целых чисел разделенных пробелом
// Данные на выходе:    Одно целое число
   
// Данные на входе:        4    15    9    56    4
// Данные на выходе:     4 








int main(void)
{
   int a, b, c, d, e;
   scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
   printf("%d\n", (a < b ? a : b) < (c < d ? c : d) ? (a < b ? a : b) : (c < d ? c : d)) < e ? ((a < b ? a : b) < (c < d ? c : d) ? (a < b ? a : b) : (c < d ? c : d)) : e;
   
   return 0;
}