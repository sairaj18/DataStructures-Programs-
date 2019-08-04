#include<stdio.h>
#include<stdlib.h>
int i=0,j=0,pb=0;
int main()
{
int k,*c,n,*a,*b,temp;
printf("enter size");
scanf("%d",&n);
printf("enter range");
scanf("%d",&k);
a=(int*)malloc(sizeof(int)*n);
b=(int*)malloc(sizeof(int)*n);
c=(int*)calloc(sizeof(int),k);
printf("enter array elements");
for(i=0;i<n;i++)
scanf("%d",a+i);
for(i=0;i<n;i++)
{
c[a[i]]++;
printf("%d",c[a[i]]);
}
for(i=0;i<n;i++)
{
if(c[i]!=0)
b[pb++]=i;
}
printf("after sorting");
for(i=0;i<n;i++)
printf("%d",*(b+i));
}
