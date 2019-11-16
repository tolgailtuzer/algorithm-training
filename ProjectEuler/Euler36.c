#include<stdio.h>
int digits[20];
int castBase2(int x)
{
	int res=0,count=0,i;
	while(x!=0)
	{
		digits[count]=x%2;
		x/=2;
		count++;
	}
	for(i=0;i<count/2;i++)
	{
		if(digits[i]!=digits[count-i-1])return 0;
	}
	return 1;
}

int isPalindrome(int x)
{
	int temp=x,neN=0;
	while(temp>0)
	{	
		neN=neN*10+temp%10;
		temp/=10;
	}
	if(neN==x)return 1;
	else return 0;	
}

int main()
{
	int i,sum=0;
	
	for(i=1;i<1000000;i++)
	{
		if(isPalindrome(i) && castBase2(i))
		{
			printf("%d %d\n",i,castBase2(i));
			sum+=i;
		}
	}
	
	printf("%d\n",sum);
}
