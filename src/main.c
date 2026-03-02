#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"
#include "person.h"

int cmp_students(const void *a, const void *b) {
    const Person *x = (const Person*)a;
    const Person *y = (const Person*)b;
    
    int fac_cmp = strcmp(x->fac, y->fac);
    if (fac_cmp != 0) return fac_cmp;
    
    if (x->group != y->group) return x->group - y->group;
    
    int d_cmp = compare_dates(&x->date, &y->date);
    if (d_cmp != 0) return d_cmp;
    
    return strcmp(x->name, y->name);
}

int main() {
    Person vuz[10];
    
    for (int i = 0; i < 10; i++) {
        if (scanf("%s %s %d %d %d %d", 
              vuz[i].name, vuz[i].fac, &vuz[i].group, 
              &vuz[i].date.day, &vuz[i].date.month, &vuz[i].date.year) != 6) break;
    }
    
    qsort(vuz, 10, sizeof(Person), cmp_students);
    
    for (int i = 0; i < 10; i++) {
        printf("%s\t %d\t %02d.%02d.%d\t %s\n", 
               vuz[i].fac, vuz[i].group, vuz[i].date.day,
               vuz[i].date.month, vuz[i].date.year, vuz[i].name);
    }
    return 0;
}
