/*
ID: bilinme1
LANG: C
TASK: transform
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
void swap(char *a, char *b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
}
void rotate(char **arr,int n)
{
	int i,j,level=n/2,last=n-1;
	for(i=0;i<level;i++)
	{
		for(j=i;j<last;j++)
		{
		swap(&arr[i][j],&arr[j][last]);
		swap(&arr[i][j],&arr[last][last-j+i]);
		swap(&arr[i][j],&arr[last-j+i][i]);
		}
		last--;
	}	
}
void reflect(char **arr,int n)
{
	int i,j,start=0,end=n-1;
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n;j++)
		{
			swap(&arr[j][start],&arr[j][end]);
		}		
		start++;
		end--;
	}
}

bool check(char **arr1,char **arr2,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr1[i][j]!=arr2[i][j])return false;
		}
	}
	return true;
}
main()
{

	FILE *fp1=fopen("transform.in","r");
	FILE *fp2=fopen("transform.out","w");
	int i,j,n;
	char empty;
	int *result;
	fscanf(fp1,"%d",&n);
	fscanf(fp1,"%c",&empty);
	char **f_arr=calloc(n,sizeof(char*));
	for(i=0;i<n;i++)
	{
		f_arr[i]=calloc(n,sizeof(char));
	}
	char **s_arr=calloc(n,sizeof(char*));
	for(i=0;i<n;i++)
	{
		s_arr[i]=calloc(n,sizeof(char));
	}	
	char **temp_arr=calloc(n,sizeof(char*));
	for(i=0;i<n;i++)
	{
		temp_arr[i]=calloc(n,sizeof(char));
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp1,"%c",&f_arr[i][j]);
		}
		fscanf(fp1,"%c",&empty);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp1,"%c",&s_arr[i][j]);			
		}
		fscanf(fp1,"%c",&empty);
	}
	bool flag=false;
	int check_result;
	for (i = 1; i < 6; i++)
	{			
		int k,l;
		for(k=0;k<n;k++)
		{
			for(l=0;l<n;l++)
			{
				temp_arr[k][l]=f_arr[k][l];
			}
		}
		switch(i)
		{
			case 1:	
			{				
				rotate(temp_arr,n);							
				break;
			}
			case 2:
			{
				rotate(temp_arr,n);rotate(temp_arr,n);
				break;
			}
			case 3:
			{
				rotate(temp_arr,n);rotate(temp_arr,n);rotate(temp_arr,n);
				break;
			}
			case 4:
			{
				reflect(temp_arr,n);
				break;	
			}
			case 5:
			{
				
				reflect(temp_arr,n);
			
				rotate(temp_arr,n);	
														
				if(!check(temp_arr,s_arr,n))
				{	
					rotate(temp_arr,n);				
				}							
				break;	
			}
		}
							
		if(check(temp_arr,s_arr,n))
		{
			
			flag=true;
			fprintf(fp2,"%d\n",i);
			break;								
		}	
	}
		
		if(!flag && check(f_arr,s_arr,n))fprintf(fp2,"%d\n",6);
		if(!check(temp_arr,s_arr,n))fprintf(fp2,"%d\n",7);

	
	exit(0);
	
}
