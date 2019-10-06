#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stacks1
{
	char ma[100];
	int top;
};


void pushi(struct stacks1 *pl,char x);
int prec(char a);
int popi(struct stacks1 *pl);
void inpos(char a[],int n);

void print(struct stacks1 l);
//MAIN()
void main()
{
	int siz;
	char a[100];
	printf("--------------------Infix Evaluation--------------------\n");
	printf("Enter the Infix Expression\n");
	scanf("%s",a);
    siz=strlen(a);
    inpos(a,siz);
    

}

void inpos(char a[],int n)
{
    struct stacks1 s1;
    char dis[n],dummy;
    int f=0;
    int comp,comp1;
    s1.top=-1;
    for(int i=0;i<n; i++)
    {   
        if(48<=a[i] && a[i]<=57)
        {   
            dis[f]=a[i];
            f++;
        }
        
        else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')
			{
					
				if(s1.top==-1)
				pushi(&s1,a[i]);
				
				else{
					
					if(prec(s1.ma[s1.top])<prec(a[i]))
					 pushi(&s1,a[i]);
					
					else
					{
						while(1)
						{
						
							dis[f]=(char)popi(&s1);
							f++;
							if(prec(a[i])>prec(s1.ma[s1.top]))
							break;
						} 
						pushi(&s1,a[i]);
					}
					
					}
					
			}
			
			else if(a[i]=='(')
			pushi(&s1,a[i]);
			
			else if(a[i]==')')	
				{
					for(int j=s1.top;;j--)
						{
							if(s1.ma[j]!='(')
							{dis[f]=(char)popi(&s1);
							f++;
							}
							else if(s1.ma[j]=='(')
							{dummy=(char)popi(&s1);
							break;}
						}
				}

			else printf("CANT BE DONE!!!\n");
			
			
				
		}
		
		
		if(s1.top!=-1)
		{for(int j=s1.top;j>=0;j--)
		{dis[f]=(char)popi(&s1);
		f++;
	    }
	    }
	
		for(int j=0;j<n;j++)
		{
		printf("%c",dis[j]);
		}
		printf("\n\n\n");

}

void pushi(struct stacks1 *pl,char x)
{
	if(pl->top==99)
	{	
		printf("ERROR: STACK IS FULL!!!\n");
	}
	
	else
	{
		pl->top++;
		pl->ma[pl->top]=x;
	}
	
}



void print(struct stacks1 l)
{
    for(int i=0;i<=l.top;i++)
    {printf("%d  ",l.ma[i]);}
    printf("\n_______________________\n");	
}

int prec(char a)
{
	if(a=='+' || a=='-')
	return 1;
	else if(a=='*' || a=='/')
	return 2;
	else return(-404);
	
}

int popi(struct stacks1 *pl)
{
	if(pl->top==-1)
	{	
		printf("ERROR: STACK IS EMPTY!!!\n");
		return(404);
	}
	
	else
	{
		return(pl->ma[pl->top--]);
		
	}
	
}

	
