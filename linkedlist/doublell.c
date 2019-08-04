#include<stdio.h>
#include<stdlib.h>
struct node
{
	int d;
	struct node *l,*r;
};
struct node *s,*temp,*t1;
void i_beg();
void i_end();
void i_any();
void d_beg();
void d_end();
void d_any();
void search();
void display();

void main()
{
	s=NULL;
	int f=1,c;
	while(f)
	{
		printf("Enter the following operations you want to perfom :\n");
		printf("1.i_beg\t2.i_end\t3.i_any\t4.d_beg\t5.d_end\t6.d_any\t7.search\t8.display\t9.exit :\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				i_beg();break;
			case 2:
				i_end();break;
			case 3:
				i_any();break;
			case 4:
				d_beg();break;
			case 5:
				d_end();break;
			case 6:
				d_any();break;
			case 7:
				search();break;
			case 8:
				display();break;
			case 9:
				f=0;break;
			default:
				printf("Enter the above given character numbers only\n");break;
		}
	}
}
void i_beg()
{
	if(s==NULL)
	{
		s=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(s->d));		
		s->l=s;
		s->r=s;
		printf("Insert success\n");
	}
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(temp->d));
		temp->l=s->l;
		temp->r=s;
		(s->l)->r=temp;
		s->l=temp;
		s=temp;
		printf("Insert success\n");
	}
}
void i_end()
{
	if(s==NULL)
	{
		s=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(s->d));		
		s->l=s;
		s->r=s;
		printf("Insert success\n");
	}
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(temp->d));
		temp->l=s->l;
		(s->l)->r=temp;
		temp->r=s;
		s->l=temp;
		printf("Insert success\n");
	}
}
void i_any()
{
	int x,k=1,t=0;
	printf("Enter location :");
	scanf("%d",&x);
	if(s==NULL)
	{
		printf("location not found\n");
	}
	else
	{
		temp=s;
		while(temp->r!=s)
		{
			temp=temp->r;k++;
		}
		if(x==0)
		{
			i_beg();		
		}
		else if(x<k)
		{
			t1=s;
			while(t<x)
			{
				t1=t1->r;t++;
			}
			temp=(struct node *)malloc(sizeof(struct node));
			printf("Enter data :");
			scanf("%d",&(temp->d));
			temp->l=t1->l;
			(t1->l)->r=temp;
			temp->r=t1;
			t1->l=temp;
			printf("Insert success\n");
		}
		else if(x==k)
		{
			i_end();
		}
		else
		{
			printf("location not found\n");
		}
	}	
}
void d_beg()
{	
	int k=1;
	if(s==NULL)
	{
		printf("No data\n");
	}
	else
	{
		temp=s;
		while(temp->r!=s)
		{
			temp=temp->r;k++;
		}	
		if(k==1)
		{
			s=NULL;printf("d_beg success");
		}
		else
		{
			(s->r)->l=s->l;
			(s->l)->r=s->r;
			s->l=NULL;
			t1=s->r;
			s->r=NULL;
			s=t1;
			printf("d_beg success");
		}
	}
}
void d_end()
{	
	int k=1;
	if(s==NULL)
	{
		printf("No data\n");
	}
	else
	{
		temp=s;
		while(temp->r!=s)
		{
			temp=temp->r;k++;
		}	
		if(k==1)
		{
			s=NULL;
		}
		else
		{
			(temp->l)->r=s;
			s->l=temp->l;
			temp->l=NULL;
			temp->r=NULL;
			printf("d_end success");
		}
	}
}
void d_any()
{
	int x,k=1,t=0;
	printf("Enter location :");
	scanf("%d",&x);
	if(s==NULL)
	{
		printf("No data\n");
	}
	else
	{
		temp=s;
		while(temp->r!=s)
		{
			temp=temp->r;k++;
		}
		if(x==1)
		{
			d_beg();
		}
		else if(x<k)
		{
			t1=s;
			while(t<x-1)
			{
				t1=t1->r;t++;
			}
			(t1->l)->r=t1->r;
			(t1->r)->l=t1->l;
			t1->l=NULL;
			t1->r=NULL;
			printf("d_any success\n");
		}
		else if(x==k)
		{
			d_end();
		}
		else
		{
			printf("data not found\n");
		}
	}
}
void search()
{
	int key;
	printf("Enter key :");
	scanf("%d",&key);
	if(s==NULL)
	{
		printf("No data\n");
	}
	else
	{
		temp=s;
		while(temp->r!=s)
		{
			if(temp->d==key)
			{
				printf("key found\n");break;
			}
			else
			{
				temp=temp->r;
			}
		}
		if(temp->d==key)
		{
			printf("key found\n");
		}
		else
		{
			printf("key not found\n");
		}
	}
}
void display()
{
	if(s==NULL)
	{
		printf("No data\n");
	}
	else
	{
		temp=s;
		while(temp->r!=s)
		{
			printf("%d ",temp->d);
			temp=temp->r;
		}
		printf("%d\n",temp->d);
	}
}
