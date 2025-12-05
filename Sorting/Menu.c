#include <stdio.h>
#include <stdlib.h>
void bubble(int ar[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(ar[j]>ar[j+1])
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
    printf("\nSorted Array through Bubble sort:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",ar[i]);
    }
}
void select(int ar[],int n)
{
    int i,j,temp,si;
    for(i=0;i<n-1;i++)
    {
        si=i;
        for(j=i+1;j<n;j++)
        {
            if(ar[si]>ar[j])
            {
                si=j;
            }
        }
        temp=ar[i];
        ar[i]=ar[si];
        ar[si]=temp;
    }
    printf("Sorted Array through bubble sort:");
    for(i=0;i<n;i++)
    {
        printf("%d",ar[i]);
    }
}
void insert(int ar[],int n)
{
    int i,j,cur,prev;
    for(i=1;i<n;i++)
    {
        cur=ar[i];
        prev=i-1;
        while(prev>=0 && ar[prev]>cur)
        {
            ar[prev+1]=ar[prev];
            prev--;
        }
        ar[prev+1]=cur;
    }
    printf("Sorted array through insertion:");
    for(i=0;i<n;i++)
    {
        printf("%d",ar[i]);
    }
}
void sort(int ar[],int n)
{
    int ch;
    printf("\n1.Bubble sort\n");
    printf("\n2.Selection sort\n");
    printf("\n3.Insertion sort\n");
    printf("\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:bubble(ar,n);
        break;
        case 2:select(ar,n);
        break;
        // case 3:insert(ar,n);
        // break;
        case 4:exit(0);
    }
}
void main()
{
    int ch;
    int ar[20],n,i;
    printf("Enter the size (max 20):");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter %d data:",i+1);
        scanf("%d",&ar[i]);
    }

    printf("Original array:");
    for(i=0;i<n;i++)
    {
        printf("%d",ar[i]);
    }

    printf("\n1.Sort\n");
    printf("\n2.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:sort(ar,n);
        break;
        case 2:exit(0);
        default:printf("Invaild Choice");
    }
}