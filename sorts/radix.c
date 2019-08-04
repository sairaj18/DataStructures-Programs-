#include<stdio.h>
#include<stdlib.h>
int a[10][100],*b,num;
void main()
{	
	int max=0,t=0,count[10],u,i,j,k,temp;
	for(i=0;i<10;i++)
	{
		for(j=0;j<100;j++)
		{
			a[i][j]=0;
		}
	}
	for(i=0;i<10;i++)
	{
		count[i]=0;
	}
	printf("Enter the number of elements you are entering :");
	scanf("%d",&num);
	b=(int *)malloc(sizeof(int)*num);
	for(i=0;i<num;i++)
	{
		printf("Enter number :");
		scanf("%d",&b[i]);
		max=b[i]>max?b[i]:max;
	}
	while(max!=0)
	{
		max/=10;
		t++;
	}
	for(i=1;i<=t;i++)
	{
		for(j=0;j<num;j++)
		{
			u=b[j];
			for(int h=1;h<i;h++)
			{
				u=u/10;
			}
			temp=u%10;
			a[temp][count[temp]++]=b[j];
		}
		int m=0;
		for(j=0;j<10;j++)
		{
			for(k=0;k<count[j];k++)
			{
					b[m]=a[j][k];m++;
			}	
		}
		for(j=0;j<10;j++)
		{
			count[j]=0;
		}
	}
	printf("after sorting :");
	for(i=0;i<num;i++)
	{
		printf("%d ",b[i]);
	}
}
