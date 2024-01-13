#include<stdio.h>
#include<stdlib.h>
#define N 5
int dequeue[N],f=-1,r=-1,x;
int *Q;

int insertfront(int x)
{
   int r,f;
    if((f==0 && r==N-1) ||(f==r+1))
    {
       queuefull();
    }
    else if (r==-1 && f==-1)
    {
       f=r=0;
       dequeue[f]=x;
    }
    else if(f==0)
    {
        f=N-1;
        dequeue[f]=x;
    }
    else{
        f--;
        dequeue[f]=x;
    }
    
}


int insertrear(int x)
{
    if((f==0 && r==N-1) || (f==r+1))
    {
       queuefull();
    }
    else if(r==-1 && f==-1)
    {
        f=r=0;
        dequeue[r]=x;
    }
    else if(r==N-1)
    {
        r=0;
        dequeue[r]=x;
    }
    else{
        r++;
        dequeue[r]=x;
    }
}

void queuefull()
{
    Q=(int*)realloc(Q,1*sizeof(int));
    if(Q==NULL)
    {
        printf("Insufficient memory\n");
        exit(0);
    }
  
}

void display()
{
    int i;
    //i=f;
    //while(i!=r)
    for(i=f;i<=r;i++)
    {
        printf("The elements are:\n");
        printf("%d",dequeue[i]);
        i=(i+1)%N;
    }
    printf("%d",dequeue[i]);
}

void deletefront()
{
    if(r==-1 && f==-1)
    {
        printf("Queue is empty\n");
    }
    else if(f==r)
    {
        printf("The deleted element is %d",dequeue[r]);
        f=r=-1;
    }
    else if(f==N-1)
    {
        printf("The deleted element is %d",dequeue[f]);
        f=0;
    }
    else
    {
        printf("The deleted element is %d",dequeue[f]);
        f++;
    
    }
}

void deleterear()
{
    if(r==-1 && f==-1)
    {
        printf("Queue is empty\n");
    }
    else if(f==r)
    {
        printf("The deleted element is %d",dequeue[r]);
        f=r=-1;
    }
    else if(r==0)
    {
        printf("The deleted element is %d",dequeue[r]);
        r= N-1;
    }
    else
    {
        printf("The deleted element is %d",dequeue[r]);
        r--;
    
    }
}

void main()
{
    int choice,x;
    for(;;)
    {
        printf("\n 1:InsertFront 2:InsertRear 3:DeleteFront 4:DeleteRear 5:Display 6:Exit\n");
        printf("Enter the choice:\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:printf("Enter the data:");
                   scanf("%d",&x);
                   insertfront(x);
                   break;
            case 2:printf("Enter the data:");
                   scanf("%d",&x);
                   insertrear(x);
                   break; 
            case 3:deletefront();
                   break;
            case 4:deleterear();
                   break;
            case 5:display();
                   break;
            case 6:exit(0);

        }
    }
}
