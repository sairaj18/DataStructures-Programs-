#include<stdio.h>
#include<stdlib.h>
int s,*a,f=0,r=-1;

void push();
void pop();
int number_of_elements();
void display();

void main()
{	
	int u=1,c;
	printf("Enter the size of array :");
	scanf("%d",&s);
	a=(int *)malloc(sizeof(int)*s);
	while(u)
	{
		printf("Enter the following operations you want to perform :\n");
		printf("1.push\t2.pop\t3.number of elements\t4.display\t5.exit as 1,2,3,4 and 5 respectively :");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				number_of_elements();
				break;
			case 4:
				display();
				break;
			case 5:
				u=0;
				break;
			default:
				printf("Enter the given characters numbers only\n");
				break;
		}
	}
}
void push()
{
	int n=number_of_elements();
	if(n==s)
	{
		printf("Over Flow\n");
	}
	else
	{
		printf("enter element:");
		scanf("%d",&a[++r%s]);
		printf("push_success\n");
	}
}
void pop()
{	
	int n=number_of_elements();
	if(n==0)
	{
		printf("Under Flow\n");
	}
	else if(f==r)
	{
		f=0;
		r=-1;
		printf("pop_success\n");
	}
	else
	{
		f=++f%s;
		printf("pop_success\n");
	}
}
int number_of_elements()
{
	if(f==0 && r==-1)
	{
		printf("number of elements are %d\n",f);
		return 0;
	}
	else if(r>=f)
	{	
		printf("number of elements are %d\n",r-f+1);
		return r-f+1;
	}
	else if(f>r)
	{	
		printf("number of elements are %d\n",s+r-f+1);
		return s+r-f+1;
	}
}
void display()
{	
	int n=number_of_elements();
	if(n==0)
	{
		printf("Under Flow\n");
	}
	else
	{
		for(int i=f;;i=++i%s)
		{
			printf("%d\n",a[i]);
			if(i==r)
			break;
		}	
	}
}
