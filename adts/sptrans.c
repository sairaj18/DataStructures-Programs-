#include<stdio.h>
#include<stdlib.h>
struct smarray
{
	int r,c,v;
};
int main()
{
	int i,j,pb=0,ra,ca,t;
	printf("enter number of rows,columns and terms:\n");
	scanf("%d%d%d",&ra,&ca,&t);
	struct smarray *a,*b;
	a=(struct smarray *)malloc(sizeof(struct smarray)*t);
	b=(struct smarray *)malloc(sizeof(struct smarray)*t);
	for(i=0;i<t;i++)
	{
		printf("enter r,c,v:\n");
		scanf("%d%d%d",&a[i].r,&a[i].c,&a[i].v);
	}
	for(i=0;i<ca;i++)
	{
		for(j=0;j<t;j++)
		{
			if(a[j].c==i)
			{
				b[pb].r=a[j].c;
				b[pb].c=a[j].r;
				b[pb].v=a[j].v;
				pb++;
			}
		}
	}
	printf("transpose of a is:\n");
	for(i=0;i<t;i++)
	{
		printf("\nr:%d\tc:%d\tv:%d\n",b[i].r,b[i].c,b[i].v);
	}
}
