 /*
ID: bilinme1
LANG: C
TASK: wormhole
*/
#include<stdio.h>
#include<stdbool.h>
int pairs[13],X[13],Y[13],N,nextWH[13];
bool checkCycle()
 {
 	int i,j,pos;
 	for(i=1;i<=N;i++)
 	{
 		pos=i;
 		for(j=0;j<N;j++)
 		{
 			pos=nextWH[pairs[pos]];				
		}
		if(pos!=0)return true;
	}
	
 	return false;
 }
int check()
{
	int i,j,total=0;
	for(i=1;i<=N;i++)
	{
		if(pairs[i]==0)break;
	}
	
	if(i>N)
	{
		if(checkCycle())return 1;
		else return 0;
	}
	
	for(j=i+1;j<=N;j++)
	{
		if(pairs[j]==0)
		{
			pairs[i]=j;
			pairs[j]=i;
			total+=check();
			pairs[i]=0;
			pairs[j]=0;
		}		
	}
	return total;
}
main()
{
	FILE * fp1=fopen("wormhole.in","r");
	FILE * fp2=fopen("wormhole.out","w");
	int i,j;
	fscanf(fp1,"%d",&N);
	for(i=1;i<=N;i++)
	{
		fscanf(fp1,"%d %d",&X[i],&Y[i]);
	}
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(X[j]>X[i] && Y[i]==Y[j])
			{
				if(nextWH[i]==0 || X[j]-X[i]<X[nextWH[i]]-X[i])nextWH[i]=j;
			}
		}
	}
	fprintf(fp2,"%d\n",check());
	fclose(fp1);
	fclose(fp2);
	exit(0);	
}
