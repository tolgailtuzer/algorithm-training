#include<stdio.h>
#include<math.h>
main()
{
	int K;
	int result=1;
	int primes[8]={2,3,5,7,11,13,17,19};
	for(K=0;K<8;K++)
	{		
		result*=pow((primes[K]),(int)(log(20)/log(primes[K])));
	}
	printf("%d",result);
}
