// reverse a string using stack
#include <stdio.h>
#define n 100

char stack[n];
int top = -1;

void push(int x){
    if(top >= n-1){
        printf("Stack Overflow");
    }
    else{
        top++;
        stack[top] = x;
    }
}
int pop(){
    if(top == -1){
        printf("Stack Underflow");
    }
    else{
        top--;
        return stack[top + 1];
    }
}
void reverse_str(char str[]){

    //push all chars to stack first
    for(int i=0; str[i] != '\0'; i++){
        push(str[i]);
    }

    //pop (so it reverses)
    int i=0;
    while(top != -1){
        str[i++] = pop();
    }
    str[i] = '\0'; //null

}
void main(){
    char str[100];

    printf("Enter any string : ");
    scanf("%s", &str);

    reverse_str(str);

    printf("\n Reversed String is : %s ", str);

}