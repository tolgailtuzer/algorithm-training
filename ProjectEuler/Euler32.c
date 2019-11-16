#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
int isUsed[100000];
bool checkPan(int x,int y)
{
	int m=x*y,i,temp;
	bool *check=calloc(10,sizeof(bool));
	int digit=log10(x)+1;
	for(i=0;i<digit;i++)
	{
		temp=x%10;
		if(check[temp] || temp==0)return false;
		x/=10;
		check[temp]=true;
	}
	digit=log10(y)+1;
	for(i=0;i<digit;i++)
	{
		temp=y%10;
		if(check[temp] || temp==0)return false;
		y/=10;
		check[temp]=true;
	}
	digit=log10(m)+1;
	for(i=0;i<digit;i++)
	{
		temp=m%10;
		if(check[temp] || temp==0)return false;
		m/=10;
		check[temp]=true;
	}
	for(i=1;i<10;i++)
	{
		if(!check[i])return false;
	}
	return true;
}
int main()
{
	int i,j,sum=0;;
	for(i=1;i<10000;i++)
	{
		for(j=1;j<10000;j++)
		{
			if(i!=j)
			{
				if(checkPan(i,j))
				{
				
					if(!isUsed[i*j])
					{	
						printf("%d %d %d\n",i,j,i*j);
						sum+=(i*j);
						isUsed[i*j]=1;
					}
					
				}
			}
		}
	}
	printf("%d\n",sum);
}
