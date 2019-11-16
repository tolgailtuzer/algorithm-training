#include<stdio.h>
#include<math.h>
int isPrime(int x)
{
  int i;
  for(i=2;i<=sqrt(x);i++)
  {
    if(x%i==0)return 0;
  }
  return 1;
}
int main()
{
  int i,j,n,max=-1,a,b;
  for(i=-999;i<1000;i++)
  {
    for(j=-1000;j<=1000;j++)
    {
      n=0;
      while(isPrime(fabs(n*n+i*n+j)))n++;
      if(n>max)
      {
        max=n;
        a=i;b=j;
      }
    }
  }
  printf("%d %d %d\n",a,b,a*b);
}
