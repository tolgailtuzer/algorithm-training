#include<stdio.h>
main()
{
	int n=999;
	int a=n/3,b=n/5,c=n/15;
	int result=(3*((a*(a+1))/2))+(5*((b*(b+1))/2))-(15*((c*(c+1))/2));
	printf("%d",result);
}
