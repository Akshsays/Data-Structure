#include <stdio.h>
#include <conio.h>
int main()
{
    int size,ar[20],i,sum=0;
    float avg;
    // accept array size
    printf("Enter the array size [max 20] :");
    scanf("%d",&size);
    // store elements
    for(i=0;i<size;i++)
    {
        printf("Enter the %d element:",i+1);
        scanf("%d",&ar[i]);
    }
    // display array 
    printf("Array elements:");
    for(i=0;i<size;i++)
    {
        printf("%d ",ar[i]);
    }
    // calculating average 
    for(i=0;i<size;i++)
    {
        sum=sum+ar[i];
        avg=sum/size;
    }
    // display the avg
    printf("\nThe average of array elements is:%f",avg);
    return 0;
}