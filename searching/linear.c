#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    int size,ar[20],i,key,flag=0;
     // accept the size
    printf("Enter the size of array [max 20] :");
    scanf("%d",&size);
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
    // linear search logic
    for(i=0;i<size;i++)
    {
        if(ar[i]==key)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("Key found\n");
    }
    else
    {
        printf("Key not found");
    }
}