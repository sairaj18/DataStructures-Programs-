#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *a,*tem,size,l=-1,k=0;

void ins();
void del();

void main()
{
	printf("Enter size of array :");
	scanf("%d",&size);
	a=(int *)malloc(sizeof(int)*(2*size+1));
	tem=(int *)malloc(sizeof(int)*size);
	for(int i=0;i<(2*size+1);i++)
	{
		a[i]=-1;
	}
	for(int i=0;i<size;i++)
	{
		ins();
	}
	for(int i=0;i<size;i++)
	{
		del();
	}
	printf("After Sorting :");	
	for(int i=0;i<size;i++)
	{
		printf("%d ",tem[i]);
	}
}
void ins()
{
	int x,temp,t;
	if(l==size-1)
	{
		printf("Over flow\n");
	}
	else
	{
		if(l==-1)
		{
			printf("Enter data :");
			scanf("%d",&a[++l]);
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
		tem[k]=a[0];k++;
		a[0]=a[l];
		a[l]=-1;
		l--;
		while(t<=l && a[2*t+1]!=-1)
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
		}
		printf("del_beg success\n");
	}
}

