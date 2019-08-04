#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 99999
int n,**a;
int main() 
{
    	char num[20];
    	printf("Ente the Num Of Nodes : ");
    	scanf("%d",&n);
    	a = (int**)malloc(sizeof(int*)*n);
    	for(int i=0;i<n;i++)
        a[i]=(int *)malloc(sizeof(int)*n);
    	printf("Enter the adjacency matrix \\ Enter 'i' for infinity\\");
    	for(int i=0;i<n;i++)
    	{
        	for(int j=0;j<n;j++)
        	{
            		scanf("%s",num);
            		if(strcmp(num,"i") == 0)
            		{
                		a[i][j]=INF;
            		}
            		else
            		{
            		    	a[i][j]=atoi(num);
           	 	}
        	}
    	}
    	int i,j,k;
    	for(k=0;k<n;k++)
    	{
    	    	for(i=0;i<n;i++)
        	{
            		for(j=0;j<n;j++)
            		{
                    		a[i][j]= a[i][j] < (a[i][k] + a[k][j]) ? a[i][j] : (a[i][k] + a[k][j]);
            		}
        	}
    	}
	printf("The shortest Paths are\n");
	for(int i=0;i<n;i++)
    	{
        	for(int j=0;j<n;j++)
        	{
            		if(a[i][j]>=INF)
            		{
                		printf("INF ");
            		}
            		else
            		{
                		printf("%d ",a[i][j]);
            		}
        	}
        	printf("\n");
    	}
}
