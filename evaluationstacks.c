#include<stdio.h>
#include<stdlib.h>
#define size 100


typedef struct asteroids
{
int top;
int data[size];
}stack;



void push(stack *d)
{
d->top++;
scanf("%d",&d->data[d->top]);
}


int pop(stack *d)
{
d->top--;
}


int IsEmpty(stack *d)
{
if(d->top==-1)
{
return 1;
}
else{return 0;}
}



void deter(stack *a , stack *b)
{
int count=0,count1=0;
while(IsEmpty(a)!=1  &&  IsEmpty(b)!=1)
{
if(a->data[a->top]==0)
{
pop(a);}

else if(b->data[b->top]==0)
{
pop(b);}
else if(a->data[a->top]>0  &&  b->data[b->top]>0)
{
pop(a);
pop(b);
count1++;
printf("0 ");
}
else if(a->data[a->top]<0  &&  b->data[b->top]<0)
{
pop(a);
pop(b);
count1++;
printf("0 ");
}
else
{
pop(a);
pop(b);
count++;
printf("1 ");
}
}
printf("\n%d",count);
printf("\n%d",count1);
}

int main()
{
stack m,o;
int n,i;
m.top=-1;
o.top=-1;
scanf("%d",&n);
for(i=0;i<n;i++)
{
push(&m);
}
for(i=0;i<n;i++)
{
push(&o);
}
deter (&m,&o);
return 0;
}
