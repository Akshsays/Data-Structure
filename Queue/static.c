#include <stdio.h>
#include <stdlib.h>
#define MAX 4
struct queue
{
    int ar[MAX];
    int r,f;
};
int isempty(struct queue *ps);
int isfull(struct queue *ps);
void add(struct queue *ps);
int del(struct queue *ps);
void display(struct queue *ps);
int main()
{
    struct queue q;
    int ch;
    q.r=q.f=-1;
    while(1)
    {
        printf("\n1.Add\n");
        printf("\n2.Del\n");
        printf("\n3.Display\n");
        printf("\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if(isfull(&q))
            {
                printf("Queue is full");
            }
            else
            {
                add(&q);
            }
            break;
            case 2:
            if(isempty(&q))
            {
                printf("Nothing to del");
            }
            else
            {
                printf("Deleted element:%d",del(&q));
            }
            break;
            case 3:
            if(isempty(&q))
            {
                printf("Nothing to display");
            }
            else
            {
                display(&q);
            }
            break;
            case 4:exit(0);
            default:printf("Invaild choice!!!");
        }
    }
    return 0;
}
int isempty(struct queue *ps)
{
    if(ps->f==ps->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct queue *ps)
{
    if(ps->r==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void add(struct queue *ps)
{
    int ele;
    printf("Enter the data:");
    scanf("%d",&ele);
    ps->r++;
    ps->ar[ps->r]=ele;
}
int del(struct queue *ps)
{
    int ele,temp;
    ele=ps->ar[ps->r];
    ps->r--;
    return (ele);
}
void display(struct queue *ps)
{
    int i;
    printf("Queue elements:");
    for(i=ps->f+1;i<=ps->r;i++)
    {
        printf(" %d\t",ps->ar[i]);
    }
}