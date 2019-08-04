#include<stdio.h>
#include<stdlib.h>
int n,*a,f=0,r=-1,u=1;

void front();
void rear();
void display();

void main()
{ 
	int c;
	printf("Enter the size of array :\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	while(u)
	{
		printf("Enter the following operations you want to perfrom :\n");
		printf("1.front to delete\t2.rear to push\t3.display\t4.exit as 1,2,3 and 4 respectively :");
		scanf("%d",&c);
		switch(c)
			{
				case 1:
					front();
					break;
				case 2:
					rear();
					break;
				case 3:
					display();
					break;
	 			case 4:
					u=0;
					break;
				default:
					printf("Enter the above given character numbers\n");
					break;
			}
	}
}
void front()
{	
	int temp;
	if(r==f-1)
	{
		printf("Under Flow\n");
	}
	else if(r>0)
	{
		f++;
	}
	else if(r==0)
	{
		r=-1;
	}
}
void rear()
{
	if(r==n-1)
	{
		printf("Over Flow\n");
	}
	else
	{	
		printf("Enter array element to insert:");
		scanf("%d",&a[++r]);
	}
}
void display()
{
	if(r==f-1)
	{		
		printf("Under Flow\n");
	}
	else
	{
		for(int i=f;i<=r;i++)
		{
			printf("%d\n",a[i]);		
		}
	}
}
