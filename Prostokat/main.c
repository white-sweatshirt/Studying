#include <stdio.h>
#include <stdlib.h>

#define WIERZCHOLKI 2 // TU do odjecia ilosci wierzcholkow 
//                      chodzi o skrajne strony bokow

#define WYPELNINIE '~' // wypelnie wnetrza prostokata
#define BOK_SZEROKOC '='//Symbol dla szerokoci
#define ROG '*'
#define BOK_DLUGOSC '|'// Symbol dla dlugiego boku


void przejscie (char a,int szerokosci)// funkcja sprawdzajaca jak  przejsci do nowego wiersza i czym zakaniczcyc stary
{
    
    if(szerokosci>=1)
        printf("%c\n",a);// przejcie do nowego wiersza
    else
        printf("\n");

}
void prosotkat(int dlugosci,int szerokosci)
{
    for(int i=0; i<dlugosci;i++ )
    {
        if(i==0||i==dlugosci-1)
        {
            printf("%c",ROG);
            for(int j=0;j<szerokosci-WIERZCHOLKI;j++)// odjecie nastepuje dlatego ze nie bedzeimy wypisywc dwoch wierzcholkow
            {
                printf("%c",BOK_SZEROKOC);
            }
            
            przejscie(ROG,szerokosci-1);// odejmuje juz wczesniej napisany wierzcholek
        }
        else{
            
            printf("%c",BOK_DLUGOSC);
            for (int  j = 0; j < szerokosci-WIERZCHOLKI; j++)
            {
                printf("%c",WYPELNINIE);
            }
            przejscie(BOK_DLUGOSC,szerokosci-1);// odjecie nastepuje dlatego ze nie bedzeimy wypisywc dwoch wierzcholkow
        }
    }
}

int main(){
    int a=0,b=0; // dlugoci,szerokoci
    printf("podaj dlugosci i szerokoci prostokata wielkoci te powinny \n byc wieksze od dwa aby zobaczyc wsztkie znaczki: ");
    scanf("%d %d",&a,&b);
    prosotkat(a,b);
    return 0;
}