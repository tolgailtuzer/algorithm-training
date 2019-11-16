#include<stdio.h>
main()
{
	int i,f1=1,f2=2,temp,sum=0;
	while(f2<4000000)
	{
		temp=f1+f2;
		f1=f2;
		f2=temp;
		if(f1%2==0)sum+=f1;
	}
	printf("%d",sum);
}
