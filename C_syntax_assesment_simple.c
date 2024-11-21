#include <stdio.h>
#include <stdbool.h>

#define MAX_NAWIASOW 1000
#define PLACE_FOR_LAST 1
// tiresome project
int main()
{
    int c = 0;
    int opened_Curly_Bascet=0,unopened_Curly_Brascets=0;
    int opened_Round_Bascets=0,unopened_Round_Bascets=0;
    int opened_squere
    int current_line = 1;
    printf("hello & wellcome to my kitchen! \n");
    printf("1. ");
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '\n':
            ++current_line;
            printf("%d. ", current_line);
            break;
        case '{': 
           opened_Curly_Bascet++;
            break;
        case '}' :
            if (opened_Curly_Bascet> 0)
                opened_Curly_Bascet--;
            
            else
                unopened_Curly_Brascets++;
            break;
        
        case '(':
                opened_Round_Bascets++;
        case ')':
                if(opened_Round_Bascets>0)
                    --opened_Round_Bascets;
                else
                unopened_Round_Bascets++;
            break;
        default:
             break;
        }

    }
    return 0;
}