#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
int create_sll();
int display_sll();
int main()
{
    head=NULL;
    create_sll();
    display_sll();
    return 0;
}
int create_sll()
{
    struct node *tail=NULL,*newnode=NULL;
    int n,i,ele;
    printf("Enter the size of list:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Allocation failed\n");
            exit(0);
        }
        printf("Enter the %d data:",i+1);
        scanf("%d",&ele);
        newnode->data=ele;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
    }
    return 0;
}
int display_sll()
{
    struct node *traverse;
    traverse=head;
    printf("Linked list data:");
    while(traverse!=NULL)
    {
        printf("%d ",traverse->data);
        traverse=traverse->next;
    }
    return 0;
}