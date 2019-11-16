/*
ID: bilinme1
LANG: C
TASK: frac1
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct number
{
    double val;
    char *out;
}num;

int cmp (const void * a, const void * b)
{

  num *numA = (num *)a;
  num *numB = (num *)b;

  return (numA->val > numB->val)?1:0;
}

bool isInList(double a,num *arr,int n)
{
  int i;
  for(i=0;i<n*n;i++)
  {
    if(arr[i].val==a)return true;
  }
  return false;
}
int main()
{
	FILE * fp1=fopen("frac1.in","r");
	FILE * fp2=fopen("frac1.out","w");
  int i,j,n;
  fscanf(fp1,"%d\n",&n);
  num *numbers=calloc(n*n,sizeof(num));
  int numC=0;
  for(i=0;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      double res=(double)i/j;
      if(!isInList(res,numbers,n)&& res>=0 &&res<=1)
      {
        numbers[numC].val=res;
        char * temp=calloc(7,sizeof(char));
        sprintf(temp,"%d/%d",i,j);
        numbers[numC].out=temp;
        numC++;
      }
    }
  }
  num res[numC+1];
  res[0].val=0;
  res[0].out="0/1";
  for(i=1;i<numC+1;i++)
  {
    res[i].val=numbers[i-1].val;
    res[i].out=numbers[i-1].out;
  }
  qsort(res,numC+1,sizeof(num),cmp);
  for(i=0;i<numC+1;i++)
  {
    fprintf(fp2,"%s\n",res[i].out);
  }
  fclose(fp1);
  fclose(fp2);
  exit(0);
}
