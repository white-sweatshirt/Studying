#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAXOP 100  /*max dlufosc operandu lub operatora*/
#define NUMBER '0' /*sygnal znaleznia liczby*/
#define MAXVAL 100 /* MAX dlugosc stotsu*/

#define SHOW_STACK '='
#define CLEAN_STACK '!'

#define MAXVARIBLES 'z' - 'a' + 1

int getline(char s[], int limit);
double pop(void);
void push(double a);

void showStack(void);
void clearStack(void);

void giveBoundriesOfFragment(char s[], int *start, int *finish);
int sayWhatTypeItIs(char s[], int start);

void copyFragmentToNewTable(char s[], char s1[], int start, int finish);
int main()
{

    char type = 0;
    double op2 = 0.0;
    char s[MAXOP], buffor[MAXOP];

    int endingIndex = MAXOP;
    int beggingIndex = 0;
    do // petla po koljenych liniach
    {
        getline(s, MAXOP);
        endingIndex = 0;
        beggingIndex = 0;
        bool wasThereIteration = false;
        do
        { // petla po kolejnych czesciach lini
            beggingIndex = endingIndex;
            wasThereIteration = true;
            giveBoundriesOfFragment(s, &beggingIndex, &endingIndex);

            type = sayWhatTypeItIs(s, beggingIndex);
            if (beggingIndex >= endingIndex)
                break;

            switch (type)
            {
            case NUMBER:
                copyFragmentToNewTable(s, buffor, beggingIndex, endingIndex);
                push(atof(buffor));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                push(pop() / op2);
                break;
            case '%': // thow away ulamki
                int iop2 = (int)pop();
                push((int)pop() % iop2);
                break;
            case SHOW_STACK:
                showStack();
                break;
            case CLEAN_STACK:
                clearStack();
                break;
            default:
                printf("blad nie znane polecnie !");
                break;
            }
        } while (s[beggingIndex] != EOF && s[beggingIndex] != '\n');
    } while ((type) != EOF);

    return 0;
}
// Text function
int getline(char s[], int limit)
{
    int i = 0;
    int c;
    while ((c = getchar()) != '\n' && c != EOF && i < limit - 1)
        s[i++] = c;
    s[i] = '\0';
    return i;
}

void copyFragmentToNewTable(char s[], char s1[], int start, int finish)
{
    int i = 0;
    while (start < finish)
        *(s1 + i++) = *(s + start++);
    *(s1 + i) = '\0';
} // We can never dig too deep

int giveBeggingIndex(char s[], int start)
{
    if (*(s + start) == '\0')
        return start;
    while (isspace(*(s + start)))
        start++;
    return start;
} // i.e getting rid of whitespaces

int giveEndingIndex(char s[], int start)
{
    if (*(s + start) == '\0')
        return start; // here is a case as if it was null symbol
    else if (isdigit(*(s + start)))
    {
        while (isdigit(*(s + start)))
            start++;

        if (*(s + start) == '.')
        {
            start++;
            while (isdigit(*(s + start)))
                start++;
        }// fractions support
        return start;
    }
    else
        return start + 1; // otherwise it is symbol and takes one space
} // returun 1 grater symbol than you need

void giveBoundriesOfFragment(char s[], int *start, int *finish)
{
    *start = giveBeggingIndex(s, *start);
    *finish = giveEndingIndex(s, *start);
}

int sayWhatTypeItIs(char s[], int start)
{
    if ('0' <= s[start] && s[start] <= '9')
        return NUMBER;
    else
        return *(s + start); // otherwise it is binary symbol
}
// Text function -END
// Stack -START
int stackP = 0;
double valStack[MAXVAL]; // Tu sa wartosc przechowywane i.e tu jest stos

void push(double valueToAdd)
{
    if (stackP < MAXVAL)
        valStack[stackP++] = valueToAdd;
    else
        printf("\nerror full stack cant add more !");

} // puting f into stack
double pop(void)
{
    if (stackP > 0)
        return valStack[--stackP];
    else
    {
        printf("error empty stack fucker !");
        return 0.0;
    }
}
#define ADJUSTMENT_FOR_LAST 1
void showStack()
{
    for (int i = stackP - ADJUSTMENT_FOR_LAST; 0 <= i; i--)
        printf("%.2lf \n", valStack[i]);
}
void clearStack()
{
    stackP = 0;
}
// Stack Ends here