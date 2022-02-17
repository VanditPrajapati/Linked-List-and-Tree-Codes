//By: Vandit Prajapati
//Tree Traversal
#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *lptr;
	char info;
	struct node *rptr;
};

//Function of preorder traversal
void preorder(struct node *t)
{
	if(t==NULL)
	{
		printf("Empty");
	}
	else
	{
		printf("%c ",t->info);
		if(t->lptr!=NULL)
		{
			preorder(t->lptr);
		}
		if(t->rptr!=NULL)
		{
			preorder(t->rptr);
		}
	}
}

//Function of inorder traversal
void inorder(struct node *t)
{
	if(t==NULL)
	{
		printf("Empty");
	}
	else
	{
		if(t->lptr!=NULL)
		{
			preorder(t->lptr);
		}
		printf("%c ",t->info);
		if(t->rptr!=NULL)
		{
			preorder(t->rptr);
		}
	}
}

//Function of postorder traversal
void postorder(struct node *t)
{
	if(t==NULL)
	{
		printf("Empty");
	}
	else
	{
		if(t->lptr!=NULL)
		{
			postorder(t->lptr);
		}
		if(t->rptr!=NULL)
		{
			postorder(t->rptr);
		}
		printf("%c ",t->info);
	}
}
				
	
int main()
{
	struct node *a,*b,*c,*d,*e,*f,*g,*t;
	//Adding nodes into linked list
	a=(struct node *)malloc(sizeof(struct node));
	b=(struct node *)malloc(sizeof(struct node));
	c=(struct node *)malloc(sizeof(struct node));
	d=(struct node *)malloc(sizeof(struct node));
	e=(struct node *)malloc(sizeof(struct node));
	f=(struct node *)malloc(sizeof(struct node));	

	//Constructing binary tree
	a->info='A';
	a->rptr=d;
	a->lptr=b;
	
	b->info='B';
	b->rptr=NULL;
	b->lptr=c;
		
	c->info='C';
	c->rptr=NULL;
	c->lptr=NULL;

	d->info='D';
	d->rptr=g;
	d->lptr=e;

	e->info='E';
	e->rptr=f;
	e->lptr=NULL;

	f->info='F';
	f->rptr=NULL;
	f->lptr=NULL;
	
	g->info='G';
	g->rptr=NULL;
	g->lptr=NULL;

	t=a;
	printf("Preorder:\n");
	preorder(t);
	printf("\n");
	t=a;
	printf("Inorder:\n");
	inorder(t);
	printf("\n");
	t=a;
	printf("Postorder:\n");
	postorder(t);
	printf("\n");
}	
