#include<stdio.h>
#include<stdlib.h>
long long max(long long a,long long b)
{
	return (a>b)?(a):(b);
}
main()
{
	char *arr=calloc(1000,sizeof(char));
	FILE *fp1=fopen("data.txt","r");
	
	int K,L,M,N;
	long long sum,maxN=INT_MIN;
	
	fscanf(fp1,"%s",arr);
		
	for(K=0;K<1000-13;K++)
	{	
		sum=1;
		for(L=K;L<K+13;L++)
		{
			
			sum*=(int)arr[L]-48;
		}
		maxN=max(maxN,sum);
	}
					
	printf("%lld",maxN);
	
}
