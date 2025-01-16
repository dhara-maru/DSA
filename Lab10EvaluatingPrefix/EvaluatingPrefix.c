#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define size 50

int stack[size];
int top = -1;

void push(int x) {
    if (top >= size - 1) {
        printf("Stack Overflow\n");
        exit(1);
    } else {
        stack[++top] = x;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        return stack[top--];
    }
}

int evaluatePrefix(char *prefix) {
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(prefix[i] - '0'); // Convert char digit to int
        } else if (prefix[i] == ' ') {
            continue; // Skip spaces
        } else {
            int op1 = pop();
            int op2 = pop();
            switch (prefix[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                default:
                    printf("Invalid operator '%c'\n", prefix[i]);
                    exit(1);
            }
        }
    }
    return pop();
}

int main() {
    char prefix[50];
    printf("Enter a prefix expression (single-digit operands, no spaces needed): ");
    scanf("%s", prefix);

    int result = evaluatePrefix(prefix);
    printf("Result of the prefix evaluation: %d\n", result);
    return 0;
}