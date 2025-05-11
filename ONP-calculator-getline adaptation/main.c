#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAXOP 100  /*max dlufosc operandu lub operatora*/
#define NUMBER '0' /*sygnal znaleznia liczby*/
#define MAXVAL 100 /* MAX dlugosc stotsu*/

#define SHOW_STACK '~'
#define CLEAN_STACK '!'
#define FINISHED_LINE -2
#define COS 0
#define SIN 1
#define POWER 2
#define EXP 3

#define MAXVARIBLES 'z' - 'a'
#define VARIBLE_OPTION 'v'

int getline(char s[], int limit);
double pop(void);
void push(double a);
void showStack(void);
void clearStack(void);

int mathExpr(char s[], int i, double varibles[]);

int main()
{

    int type = 0;
    double op2 = 0.0;
    char s[MAXOP];
    double varibles[MAXVARIBLES]; // everything w petli wiekszej wczytujacyej wieksze liczby
    while ((type) != EOF)         // tu bedzie funkcja dajaca typ dla danej lonie
    {
        switch (type)
        {
        case NUMBER:
            // dodaj wczesniej konwersje na numerek
            push(atof(s));
            // pamietaj o usunieciu tablicy buforowej
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
        case '\n':
            printf("\t %.8f\n", pop());
            break;
        case EXP:
            op2 = exp(pop());
            push(op2);
            break;
        case SIN:
            push(sin(pop()));
            break;
        case COS:
            push(cos(pop()));
            break;
        case POWER:
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case VARIBLE_OPTION:
            break;
        case CLEAN_STACK:
            clearStack();
            break;
        default:
            printf("blad nie znane polecnie !");
            break;
        }
    }
    for (int i = 0; i < MAXVARIBLES; i++)
        printf("\n %c=%.5f", 'a' + i, varibles[i]);
    ungets(s);
    showBufor();
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
int mstrlen(char s[])
{
    if (s[0] == '\0')
        return 0;
    int i = 0;
    while (s[i++] != '\0')
        ;
    return i + 1;
}
void copyFragmentToNewTable(char s[], char s1[], int start, int finish)
{
    int i = 0;
    while (start < finish)
        *(s1 + i) = *(s + start++);
}
int *declereTable(int size)
{
    int *t = malloc(size * sizeof(int));
    return t;
}
int giveBeggingIndex(char s[], int start)
{
    if (!(*(s + start)))
        return FINISHED_LINE;
    while (isspace(*(s + start++)))
        ;
    return start;
} // i.e getting rid of whitespaces

int giveEndingIndex(char s[], int start)
{
    if (start < 0)
        return start;
    if (isdigit(*(s + start)))
    {
        while (isdigit(*(s + start++)))
            ;
        return start;
    }
    else
        return start + 1; // otherwise it is symbol and takes one room
}

void giveSizeOfFragment(char s[], int *start, int *finish)
{
    *start = giveBeggingIndex(s, *start);
    *finish = giveEndingIndex(s, *start);
}

int sayWhatTypeItIs(char s[], int start)
{
}
// Text function -END
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

void showStack()
{
    for (int i = stackP; 0 <= i; i++)
        printf("%.2f ", valStack[i]);
}

void clearStack()
{
    stackP = 0;
}

#define WORDS 5
#define NMATH_FUNCTIONS 4
#define FIRST_LETTER 0

void initVarible(double varibles[], int c)
{
    double temp = pop();
    varibles[c - 'a'] = temp;
    push(temp);
} // simplest implementaion of coping varible

bool isVarilbe(char s[], int c, int i, int primeI, double varibles[])
{

    if (primeI == (i - 1) && isspace(s[i]))
    {
        initVarible(varibles, s[i - 1]);
        ungetch(c);
        return 1;
    }
    else
        return 0;
}

int giveFunctionNumber(char s[], int c, int i, double varibles[])
{

    s[i] = '\0';
    char functions[NMATH_FUNCTIONS][WORDS] = {{"cos"}, {"sin"}, {"power"}, {"exp"}}; // odpowiednio 0,1,2,3
    for (int j = 0; j < NMATH_FUNCTIONS; j++)
    {
        int isTheSameWord = 1;
        for (int m = 0; m < WORDS; m++)
        {
            if (s[m] != functions[j][m])
            {
                isTheSameWord = 0;
                break;
            }
        }
        if (isTheSameWord > 0)
            return j;
    }
    return -2;
} // TO DO : Rewrite using given string and pointers in it
int mathExpr(char s[], int i, double varibles[])
{
    int primeI = i;
    int c = s[i];
    while (islower(s[++i] = c = getch()))
        ;
    if (isVarilbe(s, c, i, primeI, varibles)) // jezeli nie zmienna to moze funkcja ?
        return 'v';
    else
        return giveFunctionNumber(s, c, i, varibles);
} // function handling matematical expressions
// TO DO : Rewrite using given string and pointers in it