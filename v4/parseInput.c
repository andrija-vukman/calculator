// Author: Andrija Vukman
// Date: 2025-12-19
// CALCULATOR
// Version 4


#include <stdio.h>
#include <stdlib.h>
#include "parseInput.h"


void parseInput(char *i, double *a, double *b, char *operator) {
    i = getNumber(i, a);
    i = getOperator(i, operator);
    i = getNumber(i, b);
}


char *skipWhitespace(char *i) {
    while (*i == ' ' || *i == '\t' || *i == '\n')
        ++i;
    return i;
}


char *getNumber(char *i, double *num) {
    char sign = '+';

    i = getSign(i, &sign);
    i = getDigits(i, num);

    if (sign == '-')
        (*num) *= (-1.0);
    return i;
}


char *getSign(char *i, char *sign) {
    i = skipWhitespace(i);
    if (*i == '(' || *i == '[' || *i == '{') 
        ++i;
    i = skipWhitespace(i);
    if (*i == '-') {
        *sign = '-';
        ++i;
    }
    if (*i == '+') {
        ++i;
    }
    i = skipWhitespace(i);
    if (*i == ')' || *i == ']' || *i == '}') 
        ++i;
    i = skipWhitespace(i);
    return i;
}


char *getDigits(char *i, double *num) {
    i = skipWhitespace(i);
    if (*i == '(' || *i == '[' || *i == '{') 
        ++i;
    i = skipWhitespace(i);
    while (*i >= '0' && *i <= '9') {
        *num = 10.0 * (*num) + (*i-'0');
        ++i;
    }
    i = skipWhitespace(i);
    if (*i == '.' || *i == ',') {
        ++i;
        i = skipWhitespace(i);

        double div;
        for (div = 1.0; *i >= '0' && *i <= '9'; div*=10.0) {
            *num = 10.0 * (*num) + (*i-'0');
            ++i;
        }
        *num /= div;
    }
    i = skipWhitespace(i);
    if (*i == ')' || *i == ']' || *i == '}') 
        ++i;
    i = skipWhitespace(i);
    return i;
}


char *getOperator(char *i, char *operator) {
    i = skipWhitespace(i);
    if (*i == '+' || *i == '-' || *i == '*' || *i == '/' || *i == '%') {
        *operator = *i;
        ++i;
    }
    i = skipWhitespace(i);
    return i;
}
