#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include "main.h"
#include "temp.h"



int main(int argc, char* argv[])
{
int month = 0, fflag = 0;
char filename;

struct sensors data[SIZE];

int average[13]; // средняя температура 0 - за год 1 - 12 за месяц
int min_t[13];   // минимальная температура
int max_t[13];   // максимальная температура
int nu_value[13] = {0}; // количество значений по месяцам
int s; // debug


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
            if(get_file(optarg))
            {
                perror("Error occured while opening input file!");
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
        s = add_info_sensors(data);
        get_statistic(data, s, average, min_t, max_t, nu_value);
        print_statistic_t(data, month, average, min_t, max_t);
    }

    // print_debug_info(data, s = add_info_sensors(data));
    // mergeSort_t(data, 0, s - 1);
    // print_debug_info(data, s);
    // mergeSort_d(data, 0, s - 1);
    // print_debug_info(data, s);

    return 0;
}