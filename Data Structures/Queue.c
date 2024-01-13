
//DOUBT


#include<stdio.h>
#include<stdlib.h>
#define max 5

int q[max],rear=-1,front=0,data;

int enqueue()
{
    if(rear==max-1)
    {
        printf("Queue is full\n");
        return ;
    }
   
    printf("Enter the element:\n");
    scanf("%d",&data);
    q[++rear]=data;
}

int dequeue()
{
    if(rear==-1 || front>rear)
    {
        printf("Queue is Empty\n");
        return;
    }
    
    data=q[front++];
    printf("The deleted item is %d",data);
    
}

void display()
{
    int i; 
    if( rear==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    for(i=front;i<=rear;i++)
    printf("%d\t",q[i]);
}

int main()
{
    int ch;
for(;;)
 {
    printf("\n 1:insert 2:delete 3:display 4:Exit\n");
    printf("Enter the choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:enqueue();
        break;
        case 2:dequeue();
        break;
        case 3:display();
        break;
        case 4:exit(0);
           
    }
 }
 return 0;
}