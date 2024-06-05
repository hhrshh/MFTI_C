#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include "main.h"
#include "temp.h"



int main(int argc, char* argv[])
{
int month = 0, fflag = 0;

char filename; // название файла
int average[13]; // средняя температура 0 - за год 1 - 12 за месяц
int min_t[13];   // минимальная температура
int max_t[13];   // максимальная температура
int nu_value[13] = {0}; // количество значений по месяцам
int nu_error[13] = {0}; // количество строк с ошибкой
int num = 0; // количество элементов в структуре


struct sensors* data = NULL; // для корректной работы динамического массива


int rez = 0;
    if(!(argc > 1))
        printf(OPTIONS_USAGE
        OPTIONS_HELP);
                
    while((rez = getopt(argc,argv,"hHf:m:")) != -1)
    {
        switch (rez)
        {
        case 'H':
        case 'h':
            printf(OPTIONS_USAGE
                 OPTIONS_A
                OPTIONS_B
                OPTIONS_C
                OPTIONS_DESCRIPTION);
            break;
        case 'm':
            if(!(month = get_month(optarg)))
            {
                printf("incorrect month!\n");
                printf(OPTIONS_HELP);
                return 1;
            }
            int x = 0;
            break;
        case 'f':
            if(get_file(optarg, &num, nu_error, &data))
            {
                printf(OPTIONS_HELP);
            }
            else
                fflag = 1;
            break;

        case '?':
            printf(OPTIONS_ERROR);
            return 1;
            break;
        }
    }
    if(fflag)
    {
        get_statistic(data, num, average, min_t, max_t, nu_value);
        print_statistic_t(data, month, nu_value, nu_error, average, min_t, max_t);
    }

    free(data);
    return 0;
}