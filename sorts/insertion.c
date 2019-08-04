#include<stdio.h>
int main()
{
int n,j,i,*a,temp;
printf("enter size");
scanf("%d",&n);
a=(int*)malloc(sizeof(int)*n);
printf("enter array elements");
for(i=0;i<n;i++)
scanf("%d",a+i);
for(i=0;i<n;i++)
{
j=i;
while(a[j]<a[j-1] && j>0)
{
temp
=a[j-1];
a[j-1]=a[j];
a[j]=temp;
j--;
}
}
for(i=0;i<n;i++)
printf("%d\n",*(a+i));
}
