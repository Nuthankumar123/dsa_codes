//Circular wirh some operations
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct series
{
    char name[10];
    int year;
    struct node *next;
};
typedef struct series *node;
node head=NULL;

void lastinsert()
{
    node ptr,temp;

    ptr = (node)malloc(sizeof(struct series));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        scanf("%s%d",ptr->name,&ptr->year);

        if(head == NULL)
        {
            head = ptr;
            ptr -> next = head;
        }
        else
        {
            temp = head;
            while(temp -> next != head)
            {
                temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> next = head;
        }
    }

}

void display()
{
    node ptr;
    ptr=head;
    if(head == NULL)
    {
        printf("\nnothing to print");
    }
    else
    {
        printf("\n");

         do
        {
             printf("%s  %d\n",ptr->name,ptr->year);
            ptr = ptr -> next;
        }while(ptr != head);
    }
}

void search()
{
    node ptr;
    ptr=head;
    char s[20];int c=0;
    if(head == NULL)
    {
        printf("\nnothing to print");
    }
    else
    {
        scanf("%s",s);
         do
        {
            if(strcmp(ptr->sname,s)==0)
            {
                printf("%s  %d\n",ptr->name,ptr->year);
                c++;
            }
             ptr = ptr -> next;
        }while(ptr!= head);

        if(c==0)
        {
            printf("0");
        }
        else
            printf("%d\n",c);

    }
}

void del()
{
    node prev,newn;
    newn=head;
    char a[20];
    printf("\nEnter the song name to be deleted\n");
    scanf("%s",a);
    if(head == NULL)
    {
        printf("\nnothing to print");
    }
    else
        if(head->next == head)
        {
            if(strcmp(head->sname,a)==0)
            {
                printf("\ndeleted\n");
                free(head);
                head=NULL;
            }
        }
    else
        if(strcmp(head->sname,a)==0)
        {
            do
            {
                newn=newn->next;
            }while(newn!= head);

            prev=head;
            newn->next=head->next;
            head=head->next;
            free(newn);
        }
    else
        {
        do
        {
            if(strcmp(newn->name,a)==0)
            {
                prev->next=newn->next;
                printf("\ndeleted\n");
            }
            prev=newn;
            newn=newn->next;
        }while(newn!= head);
        free(newn);
        }
}

void main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        lastinsert();
    }
    display();
    search();
}
