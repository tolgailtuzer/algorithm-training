/*
ID: bilinme1
LANG: C
TASK: beads
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
main () {
    FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");
    int n,i,j,ind,count=0,max=-1;
    fscanf(fin,"%d",&n);
    char clr;
    char temp;
    bool flag=false;
    char *str=calloc(n,sizeof(char));
    char *str2=calloc(n,sizeof(char));
    char *str3=calloc(n,sizeof(char));
    fscanf(fin,"%s",str);
    /*strcpy(str3,str);
    strrev(str3);
    if(abs(strcmp(str3,str)))
    {
    	strcpy(str2,str);
	    strcat(str,str2);
	    n*=2;  
	} */
	
    for(i=0;i<n;i++)
    {
    	flag=false;
    	count=0;
    	clr='e';
    	for(j=0;j<n;j++)
    	{
    		ind=(i+j)%n;
    		temp=str[ind];
			if(temp != 'w')
			{
		    	if(clr == 'e')
				{
		     		clr = temp;
		    	}
		    	else if(clr != temp)
				{
		     		if(flag)break;
		      		
		     		else
					 {
		      			clr = temp;
		      			flag = true;
		     		}
		     	}
			}
			count++;
		}
		if(count>max)
		{
			max=count;
		}		
	}
	fprintf(fout,"%d\n",max);
    
    exit (0);
}
