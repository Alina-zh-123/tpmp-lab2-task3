#ifndef PERSON_H
#define PERSON_H

#include "date.h"

typedef struct {
    char name[100];
    char fac[100];
    int group;
    Date date;
} Person;

#endif
