#include<stdio.h>
#include<stdlib.h>

struct node
{
	int d;
	struct node *p;
};
struct node *t1,*t2,*s,*temp,*search_node_add;

void insert_at_beg();
void insert_at_end();
void search();
void insert_at_any();
void delete_at_any();
void display();
void reverse();
void sort();

void main()
{
	s=NULL;
	int f=1,r;
	while(f)
	{
		printf("Enter the following operations you want to perform :\n");
		printf("1.insert_at_beg\t2.insert_at_end\t3.search\t4.insert_at_any\t5.delete_at_any\t6.display\t7.reverse\t8.sort\t9.exit :");
		scanf("%d",&r);
		switch(r)
		{
			case 1:insert_at_beg();break;
			case 2:insert_at_end();break;
 			case 3:search();break;
			case 4:insert_at_any();break;
			case 5:delete_at_any();break;
			case 6:display();break;
			case 7:reverse();break;
			case 8:sort();break;
			case 9:f=0;break;
			default :printf("Enter the above given numbers only\n");break;
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
		s->p=NULL;
		printf("Insert success\n");
	}
	else
	{
		temp=s;
		s=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(s->d));
		s->p=temp;
		printf("Insert success\n");
	}
}
void insert_at_end()
{
	if(s==NULL)
	{
		s=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(s->d));
		s->p=NULL;
		printf("Insert success\n");
	}
	else
	{
		temp=s;
		while(temp->p!=NULL)
		{
			temp=temp->p;
		}
		temp->p=(struct node *)malloc(sizeof(struct node));
		temp=temp->p;
		printf("Enter data :");
		scanf("%d",&(temp->d));
		temp->p=NULL;
		printf("insert at end success\n");
	}
}
void search()
{	
	int x;
	temp=s;
	search_node_add=NULL;
	printf("Enter the data u want to search :");
	scanf("%d",&x);	
	if(s==NULL)
	{
		printf("There is no data to search\n");
	}
	else
	{	
		while(temp!=NULL)
		{
			if(temp->d==x)
			{
				printf("data found\n");
				break;
			}
			else
				temp=temp->p;
		}	
	}
}
void display()
{
	temp=s;
	while(temp!=NULL)
	{
		printf("%d\n",temp->d);
		temp=temp->p;
	}
}
void insert_at_any()
{
	int x,t=1,k=0;
	printf("Enter location :");
	scanf("%d",&x);
	temp=s;	
	while(temp!=NULL)
	{
		temp=temp->p;k++;
	}
	if(x==0)
	{	
		insert_at_beg();printf("Insert Success\n");
	}	
	else if(x<k)
	{	
		t1=s;
		while(t<x)
		{
			t1=t1->p;			
			t++;
		}
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(temp->d));
		temp->p=t1->p;
		t1->p=temp;
		printf("Insert success\n");
	}
	else if(x==k)
	{
		insert_at_end();printf("Insert Success\n");
	}
	else
	printf("location not found\n");
}
void delete_at_any()
{
	int x,k=1,t=1;
	printf("Enter location :");
	scanf("%d",&x);
	temp=s;
	while(temp!=NULL)
	{
		temp=temp->p;k++;
	}
	if(x<k)
	{
		if(x==0)
		{	
			t2=s;
			s=t2->p;
			t2->p=NULL;//to remove link b/w deleted and t1
			printf("delete success\n");
		}
		else
		{		
			t2=s;
			while(t<x-1)
			{
				t2=t2->p;t++;
			}
			t1=t2->p;
			t2->p=t1->p;
			t2->p=NULL;//to remove link b/w deleted and t1
			printf("delete success\n");
		}
	}
	else
	{
		printf("location not found\n");
	}
}
void reverse()
{
	int tem,i=0,j=0,t;
	temp=s;
	while(temp!=NULL)
	{
		temp=temp->p;j++;
	}
	t1=s;j--;
	if(s!=NULL)
	{
		while(i<j)
		{	
			t=0;
			temp=s;
			while(t<j)
			{
				temp=temp->p;t++;
			}
			tem=t1->d;
			t1->d=temp->d;
			temp->d=tem;
			t1=t1->p;
			i++;
			j--;
		}
		printf("reverse success\n");
	}
	else
	{
		printf("no data\n");
	}
}
void sort()
{
	if(s==NULL)
	{
		printf("no data\n");
	}
	else
	{	
		int i,k=0,j,m;
		temp=s;
		while(temp!=NULL)
		{
			temp=temp->p;k++;
		}
		t1=s;
		for(i=0;i<k-1;i++)
		{	
			t2 = t1->p;
			for(j=i+1;j<k;j++)
			{       
				if((t1->d)>(t2->d))
				{
					m=t1->d;
					t1->d=t2->d;
					t2->d=m;	
				}
				t2=t2->p;	
			}
			t1=t1->p;	
		}
		printf("sort success\n");
	}
}
