/*
ID: bilinme1
LANG: C
TASK: crypt1
*/
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int setCounter=0;
void findSet(int digitSet[],int set1[],int temp[],int len,int k,int setSize)
{
	int i,j;
    if(k == setSize)
	{	
		int base=1;
		set1[setCounter]=0;	
		for(i=k-1;i>=0;i--)
		{
			set1[setCounter]+=temp[i]*base;
			base*=10;
		}				
		setCounter++;	
		
	}					       
	else 
	{            
        for(j = 0; j < len; j++) 
		{			
            temp[k] =digitSet[j];
            findSet(digitSet, set1,temp,len, k + 1,setSize);
        }       
    }
}
bool check(int digitSet[],int lenSet,int number)
{
	int K;
	bool flag=false;
	while(number>0)
	{
		flag=false;
		for(K=0;K<lenSet;K++)
		{
			if(number%10==digitSet[K])flag=true;
		}
		if(!flag)return false;
		number/=10;		
	}
	return true;
}
main()
{
	FILE * fp1=fopen("crypt1.in","r");
	FILE * fp2=fopen("crypt1.out","w");
	int K,L,setCount,temp,mult,sumProb=0;
	fscanf(fp1,"%d",&setCount);
	int digitSet[setCount];
	for(K=0;K<setCount;K++)
	{
		fscanf(fp1,"%d",&digitSet[K]);
	}
	int set1Len=pow(setCount,3);
	int set2Len=pow(setCount,2);
	int set1[set1Len];
	int set2[set2Len];
	int temp1[3];
	int temp2[2];
	findSet(digitSet,set1,temp1,setCount, 0,3);
	setCounter=0;
	findSet(digitSet,set2,temp2,setCount, 0,2);
	bool flag;
	for(K=0;K<set1Len;K++)
	{
		for(L=0;L<set2Len;L++)
		{
			flag=true;
			temp=set2[L];
			
			while(temp>0)
			{
				mult=set1[K]*(temp%10);			
				if((int)log10(mult)+1>3)
				{
					flag=false;
					break;
				}
				flag=flag&check(digitSet,setCount,mult);
				temp/=10;
			}
			mult=set1[K]*set2[L];			
			flag=flag&check(digitSet,setCount,mult);
			if(flag)
			{
				sumProb++;	
			}	
		}
	}
	fprintf(fp2,"%d\n",sumProb);
	fclose(fp1);
	fclose(fp2);
	exit(0);
	
	
	
	
}
