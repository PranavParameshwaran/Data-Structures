#include<stdio.h>
#include<stdlib.h>
void Bsort(int b[], int s);
void Isort(int b[], int s);
void Ssort(int b[], int s);
int c1=0,c2=0,c3=0;
void main()
{	int a,n;

	printf("Welcome to Sort");
	
	printf("\nEnter number of elements in a array\n");
	scanf("%d",&n);
	int ar[n],arc[n];
	
	printf("Enter elements\n");
	for(int i=0;i<n;i++)
	scanf("%d",&ar[i]);
	
	for(int i=0;i<n;i++)
	arc[i]=ar[i];
	
	Bsort(ar,n);
	printf("Number of comparisons in Bubble Sort is %d", c1);
	
	printf("\n\n");
	for(int i=0;i<n;i++)
	ar[i]=arc[i];
	
	Isort(ar,n);
	printf("Number of comparisons in Insertion Sort is %d", c2);
	
	printf("\n\n");
	for(int i=0;i<n;i++)
	ar[i]=arc[i];
	
	Ssort(ar,n);
	printf("Number of comparisons in Selection Sort is %d", c3);
	printf("\n\n");
	/*
	Bsort(ar,n);
	printf("The sorted array using Bubble Sort is : ");
	for(int i=0;i<n;i++)
	printf("%d ",ar[i]);

	printf("\n\n");
	for(int i=0;i<n;i++)
	ar[i]=arc[i];

	Isort(ar,n);
	printf("The sorted array using Insertion Sort is : ");
	for(int i=0;i<n;i++)
	printf("%d ",ar[i]);
	
	printf("\n\n");
	for(int i=0;i<n;i++)
	ar[i]=arc[i];

	Ssort(ar,n);
	printf("The sorted array using Selection Sort is : ");
	for(int i=0;i<n;i++)
	printf("%d ",ar[i]);
	printf("\n\n");
	label:
	printf("\n Please Select any one of the options");	
	printf("\n 1. Bubble Sort          2. Insertion Sort            3. Selection Sort\n");
	scanf("%d",&a);
		
	switch(a)
	{
		case 1: Bsort(ar,n);
	        	break;
	        
		case 2: Isort(ar,n);
				break;
			
    	case 3: Ssort(ar,n);
				break;
			
    	default:printf("Entered value is incorrect Please re-enter\n");
    			goto label;
    			break;
    }*/
	
	
}

void Bsort(int b[], int s)
{	int temp;
	for(int i=1;i<s;i++)
	{	
		for(int j=0;j<s-i;j++)
			{
				c1++;
				if(b[j]>b[j+1])
				{	
					temp=b[j];
					b[j]=b[j+1];
					b[j+1]=temp;
				}	
			
			}
	}
}


void Isort(int b[], int s)
{	int temp;
	for(int i=1;i<=s-1;i++)
	{	
		for(int j=i;j>0;j--)
		{	c2++;
			if(b[j]<b[j-1])
			{	
				temp=b[j];
				b[j]=b[j-1];
				b[j-1]=temp;
			}	
			
			else break;
		}	
	}
}
			
			
			
void Ssort(int b[], int s)
{	int temp,max,imax;
	for(int i=1;i<=s-1;i++)
	{	max=b[0];
		imax=0;
		
		for(int j=1;j<=s-i;j++)
			{   c3++;
				if(b[j]>max)
				{
					max=b[j];
					imax=j;
				}
			}
			
			
			
		temp=b[imax];
		b[imax]=b[s-i];
		b[s-i]=temp;
				
			
	}
}			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
