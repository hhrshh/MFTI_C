# include <stdio.h>

// На вход подается произвольное трехзначное число. 
// Нужно напечатать произведение цифр.
// Данные на входе:       Трехзначное целое положительное число
// Данные на выходе:      Одно целое число 
//printf("%s = %d, %d, %d, %d, %d, %d, %d, %d\n", a, (a[0]-'0'), (a[1]-'0'), (a[2]-'0'), (a[3]-'0'), (a[4]-'0'), (a[5]-'0'), (a[6]-'0'), (a[7]));




int main(void)
{
   char a[]="12345678";
    for (size_t i = 0; i < sizeof(a)/sizeof(*a); ++i)
    {
        /* code */
    }
    
   if ((a[0]-'0') == 2)
   {
    printf("ETO 1");
   }
   
   return 0;
}