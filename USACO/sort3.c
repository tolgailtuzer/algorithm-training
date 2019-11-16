/*
ID: bilinme1
LANG: C
TASK: sort3
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE * fp1=fopen("sort3.in","r");
	FILE * fp2=fopen("sort3.out","w");
	int n,i,j,C1=0,C2=0,C3=0,steps=0;
	fscanf(fp1,"%d",&n);
	int numbers[n];
	for(i=0;i<n;i++)
	{
		fscanf(fp1,"%d\n",&numbers[i]);
	}
	for(i=0;i<n;i++)
	{
		if(numbers[i]==1)C1++;
		else if(numbers[i]==2)C2++;
		else C3++;
	}
	int temp;
	int k;
	for(i=0;i<n;i++)
	{
		if(i<C1)
		{
			int flag=0;
			if(numbers[i]!=1)
			{
				if(numbers[i]==2)
				{
					for(j=C1;j<C1+C2;j++)
					{
						if(numbers[j]==1)
						{

							temp=numbers[i];
							numbers[i]=numbers[j];
							numbers[j]=temp;
							steps++;
							flag=1;
							break;
						}
					}
				}
				else if(numbers[i]==3)
				{
					for(j=C1+C2;j<C1+C2+C3;j++)
					{
						if(numbers[j]==1)
						{

							temp=numbers[i];
							numbers[i]=numbers[j];
							numbers[j]=temp;
							steps++;
							flag=1;
							break;
						}
					}
				}
				if(!flag)
				{
					for(j=i+1;j<n;j++)
					{
						if(j>=C1 && numbers[j]==1)
						{

							temp=numbers[i];
							numbers[i]=numbers[j];
							numbers[j]=temp;
							steps++;
							break;
						}
					}
				}
			}
		}
		else if(i>=C1 && i<(C1+C2))
		{
			if(numbers[i]!=2)
			{
				for(j=i+1;j<n;j++)
				{
					if(j>=C1+C2 && numbers[j]==2)
					{
						temp=numbers[i];
						numbers[i]=numbers[j];
						numbers[j]=temp;
						steps++;
						break;
					}
				}
			}

		}
	}
	fprintf(fp2,"%d\n",steps);
	fclose(fp1);
	fclose(fp2);
	exit(0);
}
