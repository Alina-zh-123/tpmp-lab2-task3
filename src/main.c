#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h" 

int cmp_students(const void *a, const void *b) {
    const Person *x = (const Person*)a;
    const Person *y = (const Person*)b;
    
    int fac_cmp = strcmp(x->fac, y->fac);
    if (fac_cmp != 0) return fac_cmp;
    
    if (x->group != y->group) return x->group - y->group;
    
    return compare_dates(&x->date, &y->date);
}

int main() {
    Person vuz[10];
    int count = 0;
    
    printf("Enter data (Name Faculty Group Day Month Year):\n");
    for (int i = 0; i < 10; i++) {
        if (scanf("%99s %99s %d %d %d %d", 
              vuz[i].name, vuz[i].fac, &vuz[i].group, 
              &vuz[i].date.day, &vuz[i].date.month, &vuz[i].date.year) != 6) break;
        count++;
    }
    
    if (count > 0) {
        qsort(vuz, count, sizeof(Person), cmp_students);
    }
    
    for (int i = 0; i < count; i++) {
        printf("%s\t %d\t %02d.%02d.%d\t %s\n", 
               vuz[i].fac, vuz[i].group, vuz[i].date.day,
               vuz[i].date.month, vuz[i].date.year, vuz[i].name);
    }
    return 0;
}
