/*
ID: bilinme1
LANG: C
TASK: numtri
*/
#include<stdio.h>

main()
{
	FILE *fp1=fopen("numtri.in","r");
	FILE *fp2=fopen("numtri.out","w");
	int n,i,j;
	fscanf(fp1,"%d",&n);
	int numbers[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<i+1;j++)
		{
			fscanf(fp1,"%d",&numbers[i][j]);
		}
	}
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(numbers[i][j]+numbers[i-1][j]>numbers[i][j+1]+numbers[i-1][j])numbers[i-1][j]+=numbers[i][j];
			else numbers[i-1][j]+=numbers[i][j+1];
		}		
	}
	fprintf(fp2,"%d\n",numbers[0][0]);
}
