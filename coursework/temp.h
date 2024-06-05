#ifndef TEMP_H
#define TEMP_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define YEAR 0
#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12



struct sensors // Показания датчика температуры
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t t;
};

//-----------------------------------------------------------API функции----------------------------------------------------------//
int print_statistic_t(struct sensors *, int, int*, int*, int*, int*, int*); // печать статистики
int get_file(const char *, int*, int*, struct sensors**);  // загрузить данные из файла
int get_month(char *); // проверка месяца

int get_statistic(struct sensors* data, int , int* , int* , int*, int*); //
void calculate_statistic(int*, struct sensors*, int*, int*, int*, int, int); // статистика за месяц
int max(int, int);
int min(int, int);


#endif