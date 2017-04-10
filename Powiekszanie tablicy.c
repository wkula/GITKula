#include <stdio.h>
#include <stdlib.h>
#define N 10

int * add(int* tab, int n, int new_elem)
{
    int i, *tablica;
    tablica=malloc((n+1)*sizeof(int));
    if (tablica==NULL) return tablica;
    for(i=0;i<n;i++)
        tablica[i]=tab[i];
    tablica[n]=new_elem;
    free(tab);
    return tablica;
}


int main()
{
    int *tab=NULL;
    int i;
    for(i=0;i<N;i++)
        tab=add(tab,i,i+1);
    for(i=0;i<N;i++)
        printf("%i\n",tab[i]);
    free(tab);
    return 0;
}

