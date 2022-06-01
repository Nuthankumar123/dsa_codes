#include<stdio.h>
#include<stdlib.h>
typedef struct Makemytrip
{
  char p_name[20];
  char t_name[30];
  char depart[30];
  char destin[30];
  int  amt;
  int transaction;
}MMT;

void read(MMT *m,int n)
{
   int i;
   for(i=0;i<n;i++)
   {
       printf("Enter transaction details :Name of customer\tTrain name\tDeparture place\tDestination place\tAmount and transaction for %d customer\n",(i+1));
       scanf("%s%s%s%s%d%d",m[i].p_name,m[i].t_name,m[i].depart,m[i].destin,&m[i].amt,&m[i].transaction);
   }
   for(i=0;i<n;i++)
   {
       printf("Name : %s\tTrain name\t %s\tDeparture place\t %s\tDestination place\t %s\tAmount\t %d\tTransaction number\t %d\n",m[i].p_name,m[i].t_name,m[i].depart,m[i].destin,m[i].amt,m[i].transaction);
   }
}
void display(MMT *m,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(m[i].transaction==25)
        {
            printf("Customer name who gets 50 percentage discount is: %s\n",m[i].p_name);
        }
    }
}
void amount(MMT *m,int n)
{
    int i;
    float A;
    for(i=0;i<n;i++)
    {
        if(m[i].transaction==25)
        {
            A=m[i].amt*0.5;
            printf("Customer %s will get %0.2f rupees back discount\n",m[i].p_name,A);
        }
        A=0;
    }
}
int main()
{
   MMT *t;
   int n;
   printf("\nEnter number of customers\n");
   scanf("%d",&n);
   t=(MMT *)malloc(sizeof(MMT)*n);
   read(t,n);
   display(t,n);
   amount(t,n);
   return(0);
}
