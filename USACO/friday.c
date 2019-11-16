/*
ID: bilinme1
LANG: C
TASK: friday
*/
#include<stdio.h>
#include<stdlib.h>
main () {
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");
    int *arr=calloc(7,sizeof(int));
    int starty=1900,endy,n,i,j,t,ind=2;
    fscanf(fin,"%d",&n);
    endy=1900+n-1;
    for(i=starty;i<=endy;i++)
    {
    	for(j=1;j<=12;j++)
    	{
    		if(j==2)
    		{   							
    			arr[(ind+5)%7]++;
    			if((i%4==0 && i%100!=0)|| (i%400==0)) ind=(ind+1)%7;		   		
    		}
			else if(j==4 || j==6 || j==9 || j==11)
			{
				arr[(ind+5)%7]++;
				ind=(ind+2)%7;					
			}
			else
			{	
				arr[(ind+5)%7]++;
				ind=(ind+3)%7;

			}
		}
	}
	for(i=0;i<7;i++)
	{
		if(i==6)fprintf (fout, "%d\n", arr[i]);
		else
		{
			fprintf (fout, "%d ", arr[i]);
		}	
	}
    
    exit (0);
}
