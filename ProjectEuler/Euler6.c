#include<stdio.h>
#include<math.h>
main()
{
	int n=100;
	int result1=pow((n*(n+1))/2,2);
	int result2=(n*(n+1)*(2*n+1))/6;
	printf("%d",result1-result2);
}
