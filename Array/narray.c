#include <stdio.h>
#include <conio.h>
int main()
{
    int size,ar[20],i;
    // accept size
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
    return 0;
}