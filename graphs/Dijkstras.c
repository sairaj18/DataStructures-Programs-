#include<stdio.h>
#include<stdlib.h>
int main()
{
  	int n,i,j,s;
  	printf("Enter Size ");
  	scanf("%d",&n);
  	int a[n][n],mark[n],dist[n];
  	printf("Enter Mat ");
  	for(i=0;i<n;i++)
  	{
  	  	for(j=0;j<n;j++)
    		{
      			scanf("%d",&a[i][j]);
    		}
  	}
  	for(i=0;i<n;i++)
  	{
  	  	dist[i]=500;
    		mark[i]=0;
  	}
  	printf("ËNter Source ");
  	scanf("%d",&s);
  	mark[s] = 1;
  	dist[s] = 0;
  	for(j=0;j<n;j++)
  	{
  	  	if(a[s][j] != 0 )
    		{
      			dist[j] = a[s][j];
    		}
  	}
	for(i=0;i<n;i++)
  	{
    		int min=500,minindex;
    		for(j=0;j<n;j++)
    		{
      			if(mark[j]!=1)
      			{
        			if(dist[j]<min)
        			{
          				min=dist[j];
          				minindex = j;
        			}
      			}
    		}	
    		s = minindex;
    		mark[s]=1;
    		int k;
    		for(k=0;k<n;k++)
    		{
      			if(a[s][k]!=0)
      			{
        			if(dist[s]+a[s][k]<dist[k])
        			{
          				dist[k] = dist[s]+a[s][k];
        			}
      			}
    		}
  	}
  	printf("Shortest Distances ");
  	for(int i=0;i<n;i++)
  	{
    		printf("%d ",dist[i]);
  	}
}
