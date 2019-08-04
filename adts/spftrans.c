#include<stdio.h>
#include<stdlib.h>
struct smarray
{
	int r,c,v;
};
int main()
{
	int i,j,pb,ra,ca,t;
	printf("enter number of rows,columns and terms:\n");
	scanf("%d%d%d",&ra,&ca,&t);
	struct smarray *a,*b;
	int *rowsize,*rowstart;
a=(struct smarray *)malloc(sizeof(struct smarray)*t);
b=(struct smarray *)malloc(sizeof(struct smarray)*t);
rowsize=(int *)calloc(sizeof(int),ca);
rowstart=(int *)malloc(sizeof(int)*ca);	
	for(i=0;i<t;i++)
	{
		printf("enter r,c,v:\n");
		scanf("%d%d%d",&a[i].r,&a[i].c,&a[i].v);
	}
	for(i=0;i<t;i++)
	{	
		rowsize[a[i].c]+=1;
	}
rowstart[0]=0;
	for(i=1;i<ca;i++)
	{
		rowstart[i]=rowstart[i-1]+rowsize[i-1];
	}
	for(i=0;i<t;i++)
		{
			pb=rowstart[a[i].c];
			b[pb].r=a[i].c;
			b[pb].c=a[i].r;
			b[pb].v=a[i].v;
			rowstart[a[i].c]+=1;
			
		}
printf("transpose of a is:\n");
	for(i=0;i<t;i++)
	{
		printf("\nr:%d\tc:%d\tv:%d\n",b[i].r,b[i].c,b[i].v);
	}
}
