//By: Vandit Prajapati
//Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *link;
	int data;
};

struct node *first=NULL,*last=NULL,*new_node; //Defining first and last pointers for traversing the circular linked list and new_node for creating a new node for inserting into linked list

//Function for inserting element at first
void cir_ins_first(int ele)
{
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=ele;
	if(first==NULL) //First node doesnt exit
	{
		new_node->link=new_node;
		first=new_node;
		last=new_node;
	}
	else //If first node exist
	{
		new_node->link=first;
		last->link=new_node;
		first=new_node;
	}
}

//Function for inserting element at last
void cir_ins_last(int ele)
{
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=ele;
	if(first==NULL)
	{
		new_node->link=new_node;
		first=new_node;
		last=new_node;
	}
	else
	{
		new_node->link=first;
		last->link=new_node;
		last=new_node;
	}
}

//Function for deleting an element from linked list
void cir_delete(int ele)
{
	struct node *save,*pred; // Declaring temporary nodes for traversing through linked list for deleting the element 
	if(first==NULL)
	{
		printf("Linked List is empty\n");
	}
	save=first; 
	while((save->data!=ele)) //Traversing linked list till the element is found
	{
		pred=save; 
		save=save->link;
	}
	if(save->data!=ele) //If element not found in linked list
	{
		printf("Element not found in Linked list\n");
		return;
	}
	if(save==first) //For deleting the first element
	{
		first=first->link;
		last->link=first;
	}
	else
	{
		pred->link=save->link;
		if(save==last)
		{
			last=pred;
		}
	}
}

//Function for deleting the element from circular linked list
void display()
{
	struct node *t=first;
	while(t->link!=first)
	{
		printf("%d\t",t->data);
		t=t->link;
	}
	printf("%d",t->data);
}

int main()
{
	int op,ele,c=1;
	while(c==1)
	{
		printf("Enter the operation to perform:\n1.Insert First\n2.Insert Last\n3.Delete\n4.Display\n");
		scanf("%d",&op);
		if(op==1)
		{
			printf("Enter the element to add: ");
			scanf("%d",&ele);
			cir_ins_first(ele);
		}
		else if(op==2)
		{
			printf("Enter the element to add: ");
			scanf("%d",&ele);
			cir_ins_last(ele);
		}
		else if(op==3)
		{
			printf("Enter the element to be deleted: ");
			scanf("%d",&ele);
			cir_delete(ele);
		}
		else if(op==4)
		{
			display();
			printf("\n");
		}
		printf("Do you want to continue: ");
		scanf("%d",&c);
		printf("\n");
	}
}

