#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
	long long K,L,number=1000000,chain,maxStartNumber,maxChain=INT_MIN;
	for(K=number;K>=0;K--)
	{
		
		L=K;
		chain=0;
		while(L>1)
		{
			if(L%2==0)
			{
				L/=2;
				chain++;
			}
			else if(L%2==1)
			{
				L=3*L+1;
				chain++;
			}
		}
		if(L==1)
		{
			if(chain>maxChain)
			{
				maxChain=chain;
				maxStartNumber=K;
			}			
		}
	}
	
	printf("%lld",maxStartNumber);
}
