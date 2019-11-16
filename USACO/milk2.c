/*
ID: bilinme1
LANG: C
TASK: milk2
*/
#include<stdio.h>
typedef struct members
{
	int lower;
	int upper;
}member;

int max(int a,int b)
{
	return (a>b)?(a):(b);
}

main()
{
	FILE * fp1=fopen("milk2.in","r");
	FILE * fp2=fopen("milk2.out","w");
	int lower,upper,max_time=0,max_idle=0;
	int n,i,j;
	fscanf(fp1,"%d",&n);
	member a[n];
	for(i=0;i<n;i++)
	{		
		fscanf(fp1,"%d %d",&a[i].lower,&a[i].upper);		
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j].lower>a[i].lower)
			{
				member temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}	
	lower=a[0].lower;
	upper=a[0].upper;
	max_time=upper-lower;
	for(i=1;i<n;i++)
	{
		if(a[i].lower<=upper)
		{
			upper=max(upper,a[i].upper);
			
		}
		else
		{
			max_time=max(max_time,(upper-lower));
			max_idle=max(max_idle,(a[i].lower-upper));
			upper=a[i].upper;
			lower=a[i].lower;
		}		
	}
	fprintf(fp2,"%d %d\n",max_time,max_idle);
	exit(0);
}
