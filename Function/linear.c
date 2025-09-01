#include <stdio.h>
#include <conio.h>
#include <conio.h>
int lsearch(int ar[],int n,int key,int flag)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(ar[i]==key)
        {
            flag=1;
            break;
        }
    }
    return flag;
}
void main()
{
    int n,ar[20],i,key,flag=0,result;
     // accept the size
    printf("Enter the size of array [max 20] :");
    scanf("%d",&n);
    // store array elements
    for(i=0;i<n;i++)
    {
        printf("Enter the %d element:",i+1);
        scanf("%d",&ar[i]);
    }
    // display array elements
    printf("Array elements:");
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
    // accept the key for search
    printf("\nEnter the key for searching:");
    scanf("%d",&key);
    result=lsearch(ar,n,key,flag);
    // condition
    if(result==1)
    {
        printf("\nkey found\n");
    }
    else
    {
        printf("Key not found");
    }
}