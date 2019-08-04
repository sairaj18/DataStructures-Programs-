#include<stdio.h>
#include<stdlib.h>
struct smarray
{
	int r,c,v;
};
int main()
{
	int i,j,ra,ca,rb,cb,ta,tb,pa=0,pb=0,pc=0;
printf("enter number of rows,columns and terms in a:\n");
scanf("%d%d%d",&ra,&ca,&ta);
printf("enter number of rows,columns and terms in b:\n");
scanf("%d%d%d",&rb,&cb,&tb);
struct smarray *a,*b,*c;
a=(struct smarray *)malloc(sizeof(struct smarray)*ta);
b=(struct smarray *)malloc(sizeof(struct smarray)*tb);
c=(struct smarray *)malloc(sizeof(struct smarray)*(ta+tb));
	for(i=0;i<ta;i++)
	{
		printf("enter r,c,v for matrix a:\n");
		scanf("%d%d%d",&a[i].r,&a[i].c,&a[i].v);
	}
	for(i=0;i<tb;i++)
	{
		printf("enter r,c,v for matrix b:\n");
		scanf("%d%d%d",&b[i].r,&b[i].c,&b[i].v);
	}
	for(i=0;i<ta+tb;i++)
	{
		if(a[i].r==b[i].r)
		{
			if(a[i].c>b[i].c)
			{
				c[pc].r=b[pb].r;
				c[pc].c=b[pb].c;
				c[pc].v=b[pb].v;
				pc++;
				pb++;
			}
			else if(a[i].c<b[i].c)
			{
				c[pc].r=a[pa].r;
				c[pc].c=a[pa].c;
				c[pc].v=a[pa].v;
				pc++;
				pa++;
			}
			else
			{

				c[pc].r=a[pa].r;
				c[pc].c=a[pa].c;
				c[pc].v=a[pa].v+b[pb].v;
				pc++;
				pa++;
				pb++;
			}
		}
		else if(a[i].r>b[i].r)
		{
			c[pc].r=b[pb].r;
			c[pc].c=b[pb].c;
			c[pc].v=b[pb].v;
			pc++;
			pb++;
		}
		else 
		{
			c[pc].r=a[pa].r;
			c[pc].c=a[pa].c;
			c[pc].v=a[pa].v;
			pc++;
			pa++;
		}		
	}
while(pa<ta)
{
	c[pc].r=a[pa].r;
	c[pc].c=a[pa].c;
	c[pc].v=a[pa].v;
	pc++;
	pa++;
}
while(pb<tb)
{
	c[pc].r=b[pb].r;
	c[pc].c=b[pb].c;
	c[pc].v=b[pb].v;
	pc++;
	pb++;
}
printf("matrix a + matrix b:\n");
	for(i=0;i<ta+tb;i++)
	{
		printf("\nr:%d\tc:%d\tv:%d\n",c[i].r,c[i].c,c[i].v);
	}
}
