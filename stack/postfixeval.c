#include<stdio.h>
#include<stdlib.h>
char p[25],oprns[25];
int opntop=-1;

void main()
{
	printf("Enter the postfix expression :");
	scanf("%s",p);
	for(int i=0;p[i]!='\0';i++)
	{
		if(p[i]=='+' || p[i]=='-' || p[i]=='*' || p[i]=='/' || p[i]=='%' && opntop>=1)
		{
			int temp=oprns[opntop-1],tem=oprns[opntop];
			switch(p[i])
			{	
				case '+':
				oprns[--opntop]=(temp-48)+(tem-48);oprns[opntop]+=48;break;
				case '-':
				oprns[--opntop]=(temp-48)-(tem-48);oprns[opntop]+=48;break;
				case '*':
				oprns[--opntop]=(temp-48)*(tem-48);oprns[opntop]+=48;break;
				case '/':
				oprns[--opntop]=(temp-48)/(tem-48);oprns[opntop]+=48;break;
				case '%':
				oprns[--opntop]=(temp-48)%(tem-48);oprns[opntop]+=48;break;
			}	
		}
		else
		{
			oprns[++opntop]=p[i];
		}
	}
	printf("ans :%d\n",oprns[0]-48);
}
