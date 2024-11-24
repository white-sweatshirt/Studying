#include <stdio.h>
#include <stdbool.h>
#define ALL_SYMBOLLS 256
#define COMMENTS 2
#define QUOTATION_MARK 34 // " has 34 number ASCII
#define APOSTROPHE 39     // ' has 39 number ASCII
void brascets_Opeing(int ascii[], int symbol)
{
    ++ascii[symbol];
}
void brascets_Ending(int ascii[], int opeing_Symbol, int ending_Symbol)
{
    if (ascii[opeing_Symbol] > 0)
        --ascii[opeing_Symbol];
    else
        ++ascii[ending_Symbol];
}
int main()
{
    int current_line = 1;

    int c = 0;
    int ascii_Symbols[ALL_SYMBOLLS] = {0}; /* array for bascets I know its not memory optimal
      you would have to count how many bascets there are and declere specific values for
      in order to eleminete breaks between them
  */
    int begging_Pointer = 0;
    int ending_pointer = 0;
    char begging_Comment[] = "/*";
    char ending_Commment[] = "*/";
    bool in_Comment = 0;

    char two_Slaches[] = "//";
    bool comment_Slaches = 0;
    int slasches_Pointer = 0;

    int opened_qutations = 0, opened_Apostrophe = 0;
    printf("hello & wellcome to my kitchen! \n");
    printf("1. ");
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++current_line;
            printf("%d. ", current_line);
        }
        if (in_Comment == 0)
        {
            switch (c)
            {
            case '{':
                brascets_Opeing(ascii_Symbols, '{');
                break;
            case '}':
                brascets_Ending(ascii_Symbols, '{', '}');
                break;
            case '[':
                brascets_Opeing(ascii_Symbols, '[');
                break;
            case ']':
                brascets_Ending(ascii_Symbols, '[', ']');
                break;
            case '<':
                brascets_Opeing(ascii_Symbols, '<');
                break;
            case '>':
                brascets_Ending(ascii_Symbols, '<', '>');
                break;
            case '(':
                brascets_Opeing(ascii_Symbols, '(');
                break;
            case ')':
                brascets_Ending(ascii_Symbols, '(', ')');
                break;
            case APOSTROPHE:
                /*nadurzycie funkcji aby moc usowac na bierzaco*/
                brascets_Ending(ascii_Symbols, APOSTROPHE,APOSTROPHE);
                break;
            case QUOTATION_MARK:
                brascets_Ending(ascii_Symbols, QUOTATION_MARK,QUOTATION_MARK);
                break;
            default:
                break;
            }
        }
        if (c == two_Slaches[slasches_Pointer] && in_Comment == 0 && comment_Slaches == 0)
        {
            slasches_Pointer++;
            if (slasches_Pointer >= COMMENTS)
            {
                comment_Slaches = 1;
                slasches_Pointer = 0;
            }
        }
        else
            slasches_Pointer = 0;
        
        if (c == begging_Comment[begging_Pointer] && in_Comment == 0)
        {
            begging_Pointer++;
            if (begging_Pointer >= COMMENTS)
            {
                in_Comment = 1;
                begging_Pointer = 0;
            }
        }
        else
        {
            if(begging_Pointer>0)
            {
                ascii_Symbols['/']++;
                ascii_Symbols[c]++;
            }
                
            begging_Pointer = 0;
        }
        if (c == ending_Commment[ending_pointer] && in_Comment == 1)
        {
            ending_pointer++;
            if (ending_pointer >= COMMENTS)
            {
                in_Comment = 0;
                ending_pointer = 0;
            }
        }
        else
        {

            ending_pointer = 0;
        }
    }
    for (int i = 0; i < ALL_SYMBOLLS; i++)
        if (ascii_Symbols[i] > 0)
            printf("blad z urzyciem znaku %c\n", i);
    if (in_Comment == 1)
        printf("nie zamknieto komentarza\n");
    return 0;
}