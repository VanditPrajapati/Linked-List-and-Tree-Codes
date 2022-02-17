//By: Vandit Prajapati
//Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *l;
	int data;
	struct node *r;
};

struct node *new_node;

void preorder(struct node *t)
{
	if(t==NULL)
	{
		printf("Empty");
	}
	else
	{
		printf("%d ",t->data);
		if(t->l!=NULL)
		{
			preorder(t->l);
		}
		if(t->r!=NULL)
		{
			preorder(t->r);
		}
	}
}

void inorder(struct node *t)
{
	if(t==NULL)
	{
		printf("Empty");
	}
	else
	{
		if(t->l!=NULL)
		{
			preorder(t->l);
		}
		printf("%d ",t->data);
		if(t->r!=NULL)
		{
			preorder(t->r);
		}
	}
}

void postorder(struct node *t)
{
	if(t==NULL)
	{
		printf("Empty");
	}
	else
	{
		if(t->l!=NULL)
		{
			preorder(t->l);
		}
		if(t->r!=NULL)
		{
			preorder(t->r);
		}
		printf("%d ",t->data);
	}
}

//Function for inserting element in linked list
void insert(struct node *t,int n)
{	
	//If data is greater than given node data 
	if(n>t->data && t->r!=NULL)
	{
		insert(t->r,n);
	}	
	//If data is greater than given node data and no node exisiting on right
	else if(n>t->data && t->r==NULL)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=n;
		new_node->r=NULL;
		new_node->l=NULL;
		t->r=new_node;
	} 
	//If data is smaller than given node data
	else if(n<t->data && t->l!=NULL)
	{
		insert(t->l,n);
	}
	//If data is greater than given node data and no node exisiting on left
	else if(n<t->data && t->l==NULL)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=n;
		new_node->r=NULL;
		new_node->l=NULL;
		t->l=new_node;
	}		
}


int main()
{
	struct node *first,*last,*t;
	int c=1,n,op;
	printf("Enter the number: ");
	scanf("%d",&n);
	first=(struct node *)malloc(sizeof(struct node));
	first->data=n;
	first->l=NULL;
	first->r=NULL;
	//Loop for entering elements in Binary Search Tree
	while(c==1)
	{
		printf("Enter the number: ");
		scanf("%d",&n);
		t=first;
		insert(t,n);
		printf("Do you want to continue: ");
		scanf("%d",&c);
	}
	printf("Which traversal to perform:\n1.Preorder Traversal\n2.Postorder Traversal\n3.Inorder Traversal\n");
	scanf("%d",&op);
	if(op==1)
	{
		t=first;
		printf("Preorder Traversal of BTS: ");
		preorder(t);
	}
	else if(op==2)
	{
		printf("\n");
		t=first;
		printf("Postorder Traversal of BTS: ");
		postorder(t);
	}
	else if(op==3)
	{
		printf("\n");
		t=first;
		printf("Inorder Traversal of BTS: ");
		inorder(t);
	}
	printf("\n");
}
		
