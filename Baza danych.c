#include <stdio.h>
#include <stdlib.h>
#define N 15

struct telebook
{
    char imie[N];
    char nazwisko[N];
    long telefon;
};
struct telebook *add(struct telebook *tab, int n,struct telebook new_elem)
{
    int i;
    struct telebook *tablica;
    tablica=malloc((n+1)*sizeof(struct telebook));
    if (tablica==NULL) return tablica;
    for(i=0;i<n;i++)
        tablica[i]=tab[i];
    tablica[n]=new_elem;
    free(tab);
    return tablica;
}
int pozycja(struct telebook *tab,int n,long numer)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(tab[i].telefon==numer) return i;
    }
    return -1;
}
void wypisz (struct telebook *poz)
{
    fputs((*poz).imie,stdout);
    printf("\n");
    fputs((*poz).nazwisko,stdout);
    printf("\n");
    printf("%ld\n",(*poz).telefon);
}
void del(struct telebook *tab,int rozm,int poz)
{
    struct telebook *nowa;
    int pom=0,i=0;
    nowa=malloc((rozm-1)*sizeof(struct telebook));
    for (i=0;i<rozm;i++)
    {
        if(i==poz) pom++;
        nowa[i]=tab[pom];
        pom++;
    }
    free(tab);
    tab=nowa;
}
int main()
{
    struct telebook *book;
    book=malloc(sizeof(struct telebook));
    struct telebook tmp={"Janusz","Kowalski",123456789};
    book[0]=tmp;
    
}
