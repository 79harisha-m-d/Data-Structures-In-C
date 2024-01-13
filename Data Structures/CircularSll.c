#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create()
{
    struct node *newnode,*head,*temp;
    newnode=(struct node *)malloc(suzeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=0;

    if(head==0)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    newnode->next=head;
}