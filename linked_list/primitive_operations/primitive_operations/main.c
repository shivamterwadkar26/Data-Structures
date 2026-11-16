#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} NODE;
NODE *first = NULL;
void create()
{
    NODE *temp, *last;
    int n, i;
    printf("Enter number of nodes: ");d
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        temp = (NODE *)malloc(sizeof(NODE));
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->prev = NULL;
        temp->next = NULL;
        if(first == NULL)
        {
            first = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }
}
void insert()
{
    NODE *temp, *cur;
    int key;
    printf("Enter the value before which to insert: ");
    scanf("%d", &key);
    cur = first;
    while(cur != NULL && cur->data != key)
        cur = cur->next;
    if(cur == NULL)
    {
        printf("Node not found\n");
        return;
    }
    temp = (NODE *)malloc(sizeof(NODE));
    printf("Enter new data: ");
    scanf("%d", &temp->data);
    temp->prev = cur->prev;
    temp->next = cur;
    if(cur->prev != NULL)
        cur->prev->next = temp;
    else
        first = temp;
    cur->prev = temp;
    printf("Node inserted\n");
}
void delete()
{
    NODE *cur;
    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);
    cur = first;
    while(cur != NULL && cur->data != key)
        cur = cur->next;
    if(cur == NULL)
    {
        printf("Node not found\n");
        return;
    }
    if(cur->prev != NULL)
        cur->prev->next = cur->next;
    else
        first = cur->next;
    if(cur->next != NULL)
        cur->next->prev = cur->prev;
    free(cur);
    printf("Node deleted\n");
}
void display()
{
    NODE *temp;
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = first;
    printf("Doubly Linked List: ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1. Create");
        printf("\n2. Insert to the left");
        printf("\n3. Delete");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: create();
                    break;
            case 2: insert();
                    break;
            case 3: delete();
                    break;
            case 4: display();
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
void insert()
{
    NODE *temp, *cur;
    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    cur = first;
    while(cur && cur->data != key)
        cur = cur->next;
    if(!cur) {
        printf("Node not found\n");
        return;
    }
    temp = malloc(sizeof(NODE));
    printf("Enter new data: ");
    scanf("%d", &temp->data);
    temp->prev = cur->prev;
    temp->next = cur;
    if(cur->prev)
        cur->prev->next = temp;
    else
        first = temp;
    cur->prev = temp;
}
