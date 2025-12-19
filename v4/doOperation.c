// Author: Andrija Vukman
// Date: 2025-12-19
// CALCULATOR
// Version 4


#include <stdio.h>
#include <stdlib.h>
#include "doOperation.h"


double doOperation(double *a, double *b, char *operator) {
        switch (*operator) {
        case '+': return (*a) + (*b);
        case '-': return (*a) - (*b);
        case '*': return (*a) * (*b);
        case '/':
            if (*b == 0.0) {
                printf("Fatal error: zero division...\n");
                exit(-1);
            }
            return (*a) / (*b);
        case '%':
            int mod = (int)(*a) % (int)(*b);
            return (double)mod;
        default: 
            printf("Fatal error: invalid operation...\n");
            exit(-1);
        }
}
