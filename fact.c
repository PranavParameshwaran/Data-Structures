#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *nptr;
};

struct node *top=NULL;


void push(int x);
void pop();

void main()
{
	int n;
	printf("ENTER VALUE OF n\n");
	scanf("%d",&n);
	while(n>=1)
	{
		push(n);
		n--;
	}
pop();
	
}

void push(int x)
{	
	struct node *tmp=malloc(sizeof(struct node));
	if(malloc(sizeof(struct node))!=NULL)
	{
		tmp->data=x;
		tmp->nptr=top;
		top=tmp;
	}
	
	else printf("CANNOT ADD MORE NODES!!!\n");
}

void pop()
{
	int x1,x2,pro;
	
	
	while(top!=NULL)
	{
		x1=top->data;
		x2=(top->nptr)->data;
		if((top->nptr)->nptr!=NULL)
		{top=(top->nptr)->nptr;
		pro=x1*x2;
		push(pro);
		}
		else
		{pro=x1*x2;
		printf("Factorial is:%d\n",pro);
		break;
		}
		
	}
	
	
}


/*
void fact()
{
	struct node *thptr=top;
	float prod=1.0;
	
		prod*=thptr->data;
		thptr=thptr->nptr;
	}
	
printf("The Factorial is %.0f\n",prod);
}
*/	
