/*
ID: bilinme1
LANG: C
TASK: test
*/
#include <stdio.h>
#include <stdlib.h>
main () {
    FILE *fin  = fopen ("test.in", "r");
    FILE *fout = fopen ("test.out", "w");
    int a, b;
    fscanf (fin, "%d %d", &a, &b);
    int result=a+b;
    fprintf (fout, "%d\n", result);
    exit (0);
}
