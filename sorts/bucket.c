#include<stdio.h>
#include<stdlib.h>

void isort(int *,int);

int main()
{
	  int *a,n,i,j,h,l,buc,p;
	  printf("Enter Size :");
	  scanf("%d",&n);
	  printf("\nEnter Range l and h :");
	  scanf("%d %d",&l,&h);
	  printf("\nEnter No of buckets :");
	  scanf("%d",&buc);
	  int interval = (h-l)/buc;
	  int *b[buc],count[buc];
	  for(i=0;i<buc;i++)
	  {
		    count[i]=0;
	  }
	  printf("\nEnter Elements :");
	  a=(int *)malloc(sizeof(int)*n);
	  for(i=0;i<n;i++)
	  {
		    scanf("\n%d",&a[i]);
	  }
	  for(i=0;i<buc;i++)
	  {
		    b[i]=(int*)malloc(interval*sizeof(int));
	  }
	  for(i=0;i<buc;i++)
	  {
		    for(j=0;j<interval;j++)
		    {
			      b[i][j]=0;
		    }
	  }
	  for(i=0;i<n;i++)
	  {
		    p=a[i]/interval;
		    b[p][count[p]]=a[i];
		    count[p]++;
	  }
	  for(i=0;i<buc;i++)
	  {
		    isort(&b[i][0],interval);
	  }
	  printf("\nSorted Elements are :");
	  for(i=0;i<buc;i++)
	  {
		    for(j=0;j<interval;j++)
		    {
			      if(b[i][j]!=0)
			      printf("  %d  ",b[i][j]);
		    }
	  }
}

void  isort(int *a,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		j=i;
		while(a[j]<a[j-1] && j>0)
		{
			temp=a[j-1];
			a[j-1]=a[j];
			a[j]=temp;
			j--;
		}
	}
}
