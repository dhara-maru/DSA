#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack structure
struct Stack {
    char items[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char c) {
    if (stack->top < MAX - 1) {
        stack->items[++(stack->top)] = c;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to pop an element from the stack
char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}

// Function to peek the top element of the stack
char peek(struct Stack *stack) {
    if (stack->top != -1) {
        return stack->items[stack->top];
    }
    return -1;
}

// Function to check precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        // If current character is an operand, add it to the postfix expression
        if (isalnum(current)) {
            postfix[k++] = current;
        }
        // If current character is '(', push it to the stack
        else if (current == '(') {
            push(&stack, current);
        }
        // If current character is ')', pop from the stack until '(' is encountered
        else if (current == ')') {
            while (stack.top != -1 && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); // Pop '(' from the stack
        }
        // If current character is an operator
        else if (isOperator(current)) {
            while (stack.top != -1 && precedence(peek(&stack)) >= precedence(current)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, current);
        }
    }

    // Pop all remaining operators from the stack
    while (stack.top != -1) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0';  // Null-terminate the postfix expression
}

// Main function to test the infix to postfix conversion
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}