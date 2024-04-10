// G9 ДЗ 4
// Удалить повторяющиеся символы
// В файле .txt строка из меленьких и больших английских букв, знаков препинания и пробелов. Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл .txt. 

// Данные на входе: 		Строка из меленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более 1000 сивмолов. 
// Данные на выходе: 	Строка из меленьких и больших английских букв. 

// Пример
// Данные на входе: 		abc cde def 
// Данные на выходе: 	    abcdef

#include <stdio.h>
#define SIZE 1001
#define INPUT "input.txt"
#define OUTPUT "output.txt"

int input(char*, int*);
int out(char*);
void swap(char*, char*);
void same_dell(char*, int);
void ssort(char*, int);


void arrShow(char* a)
{
    for (int i = 0; a[i] != '\0'; ++i)
        printf("%c", a[i]);
    printf("\n");
}

//-------------------------------------------------------------------- << main


int main(void)
{
int count;
char str[SIZE];
    input(str, &count);
    arrShow(str);
    out(str);
    return 0;
}


//--------------------------------------------------------------------- << main



int input(char* str, int* count)
{
FILE *in;
int i = 0, c;

    if((in = fopen(INPUT, "r")) == NULL)
    {
         perror("Error occured while opening output file!");
         return 1;
    }

    for(i = 0;((c = getc(in)) != EOF) && (c != '\n');)
        if(c != ' ')
        {
            str[i] = c;
            ++i;
        }
        else
            continue;                                            
        str[i] = '\0';
        *count = i;
        fclose(in);
        return 0;
}

int out(char* str)
{
FILE *out;
int flag = 1;
    if((out = fopen(OUTPUT, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }

    for (int i = 0; str[i] != '\0'; ++i)
    {
        flag = 1;
        for (int j = i - 1; j >= 0; --j)
            if(str[i] == str[j])
                flag = 0;
        if(flag)
            fprintf(out, "%c", str[i]);
    }
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

void same_dell(char* str, int counter)
{
int flag = 0;
    for (int i = 0; i < counter; ++i)
    {
        for (int j = i + 1; j < counter; ++j)
        {
            if(str[i] == str[j] && str[i] != '~')
            {
                str[j] = '~';
                flag = 1;
            } 
        }

        if(flag)
            {
                str[i] = '~';
                flag = 0;
            }
    }
}

void ssort(char* str, int counter)
{
    for (int k = 1; k < counter; k++)
        for (int j = k; j > 0 && str[j - 1] > str[j]; --j)
        {
            swap(&str[j], &str[j-1]);
        }
}