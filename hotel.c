#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct hotel
{
    int id;
    int age;
    struct hotel *left, *right;

}*hotel;

hotel getnode(int age, int id)
{
    hotel temp;
    temp = (hotel)malloc(sizeof(struct hotel));
    temp->left = NULL;
    temp->right = NULL;

    temp->id = id;
    temp->age = age;

    return temp;
}

hotel insert(hotel root, int age, int id)
{
    if(root == NULL)
    {
        root = getnode(age, id);
        return root;
    }

    if(root->age > age)
    {
        root->left = insert(root->left, age, id);
    }
    else
    {
        root->right = insert(root->right, age, id);
    }

    return root;
}


void inorder(hotel root)
{
    if(root == NULL)
    {
        return;
    }

        inorder(root->left);
        printf("Id: %d\n", root->id);
        printf("Age: %d\n", root->age);
        inorder(root->right);

}


void PrevPtr(hotel root)
{
    static struct hotel *pre = NULL;

    if (root != NULL)
    {
        PrevPtr(root->left);
        root->left = pre;
        pre = root;
        PrevPtr(root->right);
    }
}


hotel NextPtr(hotel root)
{
    struct hotel *prev = NULL;

    while (root && root->right != NULL)
        root = root->right;

    while (root && root->left != NULL)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }

    return (root);
}

hotel BTToDLL(hotel root)
{
    PrevPtr(root);
    return NextPtr(root);
}

void printList(hotel root)
{
    int child_age[50], child_id[50];
    int adult_age[50], adult_id[50];
    int old_age[50], old_id[50];
    int i=0, j=0, k=0;

    while (root != NULL)
    {
        if(root->age <= 20)
        {
            child_age[i] = root->age;
            child_id[i] = root->id;
            i++;
        }
        else if(root->age > 20 && root->age <= 50)
        {
           adult_age[j] = root->age;
           adult_id[j] = root->id;
           j++;
        }
        else if(root->age > 50)
        {
            old_age[k] = root->age;
            old_id[k] = root->id;
            k++;
        }
        root = root->right;
    }

    printf("Children\n\n");
    for(int ii=0;ii<i;ii++)
    {
        printf("Age: %d\t", child_age[ii]);
        printf("Id: %d\n\n", child_id[ii]);
    }
    printf("Total number of children in the hotel are: %d\n\n", i);

    printf("Adult\n\n");
    for(int ij=0;ij<j;ij++)
    {
        printf("Age: %d\t", adult_age[ij]);
        printf("Id: %d\n\n", adult_id[ij]);
    }
    printf("Total number of adults in the hotel are: %d\n\n", j);

    printf("Old\n\n");
    for(int ik=0;ik<k;ik++)
    {
        printf("Age: %d\t", old_age[ik]);
        printf("Id: %d\n\n", old_id[ik]);
    }
    printf("Total number of old in the hotel are: %d\n\n", k);
}


int main()
{
    hotel root = NULL;
    hotel head = NULL;

    int age, n, id;

    printf("1. Insert the Customer\n");
    printf("2. Display the customer\n");
    printf("3. Print the list of customers\n");
    printf("4. Exit\n");
    do{


    printf("Enter your choice: \n");
    scanf("%d", &n);

    switch(n)
    {
        case 1:
        printf("Enter the id of the customer: \n");
        scanf("%d", &id);
        printf("Enter the age of the customer: \n");
        scanf("%d", &age);

        root = insert(root, age, id);
        break;

        case 2: inorder(root);
        break;

        case 3: head= BTToDLL(root);
                printList(head);
                break;
        case 4: exit(0);
        break;

        default: printf("Please enter a valid choice\n");
    }
}while(n!=4);
}
