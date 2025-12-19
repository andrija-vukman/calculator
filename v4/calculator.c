// Author: Andrija Vukman
// Date: 2025-12-19
// CALCULATOR
// Version 4


#include <stdio.h>
#include <stdlib.h>
#include "parseInput.h"
#include "doOperation.h"

#define BUFFER 64


void calculate();


int main() {
    calculate();
    return 0;
}


void calculate() {
    char input[BUFFER];
    double a, b;
    char operator;
    a = b = 0.0;

    printf("Enter your calculation: ");
    fgets(input, BUFFER, stdin);
    parseInput(input, &a, &b, &operator);
    printf("\nRESULT = %.10lf\n\n", doOperation(&a, &b, &operator));
}


