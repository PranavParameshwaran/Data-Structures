#include<stdio.h>
#include<stdlib.h>
struct stacks
{
	int m[100];
	int top;
};

int PostEval(char a[],int n);
void push(struct stacks *pl,int x);
int pop(struct stacks *pl);
//MAIN()
void main()
{
	struct stacks kip;
	int count=0,ans;
	char a[100];
	printf("--------------------PostFix Evaluation--------------------\n");
	printf("Enter the PostFix Expression [Enter @ to Stop]\n");
	scanf("%s",a);

	ans=PostEval(a,sizeof(a));
	printf("The Answer is %d\n",ans );

}

int PostEval(char a[],int n)
{
	struct stacks s;
	int opnd1,opnd2,new,val;
	s.top=-1;

	for(int i=0; i<n; i++)
		{
			if(48<=a[i]<=57)
				{push(&s,a[i]);
				}

			else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')
			{
				opnd2 = pop(&s);
				opnd1 = pop(&s);

				switch(a[i])
				{
					
					case '+': new = opnd1+opnd2;
								break;
					case '-': new = opnd1-opnd2;
								break;
					case '*': new = opnd1*opnd2;
								break;
					case '/': new = opnd1/opnd2;
								break;

				}

				push(&s,new);
			}

			else {printf("ERROR\n");
					break;
				}

		}

		val=pop(&s);
		if(s.top==-1)
			return(val);

		else return(-666);

}

void push(struct stacks *pl,char x)
{
	if(pl->top==99)
	{	
		printf("ERROR: STACK IS FULL!!!\n");
	}
	
	else
	{
		pl->top++;
		pl->m[pl->top]=x;
	}
	
}


int pop(struct stacks *pl)
{
	if(pl->top==-1)
	{	
		printf("ERROR: STACK IS EMPTY!!!\n");
		return(-666);
	}
	
	else
	{
		return(pl->m[pl->top]);
		pl->top--;
	}
	
}