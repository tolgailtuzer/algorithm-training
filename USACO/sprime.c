/*
ID: bilinme1
LANG: C
TASK: sprime
*/
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int n=0;
int sDigits[4]={2,3,5,7};
int cDigits[6]={1,2,3,5,7,9};
int digitC=0;
bool isPrime(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)return false;
	}
	return true;
}
void solve(int number,int i,FILE *fo)
{
	if((int)log10(number)+1==n)
	{
		if(isPrime(number))fprintf(fo,"%d\n",number);
		return;
	}

	for(i=0;i<6;i++)
	{
		int temp=number;
		temp*=10;
		temp+=cDigits[i];
		if(isPrime(number))solve(temp,i,fo);
		
	}
	if(number%10==number)
	{
		digitC++;
		if(digitC>=4)return;
		number=sDigits[digitC];
		solve(number,0,fo);	
	}
	
	
}

main()
{
	FILE *fp1=fopen("sprime.in","r");
	FILE *fp2=fopen("sprime.out","w");
	int N;
	fscanf(fp1,"%d",&N);
	n=N;
	solve(2,0,fp2);
	fclose(fp1);
	fclose(fp2);
	exit(0);
}
