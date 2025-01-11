#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 50

char stack[size][size];
int top = -1;

void push(char *str) {
    if (top >= size - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        strcpy(stack[top], str);
    }
}

char *pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return NULL;
    } else {
        return stack[top--];
    }
}

int isOperator(char x) {
    return x == '+' || x == '-' || x == '*' || x == '/' || x == '^';
}

int main() {
    char postfix[size];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int i = 0;
    while (postfix[i] != '\0') {
        char temp = postfix[i];

        if (isalnum(temp)) { // Operand
            char operand[2] = {temp, '\0'};
            push(operand);
        } else if (isOperator(temp)) { // Operator
            char operand2[size], operand1[size], expr[size];
            strcpy(operand2, pop());
            strcpy(operand1, pop());

            snprintf(expr, sizeof(expr), "(%s%c%s)", operand1, temp, operand2);
            push(expr);
        } else {
            printf("Error: Invalid character '%c'\n", temp);
            return 1;
        }
        i++;
    }

    if (top == 0) {
        printf("Infix expression: %s\n", pop());
    } else {
        printf("Error: Invalid postfix expression\n");
    }

    return 0;
}
