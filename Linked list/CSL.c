#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
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
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            tail->next=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    }
}
void display()
{
    struct node *traverse=head;
    printf("CDL element:");
    do
    {
        printf("%d",traverse->data);
        traverse=traverse->next;
    }while(traverse!=head);
}
void insert()
{
    struct node *newnode,*traverse=head;
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
    newnode->next=head;
    if(pos==1)
    {
        newnode->next=head;
        do
        {
            traverse=traverse->next;
        }while(traverse->next!=head);
        head=newnode;
        traverse->next=head;
    }
    else
    {
        if(count!=pos-1)
        {
            traverse=traverse->next;
            if(traverse->next==head)
            {
                printf("Position not found");
            }
            count++;
        }
        newnode->next=traverse->next;
        traverse->next=newnode;
    }
}
void del()
{
    struct node *traverse=head,*current;
    int pos,count=1;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        while (traverse->next != head)
        {
            traverse = traverse->next;
        }
        current=head;
        head=head->next;
        traverse->next=head;
        free(current);
    }
    else
    {
        while(count!=pos-1)
        {
            traverse=traverse->next;
            if(traverse->next==head)
            {
                printf("Position doesn't found");
            }
            count++;
        }
        current=traverse->next;
        traverse->next=current->next;
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