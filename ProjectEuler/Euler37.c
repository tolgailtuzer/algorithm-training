#include<stdio.h>

int isPrime(int x)
{
	int i;
	if(x<2)return 0;
	for(i=2;i<=sqrt(x);i++)
	{		
		if(x%i==0)return 0;
	}
	return 1;
}
int checkLTR(int x)
{
	int digit=log10(x)+1;
	while(x>0)
	{
		if(!isPrime(x))return 0;		
		x%=(int)pow(10,digit-1);
		digit--;
	}
	return 1;
}

int checkRTL(int x)
{
	while(x>0)
	{
		if(!isPrime(x))return 0;
		x/=10;
	}
	return 1;
}

int main()
{
	int i,counter=0,sum=0;
	
	for(i=10;i<1000000;i++)
	{
		if(checkLTR(i) && checkRTL(i))
		{
			sum+=i;
			printf("%d\n",i);
			counter++;
		}
		if(counter==11)break;
	}
	
	printf("sum=%d\n",sum);
}
