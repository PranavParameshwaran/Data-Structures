#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int acc;  //accessory number
	char name[20];
	char title[30];
	struct node *lcptr;
	struct node *rcptr;
};

struct node *rptr=NULL;

void insert();
void delete();
void search();
void print();

void main()
{
	int opt;
	
	printf("Welcome to LIBRARY");
	while(1)
	{	
	printf("\n");
	printf("ENTER ONE OF THE OPTIONS\n");
	printf("1.Insert \n2.Delete using Title \n3.Search for Book\n4. print\n5.exit\nenter your option : ");
	scanf("%d",&opt);
	printf("\n");

	switch(opt)
	{
	case 1:insert();
       		break;
       
	case 2:	delete();
	   		break;
	   
	case 3:search();
	   		break;
	   
	case 4:print(rptr);
		   break;
	   
	case 5:exit(1);
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
	printf("Enter the acc number of the book :");
	scanf("%d",&tmp->acc);
	printf("Enter the AUTHOR of the book :");
	scanf("%s",tmp->name);
	printf("Enter the TITLE of the book :");
	scanf("%s",tmp->title);

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
		if(strcmp(tmp->title,ptr->title)<0)
		ptr=ptr->lcptr;
		else
		ptr=ptr->rcptr;
	}
	
	if(strcmp(tmp->title,pptr->title)<0)
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
		printf("ACC   : %d\t",ptr->acc);
		printf("NAME  : %s\t",ptr->name);
		printf("TITLE : %s\n",ptr->title);
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
	char t[30];
	printf("Enter the title of book to be deleted\n");
			scanf("%s",t);
	while(ptr!=NULL && strcmp(t,ptr->title)!=0)
	{
		pptr=ptr;		
		if(strcmp(t,ptr->title)<0)
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
		printf("ACC   : %d\t",ptr->acc);
		printf("NAME  : %s\t",ptr->name);
		printf("TITLE : %s is deleted\n",ptr->title);
		rptr=NULL;	
	}
	
	else if(ptr->lcptr==NULL && ptr->rcptr==NULL)
	{
		printf("ACC   : %d\t",ptr->acc);
		printf("NAME  : %s\t",ptr->name);
		printf("TITLE : %s is deleted\n",ptr->title);
		
		if(strcmp(t,pptr->title)<0)
			pptr->lcptr=NULL;
		else
			pptr->rcptr=NULL;
	}
	else if(ptr->lcptr==NULL && ptr->rcptr!=NULL || ptr->lcptr!=NULL && ptr->rcptr==NULL)
	{
		printf("ACC   : %d\t",ptr->acc);
		printf("NAME  : %s\t",ptr->name);
		printf("TITLE : %s is deleted\n",ptr->title);
		
		if(ptr==rptr)
		{
		 if(ptr->lcptr!=NULL)
		 rptr=ptr->lcptr;
		
		 else 
		rptr=ptr->rcptr;
		

		}
		else
		{
		if(strcmp(t,pptr->title)<0 && ptr->lcptr!=NULL)
			pptr->lcptr=ptr->lcptr;		
		else if(strcmp(t,pptr->title)<0 && ptr->lcptr==NULL)
			pptr->lcptr=ptr->rcptr;
		else if(strcmp(t,pptr->title)>=0 && ptr->lcptr!=NULL)
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

      	printf("ACC   : %d\t",ptr->acc);
		printf("NAME  : %s\t",ptr->name);
		printf("TITLE : %s is deleted\n",ptr->title);
		
		
		
		while(tmp->lcptr!=NULL)
		{
         	ptmp=tmp;
			tmp=tmp->lcptr;
		}
				
		ptr->acc=tmp->acc;
		strcpy(ptr->name,tmp->name);
		strcpy(ptr->title,tmp->title);	
			

		
      
       if(strcmp(t,pptr->title)<0)
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

