#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *link1,*link2;
}*head;
void create()
{
    struct node *newnode,*tail;
    int ele,i,s;
    printf("Enter the size:");
    scanf("%d",&s);
    for(i=0;i<s;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Allocation failed");
            return;
        }
        printf("Enter the %d data:",i+1);
        scanf("%d",&ele);
        newnode->data=ele;
        newnode->link2=NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            newnode->link2=head;
            newnode->link1=head;
        }
        else
        {
            tail->link2=newnode;
            newnode->link1=tail;
            tail=newnode;
            newnode->link2=head;
            head->link1=head;
        }
    }
}
void display()
{
    struct node *traverse=head;
    printf("CDLL element:");
    do
    {
        printf("%d",traverse->data);
        traverse=traverse->link2;
    }
    while(traverse!=head);
}
int main()
{
    int choice;
    head=NULL;
    while(1)
    {
        printf("\n1.Create\n");
        printf("\n2.Display\n");
        printf("\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            if(head==NULL)
            {
                create();
            }
            else
            {
                printf("list already created");
            }
            break;
            case 2:
            if(head==NULL)
            {
                printf("Nothing to display");
            }
            else
            {
                display();
            }
            break;
            case 4:exit(0);
        }
    }
}