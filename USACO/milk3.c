/*
ID: bilinme1
LANG: C
TASK: milk3
*/
#include<stdio.h>
typedef struct bottles
{
	int c[3];
}bottle;

int isOk[21];
int isSeen[21][21][21];
int capacity[3];
bottle init(int A,int B,int C)
{
	bottle nb;
	nb.c[0]=A;
	nb.c[1]=B;	
	nb.c[2]=C;	
	return nb;	
}

bottle fill(bottle a,int from,int to)
{
	
	int val;
	val=a.c[from];
	if(a.c[to]+val>capacity[to])val=capacity[to]-a.c[to];	
	a.c[to]+=val;
	a.c[from]-=val;
	return a;
}

void solve(bottle a)
{
	int i,j;
	if(isSeen[a.c[0]][a.c[1]][a.c[2]])
	{
		return;
	}
	
	isSeen[a.c[0]][a.c[1]][a.c[2]]=1;
	
	if(!a.c[0])isOk[a.c[2]]=1;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			solve(fill(a,i,j));		
		}
	}
	
}

main()
{
	FILE *fp1=fopen("milk3.in","r");
	FILE *fp2=fopen("milk3.out","w");
	int i;
	fscanf(fp1,"%d%d%d",&capacity[0],&capacity[1],&capacity[2]);
	solve(init(0,0,capacity[2]));
	char * bosluk="";
	for(i=0;i<21;i++)
	{
		if(isOk[i])
		{						
			fprintf(fp2,"%s%d",bosluk,i);
			bosluk=" ";				
		}
	}
	fprintf(fp2,"\n");
	
	fclose(fp1);
	fclose(fp2);
	exit(0);
	
}
