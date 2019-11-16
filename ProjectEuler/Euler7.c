#include<stdio.h>
#include<stdbool.h>
#include<math.h>
main()
{
	int K=2,L,count=0;
	bool isPrime=true;
	while(true)
	{
		isPrime=true;
		for(L=2;L<=sqrt(K);L++)
		{
			if(K%L==0)isPrime=false;
		}
		if(isPrime)count++;	
		if(count==10001)
		{
			printf("%d",K);
			break;
		}
		K++;
	}
}
