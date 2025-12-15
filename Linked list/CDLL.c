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
    int ele,i,n;
    printf("Enter the size:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Allocation failed");
            return;
        }
        printf("Enter %d data:",i+1);
        scanf("%d",&ele);
        newnode->data=ele;
        newnode->link2=NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            tail->link2=head;
            newnode->link1=NULL;
        }
        else
        {
            tail->link2=newnode;
            newnode->link1=tail;
            tail=newnode;
            tail->link2=head;
        }
    }
}
void display()
{
    struct node *traverse=head;
    printf("DCLL Elements:");
    do
    {
        printf("%d",traverse->data);
        traverse=traverse->link2;
    }while(traverse!=head);
}
void insert()
{
    struct node *newnode,*traverse=head,*cur;
    int ele,pos,count=1;
    printf("Enter the pos:");
    scanf("%d",&pos);
    if(pos<=0)
    {
        printf("Position not found");
        return;
    }
    printf("Enter data:");
    scanf("%d",&ele);
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Allocation failed");
        return;
    }
    newnode->data=ele;
    if(pos==1)
    {
        newnode->link2=head;
        head->link1=newnode;
        newnode->link1=NULL;
        do 
        {
            traverse=traverse->link2;
        }while(traverse->link2!=head);
        head=newnode;
        traverse->link2=head;
    }
    else
    {
        while(count!=pos-1)
        {
            traverse=traverse->link2;
            if(traverse->link2==head)
            {
                printf("Position not found");
                return;
            }
            count++;
        }
        cur=traverse->link2;
        newnode->link2=cur;
        cur->link1=newnode;
        traverse->link2=newnode;
        newnode->link1=traverse;
    }
}
void del()
{
    struct node *traverse=head,*cur,*nex;
    int pos,count=1;
    printf("Enter the pos:");
    scanf("%d",&pos);
    if(pos<=0)
    {
        printf("Position doesn't exist");
        return;
    }
    if(pos==1)
    {
        cur=head;
        do
        {
            traverse=traverse->link2;
        }while(traverse->link2!=head);
        head=head->link2;
        traverse->link2=head;
        free(cur);
    }
    else
    {
        while(count!=pos-1)
        {
            traverse=traverse->link2;
            if(traverse->link2==head)
            {
                printf("Position not found");
                return;
            }
            count++;
        }
        cur=traverse->link2;
        nex=cur->link2;
        traverse->link2=nex;
        nex->link1=traverse;
        free(cur);
    }
}
int main()
{
    int ch;
    head==NULL;
    while(1)
    {
        printf("\n1. Create\n");
        printf("\n2. Display\n");
        printf("\n3. Insert\n");
        printf("\n4. Delete\n");
        printf("\n5. Exit the program\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if(head==NULL)
            {
                create();
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
                display();
            }
            break;
            case 3:
            if(head==NULL)
            {
                printf("\n Linked list empty \n");
            }
            else
            {
                insert();
            }
            break;
            case 4:
            if(head==NULL)
            {
                printf("\n Linked list empty \n");
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