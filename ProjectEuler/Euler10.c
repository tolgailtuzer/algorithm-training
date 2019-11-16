#include<stdio.h>
#include<stdbool.h>
#include<math.h>
/*bool isPrime(int a)
{
	int L;
	if(a%2!=0)
	{
		for(L=2;L<=sqrt(a);L++)
		{
			if(a%L==0 || a%(L+2)==0)
			{
				return false;
			}
		}
		return true;			
	}
	else return false;	
}*/



main()
{
	int K=2,L,number=2000000;
	long long sum=0;
	bool res[2000000+1] = {false};
	for(K=2;K<sqrt(number);K++)//SieveOfEratosthenes
	{
		if(res[K]==false)
		{
			for(L=K*K;L<number;L+=K)
			{
				res[L]=true;
			}
		}
	}
	for(K=2;K<=number;K++)
	{
		if(res[K]==false)sum+=K;
	}
	printf("%lld",sum);
}
