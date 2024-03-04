# include <stdio.h>

// Ввести номер месяца и вывести название времени года.
// Данные на входе:    	Целое число от 1 до 12 - номер месяца.
// Данные на выходе:     Время года на английском: winter, spring, summer, autumn (используйте switch)






int main(void)
{
   int i;
   scanf("%d", &i);
   switch (i)
    {
    case 1:
        printf("Summer\n");
        break;
    case 2:
        printf("Autumn\n");
        break;
    case 3:
        printf("Winter\n");
        break;
    case 4:
        printf("Spring\n");
        break;
    }
   
   return 0;
}