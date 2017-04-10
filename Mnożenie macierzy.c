#include <stdio.h>
#define ROW1 2
#define COL1 3
#define ROW2 3
#define COL2 2

int main()
{
    int mac1[ROW1][COL1] = {{1,0,2},{-1,3,1}};
    int mac2[ROW2][COL2] = {{3,1},{2,1},{1,0}};
    int mac3[ROW1][COL2] = {{0,0},{0,0}};
    int i,j,k;
    for(i=0;i<ROW1;i++)
        for(j=0;j<COL2;j++)
            for(k=0;k<ROW2;k++)
                mac3[i][j]=mac3[i][j]+mac1[i][k]*mac2[k][j];
    for(i=0;i<ROW1;i++)
    {
        for(j=0;j<COL2;j++)
            printf("%3i ",mac3[i][j]);
        printf("\n");
    }
}

