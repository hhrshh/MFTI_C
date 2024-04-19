#ifndef TEMP_H
#define TEMP_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>

struct sensors      // Показания датчика температуры
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    int8_t t;
};

void add_records_sensors(struct sensors*, int, uint16_t, uint8_t, uint8_t, int8_t); // добавляем данные
int add_info_sensors(struct sensors*); // добавляем показания
void print(struct sensors*, int);    // печатаем структуру
int average_t(struct sensors*);                 // среднемесячная температура
int min_in_month_t(struct sensors*);           // минимальная температура в текущем месяце
int max_in_month_t(struct sensors*);          // максимальная температура в текущем
int statistic_t(struct sensors*);// Вывода статистику за год: • среднегодовая температура • минимальная температура • максимальная температура

#endif