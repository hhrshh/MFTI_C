// G7 Практ 2
// Количество букв
// В файле .txt считать символьную строку, не более 10 000 символов. Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. Учитывать только английские буквы. Результат записать в файл .txt. 

// Данные на входе: 		Строка состоящая из английских букв, цифр, пробелов и знаков препинания. 
// Данные на выходе: 	Два целых числа. Количество строчных букв и количество заглавных букв. 

// Пример №1
// Данные на входе: 		aabbAB 
// Данные на выходе: 	4 2 

// Пример №2
// Данные на входе: 		HELLO WORLD 
// Данные на выходе: 	0 10 


#include <stdio.h>
#define SIZE 10001
#define INPUT "input.txt"
#define OUTPUT "output.txt"

int input(char*);
int output(char*);
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
int count_a = 0, count_A = 0;
    if((out = fopen(OUTPUT, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            ++count_a;
        else if(str[i] >= 'A' && str[i] <= 'Z')
            ++count_A;
    }
    fprintf(out, "%d %d", count_a, count_A);

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