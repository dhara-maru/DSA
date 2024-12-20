// 1. Write a menu driven program to perform following operations on Stack: PUSH, POP, PEEP, CHANGE and DISPLAY.
#include<stdio.h>
#define size 5

int s[size];
int top = -1;
int i;

//push
void push(int x){
    if(top >= size){
        printf("Stack Overflow");
    }
    else{
        top++;
        s[top] = x;
    }
}

//pop
int pop(){
    if(top == -1){
        printf("Stack Underflow");
        return -1;
    }else{
        top--;
        return s[top + 1];
    }
}

//peep
int peep(int i){
    if(top - i + 1 <= -1){
        printf("Stack Underflow");
        return -1;
    }else{
        return s[top - i + 1];
    }
}

//change (replace)
void change(int i, int x){
    if(top - i + 1 <= -1){
        printf("The element is not available");
    }else{
        s[top - i + 1] = x;
    }
}

//display
void display(){
    int i;  //for loop

    if(top == -1){
        printf("Stack Underflow");
    }
    else{
        for(i = top; i >= 0; i--){
            printf("%d\t", s[i]);
        }
    }
}

int main(){
    int choice, x, i;
    do{
        printf("----- Menu -----");
        printf("\n1.Push\n2.Pop\n3.Peep\n4.Change\n5.Display\n6.Exit\n\n");
        printf("Enter your choice here : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter a number to push : ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                x = pop();
                if(x == -1){
                    printf("Stack Underflow");
                }else{
                    printf("Element Popped !");
                }
                break;
            case 3:
                printf("Enter I : ");
                scanf("%d", &i);
                x = peep(i);
                if (x == -1)
                {
                    printf("Ith Element is not available!\n");
                }
                else
                {
                    printf("%d is the %dth element\n", x);
                }
                break;
            case 4:
                printf("Enter i : ");
                scanf("%d", &i);
                printf("Enter x : ");
                scanf("%d", &x);
                change(i, x);
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Enter valid choice!");
                break;
        }

    } while (choice != 6);

return 0;
}