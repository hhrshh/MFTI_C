// F4 Практ 1
// Цифры в строке
// Написать функцию и программу, демонстрирующую работу данной функции.
// Вывести в порядке возрастания цифры, входящие в строку. Цифра - количество. Функция должно строго соответствовать прототипу:

// void print_digit(char s[])

// Данные на входе: 		Строка из английских букв, пробелов, знаков препинания и цифр 
// Данные на выходе: 	Функция должна принимать на вход строку и выводить на печать по формату: Цифра пробел количество. 

// Пример
// Данные на входе: 		Hello123 world77. 
// Данные на выходе: 	    1 1 2 1 3 1 7 2 


#include <stdio.h>
#define SIZE 20

void arrShow(int* a, int n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

void print_digit(char s[])
{
int count = 1;
    for (size_t i = 0, j; s[i] != '\0'; ++i)
    {   
        if (!(48 <= s[i] && s[i] <= 57))
            continue;

        for (j = i + 1; s[j] != '\0'; ++j)
        {
            if (s[i] == s[j])
            ++count;
        }

        for (size_t k = i; k > 0; --k)
            if (s[k-1] == s[i])
                goto next;
        printf("%c %d ", s[i], count);
        next: count = 1;
    }
    printf("\n");
}

int main(void)
{
char str[SIZE]="";

    fgets(str, SIZE, stdin);;
    print_digit(str);
    return 0;
}