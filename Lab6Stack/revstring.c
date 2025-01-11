#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 50

char s[size];
int top = -1;

void push(char x){
    if(top >= size - 1){
        printf("Stack Overflow");
    }
    else{
        top++;
        s[top] = x;
    }
}

char pop(){
    if(top == -1){
        printf("Stack Underflow");
        return -1;
    }else{
        top--;
        return s[top + 1];
    }
}

void display(){
    int i;

    if(top == -1){
        printf("Stack Underflow");
    }
    else{
        for(i = top; i >= 0; i--){
            printf("%c\t", s[i]);
        }
    }
}

int main(){
    char str[50];
    printf("Enter a string : ");
    scanf("%s", str);

    for(int i = 0; i < strlen(str); i++){
        push(str[i]);
    }

    for(int i = 0; i < strlen(str); i++){
        printf("%c", pop());
    }

    return 0;
}
