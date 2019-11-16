/*
ID: bilinme1
LANG: C
TASK: milk
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
typedef struct farmers
{
	int cost;
	int unit;
}farmer;

int cmp(const void *p, const void *q)  
{ 
    int l = ((struct farmers *)p)->cost; 
    int r = ((struct farmers *)q)->cost;  
    return (l - r); 
} 
main()
{
	FILE * fp1=fopen("milk.in","r");
	FILE * fp2=fopen("milk.out","w");
	int K,MUnit,MFarmer,totalCost=0;
	fscanf(fp1,"%d %d",&MUnit,&MFarmer);
	farmer farmerArr[MFarmer];
	for(K=0;K<MFarmer;K++)
	{
		fscanf(fp1,"%d %d",&farmerArr[K].cost,&farmerArr[K].unit);
	}
	qsort((farmer*)farmerArr, MFarmer, sizeof(farmerArr[0]), cmp); 
	for(K=0;K<MFarmer;K++)
	{		
		
		if(MUnit-farmerArr[K].unit>=0)
		{
			totalCost+=farmerArr[K].cost*farmerArr[K].unit;
			MUnit-=farmerArr[K].unit;		
		}
		else
		{
			totalCost+=farmerArr[K].cost*MUnit;
			MUnit=0;
			break;
		}									
	}
	fprintf(fp2,"%d\n",totalCost);
	fclose(fp1);
	fclose(fp2);
	exit(0);
	
	
	
	
}
