#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
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
    char temp;
    
    while ((temp = postfix[i]) != '\0') {
        if (isdigit(temp)) {
            push(temp - '0'); // Convert char digit to int
        } else {
            op2 = pop();
            op1 = pop();
            switch (temp) {
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
                    printf("Invalid operator '%c'\n", temp);
                    exit(1);
            }
            push(result);
        }
        i++;
    }
    return pop();
}

int main() {
    char postfix[50];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of the postfix evaluation: %d\n", result);
    return 0;
}