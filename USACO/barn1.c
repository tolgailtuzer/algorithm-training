/*
ID: bilinme1
LANG: C
TASK: barn1
*/
#include<stdio.h>
#include<limits.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}
int min(int a,int b)
{
	return (a<b)?(a):(b);
}
main()
{
	FILE *fp1=fopen("barn1.in","r");
	FILE *fp2=fopen("barn1.out","w");
	int M,S,C,k,l,max=INT_MIN,ind;
	fscanf(fp1,"%d %d %d",&M,&S,&C);
	int cows[C];
	int dist[C-1];	
	for(k=0;k<C;k++)
	{
		fscanf(fp1,"%d",&cows[k]);
	}
	qsort(cows,C,sizeof(int),cmpfunc);
	for(k=0;k<C-1;k++)
	{
		dist[k]=cows[k+1]-cows[k]+1;
	}
	int count=0;
	/*for(k=0;k<C;k++)
	{
		printf("%d ",cows[k]);
	}
	printf("\n");
	for(k=0;k<C-1;k++)
	{
		printf("%d ",dist[k]);
	}*/
	int m=min(C-1,M-1);
	int index[m];
	for(k=0;k<m;k++)
	{
		max=INT_MIN;
		for(l=0;l<C-1;l++)
		{
			if(dist[l]>max)
			{
				max=dist[l];
				ind=l;
			}
		}
		dist[ind]=0;
		index[count]=ind;
		count++;
	}
	int result=0;
	l=0;
	qsort(index,m,sizeof(int),cmpfunc);	
	/*printf("\n");
	for(k=0;k<m;k++)
	{
		printf("%d ",index[k]);
	}
	printf("\n");*/
	for(k=0;k<m;k++)
	{
		result+=cows[index[k]]-cows[l]+1;
		l=index[k]+1;	
	}
	result+=cows[C-1]-cows[l]+1;
	//printf("%d\n",result);
	fprintf(fp2,"%d\n",result);
	
	fclose(fp1);
	fclose(fp2);
	exit(0);
}
