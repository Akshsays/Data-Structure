#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data; // store data
    struct node *next; // linker for linking
}*head;
int main()
{
    struct node *tail=NULL, *newnode=NULL, *traverse=NULL;
    int ele,size,i;
    head=NULL; // starting point

    // accepting the size of link list
    printf("Enter the size of linked list:");
    scanf("%d",&size);

    // allocating dynamic memory and creating nodes
    for(i=0;i<size;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        // condition to make sure the memory is allocated 
        if(newnode==NULL)
        {
            printf("Memory allocation failed\n");
            exit(0);
        }
        // accepting the data one by one 
        printf("Enter the %d data:",i+1);
        scanf("%d",&ele);
        // pointing the elements in a temp variable "newnode"

        newnode->data=ele; // accept data from user
        newnode->next=NULL; // make sure it points to null at the end

        // condition to link these nodes together
        if(head==NULL)
        {
            head=newnode; // head will point to the start of newnode
            tail=newnode; // tail is to track the last element of newnode
        }
        else
        {
            tail->next=newnode; // tail will point to the next node of "newnode"
            tail=newnode; // updating the tail each time 
        }
    }

    // traversin logic
    traverse=head; // traverse will point to the start
    printf("Linked list data:");
    while(traverse!=NULL)
    {
        printf("%d ",traverse->data);
        traverse=traverse->next;
    }
    return 0;

}