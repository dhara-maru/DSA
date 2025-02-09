#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char item) {
    if (s->top < MAX - 1)
        s->items[++s->top] = item;
    else
        printf("Stack Overflow\n");
}

char pop(Stack *s) {
    if (!isEmpty(s))
        return s->items[s->top--];
    else
        return -1;
}

char peek(Stack *s) {
    if (!isEmpty(s))
        return s->items[s->top];
    else
        return -1;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/' || c == '%') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int j = 0;
	int i;
    for ( i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        }
        
        else if (c == '(') {
            push(&s, c);
        }

        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  
        }

        else if (isOperator(c)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}

int main() {
    char infix1[] = "(A + B * C / D - E + F / G / (H + I))";
    char infix2[] = "(A + B) * C + D / (B + A * C) + D";
    char postfix1[MAX], postfix2[MAX];

    infixToPostfix(infix1, postfix1);
    infixToPostfix(infix2, postfix2);

    printf("Infix Expression 1: %s\n", infix1);
    printf("Postfix Expression 1: %s\n", postfix1);
    printf("\n");
    printf("\n");
    printf("Infix Expression 2: %s\n", infix2);
    printf("Postfix Expression 2: %s\n", postfix2);

    return 0;
}
