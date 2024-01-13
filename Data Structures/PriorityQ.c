#include<stdio.h>
#include<stdlib.h>
#define Max 5

int priority[Max],data[Max],r=-1,f=0,i;
void isempty(){
    if(r==-1)
    printf("Queue is empty\n");
}

void isfull(){
    if(r==Max-1)
    printf("Queue is full\n");
}

int insert(int data,int priority)
{
    if(!isfull)
    {
        if(r==-1)
        {
            r++;
            data[r]=data;
            priority[r]=priority;
            return;
        }
        else{
            r++;
            for(i=r-1;i>=0;i--)
            {
                if(priority[i]>=priority)
                {
                    data[i+1]=data[i];
                    priority[i+1]=priority[i];
                }
                else{
                    data[i+1]=data;
                    priority[i+1]=priority;
                    return;
                }
            }
        }
    }
}

void delete(){
    if(r==-1 || f>r)
    {
        printf("Queue is empty\n");
        return;
    }
    data=data[f++];
    priority=priority[f++];
    printf("The deleted item is %d",data);
}

void display(){
    if(r==-1 || f>r)
    {
        printf("Queue is empty\n");
        return;
    }
    for(i=0;i<=r;i++)
    printf("%d\t",data[i]);
}

void main(){
    int ch;
    for(;;)
    {
        printf("\n 1:Enqueue\n 2:Dequeue\n 3:Display\n 4:Exit\n");
        printf("Enter thr choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
        }
    }
}