#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*f,*r;
void add();
int del();
void display();
int peek();
int main()
{
    int ch;
    f=r=NULL;
    while(1)
    {
        printf("\n1.Add\n");
        printf("\n2.Delete\n");
        printf("\n3.Display\n");
        printf("\n4.Peek\n");
        printf("\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:add();
            break;
            case 2:
                printf("Deleted data:%d",del());
            break;
            case 3:
                display();
            break;
            case 4:
                printf("Top element:%d",peek());
            break;
            case 5:exit(0);
            default:printf("Invaild choice");
        }
    }
    return 0;
}
void add()
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
    newnode->next=NULL;
    if(f==NULL)
    {
        f=newnode;
        r=newnode;
    }
    else
    {
        newnode->next=r;
        r=newnode;
    }
}
int del()
{
    struct node *traverse=r;
    int ele;
    if(r==NULL)
    {
        printf("Nothing to delete");
    }
    ele=r->data;
    r=r->next;
    return (ele);
    free(traverse);
}
void display()
{
    struct node *traverse=r;
    printf("Queue elements:");
    while(traverse!=NULL)
    {
        printf("%d",traverse->data);
        traverse=traverse->next;
    }
}
int peek()
{
    struct node *traverse=r;
    int ele;
    ele=traverse->data;
}