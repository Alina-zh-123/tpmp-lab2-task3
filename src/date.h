#ifndef DATE_H
#define DATE_H

struct Date {
    int day;
    int month;
    int year;
};

int compare_dates(const struct Date *a, const struct Date *b);

#endif
