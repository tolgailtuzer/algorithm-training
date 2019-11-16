#include<stdio.h>
#include<stdbool.h>
main()
{
	int K,L,M,number=1000;
	bool flag=true;
	for(K=3;K<number-3 && flag;K++)
	{
		for(L=K+1;L<number-K-1 && flag;L++)
		{	
			M=number-K-L;		
			if(K*K+L*L==M*M && K+L+M==1000)
			{
				printf("%d",(K*L*M));
				flag=false;
			}
			
		}	
	}
}
