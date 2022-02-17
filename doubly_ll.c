//By: Vandit Prajapati
//Doubly Linked List

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *rptr;
	int data;
	struct node *lptr;
};

struct node *first=NULL,*new_node,*last;

void dou_ins()
{
	int ele;
	printf("Enter the element to be inserted: ");
	scanf("%d",&ele);
	if(first==NULL)
	{
		first=(struct node *)malloc(sizeof(struct node));
		first->data=ele;
		first->rptr=first->lptr=NULL;
		last=first;
	}
	else
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=ele;
		new_node->rptr=last->rptr;
		new_node->lptr=last;
		last->rptr=new_node;
		last=new_node;
	}
}

void dou_delete()
{
	int ele;
	printf("Enter the element to be deleted: ");
	scanf("%d",&ele);
	if(first==NULL)
	{
		printf("Linked List is empty");
	}
	struct node *p=first;
	while(p!=NULL)
	{
		if(p->data==ele)
		{
			first=first->rptr;
			first->lptr=NULL;
			return;
		}
		else
		{
			if(p->rptr!=NULL)
			{
				p->rptr->lptr=p->lptr;
			}
			p->lptr->rptr=p->rptr;
			return;
		}
		p=p->rptr;
	}
}


void display(struct node *p)
{
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->rptr;
	}
}

int main()
{
	int op,c=1;
	while(c==1)
	{
		printf("Enter operation to perform \n1.Insertion\n2.Deletion\n3.Display");
		scanf("%d",&op);
		if(op==1)
		{
			dou_ins();
		}
		else if(op==2)
		{
			dou_delete();
		}
		else if(op==3)
		{
			display(first);
		}
		printf("Do you want to continue: ");
		scanf("%d",&c);
	}
}

	
	

					




		
