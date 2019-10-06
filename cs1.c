#include<stdio.h>
void main()
{
	/*int x=4;
	int *ptr;
	ptr= &x;
	printf("p:%p    x:%x      d:%d\n",ptr,ptr,*ptr);
	ptr++;
	printf("p:%p      %d\n",ptr,ptr);
	
	printf("%d\n",sizeof(ptr));
	
	char c='h';
	char *ctr;
	
	ctr=&c;
	*ctr='m';
	printf("p:%p      d:%d        c:%c     p:%p\n",ctr,*ctr,*ctr,&ctr);
	*/
	int a=5;
	int b=6;
	int *ptr1=&a;
	int *ptr2=&b;
	int c;
	c=(ptr1)*ptr2;
	printf("%d          %p",c,c);
	
	
	
	
	
	}
