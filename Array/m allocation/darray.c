#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    int size,*ar,i;
    // accept size
    printf("Enter the size of array:");
    scanf("%d",&size);
    // allocating dynamic memory using malloc
    ar=(int *)malloc(size*sizeof(int));
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
    free(ar);
    return 0;
}