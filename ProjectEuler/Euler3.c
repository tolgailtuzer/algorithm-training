#include<stdio.h>
#include<math.h>
main()
 {
 	long long i,j;
	int count=0,flag=1;
	long long n=600851475143;
 	for(i=(long)sqrt(n);i>=2;i--)
 	{
 		flag=1;
 		if(n%i==0)
		{
	 		for(j=2;j<i;j++)
	 		{
	 			if(i%j==0)
				 {
				 	flag=0;
				 	break;
				 }
			}
			if(flag==1)
			{		
				printf("%lld",i);break;			
			}
		}
		
	}
 }
