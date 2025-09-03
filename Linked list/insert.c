#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void create_sll();
void display_sll();
void add_first();
void add_last();
int main()
{
    head=NULL;
    int choice=0;
    while(1)
    {
    printf("\n1. Create sll\n");
    printf("2. Display sll\n");
    printf("3. Add at first\n");
    printf("4. Add at last\n");
    printf("5. End the program\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    // switch case
    switch(choice)
    {
        case 1:
        if(head==NULL)
        {
            create_sll();
        }
        else
        {
            printf("List already created\n");
        }
        break;
        case 2:
        if(head==NULL)
        {
            printf("List is not found\n");
        }
        else
        {
            display_sll();
        }
        break;
        case 3:
        if(head==NULL)
        {
            printf("Operation failed: List not found\n");
        }
        else
        {
            add_first();
        }
        break;
        case 4:
        if(head==NULL)
        {
            printf("Operation failed:List is not found\n");
        }
        else
        {
            add_last();
        }
        break;
        case 5:exit(0);
        default:printf("Wrong choice\n");
    }
    }
    return 0;
}
void create_sll()
{
    struct node *tail, *newnode;
    int n,i,ele;
    printf("Enter the size of list:");
    scanf("%d",&n);
    // allocating dynamic memory and storing element
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Allocation failed\n");
            exit(0);
        }
        printf("Enter the %d data:",i+1);
        scanf("%d",&ele);
        newnode->data=ele; // newnode now pointing the data stored in ele 
        newnode->next=NULL; // pointing null at the end
        if(head==NULL)
        {
            head=newnode; // head will point to the start of node
            tail=newnode; // tail will poin the last node 
        }
        else
        {
            tail->next=newnode; // linking other elements together
            tail=newnode; // updating tail everytime
        }
    }
}
// display
void display_sll()
{
    struct node *traverse;
    traverse=head; 
    printf("\nLinked list:");
    while(traverse!=NULL)
    {
       printf("%d ",traverse->data); // display data
       traverse=traverse->next; // update while displaying
    }
}
// add element at first
void add_first()
{
    struct node *newnode;
    int ele;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&ele);
    newnode->data=ele; // store the first element
    newnode->next=head; // new node next will be head 
    head=newnode; // head is new node now 
}
// add element at last
void add_last()
{
    struct node *newnode,*temp;
    int ele;
    temp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&ele);
    newnode->data=ele; // store the last element
    newnode->next=NULL; // pointing null
    while(temp->next!=NULL)
    {
        temp=temp->next; // traversing nodes till the end
    }
    temp->next=newnode; // adding newnode at the end of the temp
}