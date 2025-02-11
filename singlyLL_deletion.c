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

void delete_from_Beg(){
    struct node *temp;
    temp = first;
    first = first->link;
    printf("Deleted element is %d", temp->data);
    free(temp);
    

}

void delete_from_End(){
    struct node *prev;
    struct node *temp;
    temp=first;
    while(temp->link != 0){
        prev = temp;
        temp = temp->link;
    }
    if(temp==first){
        first=0;
        free(temp);
    }else{
        prev->link=0;
    }
    
    free(temp);
}


void delete_from_Position(){
    struct node *nextnode;
    int pos, i=1;
    struct node *temp;
    temp=first;
    printf("Enter position to delete an element : ");
    scanf("%d", &pos);
    while(i < pos-1){
        temp = temp -> link;
        i++;
    }
    nextnode = temp -> link;
    temp -> link = nextnode -> link;
    free(nextnode);
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
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Delete from Specific Position\n");
        printf("6. Display the list\n");
        printf("7. Count number of nodes\n");
        printf("8. Exit\n");
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
                delete_from_Beg();
                break;
            case 4:
                delete_from_End();
                break;
            case 5:
                delete_from_Position();
                break;
            case 6:
                display();
                break;
            case 7:
                count_nodes();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Enter a valid choice!\n");
        }
    }
    return 0;
}
