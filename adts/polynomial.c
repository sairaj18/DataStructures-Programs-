#include<stdio.h>
#include<stdlib.h>
void combine(int *,int *,int,int);
int main()
{
	int n1,n2,*a,*b;
	printf("\nenter number of terms in 1st polynomial : ");
	scanf("%d",&n1);
	a=(int*)malloc(sizeof(int)*(n1*2));
	printf("\nenter number of terms in 2nd polynomial : ");
	scanf("%d",&n2);
	b=(int*)malloc(sizeof(int)*(n2*2));
	for(int i=0;i<(2*n1);i++)
	{
		int r=i%2;
		if(r==0)
		{
  			printf("\nenter coefficent for 1st polynomial : ");
  			scanf("%d",a+i);
		}
 		else
		{
  			printf("\nenter the corresponding exponent for 1st polynomial : ");
  			scanf("%d",a+i);
		}
	}
   	for(int i=0;i<(2*n2);i++)
	{	
		int r=i%2;
  		if(r==0)
		{
  			printf("\nenter coefficent for 2nd polynomial : ");
  			scanf("%d",b+i);
		}
 		else
		{
  			printf("\nenter the corresponding exponent for 2nd polynomial : ");
  			scanf("%d",b+i);
		}
	}
	combine(a,b,n1,n2);
}
void combine(int *a,int *b,int n1,int n2)
{
	int g,h,k,px=1,py=1,pa=0,j=0;
	int *c=(int*)malloc(sizeof(int)*(2*(n1+n2)));		
	while(px<2*n1 && py<2*n2)
	{
		if(a[px]>b[py])
		{
			c[pa]=a[px-1];
			c[++pa]=a[px];
			px+=2;
		}
		else if(a[px]<b[py])
		{
			c[pa]=b[py-1];
			c[++pa]=b[py];
			py+=2;
		}
		else
		{
			c[pa] = a[px-1] + b[py-1];
			c[++pa]=a[px];
			px+=2;
			py+=2;
		}
		pa++;
	}
	while(px<2*n1)
	{
		c[pa++]=a[px++];		
	}
	while(py<2*n2)
	{
		c[pa++]=b[py++];		
	}
	printf("\nthe resultant polynomial obtained after addition is : \n");
	for(g=0;g<pa;g++)
	{
		if(g%2==0)
		{
			printf("the coefficent is : %d\n",*(c+g));		
		}	
		else
		{
			printf("the exponent is : %d\n",*(c+g));		
		}	
	}
}
