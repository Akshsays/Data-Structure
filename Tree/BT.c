#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *left,*right;
}*root;
struct node* create()
{
    struct node *newnode;
    int ele;
    printf("\nEnter the data (-1 for no node):");
    scanf("%d",&ele);
    if(ele==-1)
    {
        return 0;
    }
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Allocation failed!!!");
        return 0;
    }
    newnode->data=ele;
    printf("Enter the left child of %d\n",ele);
    newnode->left=create();
    printf("\nEnter the right child of %d\n",ele);
    newnode->right=create();
    
    return newnode;
}
void preorder(struct node *ps)
{
    if (ps == NULL)
    {
        return;
    }
    printf("%d ",ps->data);
    preorder(ps->left);
    preorder(ps->right);
}
void inorder(struct node *ps)
{
    if (ps == NULL)
    {
        return;
    }
    inorder(ps->left);
    printf("%d ",ps->data);
    inorder(ps->right);
}
void postorder(struct node *ps)
{
    if (ps == NULL)
    {
        return;
    }
    postorder(ps->left);
    postorder(ps->right);
    printf("%d ",ps->data);
}
void display(struct node *root)
{
    int i;
    while(1)
    {
        printf("\n1.Preorder\n");
        printf("\n2.Inorder\n");
        printf("\n3.Postorder\n");
        printf("\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&i);
        switch(i)
        {
            case 1:preorder(root);
            break;
            case 2:inorder(root);
            break;
            case 3:postorder(root);
            break;
            case 4:return;
        }
    }
}
int countl(struct node *ps)
{
    int count;
    if(ps==NULL)
    {
        return 0;
    }

    if(ps->left==NULL && ps->right==NULL)
    {
        return 1;
    }
    
    return countl(ps->left) + countl(ps->right);
}
void main()
{
    int ch;
    root=NULL;
    while(1)
    {
        printf("\n1.Create\n");
        printf("\n2.Display\n");
        printf("\n3.Count\n");
        printf("\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if(root==NULL)
            {
                root=create();
            }
            else
            {
                printf("Tree already created");
            }
            break;
            case 2:
            if(root==NULL)
            {
                printf("Nothing to display");
            }
            else
            {
                display(root);
            }
            break;
            case 3:
            if(root==NULL)
            {
                printf("Nothing to count");
            }
            else
            {
                printf("Count:%d",countl(root));
            }
            break;
            case 4:exit(0);
        }
    }
}