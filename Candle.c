
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct candle
{
    int size;
    struct candle *next;
    struct candle *prev;
};

 typedef struct candle *NODE;
 NODE head;

NODE getnode()
{
    NODE newn;
    newn=(struct candle*)malloc(sizeof(struct candle));
    /*if(newn==0)
    {
      printf("\nMemory not allocated");
      exit(0);
    }

    else*/
        /*printf("\nEnter the candles size=");*/
        scanf("%d\t",&newn->size);
        newn->next=newn;
        newn->prev=newn;

    return newn;
}

NODE insert_end()
{
    NODE last,newn;
    newn=getnode();
    if(head==0)
    {
        head=newn;
    }
    else
{
        last=head->prev;


            last->next=newn;
            newn->prev=last;

            newn->next=head;
            head->prev=newn;

}
    return head;
}

NODE sol()
{
    NODE temp,last,front;
    int count=0,flag=0;
    int max=0;
    temp=head;

    /*if(head==0)
    {

       printf("\nEmpty list");
       return NULL;
    }
    else*/

        do
        {
            count++;
            printf("%d ",temp->size);
            temp=temp->next;
        }
        while(temp!=head);


            temp=head;
            do
            {
            if(temp->size>max)
            {
                max=temp->size;
            }
            temp=temp->next;
            }
            while(temp!=head);
            printf("\nTallest Candle = %d",max);

            temp=head;
                do
                {
                if(temp->size==max)
                {
                    flag++;
                    if(temp==head&&temp->next==head)
                    {
                        head=0;
                        printf("\nTallest candles blown = %d",flag);
                        free(temp);

                        return NULL;
                    }
                    else if(temp->next==head)
                    {
                        last=temp->prev;

                        last->next=head;
                        head->prev=last;

                        temp->next=0;
                        temp->prev=0;
                        printf("\nTallest candles blown = %d",flag);
                        free(temp);


                        return head;

                    }
                    else if(temp==head)
                    {
                        last=head->prev;

                        head=head->next;
                        head->prev=last;

                        last->next=head;

                        temp->prev=0;
                        temp->next=0;
                        printf("\nTallest candles blown = %d",flag);
                        free(temp);


                        return head;
                    }
                    else
                    {
                        front=temp->next;
                        last=temp->prev;

                        last->next=front;
                        front->prev=last;

                        temp->prev=0;
                        temp->next=0;
                        printf("\nTallest candle blown = %d",flag);
                        free(temp);


                        return head;
                    }
                }
                temp=temp->next;

                }
                while(temp!=head);


}
int main()
{
    int n,i;
    //printf("\nEnter the number of candles=");
    scanf("%d\n",&n);
    if(n>0)
    {
        for(i=0;i<n;i++)
        {
            head=insert_end();
        }
        head=sol();
    }

    else
    {
        printf("Invalid input.");
    }
    return 0;
}
