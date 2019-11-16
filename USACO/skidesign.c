/*
ID: bilinme1
LANG: C
TASK: skidesign
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
int min(int a,int b)
{
	return (a<b)?(a):(b);
}
main()
{
	FILE *fp1=fopen("skidesign.in","r");
	FILE *fp2=fopen("skidesign.out","w");
	int k,l,size,cost,totalcost=INT_MAX;
	fscanf(fp1,"%d",&size);
	int hills[size];
	for(k=0;k<size;k++)
	{
		fscanf(fp1,"%d",&hills[k]);
	}	
	for(k=0;k<=83;k++)
	{
		cost=0;
		for(l=0;l<size;l++)
		{
			if(hills[l]<k)cost+=pow((k-hills[l]),2);
			else if(hills[l]>k+17)cost+=pow((hills[l]-(k+17)),2);
		}
		totalcost=min(totalcost,cost);
	}
	fprintf(fp2,"%d\n",totalcost);
	fclose(fp1);
	fclose(fp2);
	exit(0);
}
