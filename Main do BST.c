#include "bst.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

main()
{
	Wezel* droga = NULL;
    int menu=0;
    char Nazwisko[SIZE];
    while(menu!=8)
    {
    	switch(menu)
    	{
    		case 0:
    			printf(
				"0) menu\n"
                "1) wprowadz dane\n"
                "2) przejdz po drzewie (InOrder)\n"
                "3) wyszukaj pierwszego nazwiska wg alfabetu \n"
                "4) wyszukaj ostatniego nazwiska wg alfabetu\n"
                "5) podaj liczbe wezlow\n"
                "6) wyszukaj nazwisko\n"
                "7) podaj wysokosc drzewa\n"
                "8) zakoncz program\n\n");
                break;
            case 1:
            	Dodaj(&droga);
            	break;
            case 2:
            	InOrder(droga);
            	break;
            case 3:
            	Min(droga);
            	break;
            case 4:
            	Max(droga);
            	break;
            case 5:
            	printf("Niczba wezlow: %i\n",Liczba(droga));
            	break;
            case 6:
            	printf("Podaj nazwisko osoby do wyszukania: ");
            	scanf("%s", Nazwisko);
            	Znajdz(droga,Nazwisko);
            	break;
            case 7:
            	printf("Wysokosc drzewa to %i\n",Wysokosc(droga));
            	break;
            default:
            	break;
		}
		printf("Co teraz? (0-menu)\n");
        scanf("%i",&menu);
        if( menu>8 || menu<0 )
            printf("Podano zly numer\n");
	}
	Zwolnij(&droga);
}
