#include<stdlib.h>
#include<stdio.h>

struct node
{
	int d;
	struct node *p;
};
struct node *s,*temp,*t1,*t2;

void insert_at_beg();
void insert_at_end();
void insert_at_rand();
void del_at_rand();
void search();
void display();

void main()
{
	s=NULL;
	int f=1,x;
	while(f)
	{
		printf("Enter the following operations you want to perform :\n");
		printf("1.insert_at_beg\t2.insert_at_end\t3.insert_at_rand\t4.del_at_rand\t5.search\t6.display\t7.exit :");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				insert_at_beg();break;
			case 2:
				insert_at_end();break;
			case 3:
				insert_at_rand();break;
			case 4:
				del_at_rand();break;
			case 5:
				search();break;
			case 6:
				display();break;
			case 7:
				f=0;break;
			default:
				printf("Enter the above given character numbers only\n");break;
		}
	}
}
void insert_at_beg()
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
void insert_at_end()
{
	if(s==NULL)
	{
		insert_at_beg();
	}
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(temp->d));
		temp->p=s->p;
		s->p=temp;
		s=temp;
		printf("Insert success\n");
	}
}
void insert_at_rand()
{
	int x,k=1,t=0;
	printf("Enter the location you want to insert :");
	scanf("%d",&x);
	if(x==0)
	{
		insert_at_beg();
	}
	else
	{
		temp=s->p;
		while(temp!=s)
		{
			temp=temp->p;k++;
		}
		printf("%d\n",k);
		if(x<k)
		{	
			temp=s->p;
			while(t<x-1)
			{
				temp=temp->p;t++;
			}
			t1=(struct node *)malloc(sizeof(struct node));
			printf("Enter data :");
			scanf("%d",&(t1->d));		
			t1->p=temp->p;
			temp->p=t1;
			printf("Insert success\n");
		}
		else if(x==k)
		{
			insert_at_end();
		}
		else
		{
			printf("location not found\n");
		}
	}
}	
void del_at_rand()
{
	int x,k=1,t=1;
	printf("Enter location :");
	scanf("%d",&x);
	if(s==NULL)
	{
		printf("location not found\n");
	}
	else
	{
		temp=s->p;
		while(temp!=s)
		{
			temp=temp->p;k++;
		}
		if(x<k)
		{
			if(x==1)
			{
				t2=(s->p)->p;
				(s->p)->p=NULL;
				s->p=t2;
			}
			else
			{
				temp=s->p;
				while(t<x-1)
				{
					temp=temp->p;t++;
				}
				t1=temp->p;
				temp->p=t1->p;
				t1->p=NULL;	
			}printf("delete success\n");	
		}
		else if(x==k)
		{
			temp=s->p;
			while(t<x-1)
			{
				temp=temp->p;t++;
			}
			s->p=temp->p;
			s->p=NULL;
			s=temp;printf("delete success\n");
		}
		else
		{
			printf("location not found\n");
		}
	}
}	
void search()
{
	int x,k=1,t=1;
	printf("Enter data you want to search :");
	scanf("%d",&x);
	temp=s->p;
	while(temp!=s)
	{
		temp=temp->p;k++;
	}
	if(s==NULL)
	{
		printf("data not found\n");
	}
	else
	{
		temp=s->p;
		while(temp!=s)
		{
			if(temp->d==x)
			{
				break;
			}
			else
			{
				temp=temp->p;t++;
			}
		}
		if(t=k-1)
		{
			if(temp->d==x)
			{
				printf("data found\n");
			}
		}
		else if(t==k)
		{
			printf("data not found\n");
		}
	}
}	
void display()
{
	int k=1;
	if(s==NULL)
	{
		printf("no data\n");
	}
	else
	{
		temp=s->p;
		while(temp!=s)
		{
			temp=temp->p;k++;
		}
		temp=s->p;
		for(int i=0;i<k;i++)
		{
			printf("%d\n",temp->d);
			temp=temp->p;
		}
	}
}
