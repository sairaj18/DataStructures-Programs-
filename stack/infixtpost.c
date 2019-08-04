#include<stdio.h>
#include<stdlib.h>

int p1(char);

int main()
{
	int n,ostop=-1,rtop=-1;
	char *os,*a,*r;
	printf("enter the size of infix expression:\n");
	scanf("%d",&n);
	n++;
	a=(char *)malloc(sizeof(char)*n);
	os=(char *)malloc(sizeof(char)*n);
	r=(char *)malloc(sizeof(char)*n);
	printf("enter the infix expression:\n");
	scanf("%s",a);
	for(int i=0;a[i]!='\0';i++)
	{
		if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
		{
			r[++rtop]=a[i];
		}
		else if(ostop==-1 || a[i]=='(' || os[ostop]=='(')
		{
			os[++ostop]=a[i];
		}
		else if(a[i]==')')
		{
			while(os[ostop]!='(')
			{
				r[++rtop]=os[ostop];
				ostop--;
			}
			ostop--;
		}
		else if((p1(os[ostop])>=p1(a[i])) && a[i]!='^')
		{
			while(p1(os[ostop])>=p1(a[i]) && ostop!=-1)
			{
				r[++rtop]=os[ostop];
				ostop--;
			}
			os[++ostop]=a[i];
		}
		else
		{
			os[++ostop]=a[i];
		}
	}
	while(ostop!=-1)
	{
		r[++rtop]=os[ostop];
		ostop--;
	}
	r[++rtop] = '\0';
	printf("the postfix expression is:\n");
	printf("%s\n",r);
	free(os);
	free(r);
	free(a);
}
int p1(char c)
{
	if(c=='+' || c=='-')
	{
		return 1;
	}
	else if(c=='*' || c=='%' || c=='/')
	{
		return 2;
	}
	else
	{
		return 3;
	}
}
