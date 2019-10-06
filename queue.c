#include<stdio.h>
#include<stdlib.h>
struct Passenger
{
    int pnr;
    char name[20];
    int fare;
};

struct WLQueue
{
    struct Passenger w[100];
    int front;
    int rear;
};

struct Passenger n[100];

void enqueue(struct WLQueue *pl);
void dequeue(struct WLQueue *pl);
int isempty(struct WLQueue pl);
int isfull(struct WLQueue pl);
void print(struct WLQueue pl);
void Search(struct Passenger cp[],int pnrp);
void printco(struct Passenger cp[]);
int count=0,top=-1;


//MAIN()
void main()
{


struct WLQueue l;
l.front=-1;
l.rear=-1;

int opt,ie2,if2,pn;
while(1)
{
printf("\n");
printf("ENTER ONE OF THE OPTIONS\n");
printf("1.Enqueue \n2.Dequeue \n3.print\n4.isempty\n5.isfull\n6.Search Passenger in Confirmed List\n7.exit\n8. Print Confirm\nenter your option : ");
scanf("%d",&opt);
printf("\n");

switch(opt)
{
case 1:enqueue(&l);
       break;
       
case 2:dequeue(&l);
	   break;
	   

	   
case 3:print(l);
	   break;
	   
case 4:ie2=isempty(l);
		if(ie2==1)
		printf("Waiting List is Empty\n");
		
		else printf("Waiting List is not Empty\n");
	   break;
	   
case 5:if2=isfull(l);
		if(if2==1)
		printf("Waiting List is Full\n");
		
		else printf("Waiting List is not Full\n");
	   break;
	   
case 6:printf("Enter the PNR Of Passenger required\n");
		scanf("%d",&pn);
	   	Search(n,pn);
	   	break;
	   	
case 7:exit(1);break;

case 8:printco(n);
		break;

default:printf("enter correct option !!!\n");
}

}

}
//Enqueue()
void enqueue(struct WLQueue *pl)
{
	if(pl->rear==99)
	printf("ERROR: Waiting list Is Full!!!\n");
	
	else if(pl->front==-1 && pl->rear==-1)
	{
		count++;
		pl->front++;
		pl->rear++;
		pl->w[pl->rear].pnr=count;
		printf("Enter the NAME of the Passenger\n");
		scanf("%s",pl->w[pl->rear].name);
		printf("Enter the FARE of the Ticket\n");
		scanf("%d",&pl->w[pl->rear].fare);
	}
	
	else 
	{
		pl->rear++;
		count++;
		pl->w[pl->rear].pnr=count;
		printf("Enter the NAME of the Passenger\n");
		scanf("%s",pl->w[pl->rear].name);
		printf("Enter the FARE of the Ticket\n");
		scanf("%d",&pl->w[pl->rear].fare);
	}
}		

//Dequeue()
void dequeue(struct WLQueue *pl)
{
	if(pl->front==-1 && pl->rear==-1)
	printf("ERROR: Waiting list Is Empty!!!\n");
			
	else 
	{
		printf("The PNR of the Passenger whose Ticket is Confirmed is: %d\n",pl->w[pl->front].pnr);
		printf("The NAME of the Passenger whose Ticket is Confirmed is: %s\n",pl->w[pl->front].name);
		printf("The Fare of the Train whose Ticket is Confirmed is: %d\n",pl->w[pl->front].fare);
		
		top++;
		n[top]=pl->w[pl->front];
		
		
		
		if(pl->front==pl->rear)
		{
			pl->front=-1;
			pl->rear=-1;
		}
		else
			pl->front++;
	}
}		
		
int isempty(struct WLQueue pl)
{
	if((pl.front==-1 && pl.rear==-1))
	{
		return (1);	
	}	
	
	else return (0);
}

int isfull(struct WLQueue pl)
{
	if(pl.rear==99)
	{
		return (1);	
	}	
	
	else return (0);
}	
		
void print(struct WLQueue pl)
{
	for(int i=pl.front; i<=pl.rear; i++)
	{
		printf("\t%d\n",pl.w[i].pnr);
		printf("\t%s\n",pl.w[i].name);
		printf("\t%d",pl.w[i].fare);
		printf("\n__________________\n");
	}
}

void Search(struct Passenger cp[],int pnrp)
{
	for(int i=0;i<=top;i++)
	{
		if(pnrp==cp[i].pnr)
		{	
			printf("%d\n",cp[i].pnr);
			printf("%s\n",cp[i].name);
			printf("%d\n",cp[i].fare);
		    break;
		}
	}
}
		
void printco(struct Passenger cp[])
{
for(int i=0;i<=top;i++)
{
			printf("\n%d\n",cp[i].pnr);
			printf("%s\n",cp[i].name);
			printf("%d\n",cp[i].fare);
		
}
}		
		
