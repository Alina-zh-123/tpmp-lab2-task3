#include "date.h"
#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_students(const void *a, const void *b) {
    Person *x = (Person*)a;
    Person *y = (Person*)b;
    
    int fac_cmp = strcmp(x->fac, y->fac);
    if (fac_cmp != 0) return fac_cmp;
    
    if (x->group != y->group) return x->group - y->group;
    
    int date_cmp = date_cmp(&x->date, &y->date);
    if (date_cmp != 0) return date_cmp;
    
    return strcmp(x->name, y->name);
}

int main() {
    Person vuz[10];
    
    for (int i = 0; i < 10; i++) {
        printf("Enter name, faculty, group and date of entering:\n");
        scanf("%s %s %d %d %d %d", 
              vuz[i].name, 
              vuz[i].fac, 
              &vuz[i].group, 
              &vuz[i].date.day, 
              &vuz[i].date.month, 
              &vuz[i].date.year);
    }
    
    qsort(vuz, 10, sizeof(Person), cmp_students);
    
    for (int i = 0; i < 10; i++) {
        printf("%s\t %d\t %02d.%02d.%d\t %s\n", 
               vuz[i].fac,
               vuz[i].group,
               vuz[i].date.day,
               vuz[i].date.month,
               vuz[i].date.year,
               vuz[i].name);
    }
}
