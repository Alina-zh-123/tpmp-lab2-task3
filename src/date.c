#include "date.h"

int compare_dates(const struct Date *a, const struct Date *b) {
    if (a->year != b->year) return a->year - b->year;
    if (a->month != b->month) return a->month - b->month;
    return a->day - b->day;
}
