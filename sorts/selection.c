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
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
temp=a[j];
a[j]=a[i];
a[i]=temp;
}
}
}
for(i=0;i<n;i++)
printf("%d",*(a+i));
}
