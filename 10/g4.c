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

int input(char*, char*, int*, int*);
int compareWords(char*, char*);
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
int counter1, counter2;
char word1[SIZE], word2[SIZE];
    input(word1, word2, &counter1, &counter2);
    same_dell(word1, counter1);
    same_dell(word2, counter2);
    ssort(word1, counter1);
    ssort(word2, counter2);
    compareWords(word1, word2);
    return 0;
}


//--------------------------------------------------------------------- << main



int input(char* word1, char* word2, int* counter1, int* counter2)
{
FILE *in;
int i = 0, c;

    if((in = fopen(INPUT, "r")) == NULL)
    {
         perror("Error occured while opening output file!");
         return 1;
    }

    for(i = 0;(c = getc(in)) != ' '; ++i)
        word1[i] = c;                                                   
    word1[i] = '\0';
    *counter1 = i;

    for(i = 0;((c = getc(in)) != EOF) && (c != '\n'); ++i)
        word2[i] = c;                                                   
    word2[i] = '\0';
    *counter2 = i;
    fclose(in);
}

int compareWords(char* word1, char* word2)
{
FILE *out;
    if((out = fopen(OUTPUT, "w")) == NULL)
    {
        perror("Error occured while opening output file!");
        return 1;
    }

    for (int i = 0; word1[i] != '\0'; ++i)
    {
        if(word1[i] == '~')
        {
            fclose(out);
            return 0;
        }
        
        for (int j = 0; word2[j] != '\0'; ++j)
        {
            if(word1[i] == word2[j])
                fprintf(out, "%c ", word1[i]);
        }
    }
fclose(out);
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