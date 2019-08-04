#include<stdio.h>
#include<stdlib.h>

void merge_sort(int *,int,int);
void combine(int *,int,int,int);

int main()
{
	int l,h,n,i,*a,temp;
	printf("enter size");
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	printf("enter array elements");
	for(i=0;i<n;i++)
	scanf("%d",a+i);
	l=0;
	h=n-1;
	merge_sort(a,l,h);
	printf("after sorting");
	for(i=0;i<n;i++)
	printf("%d",*(a+i));
}
void merge_sort(int *a,int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,h);
		combine(a,l,m,h);
	}
}
void combine(int *a,int l,int m,int h)
{
	int *x,*y,lx,ly,px=0,py=0,pa=l,j=0,i;
	lx=m-l+1;
	ly=h-m;
	x=(int*)malloc(sizeof(int)*lx);
	y=(int*)malloc(sizeof(int)*ly);
	for(i=l;i<=m;i++)
	{
		x[j++]=a[i];
	}
	j=0;
	for(i=m+1;i<=h;i++)
	{
		y[j++]=a[i];
	}
	while(px<lx && py<ly)
	{
		if(x[px]>y[py])
		{
			a[pa++]=y[py++];
		}
		if(x[px]<y[py])
		a[pa++]=x[px++];
	}
	while(px<lx)
	a[pa++]=x[px++];
	while(py<ly)
	a[pa++]=y[py++];
}
