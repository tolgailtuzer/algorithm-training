/*
ID: bilinme1
LANG: C
TASK: ride
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char a[6];
    char b[6];
    char *result;
    int i,sum1=1,sum2=1;
    fscanf (fin, "%s %s", a, b); 
    
    for(i=0;i<strlen(a);i++)
    {
    	sum1*=(a[i]-64);	
	}
	sum1%=47;
	for(i=0;i<strlen(b);i++)
    {
    	sum2*=(b[i]-64);
	}
	sum2%=47;
	if(sum1==sum2)result="GO\n";
	else result="STAY\n";	
    fprintf (fout, "%s", result);
    exit (0);
}
