//Operations on stack array (implementation of stack)
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct stack
{
    int num[SIZE];
    int top;
};
typedef struct stack STACK;

void push(STACK *s,int data)
{

    if(s->top==SIZE-1)
    {
        printf("\nStack overflow");
    }
    else
    {
        s->top++;
        s->num[s->top]=data;

    }
}

int pop(STACK *s)
{
    int data;
    if(s->top==-1)
    {
        printf("\nStack underflow");
    }
    else
    {
        data=s->num[s->top];
        s->top--;
        return data;
    }

}

void display(STACK *s)
{
    int i;
    if(s->top==-1)
    {
        printf("\nStack empty");
    }
    else
    {
        printf("top->");
        for(i=s->top;i>=0;i--)
        {
            printf(" %d",s->num[i]);
        }
        printf("\n");
    }
}

int peek(STACK *s)
{
    int data;
    if(s->top==-1)
        printf("\nStack empty");
    else
    {
        data=s->num[s->top];
        return data;
    }

}
int main()
{
    int ch,data;
    STACK st; //variable
    STACK *s; //pointer
    s=&st;
    s->top=-1;
    printf("\nMENU STACK OPERTAIONS");
    while(1)
    {
        printf("\n 1.PUSH 2.POP 3.PEEK 4.DISPLAY 5.EXIT");
        printf("\nEnter the choice=");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("\nEnter the data to push=");
                   scanf("%d",&data);
                   push(s,data);
                   break;
            case 2:data=pop(s);
                   printf("\nThe poped data is %d",data);
                   break;
            case 3:data=peek(s);
                   printf("\nTop data in stack is %d",data);
                   break;
            case 4:display(s);
                   break;
            case 5:exit(0);
                   break;
            default:printf("\nInvalid input choice");
        }
    }

    return 0;
}
