#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link1,*link2;
}*head;
void createCDL()
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
            }
            printf("Enter the data:");
            scanf("%d",&ele);
            newnode->data=ele;
            newnode->link2=NULL;
            if(head==NULL)
            {
                head=newnode;
                tail=newnode;
                head->link1=head;
                head->link2=head;
            }
            else
            {
                tail->link2=newnode;
                newnode->link1=tail;
                tail=newnode;
                newnode->link2=head;
                head->link1=newnode;
            }
        }
    }
void displayCDL()
{
    struct node *traverse=head;
    printf("Linked list:");
    do
    {
        printf("%d->",traverse->data);
        traverse=traverse->link2;
    } while (traverse!=head);
    printf("NULL");
}
void insertCDL()
{
    struct node *newnode,*current,*tail;
    int ele,pos,count=1;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Allocation failed");
        return;
    }
    printf("Enter the position:");
    scanf("%d",&pos);
    printf("Enter the data:");
    scanf("%d",&ele);
    newnode->data=ele;
    if(head==NULL)
    {
        newnode->link1=newnode;
        newnode->link2=newnode;
        head=newnode;
        return;
    }
    if(pos==1)
    {
        tail=head->link1;          
        newnode->link2=head;
        newnode->link1=tail;
        tail->link2=newnode;
        head->link1=newnode;
        head=newnode;               
    }
    else
    {
        current=head;
        do {
            if(count==pos-1) 
            {
                newnode->link2=current->link2;
                newnode->link1=current;
                current->link2->link1=newnode;
                current->link2=newnode;
                break;
            }
            current=current->link2;
            count++;
        } while(current!=head);
    }
}
void main()
{
    int choice=0;
    head=NULL;
    while(1)
    {
        printf("\n1. Create CDL");
        printf("\n2. Display CDL");
        printf("\n3. Insert CDL");
        printf("\n4. Exit the program");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            if(head==NULL)
            {
                createCDL();
            }
            else
            {
                printf("\n Linked list exist \n");
            }
            break;
            case 2:
            if(head==NULL)
            {
                printf("\n Linked list empty \n");
            }
            else
            {
                displayCDL();
            }
            break;
            case 3:
            if(head==NULL)
            {
                printf("\n List is empty \n");
            }
            else
            {
                insertCDL();
            }
            break;
            case 4:exit(0);
        }
    }
}