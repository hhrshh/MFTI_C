#ifndef MAIN_H
#define MAIN_H

// //#define DEBUG
// #if defined DEBUG
// #define DEBBUGPRINT fprintf(stderr, "debug in %d line func: %s\n, line func: %s\n", __LINE__, __FUNC__);
// #else
// #define DEBBUGPRINT

#define SIZE 30
#define OPTIONS_USAGE "Usage: temp [OPTION]... [FILE_PATH]\n"
#define OPTIONS_DESCRIPTION "Description: a console application for reading temperature values from a CSV file.\n"
#define OPTIONS_HELP "options: -h, display help message.\n"
#define OPTIONS_A "  -h display this help text.\n"
#define OPTIONS_B "  -f the path to the CSV file containing temperature data.\n"
#define OPTIONS_C "  -m <month_number> if this option is specified, displayed only statistics for the specified month.\n"
#define OPTIONS_ERROR "Error argument: %s, try -h for help.\n", argv[optind-1]
#endif
