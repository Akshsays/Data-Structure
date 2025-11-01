#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*top;
int isempty();
void push();
int pop();
void display();
int peek();
int main()
{
    int ch;
    top=NULL;
    while(1)
    {
        printf("\n1.Push\n");
        printf("\n2.Pop\n");
        printf("\n3.Display\n");
        printf("\n4.Peek\n");
        printf("\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            push();
            break;
            case 2:
            if(isempty())
            {
                printf("Nothing to delete");
            }
            else
            {
                printf("Popped element:%d",pop());
            }
            break;
            case 3:
            if(isempty())
            {
                printf("Nothing to display");
            }
            else
            {
                display();
            }
            break;
            case 4:
            if(isempty())
            {
                printf("Nothing to display");
            }
            else
            {
                printf("Top element:%d",peek());
            }
            break;
            case 5:exit(0);
            default:printf("Invaild choice");
            
        }
    }
}
int isempty()
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push()
{
    struct node *newnode;
    int ele;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Allocation failed");
        return;
    }
    printf("Enter the data:");
    scanf("%d",&ele);
    newnode->data=ele;
    newnode->next=top;
    top=newnode;
}
int pop()
{
    struct node *traverse=top;
    int ele;
    ele=traverse->data;
    top=top->next;
    return(ele);
    free(traverse);
}
void display()
{
    struct node *traverse=top;
    printf("Stack elements:");
    while(traverse!=NULL)
    {
        printf("%d",traverse->data);
        traverse=traverse->next;
    }
}
int peek()
{
    struct node *traverse=top;
    int ele;
    ele=traverse->data;
    return (ele);
}