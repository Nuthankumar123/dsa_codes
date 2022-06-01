//SIMPLE FILE OPENING
//Create a student file enter name and roll.no!!
/*#include<stdio.h>
#include<stdlib.h>
void main()
{
    char name[100];
    int roll;
    FILE *fp;
    char ch;
    fp=fopen("student.txt","w");
    if(fp==NULL)
    {
        printf("\nError in opening a file");
        exit(0);
    }
    printf("\nInput some text");
    while((ch=getchar()) !=EOF)
        fputc(ch,fp);
        fclose(fp);
        printf("\nThe file contains");
        fp=fopen("student.txt","r");
        while((ch=fgetc(fp))!=EOF)
        putchar(ch);
        fclose(fp);
}
*/

//Create a student file enter name and roll.no!
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char name[100];
    int num,marks,i;
    FILE *fp;
    char ch;
    fp=fopen("student.txt","r+");
    if(fp==NULL)
    {
        printf("\nError in opening a file");
        exit(0);
    }
    printf("\nInput the details in text");
    printf("\nEnter the number of students:");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("\nFor student%d\n Enter name:",i+1);
        scanf("%s",name);
        printf("\nEnter the marks:");
        scanf("%d",&marks);
        fprintf(fp,"%s \n%d \n",name,marks);

    }
        fclose(fp);
        if((fp=fopen("student.txt","r"))==NULL)
        {
            printf("\nError opening file");
            exit(0);
        }

        for(i=0;i<num;i++)
        {
            fscanf(fp,"%s",name);
            fscanf(fp,"%d",&marks);
            printf("%s\n%d\n",name,marks);

         //if(feof(fp))
         //break;
        }

        return 1;
}

