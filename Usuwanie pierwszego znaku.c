#include <stdio.h>
#include <stdlib.h>
#define N 100

char deleteFirstChar(char** pstr)
{
    int p=0,i=0;
    char*tabl;
    char pom;
    pom=(*pstr)[0];
    while((*pstr)[i]!='\0') i++;
    if (i==0) return pom;
    tabl=malloc((i-1)*sizeof(int));
    for(p=0;p<i;p++) tabl[p]=(*pstr)[p+1];
    free(*pstr);
    *pstr=tabl;
    return pom;
}

int main()
{
    char *tab;
    char znak;
    int i=0;
    tab=malloc(N*sizeof(int));
    printf("Podaj napis\n");
    fgets(tab,N,stdin);
    znak=deleteFirstChar(&tab);
    printf("%c\n",znak);
    while (tab[i]!='\0')
    {
        printf("%c",tab[i]);
        i++;
    }
    return 0;
}

