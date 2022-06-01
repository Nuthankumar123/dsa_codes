//Singly complete
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
struct candid
{
    char name[20];
    int age;
    struct candid *next;
};

typedef struct candid *node;

{
    node newn;
    newn=(node)malloc(sizeof(struct candid));
    if(newn==NULL)
    {
        printf("not created\n");
        exit(0);
    }
    newn->next=NULL;
    return newn;
}

node read()
{
    node temp;
    temp=getnode();
    printf("enter name and age\n");
    scanf("%s%d",temp->name,&temp->age);
    return temp;
}

node insertend(node head)
{
    node newn=NULL,cur=NULL;
    newn=read();
    if(head==NULL)
    {
       return newn;
    }
   else
    {
        cur=head;
        while(cur->next!=NULL)
        {
             cur=cur->next;
        }
        cur->next=newn;
    }
    return head;
}

node insertfront(node head)
{
     node newn=NULL,cur=NULL;
    newn=read();
    if(head==NULL)
    {
       return newn;
    }
    newn->next =head;
    head=newn;
    return head;
}

node insertbefore(node head)
{
    char nm[20];
     node prev=NULL,cur=head;
    node newn=read();
    if(head==NULL)
    {
       return newn;
    }
    printf("\nEnter the name of candidate before which you want to enter\n");
    scanf("%s",nm);
    while(cur->next!=NULL)
    {
        if(strcmp(cur->name,nm)==0)
        {
            break;
        }
        else
        {
            prev=cur;
            cur=cur->next;
        }
    }
    prev->next=newn;
    newn->next=cur;
    return head;
}

node insertafter(node head)
{
    node cur, post, newn = NULL;
    newn = read();
    char m[20];
    if (head == NULL)
    {
        return newn;
    }
    printf("enter the name to inserted after:\n");
    scanf("%s", m);
    cur=head;
    post=cur->next;

    while (strcmp(cur->name, m) != 0)
    {


            cur = cur->next;
            post = post->next;

    }
    cur->next = newn;
    newn->next = post;
    return head;
}

node deleteend(node head)
{
    node prev=NULL,cur=head;
    if(head==NULL)
    {
        printf("Candidate list is empty\n");
    }
    if(head->next==NULL)
    {
        printf("deleted=%s\n",head->name);
        free(head);
        return NULL;
    }
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    printf("deleted=%s\n",cur->name);
    prev->next=NULL;
    free(cur);
    return head;
}

node deletefront(node head)
{
    node cur=head;
    if(head==NULL)
    {
        printf("candidate list is empty\n");
    }
    head=head->next;
    printf("deleted=%s\n",cur->name);
    cur->next=NULL;
    free(cur);
    return head;
}

node deletespecific(node head)
{
    node prev=NULL,cur=head;
    char nm[20];
    printf("Enter name of student whose details has to be deleted\n");
    scanf("%s",nm);
    if(head==NULL)
    {
        printf("Candidate list is empty\n");
    }
    if(head->next==NULL && strcmp(head->name,nm)==0)
    {
        printf("deleted candidate=%s\n",head->name);
        free(head);
        return NULL;
    }
    if(strcmp(cur->name,nm)==0)
    {
        cur=head;
        head=head->next;
        free(cur);
        return head;
    }
    while(cur->next!=NULL)
    {
         if(strcmp(head->name,nm)==0)
         {
             break;
         }
         else
         {
             prev=cur;
             cur=cur->next;
         }
    }
    prev->next=cur->next;
    printf("deleted candidate=%s\n",cur->name);
    free(cur);
    return head;
}

node reverse(node head)
{
    node nextnode,cur=head,prev=NULL;
    while(cur!=NULL)
    {
        nextnode=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nextnode;
    }
    return prev;
}

void display(node head)
{
    node cur=NULL;
    if(head==NULL)
    {
        printf("candidate list i empty\n");
    }
    else
    {
            cur=head;
        printf("\ndetails:\nName age \n head->");
        while(cur!=NULL)
        {
            printf("%s%d",cur->name,cur->age);
            cur=cur->next;
        }
        printf("  NULL\n");
    }
}

int main()
{
    node head=NULL;
        int c,cnt;
        while(1)
        {
            printf("1.Insert end  2.Insert front 3. Insert before 4. delete end 5. delete front 6.delete specific");
            printf("7.Reverse list 8.count 9.display 10.exit\nenter ur choice \n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:head=insertend(head);
                break;
                 case 2:head=insertfront(head);
                break;
                 case 3:head=insertbefore(head);
                break;
                 case 4:head=deleteend(head);
                break;
                 case 5:head=deletefront(head);
                break;
                 case 6:head=deletespecific(head);
                break;
                case 7:head=reverse(head);
                break;
                case 8:head=insertafter(head);
                break;
                case 9:display(head);
                break;
                case 10:exit(0);
                break;
                default : printf("invalid choice\n");
            }
        }
        return 0;
}
