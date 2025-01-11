#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 50

char s[size];
char input[50];
char postfix[50];
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

int main() {
    printf("Enter an infix expression: ");
    scanf("%s", input);

    // Append ')' to input and null-terminate
    int len = strlen(input);
    input[len] = ')';
    input[len + 1] = '\0';

    push('(');
    int i = 0, j = 0;
    char temp = '\0';

    while (input[i] != '\0') {
        temp = input[i];
        if (temp == '(') {
            push(temp);
        } else if (isalnum(temp)) {  // If operand
            postfix[j++] = temp;
        } else if (temp == ')') {
            char popped;
            while ((popped = pop()) != '(') {
                postfix[j++] = popped;
            }
        } else if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^') {
            while (prec(temp) <= prec(s[top])) {
                postfix[j++] = pop();
            }
            push(temp);
        } else {
            printf("Error: Invalid character '%c'\n", temp);
            return 1;
        }
        i++;
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
