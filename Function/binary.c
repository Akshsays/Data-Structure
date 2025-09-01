#include <stdio.h>
#include <conio.h>
int binarys();
void main()
{
    int size,ar[20],i,start=0,mid,end,key,flag=0,result;
    // accept size
    printf("Enter the array size [max 20] :");
    scanf("%d",&size);
    end=size-1;
    // storing elements
    for(i=0;i<size;i++)
    {
        printf("Enter the %d sorted:",i+1);
        scanf("%d",&ar[i]);
    }
    // display list
    printf("Array elements:");
    for(i=0;i<size;i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
    // accept the key
    printf("Enter the key:");
    scanf("%d",&key);
    // flag vlaue being stored 
    result=binarys(ar,size,key,flag);
    // condition 
    if(result==1)
    {
        printf("Key found\n");
    }
    else
    {
        printf("Key not found\n");
    }
}
int binarys(int ar[],int size,int key,int flag)
{
    int start=0,mid,end=size-1;
    // binary logic
    while(start<=end)
    {
        mid=(start+end)/2;
        if(ar[mid]==key)
        {
            flag=1;
            break;
        }
       else if (key>ar[mid])
       {
        start=mid+1;
       }
       else
       {
        end=mid-1;
       }
        
    }
    return flag;
}