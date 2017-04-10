#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int rownanie (float a,float b,float c,float *x1,float *x2)
{
    float delta;
    delta=b*b-4*a*c;
    if (delta<0) return 0;
    if (delta==0.)
    {
        *x1=(-b)/(2*a);
        *x2=*x1;
        return 1;
    }
    if (delta>0)
    {
        *x1=(-b-sqrt(delta)/(2*a));
        *x2=(-b+sqrt(delta)/(2*a));
        return 2;
    }
}

int main(int argc, char *argv[])
{
    float a=0,b=0,c=0,x1=0,x2=0;
    int wynik=0;
    printf("Podaj wspó³czynniki a b c\n");
    scanf("%f%f%f",&a,&b,&c);
    wynik=rownanie(a,b,c,&x1,&x2);
    switch(wynik)
    {
        case 0 :    
            printf("Rownanie nie ma pierwiastkow");
            break;
        case 1 :
            printf("Rownanie ma 1 pierwiastek rowny %f",x1);
            break;
        case 2:
            printf("Rownanie ma 2 pierwiastki rowne %f i %f",x1,x2);
            break;
    }
    return 0;
}