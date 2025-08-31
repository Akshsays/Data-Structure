#include <stdio.h>
#include <conio.h>
int main()
{
    int size,ar[20],i,sum=0;
    // accept the size of array
    printf("Enter the size of array [max 20] :");
    scanf("%d",&size);
    // storing array element
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
    // calculating sum
    for(i=0;i<size;i++)
    {
        sum=sum+ar[i];
    }
    // display the sum
    printf("\nSum of array elements:%d\n",sum);
    return 0;
}