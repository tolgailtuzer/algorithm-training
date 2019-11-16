#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
int checkPan(int x)
{
	int i,temp;
	int *check=calloc(10,sizeof(int));
	int digit=log10(x)+1;
	for(i=0;i<digit;i++)
	{
		temp=x%10;
		if(check[temp] || temp==0)return 0;
		x/=10;
		check[temp]=1;
	}
	for(i=1;i<10;i++)
	{
		if(!check[i])return 0;
	}
	return 1;
}
int addPan(int x,int y)
{
	int digit=log10(y)+1;
	x*=pow(10,digit);
	x+=y;
	return x;
}
int main()
{
	int i,j,sum=0,max=-1,digit,number,gAdd;
	for(i=1;i<1000000;i++)
	{
		digit=0;
		number=0;
		j=1;
		while(digit<10)
		{
			number=addPan(number,i*j);
			j++;
			digit=log10(number)+1;
			gAdd=log10(i*j)+1;
			if(digit+gAdd>9)break;
			//printf("%d %d %d\n",number,digit,j);
		}
		//printf("%d\n",number);
		if(checkPan(number))
		{
			if(number>max)max=number;
			//printf("%d\n",number);
		}
	}
	printf("%d\n",max);
}
