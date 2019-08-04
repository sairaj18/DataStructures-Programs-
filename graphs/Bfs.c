#include<stdio.h>
#include<stdlib.h>
int check(int);
int n,**a,*q,*mark,l=0;
int main()
{
  	printf("Size ? ");
  	scanf("%d",&n);
  	a = (int**)calloc(sizeof(int*),n);
  	mark = (int*)calloc(sizeof(int),n);
  	q = (int*)calloc(sizeof(int),n);
  	for(int i=0;i<n;i++)
  	a[i] = (int*)calloc(sizeof(int),n);
  	printf("Enter Mat ");
  	int i,j,s;
  	for(i=0;i<n;i++)
  	{
  	  	for(j=0;j<n;j++)
    		{
      			scanf("%d",&a[i][j]);
    		}
   	}
   	printf("Enter Source ");
   	scanf("%d",&s);
   	mark[s]=1;
   	q[0]=s;
   	for(i=0;i<n;i++)
   	{
     		s = q[i];
     		printf("%d ",q[i]);
     		for(j=0;j<n;j++)
     		{
     		 	if(a[s][j]==1 && check(j))
       			{
         			mark[j]=1;
         			q[++l]=j;
       			}
     		}
   	}
}
int check(int p)
{
   	if(mark[p]==1)
   		return 0;
   	else
   		return 1;
}
