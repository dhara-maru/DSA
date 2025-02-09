#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
struct Stack {
    char* items[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char* str) {
    if (stack->top < MAX - 1) {
        stack->items[++(stack->top)] = str;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to pop an element from the stack
char* pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack->items[(stack->top)--];
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert postfix to infix
void postfixToInfix(char* postfix, char* infix) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char current = postfix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(current)) {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = current;
            operand[1] = '\0';
            push(&stack, operand);
        }
        // If the character is an operator
        else if (isOperator(current)) {
            char* op2 = pop(&stack);
            char* op1 = pop(&stack);

            char* expr = (char*)malloc(strlen(op1) + strlen(op2) + 4);
            sprintf(expr, "(%s%c%s)", op1, current, op2);

            push(&stack, expr);
        }
    }

    strcpy(infix, pop(&stack));
}

int main() {
    char postfix[MAX], infix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    postfixToInfix(postfix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}