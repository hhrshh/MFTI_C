// G3 Практ 1
// Последний номер символа
// В файле .txt дана строка из 1000 символов. Показать номера символов, совпадающих с последним символом строки. Результат записать в файл .txt 

// Данные на входе: 		Строка не более 1000 символов 
// Данные на выходе: 	Целые числа через пробел - номера символа, который совпадает с последним символом строки. 

// Пример
// Данные на входе: 		aabbcdb 
// Данные на выходе: 	    2 3 

#include <stdio.h>
#define SIZE 1001
#define INPUT "input.txt"
#define OUTPUT "output.txt"

int input(char*);
int matches_last_in_string(char*, int);


//-------------------------------------------------------------------- main


int main(void)
{
char str_in[SIZE];

    matches_last_in_string(str_in, input(str_in));
    return 0;
}


//-------------------------------------------------------------------- main



int input(char *str_in)
{
FILE *in;
int count = 0, c;

    if((in = fopen(INPUT, "r")) == NULL)
    {
         perror("Error occured while opening output file!");
         return 1;
    }
    while(((c = getc(in)) != EOF) && (c != '\n'))
        str_in[count++] = c;
    str_in[count] = '\0';
    
    fclose(in);
    return count;
}

int matches_last_in_string(char* str, int count)
{
FILE *out;
    if((out = fopen(OUTPUT, "w")) == NULL)
    {
         perror("Error occured while opening output file!");
         return 1;
    }

    for (int i = 0; i < count - 1; ++i)
    {
        if(str[i] == str[count - 1])
            fprintf(out, "%d ", i);
    }
}
 