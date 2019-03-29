#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    node *left , *right;
}node;
node *create_bst();
void function(node *);
int main()
{
    printf(" << Welcome to Binary Search Tree >> \n");
    node *root;
    root = create_bst();
    function(root);
    printf(" << Thanks for using Binary Search Tree >> \n")
}
node *create_bst()
{
    int val;
    printf("Keep Entering data...... And enter -1 to exit entering \n");
    while(1)
    {
        scanf("%d",&val);
        if(val != -1)
        {
            while()
        }
        else    
            break;
    }
}