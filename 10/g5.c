// G5 ДЗ 2
// Заменить a на b
// В файле .txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в .txt. 

// Данные на входе: 		Строка из маленьких и больших английских букв, знаков препинания и пробелов. 
// Данные на выходе: 	Строка из маленьких и больших английских букв, знаков препинания и пробелов. 

// Пример
// Данные на входе: 		aabbccddABCD 
// Данные на выходе: 	    bbaaccddBACD 

#include <stdio.h>
#define SIZE 10001
#define INPUT "input.txt"
#define OUTPUT "output.txt"

int input(char*);
int output(char*);
void replacing_strings(char*);
void swap(char*, char*);

void arrShow(char* a)
{
    for (int i = 0; a[i] != '\0'; ++i)
        printf("%c", a[i]);
    printf("\n");
}

//-------------------------------------------------------------------- << main


int main(void)
{
char str[SIZE];
    input(str);
    replacing_strings(str);
    output(str);
    return 0;
}


//--------------------------------------------------------------------- << main



int input(char* str)
{
FILE *in;
int i = 0, c;

    if((in = fopen(INPUT, "r")) == NULL)
    {
         perror("Error occured while opening output file!");
         return 1;
    }

    for(i = 0;((c = getc(in)) != EOF) && (c != '\n'); ++i)
        str[i] = c;                                                   
    str[i] = '\0';
    fclose(in);
}

int output(char* str)
{
FILE *out;
    if((out = fopen(OUTPUT, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }

    for (int i = 0; str[i] != '\0'; ++i)
            fprintf(out, "%c", str[i]);

    fclose(out);
    return 0;
}


void swap(char* a, char* b)
{
char t;
    t = *a;
    *a = *b;
    *b = t;
}

void replacing_strings(char* str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if(str[i] == 'A')
            str[i] = 'B';
        else if(str[i] == 'B')
            str[i] = 'A';
        else if(str[i] == 'a')
            str[i] = 'b';
        else if(str[i] == 'b')
            str[i] = 'a';
    }
    
}