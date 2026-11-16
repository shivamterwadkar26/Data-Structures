#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void create(){
    int n,i;
    struct node *newnode,*temp;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
            head=newnode;
        else{
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }
    }
}
void insertFirst(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}
void insertPosition(){
    int pos,i;
    struct node *newnode,*temp;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<1){
        printf("Invalid position!\n");
        return;
    }
    if(pos==1){
        insertFirst();
        return;
    }
    temp=head;
    for(i=1;i<pos-1 && temp!=NULL;i++)
        temp=temp->next;
    if(temp==NULL){
        printf("Invalid position!\n");
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;
}
void insertEnd(){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
}
void deleteFirst(){
    struct node *temp;
    if(head==NULL){
        printf("List is empty!\n");
        return;
    }
    temp=head;
    head=head->next;
    free(temp);
    printf("First element deleted.\n");
}
void deleteElement(){
    int value;
    struct node *temp,*prev;
    if(head==NULL){
        printf("List is empty!\n");
        return;
    }
    printf("Enter element to delete: ");
    scanf("%d",&value);
    temp=head;
    prev=NULL;
    while(temp!=NULL && temp->data!=value){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Element not found!\n");
        return;
    }
    if(prev==NULL)
        head=temp->next;
    else
        prev->next=temp->next;
    free(temp);
    printf("Element deleted successfully.\n");
}
void deleteLast(){
    struct node *temp,*prev;
    if(head==NULL){
        printf("List is empty!\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        printf("Last element deleted.\n");
        return;
    }
    temp=head;
    prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    printf("Last element deleted.\n");
}
void display(){
    struct node *temp;
    if(head==NULL){
        printf("List is empty!\n");
        return;
    }
    temp=head;
    printf("Linked List: ");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    int choice;
    while(1){
        printf("\n1.Create\n2.Insert First\n3.Insert Position\n4.Insert End\n5.Delete First\n6.Delete Specified Element\n7.Delete Last\n8.Display\n9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: create(); break;
            case 2: insertFirst(); break;
            case 3: insertPosition(); break;
            case 4: insertEnd(); break;
            case 5: deleteFirst(); break;
            case 6: deleteElement(); break;
            case 7: deleteLast(); break;
            case 8: display(); break;
            case 9: printf("Program terminated.\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
