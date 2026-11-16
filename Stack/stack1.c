#include<stdio.h>
#include<stdlib.h>
#define max 5

int item;
int item_deleted;
int s[max];
int top=-1;
int choice;
void push(int item,int s[],int *top){
    if(*top==max-1){
        printf("Stack overflow!\n");
        return;
    }
    *top=*top+1;
    s[*top]=item;
}
int pop(int item,int s[],int *top){
    if(*top==-1){
        printf("Stack underflow!\n");
        return -1;
    }
    item_deleted=s[*top];
    *top=*top-1;
    return item_deleted;
}
int display(int item,int s[],int *top){
    if(*top==-1){
        printf("Stack is Empty !\n");
        return 0;
    }
    for(int i=*top;i>=0;i--){
        printf("%d\n",s[i]);
    }
    return 0;

}
int main(){
    for(;;){
    printf("Enter any choice: \n");
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        printf("Enter the element to be added :\n");
        scanf("%d",&item);
        push(item,s,&top);
        break;
    case 2:
        item_deleted=pop(item,s,&top);
        printf("The deleted element is :%d \n",item_deleted);
        break;
    case 3:
        printf("The elements in the Stack are : \n");
        display(item,s,&top);
        break;
    case 4:
        exit(0);
    default:
        printf("Invalid choice");
    }
    }
return 0;

}
