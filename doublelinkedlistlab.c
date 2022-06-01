//Hacker rank type
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[10];
    int times,year;
    struct node *prev;
    struct node *next;
};

struct node *head;
int length()
{
    struct node *temp;
    int count=0;
    if(head==0)
        printf("\nEmpty list");
    else
    {
        temp=head;
        while(temp!=0)
        {
            temp=temp->next;
            count ++;
        }
    }
    return count;
}
void create()
{

    struct node *newn,*temp;
    newn=(struct node*)malloc(sizeof(struct node));

    printf("\nNAME(SONG) TIMES YEAR OF RELEASE\n");
    scanf("%s %d %d",newn->name,&newn->times,&newn->year);
    newn->prev=0;
    newn->next=0;

    if(head==0)
    {
        head=newn;
    }
    else
    {
        temp=head;
        while(temp->next!=0)
        {
        temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
}

void display()
{
    struct node *temp;
    if(head==0)
        printf("\nThe list is empty");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("\n%s %d %d",temp->name,temp->times,temp->year);
            temp=temp->next;
        }
    }
}

struct node* insert_after_loc()
{
    struct node *temp,*newn,*front;
    char sn[20];

    if(head==0)
    {
        printf("\nNo nodes are present");
        return NULL;
    }
    else
        {
            printf("\nEnter the song after which new song needs to be added=");
            scanf("%s",sn);

            temp=head;
            while(temp!=0)
            {

            if(strcmp(temp->name,sn)==0)
            {
                if(temp==head&&temp->next==0)
                {
                    newn=(struct node*)malloc(sizeof(struct node));
                    printf("\nNAME(SONG) TIMES YEAR OF RELEASE\n");
                    scanf("%s %d %d",newn->name,&newn->times,&newn->year);
                    newn->prev=0;
                    newn->next=0;
                    temp->next=newn;
                    newn->prev=temp;
                    printf("\nSong inserted!!");
                    return head;
                }
                else if(temp==head)
                {
                    newn=(struct node*)malloc(sizeof(struct node));
                    printf("\nNAME(SONG) TIMES YEAR OF RELEASE\n");
                    scanf("%s %d %d",newn->name,&newn->times,&newn->year);
                    front=temp->next;
                    newn->next=front;
                    newn->prev=temp;
                    front->prev=newn;
                    temp->next=newn;
                    printf("\nSong inserted!!");
                    return head;
                }
                else if(temp->next==0)
                {
                    newn=(struct node*)malloc(sizeof(struct node));
                    printf("\nNAME(SONG) TIMES YEAR OF RELEASE\n");
                    scanf("%s %d %d",newn->name,&newn->times,&newn->year);
                    temp->next=newn;
                    newn->prev=temp;
                    newn->next=0;
                    printf("\nSong inserted!!");
                    return head;
                }
                else
                {
                    newn=(struct node*)malloc(sizeof(struct node));
                    printf("\nNAME(SONG) TIMES YEAR OF RELEASE\n");
                    scanf("%s %d %d",newn->name,&newn->times,&newn->year);
                    front=temp->next;
                    newn->prev=temp;
                    newn->next=front;
                    front->prev=newn;
                    temp->next=newn;
                    printf("\nSong inserted!!");
                    return head;


                }
              }
             temp=temp->next;
            }

        }
   }
/*void del_speci()
{
    struct node *temp,*front,*back;
    front=0;back=0;
    char sn[20];

    if(head==0)
    {
        printf("\nNo nodes are present");
        return NULL;
    }
    else
    {
        temp=head;
        printf("\nEnter the song to be deleted=");
        scanf("%s",sn);

        while(temp!=0)
        {
            if(strcmp(temp->name,sn)==0)
            {
                if(temp==head&&temp->next==0)
                {
                    printf("\nThe deleted song is %s",temp->name);
                    head=0;
                    free(temp);
                    return NULL;
                }
                else if(temp==head)
                {
                    printf("\nThe deleted song is %s",temp->name);
                    front=temp->next;
                    front->prev=0;
                    head=front;
                    free(temp);
                    return front;
                }
                else if(temp->next==0)
                {
                    printf("\nDeleted song is %s",temp->name);
                    back=temp->prev;
                    back->next=0;
                    free(temp);
                    return head;

                }
                back=temp->prev;
                front=temp->next;
                back->next=temp->next;
                front->prev=back;
                temp->next=0;
                temp->prev=0;
                free(temp);
                return head;
            }
            temp=temp->next;
        }
      printf("\nNo songs found");
      return head;
    }

}*/
struct node* del_speci()
{
  struct node *temp,*front=0,*back=0;
  int max;
  if(head==0)
  {
    printf("\nThe list is empty");
    return head;
  }
  else
  {
      temp=head;
      max=temp->times;
      while(temp!=0)
      {
          if(temp->times>max)
          {
              max=temp->times;
          }
          temp=temp->next;
      }

      temp=head;
      while(temp!=0)
      {
          if(temp->times==max)
          {
             if(temp==head&&temp->next==0)
             {
                 head=0;
                 free(temp);
                 return NULL;
             }
             else if(temp==head)
             {
                 front=temp->next;
                 head=head->next;
                 front->prev=0;
                 free(temp);
                 return head;
             }
             else if(temp->next==0)
             {
                 back=temp->prev;
                 temp->prev=0;
                 back->next=0;
                 return head;
             }
             else
             {
                 front=temp->next;
                 back=temp->prev;
                 front->prev=temp->prev;
                 back->next=temp->next;
                 temp->next=0;
                 temp->prev=0;
                 free(temp);
                 return head;
;             }
          }
          temp=temp->next;
      }
  }
}

int main()
{
    int n,i=0,l;
    printf("\nPlaylist");
    printf("\nEnter the number of songs=");
    scanf("%d",&n);
    printf("Enter the details");
    for(i=0;i<n;i++)
    {
        create();
    }
    display();
    insert_after_loc();
    display();
    printf("\n");
    del_speci();
    display();
    printf("\n");
    l=length();
    printf("\nNumber of songs in the playlist %d",l);

    return 0;
}
