#include <stdio.h>
#include <conio.h>
int main()
{
    int size,ar[20],i,sum=0,mul=1;
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
    // calculating sum and mul
    for(i=0;i<size;i++)
    {
        sum=sum+ar[i];
        mul=(mul*ar[i]);
    }
    
    printf("\nSum of elements:%d\n",sum);
    printf("Multiplication of elements:%d\n",mul);
    return 0;
}