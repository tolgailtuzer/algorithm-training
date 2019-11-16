#include<stdio.h>

int isPrime(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)return 0;
	}
	return 1;
}

int isCircular(int x)
{
	int temp=x,d;
	int digit=log10(x);
	do
	{
		if(!isPrime(temp))return 0;
		d=temp%10;
		temp/=10;
		temp+=pow(10,digit)*d;
	}while(temp!=x);
	return 1;
}

int main()
{
	int i,count=0;
	for(i=2;i<1000000;i++)
	{
		if(isCircular(i))count++;
	}
	
	printf("%d\n",count);
}
