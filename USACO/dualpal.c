/*
ID: bilinme1
LANG: C
TASK: dualpal
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
int size;         
char *convertBase(int number,int base)
{
	int remain[32];
	int nNumber=0,count=0,i;
	while(number!=0)
	{
		remain[count]=number%base;
		number=(number-remain[count])/base;
		count++;
		
	}	
	char *arr=calloc(count,sizeof(char));
	for(i=1;i<=count;i++)
	{
		arr[i-1]=remain[count-i];	
	}
	size=count;
	return arr;
}

bool isPolindrome(int number,int base)
{
	char *arr=convertBase(number,base);
	int i;
	for(i=0;i<size/2;i++)
	{
		if(arr[i]!=arr[size-1-i])return false;
	}
	return true;
}

main()
{
	FILE * fp1=fopen("dualpal.in","r");
	FILE * fp2=fopen("dualpal.out","w");
	int i,j,n,s,count1=0,count2=0;
	fscanf(fp1,"%d %d",&n,&s);
	while(true)
	{
		s++;
		count1=0;
		for(j=2;j<=10;j++)
		{
			if(isPolindrome(s,j))count1++;			
			if(count1>=2)
			{
				fprintf(fp2,"%d\n",s);
				count2++;
				break;
			}
			
		}		
		if(count2==n)break;
	}
}
