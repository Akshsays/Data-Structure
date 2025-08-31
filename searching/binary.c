#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    int size,ar[20],i,key,flag=0,start=0,mid,end;
     // accept the size
    printf("Enter the size of array [max 20] :");
    scanf("%d",&size);
    end=size-1;
    // store array elements
    for(i=0;i<size;i++)
    {
        printf("Enter the %d element:",i+1);
        scanf("%d",&ar[i]);
    }
    // display array elements
    printf("Array elements:");
    for(i=0;i<size;i++)
    {
        printf("%d ",ar[i]);
    }
    // accept the key for search
    printf("\nEnter the key for searching:");
    scanf("%d",&key);
    // Binary search logic
    for(i=0;i<size;i++)
    {
        mid=(start+end)/2;
        if(ar[mid]==key)
        {
            flag=1;
            break;
        }
        else if(key>ar[mid])
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    // condition
        if(flag==1)
    {
        printf("Key found\n");
    }
    else
    {
        printf("Key not found");
    }
    return 0;
}