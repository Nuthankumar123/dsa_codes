#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

struct stack
{
    int num[SIZE];
    int top;
};
typedef struct stack STACK;

void push(STACK *s, int data)
{
    if(s->top == SIZE-1)
     printf("Stack Overflow\n");

    else
    {
        s->top ++;
        s->num[s->top] = data;
    }
}

int pop(STACK *s)
{
    int data;
    if(s->top == -1)
    printf("Stack Underflow\n");

    else
    {
        data=s->num[s->top];
        s->top--;
        return data;
    }
}

void reversenumber(STACK *s)
{
     int n, m, rem, factor=1, rev=0;
     printf("Enter a number to reverse: ");
     scanf("%d",&n);
     printf("Entered number %d\n", n);
     m=n;
    while(n)
    {
        rem = n%10;
        push(s,rem);
        n = n/10;
    }
    while(s->top!=-1)
    {
        rev=rev+ factor * pop(s);
        factor=factor *10;
    }
     printf("Reverse number is: %d\n", rev);
     if(rev == m)
    printf("Entered number %d is palindrome number\n", m);
    else
    printf("Entered number %d is not a palindrome number\n", m);
}

int main()
{
    int ch,data;
    STACK st,*s;
    s=&st;
    s->top = -1;
    reversenumber(s);
    return 0;
}
