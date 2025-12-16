// Author: Andrija Vukman
// Date: 2025-12-15
// CALCULATOR
// Version 2


#include <stdio.h>
#include <stdlib.h>
#define BUFFER 64


void calculate();
void parseInput(char*, int*, int*, char *sign);
char *skipWhitespace(char*);
char *getNumber(char*, int*);
char *getSign(char*, char*);
int doOperation(int*, int*, char *sign);


int main() {
    calculate();
    return 0;
}


void calculate() {
    char input[BUFFER];
    int a, b;
    char sign;
    a = b = 0;

    printf("Enter your calculation: ");
    fgets(input, BUFFER, stdin);
    parseInput(input, &a, &b, &sign);
    printf("\nResult = %d\n\n", doOperation(&a, &b, &sign));
}


void parseInput(char *i, int *a, int *b, char *sign) {
    i = skipWhitespace(i);
    i = getNumber(i, a);
    i = skipWhitespace(i);
    i = getSign(i, sign);
    i = skipWhitespace(i);
    i = getNumber(i, b);
}


char *skipWhitespace(char *i) {
    while (*i == ' ' || *i == '\t' || *i == '\n')
        ++i;
    return i;
}


char *getNumber(char *i, int *num) {
    while (*i >= '0' && *i <= '9') {
        *num = 10 * (*num) + (*i - '0');
        ++i;
    }
    return i;
}


char *getSign(char *i, char *sign) {
    if (*i == '+' || *i == '-' || *i == '*' || *i == '/' || *i == '%') {
        *sign = *i;
        ++i;
    }
    return i;
}


int doOperation(int *a, int *b, char *sign) {
        switch (*sign) {
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
