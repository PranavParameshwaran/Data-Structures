#include<stdio.h>
#include<stdlib.h>
struct book
{
	int acc;
	char name[20];
	char title[30];
};

struct lib
{
	int top;
	struct book b[100];
};

void push(struct lib *pl);
void pop(struct lib *pl);
void search(struct lib pl);
int is_empty(struct lib pl);
int is_full(struct lib pl);
void print(struct lib pl);

void main()
{
	struct lib l;
	l.top=-1;
	int in,ie2,if2;
	printf("\t--------Welcome To Library!-------\n");
	printf("please choose from the options given below for entering books or searching for a book\n");
	
	do{
		printf("1. Insert  \n2. Remove  \n3. Search  \n4. is_empty  \n5. is_full  \n6. print  \n7. exit()\n");
		printf("Enter choice : ");
		scanf("%d",&in);
		
		switch(in)
		{
			case 1: push(&l);
					printf("\n\n");
					break;
			
			case 2: pop(&l);
					printf("\n\n");
					break;
		
			case 3: search(l);
					printf("\n\n");
					break;
		
			case 4:ie2=is_empty(l);
				   if(ie2==1)
				   printf("There are no Books in the Library [%d]\n",ie2);
				   
				   else printf("There are Books in the Library[%d]\n",ie2);
				   
				   printf("\n\n");
					break;
			
			case 5:if2=is_full(l);
				   if(if2==1)
				   printf("There is no place left to insert more books [%d]\n",if2);
				   
				   else printf("The Library is not full [%d]\n",if2);
				   
				   printf("\n\n");
					break;
			
			case 6: print(l);
			
					printf("\n\n");
					break;
					
			
					
			case 7: exit(1);	
					break;
			
			default:break;
			
						
		}	
	
	  }while(1);

	
	
}

void push(struct lib *pl)
{
	if(pl->top==99)
	{	
		printf("ERROR: STACK IS FULL!!! PLEASE REMOVE SOME BOOKS\n");
	}
	
	else
	{
		pl->top++;
		printf("Enter the ACCOUNT NUMBER for book %d\n",(pl->top)+1);
		scanf("%d",&(pl->b[pl->top].acc));
		printf("Enter the AUTHOR'S NAME for book %d\n",(pl->top)+1);
		scanf("%s",pl->b[pl->top].name);
		printf("Enter the TITLE for book %d\n",(pl->top)+1);
		scanf("%s",pl->b[pl->top].title);
	}
	
}


void pop(struct lib *pl)
{
	if(pl->top==-1)
	{	
		printf("ERROR: STACK IS EMPTY!!! PLEASE ADD SOME BOOKS\n");
	}
	
	else
	{
		
		printf("the ACCOUNT NUMBER for book removed is %d\n",(pl->b[pl->top].acc));
		printf("the AUTHOR'S NAME for book removed is %s\n",pl->b[pl->top].name);
		printf("the TITLE for book removed is %s\n",pl->b[pl->top].title);
		pl->top--;
	}
	
}

void search(struct lib pl)
{
	int x,temp=0;
	printf("Enter the account number of the book you want to SEARCH\n");
	scanf("%d",&x);
	printf("____________________\n");
	for(int i=0;i<=(pl.top);i++)
	{	
		if(x==pl.b[i].acc)
		{
			printf("%d\n",pl.b[i].acc);
			printf("%s\n",pl.b[i].name);
			printf("%s\n",pl.b[i].title);
			printf("____________________\n");
			temp=1;
			break;
		}
		
				
	}
	if(temp!=1)
		{printf("Given Input Is Wrong Please Re-enter\n");
		}
}

int is_empty(struct lib pl)
{
	if(pl.top==-1)
	return(1);
	
	else return(0);
}

int is_full(struct lib pl)
{
	if(pl.top==99)
	return(1);
	
	else return(0);
}

void print(struct lib pl)
{
	for(int i=0;i<=(pl.top);i++)
	{
		printf("\t%d\n",pl.b[i].acc);
		printf("\t%s\n",pl.b[i].name);
		printf("\t%s\n",pl.b[i].title);
		printf("_________________||\n");
	}
	
}	
	
	
	
	

