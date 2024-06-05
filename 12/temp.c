#include <stdlib.h>
#include "temp.h"

//-----------------------------------------------------------struct-----------------------------------------------------------------------//
void add_records_sensors(struct sensors* date, int number, uint16_t year, uint8_t month, uint8_t day, int8_t hour, int8_t minute, int8_t t)
{
    date[number].year = year;
    date[number].month = month;
    date[number].day = day;
    date[number].hour = hour;
    date[number].minute = minute;
    date[number].t = t;
}


int add_info_sensors(struct sensors* data)
{
int counter = 0;  
    add_records_sensors(data, counter++, 2023, 1, 16, 13, 32, -4);
    add_records_sensors(data, counter++, 2023, 1, 2, 13, 32, 2);
    add_records_sensors(data, counter++, 2023, 1, 1, 0, 4, 2);
    add_records_sensors(data, counter++, 2023, 2, 1, 0, 3, 5);
    add_records_sensors(data, counter++, 2023, 2, 1, 0, 1, -5);
    add_records_sensors(data, counter++, 2023, 3, 1, 0, 1, 1);
    add_records_sensors(data, counter++, 2023, 3, 1, 0, 1, 2);
    add_records_sensors(data, counter++, 2023, 3, 1, 0, 1, 3);
    add_records_sensors(data, counter++, 2023, 4, 1, 0, 1, 1);
    add_records_sensors(data, counter++, 2023, 4, 1, 0, 1, 2);
    add_records_sensors(data, counter++, 2023, 4, 1, 0, 1, 3);
    add_records_sensors(data, counter++, 2023, 5, 1, 0, 1, 1);
    add_records_sensors(data, counter++, 2023, 5, 1, 0, 1, 2);
    add_records_sensors(data, counter++, 2023, 5, 1, 0, 1, 3);
    add_records_sensors(data, counter++, 2023, 6, 1, 0, 1, 1);
    add_records_sensors(data, counter++, 2023, 6, 1, 0, 1, 2);
    add_records_sensors(data, counter++, 2023, 6, 1, 0, 1, 3);
    add_records_sensors(data, counter++, 2023, 7, 1, 0, 1, 10);
    add_records_sensors(data, counter++, 2023, 7, 1, 0, 1, 3);
    add_records_sensors(data, counter++, 2023, 8, 1, 0, 1, 1);
    add_records_sensors(data, counter++, 2023, 8, 1, 0, 1, 2);
    add_records_sensors(data, counter++, 2023, 8, 1, 0, 1, 3);
    add_records_sensors(data, counter++, 2023, 9, 1, 0, 1, 1);
    add_records_sensors(data, counter++, 2023, 9, 1, 0, 1, 2);
    add_records_sensors(data, counter++, 2023, 9, 1, 0, 1, 3);
    add_records_sensors(data, counter++, 2023, 10, 1, 0, 1, 3);
    return counter;
}

int get_file(char* file_name)
{
    FILE *input;
        if((input = fopen(file_name, "r")) == NULL)
            return 1;
    fclose(input);
    return 0;
}

//-----------------------------------------------------------API функции-----------------------------------------------------------------//
int print_debug_info(struct sensors* data, int number)
{
    printf("\033[91m========================================\033[0m\n");        
        for(int i = 0; i < number; ++i)
            printf("%04d-%02d-%02d %02d:%02d t =%3d\n", data[i].year, data[i].month, data[i].day, data[i].hour, data[i].minute, data[i].t);
    return 0;
}

int print_statistic_t(struct sensors* data, int month, int* average, int* min_t, int* max_t)
{
    printf ("\033[91m=============================================================\033[0m\n");
    printf("   # Year Month NuValue ErValue MonthAvg MonthMax MonthMin\n");
    if(month)
    {
        printf("%4d %4d %5d %7d %7d %8d %8d %8d\n", 1, 2023, month, 4, 5, average[month], min_t[month], max_t[month]);
        printf ("\033[91m=============================================================\033[0m\n");
    }
    else
    {
        for(int i = 1; i <= 12; ++i)
        {
            if(min_t[i] != -99)
                printf("%4d %4d %5d %7d %7d %8d %8d %8d\n", i, data[i].year, month, 4, 5, average[i], min_t[i], max_t[i]);
        }
        printf ("\033[91m=============================================================\033[0m\n");
        printf ("Statistic for year: avarage t = %d, max t = %d, min t = %d\n", average[YEAR], max_t[YEAR], min_t[YEAR]);
        printf ("\033[91m=============================================================\033[0m\n");
    }

    return 0;
}

