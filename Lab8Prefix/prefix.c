#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 50

char s[size];
char input[50];
char prefix[50];
int top = -1;

void push(char x) {
    if (top >= size - 1) {
        printf("Stack Overflow");
    } else {
        top++;
        s[top] = x;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow");
        return '\0';
    } else {
        return s[top--];
    }
}

int prec(char x) {
    switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void reverse(char *expr) {
    int len = strlen(expr);
    for (int i = 0; i < len / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[len - i - 1];
        expr[len - i - 1] = temp;
    }
}

int main() {
    printf("Enter an infix expression: ");
    scanf("%s", input);

    reverse(input);

    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] == '(') {
            input[i] = ')';
        } else if (input[i] == ')') {
            input[i] = '(';
        }
    }

    push('(');
    strcat(input, ")");
    int i = 0, j = 0;
    char temp = '\0';

    while (input[i] != '\0') {
        temp = input[i];
        if (temp == '(') {
            push(temp);
        } else if (isalnum(temp)) {
            prefix[j++] = temp;
        } else if (temp == ')') {
            char popped;
            while ((popped = pop()) != '(') {
                prefix[j++] = popped;
            }
        } else if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^') {
            while (prec(temp) < prec(s[top]) || (prec(temp) == prec(s[top]) && temp != '^')) {
                prefix[j++] = pop();
            }
            push(temp);
        } else {
            printf("Error: Invalid character '%c'\n", temp);
            return 1;
        }
        i++;
    }

    prefix[j] = '\0';

    reverse(prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}