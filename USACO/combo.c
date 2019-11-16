/*
ID: bilinme1
LANG: C
TASK: combo
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
int comCount=0;
int setCounter=0;
int maxIndex=INT_MIN;
void fillArr(int comCur,int nArr[comCount][5],int digitSize)
{
	int L;
	int temp=comCur;
	nArr[comCount][2]=comCur;
	for(L=3;L<5;L++)
	{
		if(temp==digitSize)temp=1;
		else temp++;		
		nArr[comCount][L]=temp;
	}
	temp=comCur;
	for(L=1;L>=0;L--)
	{		
		if(temp==1)temp=digitSize;
		else temp--;
		nArr[comCount][L]=temp;
	}
	comCount++;
	
}

void findSet(int digitSet[comCount][5],int set1[],int temp[],int k)
{
	int i,j;
    if(k == 3)
	{	
		int base=1;
		set1[setCounter]=0;	
		for(i=0;i<k;i++)
		{
			set1[setCounter]=(set1[setCounter]*pow(10,(int)(log10(temp[i])+1)))+temp[i];
			if(set1[setCounter]>maxIndex)maxIndex=set1[setCounter];
			//printf("%d ",temp[i]);
		}	
		//printf("\n");			
		setCounter++;	
		
	}					       
	else 
	{            
        for(j = 0; j < 5; j++) 
		{			
            temp[k] =digitSet[k][j];
            findSet(digitSet, set1,temp, k + 1);
        }       
    }
}

int searchArr(int arr1[],int arr2[])
{
	int K,L,result=0;
	for(K=0;K<125;K++)
	{
		for(L=K+1;L<125;L++)
		{
			if(arr1[K]==arr1[L])arr1[L]=0;
			if(arr2[K]==arr2[L])arr2[L]=0;	
		}
	}
	for(K=0;K<125;K++)
	{
		if(arr1[K]!=0)result++;
		for(L=0;L<125;L++)
		{			
			if(arr1[K]==arr2[L])
			{
				arr2[L]=0;
			}
		}
	}
	for(K=0;K<125;K++)
	{
		if(arr2[K]!=0)result++;
	}
	return result;
}
main()
{
	FILE * fp1=fopen("combo.in","r");
	FILE * fp2=fopen("combo.out","w");
	int K,L,digitSize,resultCount=1;
	fscanf(fp1,"%d",&digitSize);
	int farmerCom[3];
	int masterCom[3];
	int C1[3][5]={};
	int C2[3][5]={};
	int temp[5];
	fscanf(fp1,"%d %d %d",&farmerCom[0],&farmerCom[1],&farmerCom[2]);
	fscanf(fp1,"%d %d %d",&masterCom[0],&masterCom[1],&masterCom[2]);
	
	for(K=0;K<3;K++)fillArr(farmerCom[K],C1,digitSize);
	int result1[125];
	findSet(C1,result1,temp,0);
	comCount=0;
	setCounter=0;
	for(K=0;K<3;K++)fillArr(masterCom[K],C2,digitSize);
	int result2[125];
	findSet(C2,result2,temp,0);
	resultCount=searchArr(result1,result2);
	/*int *searchUni=calloc(maxIndex+1,sizeof(int));
	printf("%d",maxIndex);
	for(K=0;K<125;K++)
	{
		searchUni[result1[K]]++;
		searchUni[result2[K]]++;
	}
	for(K=0;K<maxIndex+1;K++)
	{
		if(searchUni[K]>0)
		{
			resultCount++;
		}
	}*/
	fprintf(fp2,"%d\n",resultCount);
	fclose(fp1);
	fclose(fp2);
	exit(0);
	
}
