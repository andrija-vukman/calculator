// Author: Andrija Vukman
// Date: 2025-12-10
// CALCULATOR
// Version 1


#include <stdio.h>
#define BUFFER 64


void calculate();
int parseInput(char*);



int main() {
    calculate();

    return 0;
}


void calculate() {
    char input[64];
    printf("Enter your calculation: ");
    fgets(input, BUFFER, stdin);
    parseInput(input);
    printf("\nResult = %d\n\n", parseInput(input));
}


int parseInput(char *i) {
    int a, b;
    char sign;
    a = b = 0;

    while (*i == ' ' || *i == '\t' || *i == '\n')
        ++i;
    while (*i >= '0' && *i <= '9') {
        a = 10 * a + (*i - '0');
        ++i;
    }
    while (*i == ' ' || *i == '\t' || *i == '\n')
        ++i;
    if (*i == '+' || *i == '-' || *i == '*' || *i == '/' || *i == '%') {
        sign = *i;
        ++i;
    }
    while (*i == ' ' || *i == '\t' || *i == '\n')
        ++i;
    while (*i >= '0' && *i <= '9') {
        b = 10 * b + (*i - '0');
        ++i;
    }
    
        switch (sign) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        default: return -1;
        }

}


