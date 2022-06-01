#include<stdio.h>
typedef struct Lebron_recharge
{
    float price;
    char d[15];
}LR;
void read(LR c[5],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter the amount spent");
        scanf("%f%*c",&c[i].price);
        printf("Enter the amount spent for the ");
        gets(c[i].d);
    }
}
void total(LR k[5],int n)
{
    float sum=0;
    int i,j;
    float h=k[0].price;
    for(i=0;i<n;i++)
        sum=sum+k[i].price;
    printf("Total amount spent is %0.2f\n",sum);
    printf("The highest amount spent in transaction \n");
    for(i=1;i<n;i++)
        if(k[i].price>h)
        {
            h=k[i].price;
            j=i;
        }
    printf("The amount was: %0.2f\n",k[j].price);
    printf("The amount was spent for:");
    puts(k[j].d);
}
void main()
{
    LR c[5];
    int n;
    printf("Enter the number of transaction ");
    scanf("%d",&n);
    read(c,n);
    total(c,n);
}
