#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

void push() {
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->link = top;
    top = newnode;
}

void pop() {
    struct node *temp;

    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", temp->data);

    top = top->link;
    free(temp);
}

void displayStack() {
    struct node *temp = top;

    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void insert() {
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->link = NULL;

    if(front == NULL) {
        front = rear = newnode;
    }
    else {
        rear->link = newnode;
        rear = newnode;
    }
}

void delete() {
    struct node *temp;

    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = front;
    printf("Deleted element: %d\n", temp->data);

    front = front->link;

    if(front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void displayQueue() {
    struct node *temp = front;

    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    int ch;

    do {
        printf("\n\n1. Stack Push");
        printf("\n2. Stack Pop");
        printf("\n3. Display Stack");
        printf("\n4. Queue Insert");
        printf("\n5. Queue Delete");
        printf("\n6. Display Queue");
        printf("\n7. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                insert();
                break;

            case 5:
                delete();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice!");
        }

    } while(ch != 7);

    return 0;
}
