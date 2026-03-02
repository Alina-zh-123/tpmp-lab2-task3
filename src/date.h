#ifndef DATE_H
#define DATE_H

typedef struct {
    int day;
    int month;
    int year;
} Date;

int compare_dates(const Date *a, const Date *b);

#endif
