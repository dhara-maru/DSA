#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *first = NULL;

void insert_B(int x) {
    struct node *newnode = malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = x;
    newnode->link = first;
    first = newnode;
}

void insert_End(int x) {
    struct node *newnode = malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = x;
    newnode->link = NULL;
    
    if (first == NULL) {
        first = newnode;
    } else {
        struct node *temp = first;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}

void display() {
    if (first == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp = first;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
    }
}

void count_nodes() {
    int count = 0;
    struct node *temp = first;
    while (temp != NULL) {
        count++;
        temp = temp->link;
    }
    printf("Number of nodes: %d\n", count);
}

int main() {
    int ch, x;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Display the list\n");
        printf("4. Count number of nodes\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert at beginning: ");
                scanf("%d", &x);
                insert_B(x);
                break;
            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d", &x);
                insert_End(x);
                break;
            case 3:
                display();
                break;
            case 4:
                count_nodes();
                break;
            case 5:
                exit(0);
            default:
                printf("Enter a valid choice!\n");
        }
    }
    return 0;
}
