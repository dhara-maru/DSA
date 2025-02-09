#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

int arr[MAX]; 
int next[MAX];
int head = -1;
int avail = 0;  


void initialize() {
    for (int i = 0; i < MAX - 1; i++) {
        next[i] = i + 1;
    }
    next[MAX - 1] = -1; 
}

int getNode() {
    if (avail == -1) {
        printf("Memory full!\n");
        return -1;
    }
    int newNode = avail;
    avail = next[avail]; 
    return newNode;
}


void insertAtBeginning(int value) {
    int newNode = getNode();
    if (newNode == -1) return;

    arr[newNode] = value;
    next[newNode] = head;
    head = newNode;
}


void insertAtEnd(int value) {
    int newNode = getNode();
    if (newNode == -1) return;

    arr[newNode] = value;
    next[newNode] = -1;

    if (head == -1) {
        head = newNode;
        return;
    }

    int temp = head;
    while (next[temp] != -1) {
        temp = next[temp];
    }
    next[temp] = newNode;
}


void display() {
    if (head == -1) {
        printf("List is empty!\n");
        return;
    }

    int temp = head;
    printf("Linked List: ");
    while (temp != -1) {
        printf("%d -> ", arr[temp]);
        temp = next[temp];
    }
    printf("NULL\n");
}


int countNodes() {
    int count = 0, temp = head;
    while (temp != -1) {
        count++;
        temp = next[temp];
    }
    return count;
}


void main() {
    int choice, value;
    initialize();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning [A]\n");
        printf("2. Insert at End [A]\n");
        printf("3. Display List [B]\n");
        printf("4. Count Nodes [C]\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
 
}
