/*#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct q
{
    int items[SIZE];
    int front,rear;
};
typedef struct q QUEUE;
QUEUE create_queue()
{
    QUEUE q1;
    q1.front=-1;
    q1.rear=0;
    return q1;
}

void enq(QUEUE *q1,int element)
{
    if(q1->rear==SIZE)
        printf("\nOverflow");
    else
    {
        q1->items[q1->rear]==element;
        q1->rear++;
    }
}
void deq(QUEUE *q1)
{
    if(q1->rear==q1->front+1)
        printf("\nUnderflow");
    else
    {
        q1->front++;
        printf("\nThe dequeued element is %d",q1->items[q1->front]);
    }
}

void display(QUEUE *q1)
{
    int i;
    if(q1->rear==q1->front+1)
        printf("\nEmpty list");
    else
    {
        for(i=q1->front+1;i<q1->rear;i++)
        {
            printf("%d",q1->items[i]);
        }
    }
}
int main()
{
    int i,element,n;
QUEUE q11,*q1;
q11=create_queue();
q1=&q11;
printf("\nEnter the number of elements");
scanf("%d",&n);
if(n>SIZE)
    printf("\nNumber of elements to enq are more than size");
else
{
    for(i=0;i<n;i++)
    {
        printf("\nEnter the element to enqueue");
        scanf("%d",&element);
        enq(q1,element);
    }
    display(q1);

    deq(q1);
    display(q1);
}
}*/




//LAB QUS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

struct q
{
    char vnum[SIZE][15];
    char vtype[SIZE][5];
    int cost[SIZE];
    int front;
    int rear;
};
typedef struct q QUEUE;

QUEUE create_queue()
{
    QUEUE q1;
    q1.front = -1;
    q1.rear = 0;
    return q1;
}

void enqueue(QUEUE *q1)
{
    char vcnum[15], vctype[5];
    if(q1->rear == SIZE)
        printf("Queue Overflow\n");
    else
    {
        scanf("%s%s", vcnum, vctype);
        strcpy(q1->vnum[q1->rear],vcnum);
        strcpy(q1->vtype[q1->rear], vctype);
        if(strcmp(q1->vtype[q1->rear],"HMV")==0)
            q1->cost[q1->rear]= 100;
        else
            q1->cost[q1->rear]= 50;
        q1->rear ++;
    }
}

void dequeue(QUEUE *q1)
{
    if(q1->rear == q1->front +1)
        printf("Queue Underflow\n");
    else
    {
        q1->front++;
        printf("\nVehicle moving out of toll: %s. %s. \n", q1->vnum[q1->front], q1->vtype);
    }
}


void displayqueue(QUEUE *q1)
{
    int i;
    if(q1->rear == q1->front+1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Vehicles at Toll bay are: \n");
        for(i=q1->front+1; i<q1->rear; i++)
        {
                printf("%s %s %d\n", q1->vnum[i], q1->vtype[i], q1->cost[i]);
        }
        printf("\n");
    }
}


void displayqueuevehicles(QUEUE *q1)
{
    int i, lmvcount=0,hmvcount=0;
    if(q1->rear == q1->front+1)
    {
        printf("Queue is empty\n");
    }
    else
    {
       printf("HMV Vehicles at Toll bay are: \n");
        for(i=q1->front+1; i<q1->rear; i++)
        {
            if(strcmp(q1->vtype[i], "HMV")==0)
            {

                hmvcount++;
               printf("%s %s %d\n", q1->vnum[i], q1->vtype[i], q1->cost[i]);
            }
            else
                lmvcount++;
        }
        printf("\n");
    }
    printf("PREDICTED AMOUNT OF LMV VEHICLES: %d\n", lmvcount*50);
    printf("PREDICTED AMOUNT OF HMV VEHICLES: %d\n", hmvcount*100);
}


int main()
{
    int i, n;
    QUEUE q11, *q1;
    q11 = create_queue();
    q1=&q11;
    printf("Enter number of vehicles waiting at Toll bay?\n");
    scanf("%d",&n);
    if(n>SIZE)
    {
        printf("Number of vehicles to enqueue are more than the size of toll bay.\n");
    }
    else
    {
         printf("Enter vehicle number, vehicle type (as LMV or HMV)\n");
        for(i=0;i<n;i++)
        {
            enqueue(q1);
        }
        displayqueue(q1);
        displayqueuevehicles(q1);
      /*  dequeue(q1);
        printf("After vehicle moves out\n");
        displayqueue(q1);

        dequeue(q1);
        printf("After 2nd vehicle moves out \n");
        displayqueue(q1);*/
    }
    return 0;
}
