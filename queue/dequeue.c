#include<stdio.h>
#include<stdlib.h>
int *a,s,f=0,r=-1;

void i_atbeg();
void i_atend();
void d_atbeg();
void d_atend();
void display();

void main()
{	
	int c,u=1;
	printf("Enter the size of array :");
	scanf("%d",&s);
	a=(int *)malloc(sizeof(int)*s);
	while(u)
	{
		printf("Enter the following operations you want to perform :\n");
		printf("1.i_atbeg\t2.i_atend\t3.d_atbeg\t4.d_atend\t5.display\t6.exit as 1,2,3,4,5 and 6 respectively :");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				i_atbeg();
				break;
			case 2:
				i_atend();
				break;
			case 3:
				d_atbeg();
				break;
			case 4:
				d_atend();
				break;
			case 5:
				display();
				break;
			case 6:
				u=0;
				break;
			default:
				printf("Enter the given character numbers only\n");
				break;
		}
	}
}
void i_atbeg()
{	
	int temp,t;
	if(r==s-1)
	{
		printf("Over flow\n");
	}
	else if(r==-1)
	{
		printf("Enter element :");
		scanf("%d",&a[++r]);	
	}
	else
	{
		printf("Enter element :");
		scanf("%d",&t);
		for(int i=r;i>=0;i--)
		{
			temp=a[i];
			a[i+1]=temp;	
		}
		a[0]=t;
		r++;
	}
}
void i_atend()
{
	if(r==s-1)
	{
		printf("Over Flow\n");
	}
	else if(r>0)
	{
		printf("Enter element :");
		scanf("%d",&a[++r]);
	}
	else if(r==-1)
	{
		printf("Enter 1.i_atbeg first to insert at end\n");
	}
}
void d_atbeg()
{	
	int tem;
	if(r==-1)
	{
		printf("Under flow\n");
	}
	else if(r>0)
	{
		for(int i=0;i<r;i++)
		{
			tem=a[i+1];
			a[i]=tem;
		}
		r--;
	}
}
void d_atend()
{
	if(r==-1)
	{
		printf("Under Flow\n");
	}
	else
	{
		r--;
		printf("d_atend success\n");	
	}
}
void display()
{
	if(r==-1)
	{
		printf("Under Flow\n");
	}
	else if(r>=0)
	{	
		for(int i=0;i<=r;i++)
		printf("%d\n",a[i]);
	}
}
