#include "bst.h"

void Dodaj (Wezel** droga)
{
	int cmp;
	int ilosc=0;
	int i=0;
	Wezel* nowy = (Wezel*) malloc(sizeof(Wezel));
	Osoba* nowaosoba = (Osoba*) malloc(sizeof(Osoba));		//Tworzenie struktury osoba
		if(nowaosoba==NULL)
		{
			printf("Brak pamieci. Zakonczenie dodawania");
			return;
		}
		printf("Podaj nazwisko ");
		scanf("%s",nowaosoba->Nazwisko);
		printf("Podaj imie ");
		scanf("%s",nowaosoba->Imie);
		do	{
			printf("Podaj ilosc numerow ");
			scanf("%i",&ilosc);
			if(ilosc<1)
				printf("Musi byc przynajmniej jeden numer");
			}while(ilosc<1);
		nowaosoba->ilosc=ilosc;
		nowaosoba->numery=(int*)malloc(sizeof(int)*ilosc); //nale�y jeszcze doda� sprawdzanie czy wystarczy pami�ci na podan� ilo�� numer�w
		if(nowaosoba->numery==NULL)
		{
			printf("Brak pami�ci, tworzenie wpisu przerwane. \n");
			free(nowaosoba);
			return;
		}
		for(i=0;i<ilosc;i++)
		{
			printf("Podaj numer %i ", i+1);
			scanf("%i",(nowaosoba->numery + i));
		}														//Koniec tworzenia struktury osoba

	nowy->dane = nowaosoba; //tworzenie nowego w�z�a kt�ry p�niej zostanie dodany na ko�cu odpowiedniej �cie�ki
	nowy->left = NULL;
	nowy->right = NULL;
	if(*droga == NULL)		//sprawdzanie czy posiadamy ju� zdeklarowany wcze�niej w�ze�
	{
		*droga=nowy;
		return;
	}
	Wezel* starszy = *droga;
	while(1)													//Algorytm umieszczaj�cy w�zel w odpowiednim miejscu
	{
		cmp=strcmp(starszy->dane->Nazwisko,nowaosoba->Nazwisko);
		if(cmp==0)
		{
			cmp=strcmp(starszy->dane->Imie,nowaosoba->Imie);
			if(cmp==0)
			{
				printf("Istnieje juz taka osoba"); //uzupe�ni� potem o dodawanie nowych numer�w
				return;
			}
			if(cmp<0)		//nowa osoba jest wcze�niej w alfabecie od aktualnego wezla
			{
				if(starszy->left==NULL)
				{
					starszy->left=nowy;
					return;
				}else
				{
					starszy = starszy->left;
				}
			}else
			{
				if(starszy->right==NULL)
				{
					starszy->right=nowy;
					return;
				}else
				{
					starszy = starszy->right;
				}
			}

		}else
		{
			if(cmp<0)		//nowa osoba jest wcze�niej w alfabecie od aktualnego wezla
			{
				if(starszy->left==NULL)
				{
					starszy->left=nowy;
					return;
				}else
				{
					starszy = starszy->left;
				}
			}else
			{
				if(starszy->right==NULL)
				{
					starszy->right=nowy;
					return;
				}else
				{
					starszy = starszy->right;
				}
			}
		}
	}
	printf("Wpisu dokonano pomyslnie.\n");
	return;
}
void wypiszpoz(Wezel* droga)	//przekazac wskaznik na dane struktury
{
	int i;
    printf("Imie: %s\n",droga->dane->Imie);		//dodac sciezki do struktury
    printf("Nazwisko: %s\n",droga->dane->Nazwisko);
    for(i=0;i<droga->dane->ilosc;i++)
    	printf("Numer %i: %i\n",i+1,(droga->dane->numery[i]));
}
void InOrder(Wezel* droga)		//przekazac wskaznik na wezel
{
    if(droga==NULL)
	printf("Brak pierwszego wezla\n");	//sprawdzanie czy posiadamy 1 wezel
    else
    {
   	if(droga->right!=NULL)		//wkaznik na prawa strukture
		InOrder(droga->right);
	wypiszpoz(droga);		//przekazujemy wskaznik na aktualna strukture
	if(droga->left!=NULL)
	    InOrder(droga->left);		//wskaznik na lewa strukture
    }
}
void Min (Wezel* droga)		//wskaznik na 1 wezel
{
    if(droga==NULL)		//czy posiadamy 1 wezel
	printf("Brak pierwszego wezla");
    if(droga->right!=NULL)
      Min (droga->right);		//przekazujemy wskaznik na prawo
    else
    {
      printf("Min na drzewie to: \n");
      wypiszpoz(droga);	//przekazujemy wskaznik na aktualna strukture
    }
}
void Max (Wezel* droga)		//wskaznik na 1 wezel
{
    if(droga==NULL)		//czy posiadamy 1 wezel
	printf("Brak pierwszego wezla");
    else
    if(droga->left!=NULL)
      Max (droga->left);		//przekazujemy wskaznik na lewo
    else
    {
      printf("Max na drzewie to: \n");
      wypiszpoz(droga);	//przekazujemy wskaznik na aktualna strukture
    }
}
int Liczba (Wezel* droga)		//wskaznik na 1 wezel
{
    int ilosc=1;
    if(droga==NULL)
    {
	printf("Brak pierwszego wezla");	//sprawdzanie czy posiadamy 1 wezel
	return 0;
    }else
    {
	if(droga->left!=NULL)		//wskaznik na lewa strukture
	    ilosc+=Liczba(droga->left);
	if(droga->right!=NULL)		//wkaznik na prawa strukture
	    ilosc+=Liczba(droga->right);
    }
    return ilosc;
}
void Znajdz (Wezel* droga,char* klucz)		//wskaznik na 1 wezel oraz slowo klucz
{
    int cmp=strcmp(droga->dane->Nazwisko,klucz);	//wskaznik na dane kolejnych struktur oraz slowo klucz
    if(cmp==0)
		wypiszpoz(droga); 	//aktualny wskaznik
	if(cmp<0)
    {
    	if(droga->left==NULL)
    	{
			printf("Brak osoby o podanym nazwisku\n");
			return;
		}
		Znajdz (droga->left, klucz);	//wkaznik na lewy wezel oraz klucz
	}
	if(cmp>0)
	{
		if(droga->right==NULL)
		{
			printf("Brak osoby o podanym nazwisku\n");
			return;
		}
		Znajdz (droga->right, klucz);	//wskaznik na prawy wezel oraz klucz
	}

} 					//doda� sprawdzanie w przypadku tych samych nazwisk
int Wysokosc (Wezel* droga)
{
	if(droga==NULL) return 0;
	int lewa = 1 , prawa = 1;
	if(droga->left!=NULL)
		lewa += Wysokosc(droga->left);
	if(droga->right!=NULL)
		prawa += Wysokosc(droga->right);
	if(lewa>=prawa)
		return lewa;
	else
		return prawa;
}
void Zwolnij(Wezel** droga)
{
	if(droga==NULL)
		return;
	if(*droga==NULL)
		return;
	if((*droga)->left !=NULL)
		Zwolnij(&((*droga)->left));
	if((*droga)->right !=NULL)
		Zwolnij(&((*droga)->right));
	free((*droga)->dane->numery);
	free((*droga)->dane);
	free(*droga);
	*droga=NULL;
}
