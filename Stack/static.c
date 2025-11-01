#include <stdio.h>
#include <stdlib.h>
#define MAX 4
struct array
{
    int ar[MAX];
    int top;
};
int isempty(struct array *ps);
int isfull(struct array *ps);
void push(struct array *ps);
int pop(struct array *ps);
int peek(struct array *ps);
void display(struct array *ps);
int main()
{
    struct array s;
    int ch;
    s.top=-1;
    while(1)
    {
        printf("\n1.Push\n");
        printf("\n2.Pop\n");
        printf("\n3.Display\n");
        printf("\n4.Peek\n");
        printf("\n5.Exit the program\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if(isfull(&s))
            {
                printf("Stack is full");
            }
            else
            {
                push(&s);
            }
            break;
            case 2:
            if(isempty(&s))
            {
                printf("Nothing to delete");
            }
            else
            {
                printf("Popped element:%d",pop(&s));
            }
            break;
            case 3:
            if(isempty(&s))
            {
                printf("Nothing to display");
            }
            else
            {
                display(&s);
            }
            break;
            case 4:
            if(isempty(&s))
            {
                printf("Nothing to display");
            }
            else
            {
                printf("Top element:%d",peek(&s));
            }
            break;
            case 5:exit(0);
            default:printf("Invaild choice!!!");
        }
    }
    return 0;
}
int isempty(struct array *ps)
{
    if(ps->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct array *ps)
{
    if(ps->top==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct array *ps)
{
    int ele;
    printf("Enter the data:");
    scanf("%d",&ele);
    ps->top++;
    ps->ar[ps->top]=ele;
}
int pop(struct array *ps)
{
    int ele;
    ele=ps->ar[ps->top];
    ps->top--;
    return (ele);
}
void display(struct array *ps)
{
    int i;
    printf("Stack elements:");
    for(i=0;i<=ps->top;i++)
    {
        printf(" %d\t",ps->ar[i]);
    }
}
int peek(struct array *ps)
{
    int ele;
    ele=ps->ar[ps->top];
    return (ele);
}