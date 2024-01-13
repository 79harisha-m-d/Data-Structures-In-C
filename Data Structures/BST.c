#include<stdio.h>
#include<stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST NODE;
NODE *node;

NODE* createtree(NODE *node,int data)
{
    if (node==NULL)
    {
        NODE *temp;
        temp=(NODE*)malloc(sizeof(NODE));
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(data<(node->data))
    {
        node->left=createtree(node->left,data);
    }
    else if(data>(node->data))
    {
        node->right=createtree(node->right,data);
    }
    return node;
}

NODE* search(NODE *node,int data)
{
    if(node==NULL)
    printf("\nElement not found\n");
    else if(data<(node->data))
    {
        node->left=search(node->left,data);
    }
    else if(data>(node->data))
    {
        node->right=search(node->right,data);
    }
    else
    printf("\nElement found is :%d",node->data);
    return node;
}

void inorder(NODE *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d\t",node->data);
        inorder(node->right);
    }
}

void preorder(NODE *node)
{
    if(node!=NULL)
    {
        printf("%d\t",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(NODE *node)
{
    if(node!=NULL)
    {
        postorder(node->left);
        postorder(node->right);
         printf("%d\t",node->data);
    }
}

int main()
{
    int i,n,ch,data;
    NODE *root=NULL;

    while(1)
    {
        printf("\n1:Insertion in Binary search tree");
         printf("\n2:Search element in Binary Search Tree");
       printf("\n3:Inorder \n4:Preorder \n5:Postorder  \n6:Exit");
       printf("\n Enter the choice:");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1:printf("Enter N value\n");
        scanf("%d",&n);
        printf("Enter the values to create a BST\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&data);
            root=createtree(root,data);
        }
        break;
        case 2:printf("Enter the element to be searched\n");
        scanf("%d",&data);
        root=search(root,data);
        break;
        case 3:printf("Inorder Traversal\n");
        inorder(root);
        break;
        case 4:printf("Preorder Traversal\n");
        preorder(root);
        break;
        case 5:printf("Postorder Traversal\n");
        postorder(root);
        break;
        case 6:exit(0);
        default:printf("Wrong option\n");
        break;
       }
    }
}

