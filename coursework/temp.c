#include <stdlib.h>
#include "temp.h"

int get_file(const char* file_name, int* num, int* nu_error, struct sensors **data)
{
    FILE *input;
        if((input = fopen(file_name, "r")) == NULL)
        {
            printf("error open file,\n");
            return 1;
        }
    char buf[64]; // буфер для чтения
    printf ("\033[91m=============================================================\033[0m\n");
    printf ("Number of lines read with error:");
    while(fgets(buf, sizeof(buf), input))
    {
        struct sensors new_data;
        ++nu_error[0]; // увеличиваешь счетчик строк
        if(sscanf(buf, "%hd;%hhd;%hhd;%hhd;%hhd;%hhd", &new_data.year, &new_data.month, &new_data.day, &new_data.hour, &new_data.minute, &new_data.t) == 6) 
        {
            (*data) = realloc(*data, sizeof(struct sensors) * (*num + 1)); //увеличиваем выделенную память  на размер одной структуры
            if(!(*data)) 
            { 
                printf("Memory allocation error\n"); //если память не выделилась закрыть, сообщить об ошибке
                fclose(input); 
                return 1;
            }
            (*data)[*num] = new_data; //добавляем структуру и  увеличиваем счетчик считанных строк
            *num = *num + 1; 
        }
        else
        {
            if(new_data.month)      // если показания месяца считались добавить ошибку в массив ошибок и выводик строку с ошибкой
                ++nu_error[new_data.month];
            printf(" %d", nu_error[0]);
        }
    }
    printf("\nTotal values read: %d\n", *num);
    fclose(input);
    return 0;
}
//-----------------------------------------------------------API функции-----------------------------------------------------------------//
int print_statistic_t(struct sensors* data, int month, int* n, int* nu_error, int* average, int* min_t, int* max_t)
{
    printf ("\033[91m=============================================================\033[0m\n");
    printf("   # Year Month NuValue ErValue MonthAvg MonthMax MonthMin\n");
    if(month)
    {
        printf("%4d %4hd %5d %7d %7d %8d %8d %8d\n", month, data[month].year, month, n[month], nu_error[month], average[month], min_t[month], max_t[month]);
        printf ("\033[91m=============================================================\033[0m\n");
    }
    else
    {
        for(int i = 1, s = 1; i <= 12; ++i)
        {
            if(min_t[i] != -99)
                printf("%4d %4hd %5d %7d %7d %8d %8d %8d\n", s++, data[0].year, i, n[i], nu_error[i], average[i], min_t[i], max_t[i]);
        }
        printf ("\033[91m=============================================================\033[0m\n");
        printf ("Statistic for year: avarage t = %d, max t = %d, min t = %d\n", average[YEAR], min_t[YEAR], max_t[YEAR]);
        printf ("\033[91m=============================================================\033[0m\n");
    }
    return 0;
}

//------------------------------------------------------statistics function-------------------------------------------------------------//
int get_statistic(struct sensors* data, int count, int* average, int* max_t, int* min_t, int* nu_value) //
{
int tmp_t[13] = {0};                                                                         // переменные для промежуточных вычислений
int tmp_max[13] = {-99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99};         //
int tmp_min[13] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};                      //
    for (int i = 0; i < count; ++i)
    {
        calculate_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, data[i].month);
        calculate_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, YEAR);
    }
    for (int i = YEAR; i <= DEC; ++i)
    {
        average[i] = (double)tmp_t[i] / nu_value[i];
        min_t[i] = tmp_min[i];
        max_t[i] = tmp_max[i];
    }
}

void calculate_statistic(int* average_t, struct sensors* data, int* min_t, int* max_t, int* n, int i, int month)
{
    average_t[month] += data[i].t;
    min_t[month] = min(min_t[month], data[i].t);
    max_t[month] = max(max_t[month], data[i].t);
    ++n[month];
}

int max(int t1, int t2)
{
    return t1 > t2 ? t1 : t2;
}

int min(int t1, int t2)
{
    return t1 < t2 ? t1 : t2;
}

int get_month(char* month)
{
int resalt = 0;
    for(int i = 0; month[i] != '\0'; ++i)
    {
        if(i)
            resalt *= 10;
        resalt += month[i] - '0';
        if(i > 1)
            return 0;
    }
    if(resalt <= 12)
        return resalt;
    return 0;
}