#include <stdio.h>ddddd
#define N 4

int main()
{
    int tab[N][N];
    int i=0,j=0,k,n=1,m=1,obieg=0;


    for(k=0;k<N*N;k++)
    {
        tab[j][i]=n;
        n++;
        if (m>0)
        {
            if (i<N-1-obieg) i+=m;
            else j+=m;
        }else
        {
            if (i>0+obieg) i+=m;
            else j+=m;
        }


        if ((i==j) && (i!=obieg)) m=-m;
        if ((j==obieg+1) && (i==obieg))
        {
            m=-m;
            obieg++;
        }
    }



    for (i=0;i<N;i++) //wypisywanie tablicy
        {
            for(j=0;j<N;j++)
                printf("%2i",tab[i][j]);
            printf("\n");
        }
}
