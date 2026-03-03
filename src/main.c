#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h" 
#include "date.h"

int cmp_students(const void *a, const void *b) {
    const struct Person *x = (const struct Person*)a;
    const struct Person *y = (const struct Person*)b;
    
    int result;
    
    result = strcmp(x->fac, y->fac);
    if (result != 0) return result;
    
    result = x->group - y->group;
    if (result != 0) return result;
    
    result = compare_dates(&x->date, &y->date);
    if (result != 0) return result;
    
    return strcmp(x->name, y->name);
}

int main() {
    struct Person vuz[10];
    int count = 0;
    
    printf("Enter data (Name Faculty Group Day Month Year):\n");
    for (int i = 0; i < 10; i++) {
        if (scanf("%99s %99s %d %d %d %d", 
              vuz[i].name, vuz[i].fac, &vuz[i].group, 
              &vuz[i].date.day, &vuz[i].date.month, &vuz[i].date.year) != 6) break;
        count++;
    }
    
    if (count > 0) {
        qsort(vuz, count, sizeof(struct Person), cmp_students);
    }
    
    for (int i = 0; i < count; i++) {
        printf("%s\t %d\t %02d.%02d.%d\t %s\n", 
               vuz[i].fac, vuz[i].group, vuz[i].date.day,
               vuz[i].date.month, vuz[i].date.year, vuz[i].name);
    }
    return 0;
}
