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
    int ele,i,size;
    printf("Enter the size:");
    scanf("%d",&size);
    for(i=0;i<size;i++)
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
            head->link1=NULL;
        }
        else
        {
            tail->link2=newnode;
            newnode->link1=tail;
            tail=newnode;
        }
    }
}
void display()
{
    struct node *traverse=head;
    printf("Cdl element:");
    while(traverse!=NULL)
    {
        printf("%d",traverse->data);
        traverse=traverse->link2;
    }
}
void insert()
{
    struct node *newnode,*traverse=head,*current;
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
    if(pos==1)
    {
        newnode->link2=head;
        head->link1=newnode;
        head=newnode;
        newnode->link1=NULL;
    }
    else
    {
        while(count!=pos-1)
        {
            traverse=traverse->link2;
            if(traverse->link2==NULL)
            {
                printf("Position not found");
            }
            count++;
        }
        current=traverse->link2;
        newnode->link2=current;
        current->link1=newnode;
        traverse->link2=newnode;
        newnode->link1=traverse;
    }
}
void del()
{
    struct node *traverse=head,*current,*temp;
    int pos,count=1;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        current=head;
        head=head->link2;
        free(current);
    }
    else
    {
        while(count!=pos-1)
        {
            traverse=traverse->link2;
            if(traverse->link2==NULL)
            {
                printf("Position not found");
            }
            count++;
        }
        current=traverse->link2;
        temp=current->link2;
        traverse->link2=temp;
        temp->link1=traverse;
        free(current);
    }
}
int main()
{
    int choice;
    head=NULL;
    while(1)
    {
        printf("\n1.Create\n");
        printf("\n2.Display\n");
        printf("\n3.Insert\n");
        printf("\n4.Delete\n");
        printf("\n5.Exit\n");
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
            case 3:
            if(head==NULL)
            {
                printf("Nothing to insert in");
            }
            else
            {
                insert();
            }
            break;
            case 4:
            if(head==NULL)
            {
                printf("Nothing to delete");
            }
            else
            {
                del();
            }
            break;
            case 5:exit(0);
        }
    }
    return 0;
}