// Author: Andrija Vukman
// Date: 2025-12-16
// CALCULATOR
// Version 3


#include <stdio.h>
#include <stdlib.h>
#define BUFFER 64


void calculate();
void parseInput(char*, int*, int*, char *operator);
char *skipWhitespace(char*);
char *getNumber(char*, int*);
char *getSign(char*, char *sign);
char *getDigits(char*, int*);
char *getOperator(char*, char*);
int doOperation(int*, int*, char *operator);


int main() {
    calculate();
    return 0;
}


void calculate() {
    char input[BUFFER];
    int a, b;
    char operator;
    a = b = 0;

    printf("Enter your calculation: ");
    fgets(input, BUFFER, stdin);
    parseInput(input, &a, &b, &operator);
    printf("\nResult = %d\n\n", doOperation(&a, &b, &operator));
}


void parseInput(char *i, int *a, int *b, char *operator) {
    i = getNumber(i, a);
    i = getOperator(i, operator);
    i = getNumber(i, b);
}


char *skipWhitespace(char *i) {
    while (*i == ' ' || *i == '\t' || *i == '\n')
        ++i;
    return i;
}


char *getNumber(char *i, int *num) {
    char sign = '+';

    i = getSign(i, &sign);
    i = getDigits(i, num);

    if (sign == '-')
        (*num) *= (-1);
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


char *getDigits(char *i, int *num) {
    i = skipWhitespace(i);
    if (*i == '(' || *i == '[' || *i == '{') 
        ++i;
    i = skipWhitespace(i);
    while (*i >= '0' && *i <= '9') {
        *num = 10 * (*num) + (*i-'0');
        ++i;
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


int doOperation(int *a, int *b, char *operator) {
        switch (*operator) {
        case '+': return (*a) + (*b);
        case '-': return (*a) - (*b);
        case '*': return (*a) * (*b);
        case '/':
            if (*b == 0) {
                printf("Fatal error: zero division...\n");
                exit(-1);
            }
            return (*a) / (*b);
        case '%': return (*a) % (*b);
        default: 
            printf("Fatal error: invalid operation...\n");
            exit(-1);
        }
}


