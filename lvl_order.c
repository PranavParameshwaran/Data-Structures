#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;  //accessory number
	struct node *lcptr;
	struct node *rcptr;
};

struct node *rptr=NULL;

void insert();
void delete();
void print();
void max();
void min();
void printtopo(struct node *ptr);

void main()
{
	int opt;
	
	printf("Welcome to LIBRARY");
	while(1)
	{	
	printf("\n");
	printf("ENTER ONE OF THE OPTIONS\n");
	printf("1.Insert \n2.Delete using Title \n3.find max\n4. print\n5. find min\n6.exit\n7. print topo\nenter your option : ");
	scanf("%d",&opt);
	printf("\n");

	switch(opt)
	{
	case 1:insert();
       		break;
       
	case 2:	delete();
	   		break;
	   
	case 3:max();
	   		break;
	   
	case 4:print(rptr);
		   break;

	case 5:min();
			break;
	   
	case 6:exit(1);
		   	break;

	case 7:printtopo(rptr);
			break;	   	

default:printf("enter correct option !!!\n");
	}
	
	}	
}
//Insert FUNCTION STARTS
void insert()
{
	struct node *tmp=malloc(sizeof(struct node));
	struct node *ptr=rptr;
	struct node *pptr=NULL;
	printf("Enter the number:");
	scanf("%d",&tmp->data);

	tmp->lcptr=NULL;
	tmp->rcptr=NULL;
	if(rptr==NULL)
	{	
		rptr=tmp;
	}
	else
	{
	
	while(ptr!=NULL)
	{
		pptr=ptr;
		if(tmp->data<ptr->data)
		ptr=ptr->lcptr;
		else
		ptr=ptr->rcptr;
	}
	
	if(tmp->data<pptr->data)
	pptr->lcptr=tmp;
	else
	pptr->rcptr=tmp;
	}
}
//Insert FUNCTION ENDS

//Print FUNCTION STARTS
void print(struct node *ptr)
{
	if(ptr!=NULL)
	{
		print(ptr->lcptr);
		printf("ACC   : %d\t",ptr->data);
		printf("_____________________\n");
		print(ptr->rcptr);
	}
}
//Print FUNCTION ENDS

//Delete FUNCTION STARTS
void delete()
{
	 struct node *ptmp=NULL;
	struct node *ptr=rptr;
	struct node *pptr=NULL;
	int t;
	printf("Enter the number to be deleted\n");
			scanf("%d",&t);
	while(ptr!=NULL && t!=ptr->data)
	{
		pptr=ptr;		
		if(t<ptr->data)
			ptr=ptr->lcptr;	
		else 
			ptr=ptr->rcptr;
	}	
	
	if(ptr==NULL)
	{
		printf("\n Deletion Fails");
	}
	
	
	else if(rptr->lcptr==NULL && rptr->rcptr==NULL)
	{		
		printf("number deleted   : %d\n",ptr->data);
		rptr=NULL;	
	}
	
	else if(ptr->lcptr==NULL && ptr->rcptr==NULL)
	{
		printf("number deleted   : %d\n",ptr->data);
		
		if(t<pptr->data)
			pptr->lcptr=NULL;
		else
			pptr->rcptr=NULL;
	}
	else if(ptr->lcptr==NULL && ptr->rcptr!=NULL || ptr->lcptr!=NULL && ptr->rcptr==NULL)
	{
		printf("number deleted is   : %d\n",ptr->data);		
		if(ptr==rptr)
		{
		 if(ptr->lcptr!=NULL)
		 rptr=ptr->lcptr;
		
		 else 
		rptr=ptr->rcptr;
		

		}
		else
		{
		if(t<pptr->data && ptr->lcptr!=NULL)
			pptr->lcptr=ptr->lcptr;		
		else if(t<pptr->data && ptr->lcptr==NULL)
			pptr->lcptr=ptr->rcptr;
		else if(t>=pptr->data && ptr->lcptr!=NULL)
			pptr->rcptr=ptr->lcptr;
		else
			pptr->rcptr=ptr->rcptr;
		}
	}
	
	else
	{		
		struct node *tmp=ptr;
      	ptmp=tmp;		
		tmp=tmp->rcptr;

      	printf("number deleted   : %d\n",ptr->data);
		while(tmp->lcptr!=NULL)
		{
         	ptmp=tmp;
			tmp=tmp->lcptr;
		}
				
		ptr->data=tmp->data;
  
       if(t<pptr->data)
			{
			tmp->lcptr=ptr->lcptr;
			pptr->lcptr=tmp;
			
			}
		else
			{tmp->lcptr=ptr->lcptr;
			pptr->rcptr=tmp;
			}

	}
	
}
//Delete FUNCTION ENDS

//Search FUNCTION STARTS
/*
void search()
{
	char s[30];
	printf("Enter the title of the book you want to enter\n");
	scanf("%s",s);
	struct node *ptr=rptr;
	while(ptr!=NULL && strcmp(s,ptr->title)!=0)
	{		
		if(strcmp(s,ptr->title)<0)
			ptr=ptr->lcptr;	
		else 
			ptr=ptr->rcptr;
	}	
	
	if(ptr==NULL)
	{
		printf("\n Search Fails");
	}
	else
	{
	printf("The Acc Number of the book searched is %d and the title of the book is %s by the author %s\n",ptr->acc,ptr->title,ptr->name);
	}
}
*/
void max()
{
	struct node *tmp=rptr;
	struct node *ptmp=NULL;

	while(tmp->rcptr!=NULL)
		{
			ptmp=tmp;
			tmp=tmp->rcptr;
		}
		if(rptr->rcptr==NULL)
			printf("the max value in BST IS %d\n",tmp->data);
		else
		printf("the max value in BST IS %d\n",tmp->data);

}

void min()
{
	struct node *tmp=rptr;
	struct node *ptmp=NULL;

	while(tmp->lcptr!=NULL)
		{
			ptmp=tmp;
			tmp=tmp->lcptr;
		}
		if(rptr->lcptr==NULL)
			printf("the max value in BST IS %d\n",tmp->data);
		else
		printf("the max value in BST IS %d\n",tmp->data);

}

void printtopo(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("ACC   : %d\t",ptr->data);
		printf("_____________________\n");
		printtopo(ptr->lcptr);
		printtopo(ptr->rcptr);
	}
}



