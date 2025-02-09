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
        printf("Stack Overflow\n");
    } else {
        top++;
        s[top] = x;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
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

void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

void infixToPrefix(char *infix) {
    reverse(infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    int i = 0, j = 0;
    char temp;
    push('('); // Add '(' at the beginning
    strcat(infix, ")"); // Add ')' at the end

    while (infix[i] != '\0') {
        temp = infix[i];
        if (isalnum(temp)) { 
            prefix[j++] = temp;
        } else if (temp == '(') {
            push(temp);
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
            exit(1);
        }
        i++;
    }

    prefix[j] = '\0'; // Null-terminate the result
    reverse(prefix);  // Reverse to get the final prefix expression
}

int main() {
    printf("Enter an infix expression: ");
    scanf("%s", input);

    infixToPrefix(input);

    printf("Prefix expression: %s\n", prefix);
    return 0;
}
