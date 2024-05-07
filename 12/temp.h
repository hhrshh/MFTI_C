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
int print_statistic_t(struct sensors *, int, int*, int*, int*); // печать статистики
int get_file(char *);  // загрузить данные из файла
int get_month(char *); // проверка месяца

int get_statistic(struct sensors* data, int , int* , int* , int*, int*); //
int max(int, int);
int min(int, int);
void calculate_month_statistic(size_t*, struct sensors*, int*, int*, int*, int, int); // статистика за месяц
void calculate_year_statistic(size_t*, struct sensors*, int*, int*, int*, int, int);  // статистика за год
//-----------------------------------------------------------debug info----------------------------------------------------------//
int print_debug_info(struct sensors *, int); // debug info
void add_records_sensors(struct sensors *date, int, uint16_t, uint8_t, uint8_t, int8_t, int8_t, int8_t); // добавляем данные
int add_info_sensors(struct sensors *);      // добавляем показания
void mergeSort_t(struct sensors*, int, int); // сортировка по температуре
void mergeSort_d(struct sensors*, int, int); // сортировка по датер

#endif