//-------------------------------------------------------statistics function-------------------------------------------------------------//
int get_statistic(struct sensors* data, int count, int* average, int* max_t, int* min_t, int* nu_value) //
{
size_t tmp_t[13] = {0};                                                                         // переменные для промежуточных вычислений
int tmp_max[13] = {-99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99};            //
int tmp_min[13] = {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};                         //
    for (int i = 0; i < count; ++i)
    {
        if (data[i].month == JAN)
            calculate_month_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, JAN);
        else if (data[i].month == FEB)
            calculate_month_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, FEB);
        else if (data[i].month == MAR)
            calculate_month_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, MAR);
        else if (data[i].month == APR)
            calculate_month_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, APR);
        else if (data[i].month == MAY)
            calculate_month_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, MAY);
        else if (data[i].month == JUN)
            calculate_month_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, JUN);
        else if (data[i].month == JUL)
            calculate_month_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, JUL);
        else if (data[i].month == AUG)
            calculate_month_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, AUG);
        else if (data[i].month == SEP)
            calculate_month_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, SEP);
        else if (data[i].month == OCT)
            calculate_month_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, OCT);
        else if (data[i].month == NOV)
            calculate_month_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, NOV);
        else if (data[i].month == DEC)
            calculate_month_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, DEC);
        calculate_year_statistic(tmp_t, data, tmp_min, tmp_max, nu_value, i, YEAR);
    }
    for (int i = YEAR; i <= DEC; ++i)
    {
        average[i] = (double)tmp_t[i] / nu_value[i];
        min_t[i] = tmp_min[i];
        max_t[i] = tmp_max[i];
    }
}

void calculate_month_statistic(size_t* average_t, struct sensors* data, int* min_t, int* max_t, int* n, int i, int month)
{
    average_t[month] += data[i].t;
    min_t[month] = min(min_t[month], data[i].t);
    max_t[month] = max(max_t[month], data[i].t);
    ++n[month];
}

void calculate_year_statistic(size_t* average_t, struct sensors* data, int* min_t, int* max_t, int* n, int i, int month)
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
//------------------------------------------------------statistics function-------------------------------------------------------------//
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

//----------------------------------------------c Функции сортировки нисходящим слиянием-------------------------------------------------//
void mergeSort_t(struct sensors* data, int l, int r) // l - индекс начала левой последовательности r - првой
{
    if (l == r)
        return;            // границы сомкнулись
    int mid = (l + r) / 2; // определяем середину последовательности
                           // и рекурсивно вызываем функцию сортировки для каждой половины
    mergeSort_t(data, l, mid);
    mergeSort_t(data, mid + 1, r);

    int i = l; // индекс первого массива
    int j = mid + 1; // индекс второго массива
    struct sensors *tmp = (struct sensors*)malloc(r * sizeof(struct sensors));     // дополнительный массив
    for (int step = 0; step < r - l + 1; step++)                                   // для всех элементов дополнительного массива
    { 
        // записываем в формируемую последовательность меньший из элементов двух массивов
        // или остаток первого массива если j > r
        if ((j > r) || ((i <= mid) && (data[i].t < data[j].t)))
        {
            tmp[step] = data[i];
            ++i;
        }

        else 
        {
            tmp[step] = data[j];
            ++j;
        }
    }
        // переписываем сформированную последовательность в исходный массив
    for (int step = 0; step < r - l + 1; ++step)
        data[l + step] = tmp[step];
    free(tmp);
}


unsigned long long date_to_ull(struct sensors* data)
{
    return (unsigned long long)data->year << 32 | data->month << 24 | data->day << 16 | data->hour << 8 | data->minute;
}

void mergeSort_d(struct sensors* data, int l, int r) // l - индекс начала левой последовательности r - првой
{
    if (l == r)
        return;            // границы сомкнулись
    int mid = (l + r) / 2; // определяем середину последовательности
                           // и рекурсивно вызываем функцию сортировки для каждой половины
    mergeSort_d(data, l, mid);
    mergeSort_d(data, mid + 1, r);

    int i = l;      // индекс первого массива
    int j = mid + 1; // индекс второго массива
    struct sensors *tmp = (struct sensors*)malloc(r * sizeof(struct sensors));     // дополнительный массив
    for (int step = 0; step < r - l + 1; step++)                                   // для всех элементов дополнительного массива
    { 
        // записываем в формируемую последовательность меньший из элементов двух массивов
        // или остаток первого массива если j > r
        if ((j > r) || ((i <= mid) && (date_to_ull(data + i) < date_to_ull(data + j))))
        {
            tmp[step] = data[i];
            ++i;
        }

        else 
        {
            tmp[step] = data[j];
            ++j;
        }
    }
        // переписываем сформированную последовательность в исходный массив
    for (int step = 0; step < r - l + 1; ++step)
        data[l + step] = tmp[step];
    free(tmp);
}
