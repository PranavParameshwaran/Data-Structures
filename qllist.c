#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *nptr;
};

struct node *fptr=NULL;
struct node *rptr=NULL;

void enqueue(int x);
int dequeue();
void print();
void isempty();
void isfull();

void main()
{
	int x,opt;
	while(1)
	{
		printf("\n");
		printf("ENTER ONE OF THE OPTIONS\n");
		printf("1.ENQUEUE \n2.DEQUEUE	 \n3.print\n4.isempty\n5.isfull\n6.exit\nenter your option : ");
		scanf("%d",&opt);
		printf("\n");

	switch(opt)
	{
		case 1:printf("ENTER DATA :");
				scanf("%d",&x);
				enqueue(x);
       			break;
       
		case 2:printf("The VALUE DEQUEUED IS %d\n",dequeue());
	   			break;
	   
		case 3:print();
	   			break;
	   
		case 4:isempty();
	   			break;
	   
		case 5:isfull();
				break;
	  
	   	
		case 6:exit(1);break;
		
		default:printf("enter correct option !!!\n");
	}

	}

}

void enqueue(int x)
{
	struct node *tmp=malloc(sizeof(struct node));
	if(malloc(sizeof(struct node))!=NULL)
	{
		if(fptr==NULL)	
		{	
			tmp->data=x;
			tmp->nptr=rptr;
			fptr=tmp;
			rptr=tmp;
		}
		
		else
		{	
			tmp->data=x;
			tmp->nptr=rptr->nptr;
			rptr->nptr=tmp;
			rptr=tmp;
		}
	}
	
	else printf("CANNOT ADD MORE NODES!!!\n");
}
			
int dequeue()
{
	int x=-666;
	if(fptr!=NULL)
	{
		if(fptr==rptr)
		{
			x=fptr->data;
			fptr=NULL;
			rptr=NULL;
		}
		
		else
		{
			x=fptr->data;
			fptr=fptr->nptr;
		}
		
	}
	
	else printf("QUEUE IS EMPTY!!!\n");
	
	return(x);
	
}

void print()
{
	struct node *thptr=fptr;
	if(fptr==NULL)
	printf("NO ELEMENTS CANT PRINT!!!\n");
	
	else
	{
		while(thptr!=NULL)
		{
			printf("%d\t",thptr->data);
			thptr=thptr->nptr;
		}
		printf("\n");
	}
}

void isempty()
{
	if(fptr==NULL)
	printf("QUEUE IS EMPTY!!\n");
	
	else printf("QUEUE IS NOT EMPTY\n"); 		
}

void isfull()
{
	if(malloc(sizeof(struct node))==NULL)
	printf("QUEUE IS FULL!!\n");
	
	else printf("QUEUE IS NOT FULL\n"); 		
}	
	
