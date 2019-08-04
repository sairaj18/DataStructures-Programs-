#include<stdio.h>
#include<stdlib.h>
void insert(int *);
void delete(int *);
void display(int *);
void min_max(int *);
int size,f=1,l,i,j,k;
int main()
{		
	int *a;
	char g;
	printf("enter array size");
	scanf("%d",&size);
	a=(int*)malloc(sizeof(int)*size);
	for(i=0;i<size;i++)
	a[i]=-1;
	while(f)
	{
		printf("enter the following charaters to perform following operations:\n");
		printf("1.insert 2.delete 3.display 4.min_max 5.exit as x,y,z,w,n respectively:\n");
		scanf("%c",&g);
		switch(g)
		{
			case 'x':insert(a);break;
			case 'y':delete(a);break;
			case 'z':display(a);break;
			case 'w':min_max(a);break;
			case 'n':f=0;break;
			default :
				printf("enter the given numbers only\n");
		}
	}
}
void insert(int *a)
	{

		int q;
		printf("enter the location at which you want to insert element\n");
		scanf("%d",&l);
			if(l<size)
			{
				if(a[l]==-1)
				{
					printf("enter the array element to be insterted in %d location\n",l);
					scanf("%d",a+l);
				}
				else
				{
					printf("the given location is not empty\n");
					printf("enter the below given characters\n");
					printf("1.replace 2.move as 6,7 respectively\n");
					scanf("%d",&q);
					switch(q)
					{
						case 6:
							printf("enter the new element to be inserted at %d location\n",l);
							scanf("%d",a+l);
							break;
						case 7:
							a=(int*)realloc(a,(size+1)*sizeof(int));
							size+=1;
							for(i=size-1;i>l;i--)
							a[i]=a[i-1];
							printf("enter the new element to move the already existing elements \n");		
							scanf("%d",a+l);
							break;
						default:
							printf("enter the above mentioned numbers only\n");
					}

				}

			}
			else
			{
				printf("location not found\n");
			}
	}
void delete(int *a)
	{       
    		int h,key;
		printf("enter the following characters\n");
		printf("8.key 9.location as 8,9 respectively\n");
		scanf("%d",&h);
		switch(h)
		{
			case 8:
			printf("enter the key to delete\n");
			scanf("%d",&key);
				for(i=0;i<size;i++)
				{
					if(key==a[i])
					a[i]=-1;
				}
			break;	
			case 9:
			printf("enter the location of the element to be deleted\n");
			scanf("%d",&l);
			a[l]=-1;
			break;
			default:
			printf("enter the above given numbers\n");
		}
	}
void display(int *a)
	{
		for(i=0;i<size;i++)
		printf("%d\n",*(a+i));
	}
void min_max(int *a)
	{
		int min=a[0],max=a[0];
			for(i=1;i<size;i++)
			{
				if(a[i]<min && a[i]!=-1)
				min=a[i];
				if(a[i]>max)
				max=a[i];
			}		
		
		printf("min:%d max:%d",min,max);			
	}
