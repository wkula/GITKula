#include <stdio.h>
#include <stdlib.h>

char * isElement(char *tab, char znak)
{
    int miejsce;
    char * zwrot=0;
    for(miejsce=0;(tab[miejsce]!=znak) && (tab[miejsce]!='\0');miejsce++);
    if(tab[miejsce]=='\0')
        zwrot=NULL;
    else zwrot=&tab[miejsce];
return zwrot;
}

 

int main()
{
    char napis[20];
    char znak;
    char * wynik;
    fgets(napis,20,stdin);
    printf("Wczytany tekst: %s\n", napis);
    scanf("%c",&znak);
    printf("Zadana litera to: %c\n", znak);
    wynik=isElement(napis,znak);
    if(wynik==NULL)
        printf("Nie ma takiego znaku\n");
    else
        printf("Znak ten jest w miejscu %c\n", *wynik);
return 0;
}