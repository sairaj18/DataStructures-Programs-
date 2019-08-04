#include<stdio.h>
#include<stdlib.h> 
void push();
void pop();
void display();
struct node
{
	int d;
	struct node *p;
};
struct node *s,*temp,*t1;
void main()
{
	s=NULL;
	int f=1,c;
	while(f)
	{
		printf("Enter the following operations you want to perform :\n");
		printf("1.push\t2.pop\t3.display\t4.exit :");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				push();break;
			case 2:
				pop();break;
			case 3:
				display();break;
			case 4:
				f=0;break;
			default:
				printf("Enter the above given character numbers only\n");break;
		}
	}
}
void push()
{
	if(s==NULL)
	{
		s=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(s->d));
		s->p=s;
		printf("Insert success\n");
	}
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(temp->d));
		temp->p=s->p;
		s->p=temp;
		printf("Insert success\n");
	}
}
void pop()
{
	int k=1;
	if(s==NULL)
	{
		printf("No data to pop\n");
	}
	else
	{
		temp=s->p;
		while(temp!=s)
		{
			temp=temp->p;k++;
		}
		if(k>1)
		{
			temp=s->p;
			t1=temp->p;
			temp->p=NULL;
			s->p=t1;
		}
		else
		{
			s=NULL;
		}
	}
}
void display()
{
	if(s==NULL)
	{
		printf("No data to display\n");
	}
	else
	{
		temp=s->p;
		while(temp!=s)
		{
			printf("%d\n",temp->d);
			temp=temp->p;
		}
		printf("%d\n",temp->d);
	}
}
