#include <stdio.h>
#include <conio.h>
int main()
{
    int ar[20][20],rows,columns,i,j;
    // accept row size
    printf("Enter the size of rows:");
    scanf("%d",&rows);
    // accept column size
    printf("Enter the column size :");
    scanf("%d",&columns);
    // store elements
    for(i=0;i<rows;i++)
    {
        for(j=0;j<columns;j++)
        {
            printf("Enter the elements:");
            scanf("%d",&ar[i][j]);
        }
    }
    // display 2d array
    printf("\n**Matrix**\n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<columns;j++)
        {
            printf("\t%d",ar[i][j]);
        }
        printf("\n");
    }
    return 0;
}