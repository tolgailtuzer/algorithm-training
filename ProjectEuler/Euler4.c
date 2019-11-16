#include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool isPalindrome(int i)
{
	int orNumber=i;
	int polNumber;
	int count;	
	while(i>0)
	{
		count=i%10;
		polNumber=polNumber*10+count;
		i/=10;
	}
	if(orNumber==polNumber)return true;
	else return false;
}
main()
{
	int K,L;
	bool flag=true;
	for(K=999;K>=100 && flag;K--)
	{	
		for(L=999;L>=100 && flag;L--)
		{
			int temp=K*L;
			if(isPalindrome(temp))
			{
				printf("%d\n",temp);
				flag=false;
			}
		}
	}

}
