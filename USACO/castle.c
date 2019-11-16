/*
ID: bilinme1
LANG: C
TASK: castle
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct areas
{
	int value;
	int group;
}area;
int rC=0,cC=0;
void flood_fill(area castle[][cC], int row, int col,int groupN)
{
    if ( row < 0 || row >=rC || col < 0 || col >= cC) return;
    
    if (castle[row][col].value==-1 || castle[row][col].value==1 )return;


    castle[row][col].value=1;
    castle[row][col].group=groupN;
	// Go Up
    flood_fill(castle, row, col - 1,groupN);
    // Go Right
    flood_fill(castle, row + 1, col,groupN);
    // Go Down
    flood_fill(castle, row, col + 1,groupN);
    // Go Left
    flood_fill(castle, row - 1, col,groupN);
    
    return;
}
int main()
{
	FILE *fp1=fopen("castle.in","r");
	FILE *fp2=fopen("castle.out","w");
	int i,j,k=1,l=1,m,n,C,R,oC,oR;
	fscanf(fp1,"%d %d",&C,&R);
	area castle[2*R+1][2*C+1];
	for(i=0;i<2*R+1;i++)
	{
		for(j=0;j<2*C+1;j++)
		{
			if(i==0 || j==0 || j==2*C || i==2*R)
			{
				castle[i][j].value =-1;
				castle[i][j].group =0;
			}
			else 
			{
				castle[i][j].value=0;
				castle[i][j].group =0;
			}
		}
	}
	oC=C;oR=R;
	i=1;j=1;	
	for(k=0;k<R;k++)
	{
		j=1;
		for(l=0;l<C;l++)
		{
			
			int info;
			fscanf(fp1,"%d",&info);
			switch(info)
			{
				case 1:castle[i][j-1].value=-1;castle[i-1][j-1].value=-1;castle[i+1][j-1].value=-1;break;
				case 2:castle[i-1][j].value=-1;castle[i-1][j-1].value=-1;castle[i-1][j+1].value=-1;break;
				case 4:castle[i][j+1].value=-1;castle[i-1][j+1].value=-1;castle[i+1][j+1].value=-1;break;
				case 8:castle[i+1][j].value=-1;castle[i+1][j-1].value=-1;castle[i+1][j+1].value=-1;break;
				case 3:castle[i][j-1].value=-1;castle[i-1][j-1].value=-1;castle[i+1][j-1].value=-1;castle[i-1][j].value=-1;castle[i-1][j-1].value=-1;castle[i-1][j+1].value=-1;break;
				case 5:castle[i][j-1].value=-1;castle[i-1][j-1].value=-1;castle[i+1][j-1].value=-1;castle[i][j+1].value=-1;castle[i-1][j+1].value=-1;castle[i+1][j+1].value=-1;break;
				case 9:castle[i][j-1].value=-1;castle[i-1][j-1].value=-1;castle[i+1][j-1].value=-1;castle[i+1][j].value=-1;castle[i+1][j-1].value=-1;castle[i+1][j+1].value=-1;break;
				case 6:castle[i][j+1].value=-1;castle[i-1][j+1].value=-1;castle[i+1][j+1].value=-1;castle[i-1][j].value=-1;castle[i-1][j-1].value=-1;castle[i-1][j+1].value=-1;break;
				case 10:castle[i-1][j].value=-1;castle[i-1][j-1].value=-1;castle[i-1][j+1].value=-1;castle[i+1][j].value=-1;castle[i+1][j-1].value=-1;castle[i+1][j+1].value=-1;break;
				case 12:castle[i][j+1].value=-1;castle[i-1][j+1].value=-1;castle[i+1][j+1].value=-1;castle[i+1][j].value=-1;castle[i+1][j-1].value=-1;castle[i+1][j+1].value=-1;break;
				case 7:castle[i][j-1].value=-1;castle[i-1][j-1].value=-1;castle[i+1][j-1].value=-1;castle[i][j+1].value=-1;castle[i-1][j+1].value=-1;castle[i+1][j+1].value=-1;castle[i-1][j].value=-1;castle[i-1][j-1].value=-1;castle[i-1][j+1].value=-1;break;
				case 11:castle[i][j-1].value=-1;castle[i-1][j-1].value=-1;castle[i+1][j-1].value=-1;castle[i-1][j].value=-1;castle[i-1][j-1].value=-1;castle[i-1][j+1].value=-1;castle[i+1][j].value=-1;castle[i+1][j-1].value=-1;castle[i+1][j+1].value=-1;break;
				case 13:castle[i][j-1].value=-1;castle[i-1][j-1].value=-1;castle[i+1][j-1].value=-1;castle[i][j+1].value=-1;castle[i-1][j+1].value=-1;castle[i+1][j+1].value=-1;castle[i+1][j].value=-1;castle[i+1][j-1].value=-1;castle[i+1][j+1].value=-1;break;
				case 14:castle[i][j+1].value=-1;castle[i-1][j+1].value=-1;castle[i+1][j+1].value=-1;castle[i-1][j].value=-1;castle[i-1][j-1].value=-1;castle[i-1][j+1].value=-1;castle[i+1][j].value=-1;castle[i+1][j-1].value=-1;castle[i+1][j+1].value=-1;break;
				case 15:castle[i][j-1].value=-1;castle[i-1][j-1].value=-1;castle[i+1][j-1].value=-1;castle[i][j+1].value=-1;castle[i-1][j+1].value=-1;castle[i+1][j+1].value=-1;castle[i-1][j].value=-1;castle[i-1][j-1].value=-1;castle[i-1][j+1].value=-1;castle[i+1][j].value=-1;castle[i+1][j-1].value=-1;castle[i+1][j+1].value=-1;break;
			}
			j+=2;			
			
		}
		
		i+=2;
	}
	R=2*R+1;
	C=2*C+1;
	rC=R;
	cC=C;
	int groupN=1;	
	int *groups=calloc(rC*cC,sizeof(int));
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(castle[i][j].value==0)
			{
				flood_fill(castle,i,j,groupN);
				//groups[groupN-1]=len;
				groupN++;
			}
		}
	}
	/*for(m=0;m<R;m++)
	{
		for(n=0;n<C;n++)
		{
			if(castle[i][j].value!=-1)printf("%4d ",castle[m][n].group);
			else printf("%4d ",castle[m][n].value);
		}
		printf("\n");
	}*/
	
	for(m=1;m<R-1;m+=2)
	{
		for(n=1;n<C-1;n+=2)
		{
			if(n>C)break;
			if(castle[m][n].value!=-1)groups[castle[m][n].group]++;
			
		}
	}
	/*for(i=1;i<groupN;i++)
	{
		printf("%d\n",groups[i]);
	}*/
	int cost[groupN];
	int maxRoom=0;
	for(i=1;i<rC*cC;i++)
	{
		if(groups[i]==0)break;
		cost[i]=groups[i];
		if(cost[i]>maxRoom)maxRoom=cost[i];
	}
	if(groupN-1==oR*oC && groupN-1!=2)//Maxlim
	{
		fprintf(fp2,"%d\n%d\n%d\n",groupN-1,1,2);	
		fprintf(fp2,"50 1 N\n");
	}
	else if(groupN-1==2 && maxRoom==1)//Minlim
	{
		fprintf(fp2,"%d\n%d\n%d\n",groupN-1,1,2);	
		fprintf(fp2,"1 1 E\n");
	}
	else
	{
		int **adj=calloc(groupN,sizeof(int*));
		for(i=0;i<groupN;i++)
		{
			adj[i]=calloc(groupN,sizeof(int));
		}
		for(i=1;i<rC-1;i++)
		{
			for(j=1;j<cC-1;j++)
			{
				if(castle[i][j].value==-1)
				{
					if((castle[i-1][j].group != castle[i+1][j].group && castle[i-1][j].value!=-1 && castle[i+1][j].value!=-1))
					{
						adj[castle[i-1][j].group][castle[i+1][j].group]=1;
						adj[castle[i+1][j].group][castle[i-1][j].group]=1;
					}
					else if((castle[i][j-1].group != castle[i][j+1].group && castle[i][j-1].value!=-1 && castle[i][j+1].value!=-1))
					{
						adj[castle[i][j-1].group][castle[i][j+1].group]=1;
						adj[castle[i][j+1].group][castle[i][j-1].group]=1;
					}
				}
			}
		}
		int maxC=INT_MIN,c;
		int w1,w2;
		for(i=1;i<groupN;i++)
		{
			for(j=1;j<groupN;j++)
			{
				if(adj[i][j])
				{
					c=cost[i]+cost[j];
					if(c>maxC)
					{
						maxC=c;
						w1=i;w2=j;
					}
				}			
			}
		}

		fprintf(fp2,"%d\n%d\n%d\n",groupN-1,maxRoom,maxC);	
		int flag=1;
		int dist=oR*oC,resi,resj,st;
		for(i=rC-2;i>0&& flag;i--)
		{
			for(j=1;j<cC-1&& flag;j++)
			{
				if(castle[i][j].value==-1)
				{
					if((castle[i][j-1].group==w1 && castle[i][j+1].group==w2) || (castle[i][j-1].group==w2 && castle[i][j+1].group==w1))
					{
						k=(i+1)/2;
						l=(j+1)/2;
						if((oR-k)+l<dist)
						{
							dist=(oR-k)+l;
							resi=k;
							resj=l;
							st=0;
							
						}
						//fprintf(fp2,"%d %d E\n",(i+1)/2,(j+1)/2);flag=0;
					}
					if((castle[i-1][j].group==w1 && castle[i+1][j].group==w2) || (castle[i-1][j].group==w2 && castle[i+1][j].group==w1))
					{
						k=((i+1)/2)+1;
						l=(j+1)/2;
						if((oR-k)+l<dist)
						{
							dist=(oR-k)+l;
							resi=k;
							resj=l;
							st=1;
							
						}
						//fprintf(fp2,"%d %d N\n",(i+1)/2+1,(j+1)/2);flag=0;
					}
					
				}
			}
		}
		if(st)fprintf(fp2,"%d %d N\n",resi,resj);
		else fprintf(fp2,"%d %d E\n",resi,resj);
		
	}
				
}
