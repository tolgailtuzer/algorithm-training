/*
ID: bilinme1
LANG: C
TASK: ariprog
*/

#include<stdio.h>
#include<math.h>
int numbers[180000],isIN[180000];//250*250*2 125000 YETERLÝ

int cmpfunc (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
	int N,M,i,j,k,countN=0;
	FILE * fp1=fopen("ariprog.in","r");
	FILE * fp2=fopen("ariprog.out","w");
	fscanf(fp1,"%d%d",&N,&M);
	
	for(i=0;i<=M;i++)
	{
		for(j=0;j<=M;j++)
		{
			if(isIN[i*i+j*j]==0)
			{
				numbers[countN]=i*i+j*j;
				isIN[i*i+j*j]=1;
				countN++;
			}
		}
	}
	
	qsort(numbers,countN, sizeof(int), cmpfunc);
	
	int limit=(2*pow(M,2))/(N-1);
	int count=0,check;
	int isK=1;
	for(i=1;i<=limit;i++)
	{
		for(j=0;j<countN;j++)
		{
			check=numbers[j];
			for(k=0;k<N && check<2*pow(M,2)+1;k++)
			{
				check+=i;
				if(isIN[check]==1)count++;
				else break;
			}
			
			if(count>=N-1)
			{
				fprintf(fp2,"%d %d\n",numbers[j],i);
				isK=0;
			}
			count=0;		
		}
	}
	if(isK)fprintf(fp2,"NONE\n");
	
}
