#include<stdio.h>
#include<stdlib.h>

struct node
{
	int aadhaar;
	int phone;
	int height;
	struct node *lcptr;
	struct node *rcptr;
};

struct node *rptr=NULL;

struct node *insert(struct node *ptr,int x,int y);
int findheight(struct node *ptr);
void updateheight(struct node *ptr);
struct node *rotateRight(struct node *ptr);
struct node *rotateLeft(struct node *ptr);
struct node *rotateLeftRight(struct node *ptr);
struct node *rotateRightLeft(struct node *ptr);
void print(struct node *ptr);
void search();

void main()
{
	int opt;
	int x,y;
	
	printf("Welcome to Phone Directory");
	while(1)
	{	
	printf("\n");
	printf("ENTER ONE OF THE OPTIONS\n");
	printf("1.Insert and print\n2.exit\n3. search\nenter your option : ");
	scanf("%d",&opt);
	printf("\n");

	switch(opt)
	{
	case 1:printf("Enter the aadhaar number\n");
			scanf("%d",&x);
			printf("Enter the phone number\n");
			scanf("%d",&y);
			rptr=insert(rptr,x,y);
			print(rptr);
       		break;
 
	case 2:exit(1);
		   	break;
		   	
	case 3:search();
			break;
default:printf("enter correct option !!!\n");
	}
	
	}	
}


//INSERT STARTS
struct node *insert(struct node *ptr,int x,int y)
{	
	
	if(ptr==NULL)
	{
		ptr=malloc(sizeof(struct node));
		ptr->aadhaar=x;
		ptr->phone=y;
		ptr->lcptr=NULL;
		ptr->rcptr=NULL;
		ptr->height=0;
	}
		
		
	else
	{
		if(x<ptr->aadhaar)
		{
				ptr->lcptr=insert(ptr->lcptr,x,y);
				if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==2 || findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2)
				{
					if(x<ptr->lcptr->aadhaar)
						ptr=rotateRight(ptr);
					else
						ptr=rotateLeftRight(ptr);	
				}
		}
		else
		{
				ptr->rcptr=insert(ptr->rcptr,x,y);
				if((findheight(ptr->lcptr)-findheight(ptr->rcptr)==2) || (findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2))
				{
					if(x>ptr->rcptr->aadhaar)
						ptr=rotateLeft(ptr);
					else
						ptr=rotateRightLeft(ptr);	
				}
		}
		
	}

updateheight(ptr);
return ptr;
}
//INSERT ENDS

//FIND HEIGHT STARTS
int findheight(struct node *ptr)	
{
	int h1,h2;
	if(ptr==NULL)
	{
		return(-1);
	}
	else
	{
		h1=findheight(ptr->lcptr);
		h2=findheight(ptr->rcptr);
		if(h1 < h2)
		{	
			return(h2+1);
		}
		else
		{	
			return(h1+1);
		}
	}
}
//FIND HEIGHT STARTS

//UPDATE HEIGHT STARTS
void updateheight(struct node *ptr)
{
	int h1,h2;
	if(ptr->lcptr==NULL)
	{
		h1=-1;
	}
	else
		h1=ptr->lcptr->height;
	
	if(ptr->rcptr==NULL)
	{
		h2=-1;
	}
	else
		h2=ptr->rcptr->height;
	
	if(h1<h2)
		ptr->height=h2+1;
	else
		ptr->height=h1+1;
}
//UPDATE HEIGHT ENDS

//ROATATE RIGHT STARTS
struct node *rotateRight(struct node *ptr)
{
	struct node *jptr=ptr;
	struct node *kptr=ptr->lcptr;
	jptr->lcptr=kptr->rcptr;
	kptr->rcptr=jptr;
	updateheight(jptr);
	updateheight(kptr);
	return (kptr);
}
//ROATATE RIGHT ENDS

//ROATE LEFT STARTS
struct node *rotateLeft(struct node *ptr)
{
	struct node *jptr=ptr;
	struct node *kptr=ptr->rcptr;
	jptr->rcptr=kptr->lcptr;
	kptr->lcptr=jptr;
	updateheight(jptr);
	updateheight(kptr);
	return (kptr);
}
//ROATATE LEFT ENDS

//ROATATE LEFT-RIGHT STARTS
struct node *rotateLeftRight(struct node *ptr)
{
	struct node *jptr=ptr;
	struct node *kptr=ptr->lcptr;
	ptr->lcptr=rotateLeft(kptr);
	return(rotateRight(jptr));
}
//ROATATE LEFT-RIGHT STARTS

//ROATATE RIGHT-LEFT STARTS
struct node *rotateRightLeft(struct node *ptr)
{
	struct node *jptr=ptr;
	struct node *kptr=ptr->rcptr;
	ptr->rcptr=rotateRight(kptr);
	return(rotateLeft(jptr));
}
//ROATATE RIGHT-LEFT ENDS

void print(struct node *ptr)
{	
	if(ptr!=NULL)
	{
		print(ptr->lcptr);
		printf("Aadhar: %d\t",ptr->aadhaar);
		printf("Phone: %d\t",ptr->phone);
		printf("HEIGHT: %d\t",ptr->height);
		printf("BF: %d\n",findheight(ptr->lcptr)-findheight(ptr->rcptr));
		print(ptr->rcptr);
	}
}

void search()
{
	int t,flag=0;
	struct node *ptr=rptr;
	if(rptr==NULL)
	{
		printf("AVL tree is empty\n");
	}
	else
	{
		printf("enter the aadhaar number u want to search\n");
		scanf("%d",&t);
		while(ptr!=NULL)
		{
			if(t==ptr->aadhaar)
			{	printf("Aadhar: %d\t",ptr->aadhaar);
				printf("Phone: %d\t",ptr->phone);
				printf("HEIGHT: %d\t",ptr->height);
					printf("BF: %d\n",findheight(ptr->lcptr)-findheight(ptr->rcptr));
				flag=1;
				break;
			}
			else if(t<ptr->aadhaar)
				ptr=ptr->lcptr;
			else
				ptr=ptr->rcptr;
		}
		if(flag==0)
			printf("NOT AVAILAble\n");
		
	}
}

	
	
