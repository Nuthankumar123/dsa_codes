//Write in the file using the fprintf to write in the file
/*#include<stdio.h>
#include<stdlib.h>
void write_to_file(FILE *fp,int n)
{
    fp=fopen("number.txt","w");
    if(fp==NULL)
    {
        printf("\nERROR\n");
        exit(0);
    }
        else
     fprintf(fp,"%d",n);
     fclose(fp);
}

int main()
{
    int n;
    FILE *fp;
    printf("\nEnter the number you wanna store\n");
    scanf("%d",&n);
    write_to_file(fp,n);
}*/


//Write a C program to read the data from the file
/*#include<stdio.h>
#include<stdlib.h>

void read_from_file(FILE *fp,int n)
{
    fp=fopen("number.txt","r");
    if(fp==NULL)
    {
        printf("\nERROR\n");
        exit(0);
    }
    fscanf(fp,"%d",&n);
    printf("\nThe value of n is %d",n);
    fclose(fp);
}
int main()
{
    int n;
    FILE *fp;
    read_from_file(fp,n);
    return 0;
}*/

//Write a C program to store n number of students name and marks from the user and store them in the file

#include<stdio.h>
#include<stdlib.h>

void write_to_file(FILE *fp,int n)
{
    char name[20];
    int m1,m2,m3,i,p;
    fp=fopen("student.txt","w");
    if(fp==NULL)
    {
        printf("\nERROR\n");
        exit(0);
    }
    printf("\nEnter the student details\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter the NAME, MARKS1, MARKS2, MARKS3\n");
        scanf("%s %d %d %d",name,&m1,&m2,&m3);
        fprintf(fp,"%s\t%d\t%d\t%d\n",name,m1,m2,m3);
    }
    fclose(fp);
}

void read_from_file(FILE *fp,int n)
{

    char name[20];
    int m1,m2,m3,i,p;
    fp=fopen("student.txt","r");
    if(fp==NULL)
    {
        printf("\nERRROR\n");
        exit(0);
    }
    printf("\nEntered details of the students\n");
    printf("\nNAME MARKS1 MARKS2 MARKS3\n");
    for(i=0;i<n;i++)
    {

    fscanf(fp,"%s%d%d%d",name,&m1,&m2,&m3);
    printf("\n%s\t%d\t%d\t%d",name,m1,m2,m3);

    }
    fclose(fp);
}
void percentage(FILE *fp,int n)
{
     /*char name[20];
    int p,m1,m2,m3,i;
    fp=fopen("student.txt","w");
    if(fp==NULL)
    {
        printf("\nERRROR\n");
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        p=m1+m2+m3/150*(100);
        scanf("%s %d %d %d %d",name,&m1,&m2,&m3,&p);
        fprintf(fp,"%s%d%d%d%d",name,m1,m2,m3,p);
    }
    fclose(fp);

    fp=fopen("student.txt","r");
    if(fp==NULL)
    {
        printf("\nERROR\n");
        exit(0);
    }
     printf("\nThe updated list with percentage:\n");
     printf("\nNAME MARKS1 MARKS2 MARKS3 PERCENTAGE\n");
     for(i=0;i<n;i++)
     {
         fscanf(fp,"%s%d%d%d%d",name,&m1,&m2,&m3,&p);
         printf("\n%s%d%d%d%d",name,m1,m2,m3,p);
     }
     fclose(fp);*/
}

int main()
{
    FILE *fp;
    int n;
    printf("\nEnter the number of students\n");
    scanf("%d",&n);
    write_to_file(fp,n);
    read_from_file(fp,n);
    percentage(fp,n);
    return 0;
}

//
