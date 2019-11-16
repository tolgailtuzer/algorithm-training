#include<stdio.h>
int factorial(int x)
{
	int i,res=1;
	for(i=2;i<=x;i++)
	{
		res*=i;	
	}
	return res;
}
int isCurious(int x)
{
	int digit=log10(x)+1,i,temp=x,sum=0;
	for(i=0;i<digit;i++)
	{
		sum+=factorial(temp%10);
		temp/=10;
	}
	if(sum==x)return 1;
	else return 0;
}
int main()
{
	int i,j,sum=0;
	
	for(i=3;i<100000;i++)
	{
		if(isCurious(i))sum+=i;
	}
	
	printf("%d\n",sum);
}
