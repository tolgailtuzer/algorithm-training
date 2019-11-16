/*
ID: bilinme1
LANG: C
TASK: namenum
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
char *letters[] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
void check(char * number)
{
	FILE *fout = fopen ("namenum.out", "w");
    FILE *ft = fopen ("dict.txt", "r");
    bool flag,found=false; 
    char c;
    int i, n_digits, valid, n_valids=0;
    int digitlen=strlen(number);
	char temp[13];
    while (!feof(ft)) 
	{
        fscanf(ft,"%s\n", temp);
        if (strlen(temp) != digitlen)
            continue;
        flag = true;
        for (i=0; i < strlen(temp); i++) 
		{
			c=number[i]-'2';
            if (!(letters[c][0] <= temp[i] && temp[i] <= letters[c][2])) 
			{
                flag = 0;
                break;
            }
        }
        if (flag) 
		{
            fprintf(fout, "%s\n", temp);
            found =true;
        }
    }
    if (!found)fprintf(fout, "NONE\n", temp);
}


main () {
    FILE *fin  = fopen ("namenum.in", "r");
	char number[13];
	fscanf(fin,"%s\n",&number);	
	check(number);	
    exit (0);
}
