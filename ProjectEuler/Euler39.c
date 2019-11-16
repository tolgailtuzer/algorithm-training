#include<stdio.h>
#include<math.h>
int main()
{
  int i,k,l,m,sol,max=-1,val;
  for(i=3;i<=1000;i++)
  {
    sol=0;
    for(k=1;k<1000;k++)
    {
      for(l=k+1;l<1000;l++)
      {
          m=sqrt(k*k+l*l);//k+l+kök m olduğu için k*k+l*l=m*m kontrolü yapmalısın
          if((k*k+l*l==m*m)&&(k+l+m)==i)
          {
            sol++;
            //if(i==120)printf("%d %d %d\n",k,l,m);
          }
      }
    }
    if(sol>max)
    {
      //if(i==120)printf("%d\n",sol);
      max=sol;
      val=i;
    }
  }

  printf("%d\n",val);
}
