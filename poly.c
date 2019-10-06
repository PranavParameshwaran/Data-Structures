#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node
{
	int coef;
	int powe;
	struct node *nptr;
};

struct node *hptr=NULL;
void insert(int c,int p);
void compute(int x);
void print();

void main()
{
	int op=1;
	int ca,p,x;

	printf("Enter polynomial coefficients and its power\n");
	while(op)
	{	printf("Coefficient:");
		scanf("%d",&ca);
		printf("power:");
		scanf("%d",&p);
		insert(ca,p);
		printf("\nDo you Want to Enter more terms??? (0 to stop)\n");
		scanf("%d",&op);
		if(op==0)
			break;

	}

print();

printf("\nEnter the value of x\n");
scanf("%d",&x);
compute(x);

}


void insert(int c,int p)
{
	struct node *tmp=malloc(sizeof(struct node));
	tmp->coef=c;
	tmp->powe=p;
	tmp->nptr=hptr;
		hptr=tmp;
	
}

void compute(int x)
{
	int sum=0;
	struct node *thptr=hptr;
	while(thptr!=NULL)
	{
		sum+=(thptr->coef)*pow(x,(thptr->powe));
		thptr=thptr->nptr;

	}

	printf("Answer after computation is : %d\n",sum);
}

void print()
{
	printf("The Inputted Expression is\n");
	struct node *thptr=hptr;
	while(thptr!=NULL)
	{
		printf("%dx^%d",thptr->coef,thptr->powe);
		thptr=thptr->nptr;
		if(thptr!=NULL)
			printf("+ ");
	}
}