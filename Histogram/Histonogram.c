#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGHT_WORD 100 // maksymalna dlugosci slowa
#define IN 1 // in word 
#define OUT 0 // out of  word
#define ODSTEP " "
// Tworzenie Hisotgramu
void rysuj_poziomo(int *llenght)
{
    
    for(int i=0;i<MAX_LENGHT_WORD;i++)
    {
        if(llenght[i]!=0)
        {
            printf("slowa o dlugosci %d:",i);
            for(int j=0;j<llenght[i];j++)
            {
                printf("*");
            }
            printf("  \n");
        }
            
    }
}
void rysuj_pionowo(int *number)
{
    int max_height=0;// wysokosci wykresu
    // sprawdzanie wysokosci wykresu
    for(int i=0;i<MAX_LENGHT_WORD;i++)
    {
        if(number[i]>max_height)
            max_height=number[i];
    }
    // rysowanie wykresu- miesko
    for(int i=0;i<max_height;i++){
        for (int j=1;j<MAX_LENGHT_WORD; j++)
        {
            if(number[j]>=max_height-i)
            {
                printf("* ");
            }
            else if(number[j]>0) // BIG BRAIN MOVE OMJAMY PUSTE WIERSZE w dopisywaniu spacji XD
                printf("  ");
        }
        printf("\n");
    }

    // tworzenie legendy
    for (int i = 1; i < MAX_LENGHT_WORD; i++)
    {
        if(number[i]>0)
        {
            printf("%d ",i);
           
        }
    }
    
}
int main()
{
    int c=0,lcureent=0; // dlugosci obecnego slowa 
    int number[MAX_LENGHT_WORD] ;// ilosci slow o danej dlogosci
    bool state=OUT; // czy jest w slowie
    printf("HISTOGRAM O WARTOSCI SLOW: \n '*'-1 wystapenie \n" );
    for(int i=0;i<MAX_LENGHT_WORD;i++)
        number[i]=0;
    while((c=getchar())!=EOF)
    {
        if(c=='\t'||c=='\n'||c==' ')
        {
            state=OUT;
            if(lcureent>0)
                ++number[lcureent];

            lcureent=0;
        }
        else if(state==OUT)
        {
            state=IN;
            ++lcureent;
        } 
        else if(state==IN)
            ++lcureent;
        
    }
    rysuj_poziomo(number);
    rysuj_pionowo(number);
    printf("\nave cezar!");
    return 0;

}