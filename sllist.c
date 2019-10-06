#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *nptr;
};

struct node *top=NULL;

void push(int x);
int pop();
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
		printf("1.PUSH \n2.POP \n3.print\n4.isempty\n5.isfull\n6.exit\nenter your option : ");
		scanf("%d",&opt);
		printf("\n");

	switch(opt)
	{
		case 1:printf("ENTER DATA :");
				scanf("%d",&x);
				push(x);
       			break;
       
		case 2:printf("The VALUE POPPED IS %d\n",pop());
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
			
int pop()
{
	int x=-666;
	if(top!=NULL)
	{
		x=top->data;
		top=top->nptr;
	}
	
	else printf("STACK IS EMPTY!!!\n");
	
	return(x);
	
}

void print()
{
	struct node *thptr=top;
	while(thptr!=NULL)
	{
		printf("%d\t",thptr->data);
		thptr=thptr->nptr;
	}
	printf("\n");
}

void isempty()
{
	if(top==NULL)
	printf("STACK IS EMPTY!!\n");
	
	else printf("STACK IS NOT EMPTY\n"); 		
}

void isfull()
{
	if(malloc(sizeof(struct node))==NULL)
	printf("STACK IS FULL!!\n");
	
	else printf("STACK IS NOT FULL\n"); 		
}	
	
