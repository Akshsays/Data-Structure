#include <stdio.h>
#include <conio.h>
int main()
{
    int ar[20][20],i,j,rows,columns,mul=1,sum=0;
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
    // calculating sum and multiplication of row
    for(i=0;i<rows;i++)
    {
        mul=1;
        sum=0;
        for(j=0;j<columns;j++)
        {
            sum=sum+ar[i][j];
            mul=mul*ar[i][j];
        }
        printf("Sum of row:%d\n",sum);
        printf("Mul of row:%d\n",mul);
    }
    // calculating sum and multiplication of columns
    for(j=0;j<columns;j++)
    {
        mul=1;
        sum=0;
        for(i=0;i<rows;i++)
        {
            sum=sum+ar[i][j];
            mul=mul*ar[i][j];
        }
        printf("Sum of column:%d\n",sum);
        printf("Mul of column:%d\n",mul);
    }
    return 0;
}