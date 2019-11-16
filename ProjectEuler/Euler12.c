#include<stdio.h>
#include<stdbool.h>
#include<math.h>

main()
{
	int L;
	long long K=1,number,count,us,temp;
	int primes[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	while(true)
	{
		count=1;		
		number=(K*(K+1))/2;
		temp=number;
		for(L=0;L<25;L++)
		{
			us=0;
			while(temp%primes[L]==0)
			{
				temp/=primes[L];
				us++;				
			}
			count*=us+1;
		}
		//printf("%lld %lld\n",number,count);
		if(count>=500)
		{
			printf("%lld",number);
			break;
		}
		K++;
	}
}




