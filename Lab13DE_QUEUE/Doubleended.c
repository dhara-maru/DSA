#include <stdio.h>
#include <stdlib.h>
#define n 100

int q[n];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear >= n - 1) {
        printf("Q overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = rear + 1;
        q[rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Q underflow\n");
    } else {
        printf("Dequeued element: %d\n", q[front]);
        front = front + 1;
    }
}

void insert_front(int y){
    if(front == 0){
        printf("Overflow");
    }
    else{
        if(front == -1){
            front == 0;
            rear == 0;
        }
        else{
            front = front - 1;
        }
        q[front] = y;
    }
}
void del_rear(){
    if (rear == -1)
    {
        printf("Overflow");
    }
    else{
       int y=q[rear];
        q[rear] = '\0';
        if(front == rear){
            front = rear= -1;
        }
        else{
            rear = rear -1;
        }
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("Q is empty\n");
    } else {
        printf("Q elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

void main() {
    int choice;
   
    while(choice !=4){
         printf("Choose something : \n1. Enqueue \n 2. Dequeue \n 3. Display \n 4. Exit ");
    scanf("%d", &choice);

    switch(choice){
        case 1 : 
        int x;
        printf("Enter elem to insert : ");
        scanf("%d", &x);
        enqueue(x);
        break;
        case 2 : 
        dequeue();
        break;
        case 3 :
        display();
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("Enter valid operation !!!!");
        break;

    }
    }
   
}
