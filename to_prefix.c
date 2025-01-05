#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top >= (MAX - 1))
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}

char pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        return stack[top--];
    return -1;
}

int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}


void infixToPrefix(char *exp, char *prefix) {
    int i = 0, j = 0;
    char c;

    reverse(exp);

    while (exp[i] != '\0') {
        c = exp[i];

        if (isalnum(c)) {
            prefix[j++] = c;
        }
        else if (c == ')') {
            push(c);
        }
        else if (c == '(') {
            while (top != -1 && stack[top] != ')') {
                prefix[j++] = pop();
            }
            top--; 
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                prefix[j++] = pop();
            }
            push(c);
        }
        i++;
    }

    while (top != -1) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
