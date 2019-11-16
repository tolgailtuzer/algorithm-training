/*
ID: bilinme1
LANG: C
TASK: gift1
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main () {
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    int n,i,cash,pN,calc;
    fscanf (fin,"%d",&n); 
    const char *person[n];
    int *account=calloc(n,sizeof(int));
    char *search;
    char *temp;
    printf("%d\n",n);
    for(i=0;i<n;i++)
    {
    	fscanf(fin, "%s",person[i]);
    	printf("%s\n",person[i]);
	}
    do
    {
    	fscanf (fin, "%s %d %d",search,&cash,&pN);
    	printf("%s",search);
    	calc=cash/pN;
    	for(i=0;i<n;i++)
		{
			if(person[i]==search)
			{
				account[i]-=cash;
				account[i]+=cash%pN;
			}					
		}
		for(i=0;i<pN;i++)
		{
			fscanf (fin, "%s",temp);
			for(i=0;i<n;i++)
			{
				if(person[i]==temp)
				{
					account[i]+=calc;
				}					
			}
		}    	
	}while(pN!=0);
    	
    for(i=0;i<n;i++)
    {
    	fprintf(fout,"%s %d",person[i],account[i]);
	}
    exit (0);
}
