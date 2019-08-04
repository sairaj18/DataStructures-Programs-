#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int top=-1,*a,n;
void push();
void pop();
int tope();
bool isempty();
bool isfull();
int main()
{
int d,f=1;
	printf("enter size:\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	while(f)
	{
		printf("enter any of the following operations which you want to perfom:\n");
		printf("1.push 2.pop 3.top 4.isempty 5.isfull 6.exit\n");
		scanf("%d",&d);
		switch(d)
		{
			case 1:
			push(a,top);
			break;
			case 2:
			pop(top);
			break;
			case 3:
			tope(a,top);
			break;
			case 4:
			isempty(top);
			break;
			case 5:
			isfull(top,n);
			break;
			case 6:
			f=0;
			break;
			default:
			printf("enter the given character numbers only\n");
		}
	}
}
void push()
{
	if(isfull())
	{
		printf("stack over flow\n");
	}
	else
	{
		printf("ente value\n");
		scanf("%d",&a[++top]);
		printf("success_push\n");
	}
}
void pop()
{
	if(isempty())
	{
		printf("stack under flow\n");
	}
	else
	{
		top--;
		printf("pop_success\n");
	}
}
int tope()
{
	if(isempty())
	{
		printf("system under flow\n");
	}
	else
	{
		return  a[top];
	}
} 
bool isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
bool isfull()
{
	if(top==n-1)
	return 1;
	else 
	return 0;
}
