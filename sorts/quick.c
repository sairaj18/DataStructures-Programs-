#include<stdio.h>
#include<stdlib.h>
int i=0,j=0,temp=0;
void quick_sort(int *,int,int);
int main()
{
int l,h,n,*a,temp;
printf("enter size");
scanf("%d",&n);
a=(int*)malloc(sizeof(int)*n);
printf("enter array elements");
for(i=0;i<n;i++)
scanf("%d",a+i);
l=0;
h=n-1;
quick_sort(a,l,h);
printf("after sorting");
for(i=0;i<n;i++)
printf("%d",*(a+i));
}
void quick_sort(int *a,int l,int h)
{
int p;
if(l<h)
{
p=l;
for(i=p+1;i<=h;i++)
{
if(a[i]<a[p])
{
for(j=i;j>p;j--)
{
temp=a[j-1];
a[j-1]=a[j];
a[j]=temp;
}
p=p+1;
}
}
quick_sort(a,l,p-1);
quick_sort(a,p+1,h);
}
}
