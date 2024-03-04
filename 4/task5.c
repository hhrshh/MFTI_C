# include <stdio.h>

// Определить уравнение прямой по координатам двух точек. Уравнение вида y=k*x+b
// Данные на входе:    	Четыре целых числа через пробел. Координаты X1 Y1 X2 Y2
// Данные на выходе:     Два числа k,b в формате "%.2f %.2f"
// k = (y2 — y1) / (x2 — x1)
//b = y1 — k * x1

int main(void)
{
   int x1, y1, x2, y2;
   float k, b;

   scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
   k = (float)(y2-y1)/(float)(x2-x1);
   b = (float)y1 - k * (float)x1;
   printf("%.2f %.2f\n", k, b);

   return 0;
}