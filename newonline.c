#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct online
{
    int id;
    char name[20];
    int hr;
    int min;
    struct online *prev;
    struct online *next;
}*NODE;
 NODE head;
NODE getnode()
{
     NODE newn, temp = head;
     newn = (NODE)malloc(sizeof(struct online));
     scanf("%d%s%d%d", &newn->id, newn->name, &newn->hr, &newn->min);
     newn->next = newn;
     newn->prev = newn;
     if(head == NULL){
         head = newn;
     }else
     {
         while(temp->next!=head){
             temp = temp->next;
         }
         temp->next = newn;
         newn->prev = temp;
         newn->next = head;
         head->prev = newn;
     }
     return head;
 }

void display(){
     NODE temp = head;
     do{
         printf("%d\t%s\t%d\t%d\n", temp->id, temp->name, temp->hr, temp->min);
         temp = temp->next;
     }while( temp->next != head->next);
     printf("\n");
 }

 NODE del(){
    NODE temp = head, front, temp1;
    char sn[20];
    scanf("%s", sn);
    do{
        temp = temp->prev;
        if(strcmp(temp->name, sn)==0){
            temp1 = temp->next;
            front->next = temp1;
            temp1->prev = front;
            free(temp);
            temp = front;
        }
        temp = temp->next;
    }while(temp->next != head->next);
    return head;
}



int main(){
 int n;
 scanf("%d", &n);
if(n>5)
{

 for(int i = 0; i<n; i++)
    {
     head = getnode();
 }
}
 del();

 display();


    return 0;
}
