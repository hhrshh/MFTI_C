#include "temp.h"

void add_records_sensors(struct sensors* date, int number, uint16_t year, uint8_t month, uint8_t day, int8_t t)
{
    date[number].year = year;
    date[number].month = month;
    date[number].day = day;
    date[number].t = t;
}

int add_info_sensors(struct sensors* data)
{
int counter = 0;  
    add_records_sensors(data, counter++, 2020, 1, 16, 1);
    add_records_sensors(data, counter++, 2021, 1, 2 , -2);
    add_records_sensors(data, counter++, 2022, 2, 7, 3);
    add_records_sensors(data, counter++, 2023, 3, 5, 4);
    return counter;
}

void print(struct sensors* data, int number)
{
    printf("===================================\n");        
        for(int i = 0; i < number; ++i)
            printf("%04d-%02d-%02d t = %3d\n", data[i].year, data[i].month, data[i].day, data[i].t);
}

int average_t(struct sensors* data)
{
    return 0;
}
int min_in_month_t(struct sensors* data)
{
    return 0;
}
int max_in_month_t(struct sensors* data)
{
    return 0;
}
int statistic_t(struct sensors* data)
{
    return 0;
}
