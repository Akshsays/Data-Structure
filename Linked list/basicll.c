#include <Stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node 
{
    int data; // to store data 
    struct node *next; // linker
};
int main()
{
    // variables storing data
    struct node *head; 
    struct node *second;
    struct node *third;
    
    // allocating memory space
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    // data and link of head
    head->data=1;
    head->next=second;
    // data and link of second
    second->data=2;
    second->next=third;
    // data and link of third
    third->data=3;
    third->next=NULL;

    // pointer for traversing
    struct node *temp;
    temp=head;
    printf("Link list data:");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}