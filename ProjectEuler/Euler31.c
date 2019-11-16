#include<stdio.h>
#include<stdbool.h>
int arr[8][201];
main()
{
	
	int value[]={1,2,5,10,20,50,100,200};
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<201;j++)
		{
			if(j<value[i])
			{
				if(i-1<0)arr[i][j]=value[i];
				else arr[i][j]=arr[i-1][j];
			}
			else
			{
				if(i-1<0)arr[i][j]=value[i];
				else arr[i][j]=arr[i-1][j]+arr[i][j-value[i]];
			}
		}
	}
	printf("%d\n",arr[7][200]);
	
	
	
	
}
