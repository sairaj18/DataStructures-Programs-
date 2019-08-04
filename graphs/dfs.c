#include<stdio.h>
#include<stdlib.h>

void dfs(int);
int check(int);

int **a,n,*mark;

int main()
{
  	printf("Enter Vertices ");
  	scanf("%d",&n);
  	a = (int**)malloc(sizeof(int*)*n);
  	mark = (int*)calloc(sizeof(int),n);
  	for(int i=0;i<n;i++)
  	a[i] = (int*)malloc(sizeof(int)*n);
  	int i,j,s;
  	printf("ENter Mat\n");
  	for(i=0;i<n;i++)
  	{
  	  	for(j=0;j<n;j++)
    		{
      			scanf("%d",&a[i][j]);
    		}
  	}
  	printf("Source ? ");
  	scanf("%d",&s);
  	mark[s]=1;
  	dfs(s);
}
void dfs(int s)
{
  	printf("%d ",s);
  	int j;
  	for(j=0;j<n;j++)
  	{
    		if(a[s][j]==1 && check(j))
    		{
      			mark[j]=1;
      			dfs(j);
    		}
  	}	
}
int check(int p)
{
  	if(mark[p]==0)
  		return 1;
  	else
  		return 0;
}
