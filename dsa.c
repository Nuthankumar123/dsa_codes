
/*#include<stdio.h>

int main()
{
    printf("hello world");
    return 0;
}*/

/*#include<stdio.h>

int add(int x ,int y)
{
    int sum,a,b;
    sum=a+b;
    return sum;
}

int main()
{
    int y,x;
    printf("Enter the numbers");
    scanf("%d %d",&x,&y);
    int n=add(x,y);
    printf("The sum is ",n);
    return 0;

}*/
/*#include<stdio.h>
void main()
{
    int *n;
    printf("\nThe size of integer is %d",sizeof(*n));

}*/
#include<stdio.h>

void insert(int a[100],int pos)
{
    int ele,i;
    printf("\nEnter the element=");
    scanf("%d",&ele);
    printf("\nEnter the position=");
    scanf("%d",&pos);
    for(i=0;i!=pos;i++)
    {
        a[i]=ele;
    }
    printf("\nInserted the element %d",a[i]);
}

void main()
{
    int pos,a[100];
    insert(a,pos);

}
