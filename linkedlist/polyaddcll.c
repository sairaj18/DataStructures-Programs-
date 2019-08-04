#include<stdio.h>
#include<stdlib.h>
void push1();
void push2();
struct node
{
	int d;
	struct node *p;
};
struct node *s1,*s2,*s3,*temp,*t1,*t2,*t3,*tem,*te;
void main()
{
	s1=NULL;
	s2=NULL;
	s3=NULL;
	int i,r,pa=1,pb=1,pc=0,ta,tb,t=0,k=0,x=0,y=0,z=0;
	printf("enter number of terms in a :");
	scanf("%d",&ta);
	printf("enter number of terms in b :");
	scanf("%d",&tb);
	for(i=0;i<2*ta;i++)
	{
		r=i%2;
		if(r==0)
		{
			printf("enter the exponent of a :");
			push1();
		}
		else
		{
			printf("enter the co-efficent of a :");
			push1();
		}
	}
	for(i=0;i<2*tb;i++)
	{
		r=i%2;
		if(r==0)
		{
			printf("enter the exponent of b :");
			push2();
		}
		else
		{		
			printf("enter the co-efficent of b :");
			push2();
		}
	}
	temp=s1;
	t1=s2;
	tem=s1;
	te=s2;
	while(pa<2*ta && pb<2*tb)
	{
		while(t<pa)
		{
			temp=temp->p;t++;
		}
		while(k<pb)
		{
			t1=t1->p;k++;
		}
		if((temp->d)>(t1->d))
		{	
			if(s3==NULL)
			{
				s3=(struct node *)malloc(sizeof(struct node));
				s3->d=temp->d;
				s3->p=s3;pa+=2;pc++;
			}	
			else
			{
				t2=(struct node *)malloc(sizeof(struct node));
				t2->d=temp->d;
				t3=s3->p;
				s3->p=t2;
				t2->p=t3;
				s3=t2;pa+=2;pc++;
			}
			while(x<=t)
			{
				tem=tem->p;x++;
			}
			t2=(struct node *)malloc(sizeof(struct node));
			t2->d=tem->d;
			t3=s3->p;
			s3->p=t2;
			t2->p=t3;
			s3=t2;pc++;
		}	
		else if((t1->d)>(temp->d))
		{
			if(s3==NULL)
			{
				s3=(struct node *)malloc(sizeof(struct node));
				s3->d=t1->d;
				s3->p=s3;pb+=2;pc++;
			}	
			else
			{
				t2=(struct node *)malloc(sizeof(struct node));
				t2->d=t1->d;
				t3=s3->p;
				s3->p=t2;
				t2->p=t3;
				s3=t2;pb+=2;pc++;
			}
			while(y<=t)
			{
				te=te->p;y++;
			}
			t2=(struct node *)malloc(sizeof(struct node));
			t2->d=te->d;
			t3=s3->p;
			s3->p=t2;
			t2->p=t3;
			s3=t2;pc++;
		}
		else if((t1->d)==(temp->d))
		{
			if(s3==NULL)
			{
				s3=(struct node *)malloc(sizeof(struct node));
				s3->d=temp->d+t1->d;
				s3->p=s3;pa+=2;pb+=2;pc++;
			}	
			else
			{
				t2=(struct node *)malloc(sizeof(struct node));
				t2->d=temp->d;
				t3=s3->p;
				s3->p=t2;
				t2->p=t3;
				s3=t2;pa+=2;pb+=2;pc++;
			}
			while(z<=t)
			{
				tem=tem->p;te=te->p;z++;
			}
			t2=(struct node *)malloc(sizeof(struct node));
			t2->d=tem->d+te->d;
			t3=s3->p;
			s3->p=t2;
			t2->p=t3;
			s3=t2;pc++;
		}
	}
	while(pa<2*ta)
	{
		while(t<pa)
		{
			temp=temp->p;t++;
		}
		if(s3==NULL)
		{
			s3=(struct node *)malloc(sizeof(struct node));
			s3->d=temp->d;
			s3->p=s3;pa+=2;pc++;
		}	
		else
		{
			t2=(struct node *)malloc(sizeof(struct node));
			t2->d=temp->d;
			t3=s3->p;
			s3->p=t2;
			t2->p=t3;
			s3=t2;pa+=2;pc++;
		}
		while(x<=t)
		{
			tem=tem->p;x++;
		}
		t2=(struct node *)malloc(sizeof(struct node));
		t2->d=tem->d;
		t3=s3->p;
		s3->p=t2;
		t2->p=t3;
		s3=t2;pc++;
	}
	while(pb<2*tb)
	{
		while(k<pb)
		{
			t1=t1->p;k++;
		}
		if(s3==NULL)
		{
			s3=(struct node *)malloc(sizeof(struct node));
			s3->d=t1->d;
			s3->p=s3;pb+=2;pc++;
		}	
		else
		{
			t2=(struct node *)malloc(sizeof(struct node));
			t2->d=t1->d;
			t3=s3->p;
			s3->p=t2;
			t2->p=t3;
			s3=t2;pb+=2;pc++;
		}
		while(y<=t)
		{
			te=te->p;y++;
		}
		t2=(struct node *)malloc(sizeof(struct node));
		t2->d=te->d;
		t3=s3->p;
		s3->p=t2;
		t2->p=t3;
		s3=t2;pc++;
	}
	t=0;
	temp=s3->p;
	while(t<pc)
	{
		r=t%2;
		if(r==0)
		{
			printf("Exponent is :%d\n",temp->d);t++;
			temp=temp->p;	
		}
		else
		{
			printf("Co-efficent is :%d\n",temp->d);t++;
			temp=temp->p;
		}
	}
}
void push1()
{
	if(s1==NULL)
	{
		s1=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(s1->d));
		s1->p=s1;
	}
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(temp->d));
		t1=s1->p;
		s1->p=temp;
		temp->p=t1;
		s1=temp;
	}
}
void push2()
{
	if(s2==NULL)
	{
		s2=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(s2->d));
		s2->p=s2;
	}
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter data :");
		scanf("%d",&(temp->d));
		t1=s2->p;
		s2->p=temp;
		temp->p=t1;
		s2=temp;
	}
}
