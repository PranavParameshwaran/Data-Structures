#include<stdio.h>

struct stack
{
	int a[100];
	int top;
};

struct stack s1,s2,s3;


int m=0;

void push(struct stack *s,int x);
void F(int x,struct stack *a,struct stack *b,struct stack *c);
void pop13(struct stack *sa,struct stack *sc);

void main()
{
	s1.top=-1;
	s2.top=-1;
	s3.top=-1;
	int n,cp;
	printf("Enter the number of rings\n");
	scanf("%d",&n);
	cp=n;
	while(cp>0)
	{
		push(&s1,cp);
		cp--;
		m++;

	}

	F(n,&s1,&s2,&s3);
	for(int i=0;i<n;i++)
	printf("---%d---\n",s3.a[i] );


}


void push(struct stack *s,int x)
{
	s->top++;
	s->a[m]=x;


}

void F(int x,struct stack *a,struct stack *b,struct stack *c)
{
	if(x!=1)
	{
		//printf("1 to 3\n");
		F(x-1,a,b,c);
		//printf("3 to 2\n");
		F(x-1,b,c,a);
		pop13(&s1,&s3);
		//printf("2 to 3\n");
		F(x-1,b,a,c);
	}

	else pop13(&s1,&s3);
}

void pop13(struct stack *sa,struct stack *sc)
{
	sc->top++;
	sc->a[sc->top]=sa->a[sa->top];
	sa->top--;
	printf("@   %d  @\n",sc->a[sc->top] );

}