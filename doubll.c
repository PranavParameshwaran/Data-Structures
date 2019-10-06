#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char fname[30];
	struct node *nptr;
	struct node *pptr;
};

struct node *hptr=NULL;
struct node *play;

void insert();
void delete(char s[]);
void next();
void prev();
void playc();

void main()
{
	int opt;
	char s[30];
	printf("Welcome to songs <PLAYLIST>");
	while(1)
	{	
	printf("\n");
	printf("ENTER ONE OF THE OPTIONS\n");
	printf("1.Insert \n2.Delete \n3.previous song\n4.next song\n5. play the current song\n6.exit\nenter your option : ");
	scanf("%d",&opt);
	printf("\n");

	switch(opt)
	{
	case 1:insert();
       		break;
       
	case 2:printf("Enter the name of the audio file to be deleted\n");
			scanf("%s",s);
			delete(s);
	   		break;
	   
	case 3:prev();
	   		break;
	   
	case 4:next();
		   break;
	   
	case 5:playc();
		   break;
	   
	case 6:exit(1);
		   	break;

default:printf("enter correct option !!!\n");
}

}	
}

void insert()
{
	struct node *tmp=malloc(sizeof(struct node));
	struct node *thptr=hptr;
	printf("Enter the audio file name\n");
	scanf("%s",tmp->fname);
	
	if(hptr==NULL)
	{
		hptr=tmp;
		tmp->nptr=NULL;
		tmp->pptr=NULL;
		play=hptr;
	}
	
	else
	{
		while(thptr->nptr!=NULL)
		{
			thptr=thptr->nptr;
			
		}
		tmp->nptr=NULL;
		tmp->pptr=thptr;
		thptr->nptr=tmp;
	}
}

void delete(char s[])
{
	struct node *thptr=hptr;
	if(hptr==NULL)
	printf("Can't Delete Audio File Because Playlist is Empty\n");
	
	else
	{
		while(strcmp(thptr->fname,s)!=0 && thptr!=NULL)
		{
			if(thptr->nptr==NULL)
			break;
			
			thptr=thptr->nptr;
			
		}
		if(thptr==NULL)
		printf("no audio file with entered name\n");
		else
		{
			
			printf("%s is deleted\n",thptr->fname);
			if(play==thptr && play->nptr!=NULL)
			play=play->nptr;
			else if(play==thptr && play->pptr!=NULL)
			play=play->pptr;
			else if(play==thptr)
			play=NULL;
		
		if(thptr->nptr==NULL)
		{
			if(thptr->pptr==NULL)
			hptr=NULL;
			else
			(thptr->pptr)->nptr=NULL;
		}
		
		else if(thptr->pptr==NULL)
		{
			(thptr->nptr)->pptr=NULL;
			hptr=thptr->nptr;
		}
		
		else{			
			thptr=thptr->pptr;
			thptr->nptr=(thptr->nptr)->nptr;
			(thptr->nptr)->pptr=thptr;
			}
		}
	}
}

void prev()
{
	if(play->pptr==NULL)
	printf("Can't play previos song coz playlist is empty\n");
	
	else{
	play=play->pptr;
	printf("PLAYING(prev) -----> %s\n",play->fname);
	}
}

void next()
{
	if(play->nptr==NULL)
	printf("Can't play next song coz playlist is empty\n");
	
	else{
	play=play->nptr;
	printf("PLAYING(next) -----> %s\n",play->fname);	
	}
}

void playc()
{
	if(play==NULL)
	printf("Can't play current song coz playlist is empty\n");
	
	else{	
	printf("PLAYING(curr) -----> %s\n",play->fname);
	}
}

	
	
