#include<stdlib.h>

struct data
{
	int key;
	int value;
};

struct data *array;
int capacity = 10;
int size = 0;


int hashcode(int key)
{
	return (key % capacity);
}


int get_prime(int n)
{
	if (n % 2 == 0)
        {
		n++;
	}
	for (; !if_prime(n); n += 2);

	return n;
}


int if_prime(int n)
{
	int i;
	if ( n == 1  ||  n == 0)
        {
		return 0;
	}
	for (i = 2; i < n; i++)
        {
		if (n % i == 0)
                {
			return 0;
		}
	}
	return 1;
}

void init_array()
{
	int i;
	capacity = get_prime(capacity);
	array = (struct data*) malloc(capacity * sizeof(struct data));
	for (i = 0; i < capacity; i++)
        {
		array[i].key = 0;
		array[i].value = 0;
	}
}

void insert(int key)
{
	int index = hashcode(key);
	if (array[index].value == 0)
        {

		array[index].key = key;
		array[index].value = 1;
		size++;
		printf("\n book (%d) has been inserted \n", key);
	}
	else if(array[index].key == key)
        {

		printf("\n book (%d) already present, hence updating its value \n", key);
		array[index].value += 1;
	}
	else
        {

		printf("\n book CANNOT BE INSERTED \n");
	}
}

void remove_element(int key)
{
	int index  = hashcode(key);
	if(array[index].value == 0)
        {
		printf("\n This book does not exist \n");
	}
	else {
		array[index].key = 0;
		array[index].value = 0;
		size--;
		printf("\n book (%d) has been removed \n", key);
	}
}


void display()
{
	int i;
	for (i = 0; i < capacity; i++)
        {
		if (array[i].value == 0)
                {
			printf("\n [%d] has no books \n");
		}
		else
                {
			printf("\n [%d] has books -:\n BOOK(%d) and SI_NO(%d) \t", i, array[i].key, array[i].value);
		}
	}
}

int size_of_hashtable()
{
	return size;
}

void main()
{
	int choice, key, value, n, c;


	init_array();

	do {
		printf("\n LIBRARY MANAGEMENT SYSTEM USING HAST TABLE \n\n");
		printf("MENU-:  \n1.INSERT BOOK IN SHELF"
                        "\n2.REMOVE BOOK FROM SHELF "
		               "\n3.NUMBER OF BOOK THE SHELF"
                        "\n4."
                        "\n\n >ENTER YOUR CHOICE<-- -:");

		scanf("%d", &choice);

		switch(choice)
                {

		case 1:

		      printf("Inserting element in Hash Table\n");
		      printf("Enter key -:\t");
		      scanf("%d", &key);
		      insert(key);

		      break;

		case 2:

		      printf("Deleting in Hash Table \n Enter the key to delete-:");
		      scanf("%d", &key);
		      remove_element(key);

		      break;

		case 3:

		      n = size_of_hashtable();
		      printf("Size of Hash Table is-:%d\n", n);

		      break;

		case 4:

		      display();

		      break;

		default:

		       printf("Wrong Input\n");

		}

		printf("\n Do you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);

	}while(c == 1);

	getch();

}
