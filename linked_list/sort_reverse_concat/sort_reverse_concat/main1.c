#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *create(struct node *first, int n) {
    struct node *temp, *newnode;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->link = NULL;

        if(first == NULL) {
            first = newnode;
            temp = first;
        }
        else {
            temp->link = newnode;
            temp = newnode;
        }
    }
    return first;
}

void display(struct node *first) {
    struct node *temp = first;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

struct node* sort(struct node *first) {
    struct node *i, *j;
    int temp;

    for(i = first; i != NULL; i = i->link) {
        for(j = i->link; j != NULL; j = j->link) {
            if(i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return first;
}

struct node* reverse(struct node *first) {
    struct node *prev = NULL;
    struct node *current = first;
    struct node *next = NULL;

    while(current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct node* concatenate(struct node *first, struct node *second) {
    struct node *temp = first;

    if(first == NULL)
        return second;

    while(temp->link != NULL) {
        temp = temp->link;
    }

    temp->link = second;

    return first;
}

int main() {
    struct node *first = NULL, *second = NULL;
    int n, m, ch;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);
    first = create(first, n);

    do {
        printf("\n1. Sort\n2. Reverse\n3. Concatenate\n4. Display\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                first = sort(first);
                printf("Sorted list:\n");
                display(first);
                break;

            case 2:
                first = reverse(first);
                printf("Reversed list:\n");
                display(first);
                break;

            case 3:
                printf("Enter number of nodes in second list: ");
                scanf("%d", &m);
                second = create(second, m);

                first = concatenate(first, second);
                second = NULL;

                printf("Concatenated list:\n");
                display(first);
                break;

            case 4:
                display(first);
                break;

            case 5:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice!");
        }
    } while(ch != 5);

    return 0;
}
