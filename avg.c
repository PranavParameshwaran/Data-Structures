#include<stdio.h>

int a[100];
float avg(int beg,int end)
{
	int mid;
	if(beg==end)
	{
		return(a[beg]);
	}

	else
	{
		mid=(beg+end)/2;
		float lval=avg(beg,mid);
		float rval=avg(mid+1,end);
		int c1=mid-beg+1;
		int c2=end-mid;
		float a=((lval*c1)+(rval*c2))/(c1+c2);
		return(a);
	}
}

void main()
{
	int n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	float aver=avg(0,n-1);
	printf("ANSWER %0.2f\n",aver);
}