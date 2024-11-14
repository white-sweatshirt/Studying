#include <stdio.h>
#include <stdbool.h>

#define MAX_NAWIASOW 1000

typedef struct my_error
{
    int where[MAX_NAWIASOW];
    int pointer;
} my_error, *pmy_error;
void init(my_error t)
{
    for (int i = 0; i < MAX_NAWIASOW; i++)
        t.where[i] = 0; // umowa ze zero to no problemo
    t.pointer = 0;
}
void writing_of_errors_for_bascets(my_error opening, my_error ending)
{
    // if(opening.pointer>0)
    for (int i = 0; opening.where[i] > 0; i++)
        printf("Brak nawiasa konczacego do nawiasu {  na lini %d \n", opening.where[i]);

    for (int i = 0; ending.where[i] > 0; i++)
        printf("Brak nawiasa rozpoczynajacego do nawiasu }  na lini %d \n", ending.where[i]);
    printf("sth happened");
}
void brascets_function_opening(my_error opening,int current_line)// nawias lub rzecz otwierajaca
{
    opening.where[opening.pointer]=current_line;
    if(opening.pointer<MAX_NAWIASOW-1)
        opening.pointer++;
}
void brascets_function_ending(my_error opening,my_error ending,int current_line)
{
    if(opening.where[opening.pointer]>0)
        {
            
        }
        else
        {

        }
}
int main()
{
    int c = 0;
    my_error curly_Bracets, curly_Bracets_Ending;// ending -}
    init(curly_Bracets);
    init(curly_Bracets_Ending);
    int current_line = 1;
    printf("hello & wellcome to my kitchen! \n");
    printf("1. ");
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++current_line;
            printf("%d. ", current_line);
        }
        if (c == '{')
        {
            curly_Bracets.where[curly_Bracets.pointer] = current_line;
            if(curly_Bracets.pointer<MAX_NAWIASOW-1)
            curly_Bracets.pointer++;
        }
        if (c == '}')
        {
            if (curly_Bracets.where[curly_Bracets.pointer]> 0)
            {
                curly_Bracets.where[curly_Bracets.pointer] = 0;
                if(curly_Bracets.pointer>0)
                    --curly_Bracets.pointer;
            }
            else
            {
                curly_Bracets_Ending.where[curly_Bracets_Ending.pointer] = current_line;
                if(curly_Bracets_Ending.pointer<MAX_NAWIASOW-1)
                    ++curly_Bracets_Ending.pointer;
            }
        }
    }
    writing_of_errors_for_bascets(curly_Bracets, curly_Bracets_Ending);
    return 0;
}