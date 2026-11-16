#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void insert()
{
    int item;
    if (rear ==MAX- 1)
    {
        printf("Queue Overflow");
    }
    else
    {
     printf("\nEnter the element: ");
        scanf("%d", &item);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
    }
}
void delete()
{
    if (front ==-1||front> rear)
    {
        printf("\nQueue Underflow.");
    }
    else
    {
        printf("\nDeleted element: %d", queue[front]);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("\nQueue is empty.");
    }
    else
    {
        for (i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}
int main()
{
    int choice;
    for(;;)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid choice ");
        }
    }

    return 0;
}
