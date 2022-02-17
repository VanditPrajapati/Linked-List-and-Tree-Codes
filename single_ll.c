//By: Vandit Prajapati
//Single Linked list 6 Operations

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node * link;
};
struct node *first,*new_node,*l,*p,*t,*d; //Declaring global structure node pointers

struct node *first1; //Declaring linked list 2 first pointer

// Inserting in linked list at first
void insert_first()
{
	int ele;
	if(first==NULL) 
	{
		first=(struct node *)malloc(sizeof(struct node));
		printf("Enter the element to be added: ");
		scanf("%d",&ele);
		first->info=ele;
		first->link=NULL;
		p=first;
		l=first;
	}
	else
	{
		first=(struct node *)malloc(sizeof(struct node));
		printf("Enter the element to be added: ");
		scanf("%d",&ele);
		first->info=ele;
		first->link=p;
		p=first;
	}
}

//Function for inserting in linked list at end
void insert_end()
{
	int ele;
	if(first==NULL)
	{
		printf("Underflow\n");
	}
	else
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		printf("Enter the element to be added: ");
		scanf("%d",&ele);
		new_node->info=ele;
		new_node->link=NULL;
		l->link=new_node;
		l=new_node;
	}
}

// Inserting element at a particular position in linked list
void insert_pos()
{
	int pos,ele;
	printf("Enter the position of the element to be added: ");
	scanf("%d",&pos);
	t=first;
	for(int i=0;i<pos-1;i++) // For loop to reach the desired position
	{
		t=t->link;
	}
	if(t)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		printf("Enter the element to be added: ");
		scanf("%d",&ele);
		new_node->info=ele;
		new_node->link=t->link;
		t->link=new_node;
	}
}

// Deleting element from linked list 
void delete()
{
	int pos,ele;
	printf("Enter the position of the element to be added: ");
	scanf("%d",&pos);
	d=first;
	if(pos==0) // Deleting front element
	{
		ele=first->info;
		first=first->link;
		printf("Element %d is deleted\n",ele);
	}
	else // Deleting element from a specific position
	{
		for(int i=0;i<pos;i++)
		{
			t=d;
			d=d->link;
		}
		t->link=d->link;
		ele=d->info;
		printf("Element %d is deleted\n",ele);
	}		
}

// Creating a new linked list and copying the elements of old linked list into new
void copy_ll()
{
	if(first==NULL)
	{
		printf("Linked List 1 not exist\n");
	}
	else
	{
		first1=(struct node *)malloc(sizeof(struct node));
		new_node=(struct node *)malloc(sizeof(struct node));
		first1->info=first->info;
		first1->link=NULL;
		d=first1;
		t=first->link;
		while(t!=NULL)
		{
			new_node=(struct node *)malloc(sizeof(struct node));
			new_node->info=t->info;
			new_node->link=NULL;
			d->link=new_node;
			d=new_node;
			t=t->link;
		}
		printf("Linked List 2:\n");
		while(first1!=NULL)
		{
			printf("%d\t",first1->info);
			first1=first1->link;
		}
		printf("\n");
	}
}

// Counting the no. of elements in linked list
void count_ll()
{
	int count=0;
	t=first;
	if(first==NULL)
	{
		printf("Count: %d\n",count); 
	}
	else
	{
		while(t!=NULL)
		{
			t=t->link;
			count++;
		}
		printf("Count: %d\n",count);
	}
}

int main()
{
	int op,c=1;
	while(c==1)
	{
		printf("\nEnter the operation to be performed:\n1.Insert at first\n2.Insert at end\n3.Insert at a position\n4.Delete element\n5.Copy linked list\n6.Count elements\n");
		scanf("%d",&op);
		if(op==1)
		{
			insert_first();
		}
		else if(op==2)
		{
			insert_end();
		}
		else if(op==3)
		{
			insert_pos();
		}
		else if(op==4)
		{
			delete();
		}
		else if(op==5)
		{
			copy_ll();
		}
		else if(op==6)
		{
			count_ll();
		}
		d=first;
		printf("\nLinked List:\n");
		while(d!=NULL)
		{
			printf("%d\t",d->info);
			d=d->link;
		}
		printf("\nDo you want to continue[1(yes)/0(no)]:  ");
		scanf("%d",&c);
	}
	d=first;
	printf("\nLinked List:\n");
	while(d!=NULL)
	{
		printf("%d\t",d->info);
		d=d->link;
	}
	printf("\n");
}
	

 
