// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[100];
    struct node *next;
};
struct node *head=0,*newnode,*temp;
void create(){
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==0)
    {
        printf("Out of memory\n");
    }
    else{
        printf("Enter name:\n");
        scanf("%s",&newnode->name);
    newnode->next=0;
        }
        if(head==0)
        head=newnode;
        else{
            temp=head;
            while(temp->next!=0)
            temp=temp->next;
            temp->next=newnode;
        }
}

void search()
{
    int flag=0,pos=0;
    /*if(head==0)
    {
    printf("No data available to perform search\n");
    return ;
    }*/
    char n[100];
    printf("Enter name to search:\n");
    scanf("%s",n);
    temp=head;
    while(temp!=0)
    {
        if(strcmp(temp->name,n)==0)
        {
            flag=1;
        }
        temp=temp->next;
        pos++;
    }
    if(flag!=0)
    printf("Name found in position %d",pos);
    else
    printf("Name not found\n");
}
int main() {
 create();
 // create();
   create();
    create();
     search();
  //  return 0;
}