#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
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

int evaluatePostfix(char *postfix) {
    int i = 0, op1, op2, result;
    char temp[10];
    
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            int j = 0;
            while (isdigit(postfix[i])) {
                temp[j++] = postfix[i++];
            }
            temp[j] = '\0';  // Null-terminate the multi-digit number
            push(atoi(temp)); // Convert to integer and push onto stack
        } else if (postfix[i] == ' ') {
            i++;  // Skip spaces
        } else {
            op2 = pop();
            op1 = pop();
            switch (postfix[i]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                default:
                    printf("Invalid operator '%c'\n", postfix[i]);
                    exit(1);
            }
            push(result);
            i++;
        }
    }
    return pop();
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression with space-separated operands and operators: ");
    fgets(postfix, sizeof(postfix), stdin); // Read input with spaces

    int result = evaluatePostfix(postfix);
    printf("Result of the postfix evaluation: %d\n", result);
    return 0;
}