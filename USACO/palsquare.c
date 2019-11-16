/*
ID: bilinme1
LANG: C
TASK: palsquare
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
char symbols[]={'0', '1', '2', '3', '4', '5',
                '6', '7', '8', '9', 'A', 'B',
                'C', 'D', 'E', 'F', 'G', 'H',
                'I', 'J', 'K', 'L', 'M', 'N',
                'O', 'P', 'Q', 'R', 'S', 'T',
                'U', 'V', 'W', 'X', 'Y', 'Z'};
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
		arr[i-1]=symbols[remain[count-i]];	
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
	FILE *fp1=fopen("palsquare.in","r");
	FILE *fp2=fopen("palsquare.out","w");	
	int i,base;
	fscanf(fp1,"%d",&base);
	for(i=1;i<=300;i++)
	{
		if(isPolindrome(i*i,base))
		{
			fprintf(fp2,"%s %s\n",convertBase(i,base),convertBase(i*i,base));
		}
	}
	
}
