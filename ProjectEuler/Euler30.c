#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<stdbool.h>
bool isOk(int x)
{
	int i,temp=x,sum=0;
	int digit=log10(x)+1;
	for(i=0;i<digit;i++)
	{
		sum+=pow(temp%10,5);
		temp/=10;
	}
	if(sum==x)return true;
	else return false;
}
int main()
{
	int i,low=2,up=pow(9,5)*5,sum=0;
	for(i=low;i<=up;i++)
	{
		if(isOk(i))sum+=i;
	}
	printf("%d\n",sum);
}
