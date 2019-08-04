#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *a,size,l=-1;

void ins();
void del();
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
		printf("1.insert\t2.delete\t3.display\t4.exit :");
		scanf("%d",&c);
		switch(c)
		{
			case 1:ins();break;
			case 2:del();break;
			case 3:display();break;
			case 4:f=0;break;
			default:
				printf("Enter the above given characters only\n");break;
		}
	}
}
void ins()
{
	int x,temp,t=0;
	if(l==size-1)
	{
		printf("Over flow\n");
	}
	else
	{
		if(l==-1)
		{
			printf("Enter data :");
			scanf("%d",&a[++l]);t++;
			printf("insert success\n");
		}
		else
		{
			printf("Enter data :");
			scanf("%d",&x);
			a[++l]=x;
			t=l;
			while(a[t]>a[(int)(ceil(t/2.0))-1] && t>0)
			{
				temp=a[t];
				a[t]=a[(int)(ceil(t/2.0))-1];
				a[(int)(ceil(t/2.0))-1]=temp;
				t=(int)(ceil(t/2.0))-1;	
			}
			printf("insert success\n");
		}
	}
}
void del()
{
	int temp,t=0;
	if(l==-1)
	{
		printf("Under Flow\n");
	}
	else
	{
		a[0]=a[l];printf("%d\n",a[0]);
		a[l]=-1;
		l--;	
		while(t<l && a[2*t+1]!=-1)
		{
			if(a[2*t+2]!=-1)
			{
				if(a[2*t+1]>a[2*t+2] && a[t]<a[2*t+1])
				{
					temp=a[t];
					a[t]=a[2*t+1];
					a[2*t+1]=temp;
					t=2*t+1;
				}
				else if(a[2*t+2]>a[2*t+1] && a[t]<a[2*t+2])
				{
					temp=a[2*t+2];
					a[2*t+2]=a[t];
					a[t]=temp;
					t=2*t+2;
				}
				else
				{
					t++;
				}
			}
			else if(a[2*t+2]==-1)
			{
				if(a[t]<a[2*t+1])
				{
					temp=a[2*t+1];
					a[2*t+1]=a[t];
					a[t]=temp;
					t=2*t+1;
				}
				else
				{
					t++;			
				}
			}
			else
			{
				t++;
			}
		}	
		printf("del_beg success\n");
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
