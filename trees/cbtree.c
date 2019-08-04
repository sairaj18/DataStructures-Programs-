#include<stdio.h>
#include<stdlib.h>

int *a,size,l=-1,r=0;

void ins();
void del_b();
void del_e();
void del_any();
void search();
void display();

void main()
{
	int f=1,c;
	printf("Enter size :");
	scanf("%d",&size);
	a=(int *)malloc(sizeof(int)*(2*size+1));
	for(int i=0;i<(2*size+1);i++)
	{
		a[i]=-1;
	}
	while(f)
	{
		printf("Enter the following operations you want to perform :\n");
		printf("1.insert\t2.delete_at_beg\t3.delete_at_end\t4.del_rand\t5.search\t6.display\t7.exit :");
		scanf("%d",&c);
		switch(c)
		{
			case 1:ins();break;
			case 2:del_b();break;
			case 3:del_e();break;
			case 4:del_any();break;
			case 5:search();break;
			case 6:display();break;
			case 7:f=0;break;
			default:
			printf("Enter the above given characters only\n");break;
		}
	}
}
void ins()
{
	if(l==size-1)
	{
		printf("Over flow\n");		
	}
	else
	{
		printf("Enter the element you want to insert :");
		scanf("%d",&a[++l]);
		printf("Insert success\n");
		
	}
}
void del_b()
{
	if(l==-1)
	{
		printf("Under Flow\n");
	}
	else
	{
		a[0]=a[l];
		a[l]=-1;			
		l--;
		printf("del_beg success\n");
	}
}
void del_e()
{
	if(l==-1)
	{
		printf("Under Flow\n");
	}
	else
	{
		a[l]=-1;
		l--;
		printf("del_end success\n");
	}
}
void del_any()
{	
	int x,temp=-1;
	if(l==-1)
	{
		printf("Under Flow\n");
	}
	else
	{
		printf("Enter the location you want to del :");
		scanf("%d",&x);
		if(x==0)
		{
			del_b();
			printf("del_any success\n");
		}
		else if(x<size-1)
		{
			a[x]=a[l];
			a[l]=-1;
			l--;
			printf("del_any success\n");	
		}
		else if(x==size-1)
		{
			del_e();
			printf("del_any success\n");
		}
		else
		{
			printf("location not found\n");
		}
	}
}
void search()
{
	int x,temp=-1;
	if(l==-1)
	{
		printf("Under Flow\n");
	}
	else
	{
		printf("Enter element you want to search :");
		scanf("%d",&x);
		for(int i=0;i<size;i++)
		{
			if(a[i]==x)
			{
				temp=i;break;
			}
		}
		if(temp!=-1)
		{
			printf("Element found\n");temp=-1;
		}
		else
		{
			printf("Element not found\n");
		}
	}
}
void display()
{
	int t=0,r=0;
	if(l==-1)
	{
		printf("Under Flow\n");
	}
	else
	{
		while(t<=l)
		{
			if(t==0)
			{
				printf("Root element is :%d\n",a[t]);
				if(a[2*t+1]!=-1)
				{
					printf("%d's left is %d\n",a[t],a[2*t+1]);
					if(a[2*t+2]!=-1)
					{
						printf("%d's right is %d\n",a[t],a[2*t+2]);
					}
				}
				t++;r++;
			}
			else if(t>0)
			{
				if(a[2*t+1]==-1)
				{
					printf("%d is leaf\n",a[t]);t++;
				}
				else
				{
					if(r>0)
					{
						printf("%d is parent\n",a[t]);
					}
					if(a[2*t+1]!=-1)
					{
						printf("%d's left is %d\n",a[t],a[2*t+1]);
						if(a[2*t+2]!=-1)
						{
							printf("%d's right is %d\n",a[t],a[2*t+2]);
						}
					}
					t++;
				}
			}
		}
	}
}
