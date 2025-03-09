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

#define COS 0
#define SIN 1
#define POWER 2
#define EXP 3

#define MAXVARIBLES 'z' - 'a'
#define VARIBLE_OPTION 'v'

int getop(char s[], double vi[]);
int getline(char s[], int limit);
double pop(void);
void push(double a);
void showStack(void);
void clearStack(void);
void ungets(char s[]);
void showBufor();
struct varible
{
    char name;
    double value;
};

int main()
{
    struct varible kutas;

    int type = 0;
    double op2 = 0.0;
    char s[MAXOP];
    double varibles[MAXVARIBLES];
    while ((type = getop(s, varibles)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
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
    for (int i = 0; i <= MAXVARIBLES; i++)
        printf("\n %c=%.5f", 'a' + i, varibles[i]);
    ungets(s);
    showBufor();
    return 0;
}
int getline(char s[], int limit)
{
    int i = 0;
    int c;
    while ((c = getchar()) != '\n' && c != EOF && i < limit - 1)
        s[i++] = c;
    s[i] = '\0';
    return i;
}
int stackP = 0;
double valStack[MAXVAL];

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

#define BUFOR_SIZE 100  // rozmiar buforu
//zad 4.8 to poprostu wyrzucenie tablicy i patrzenie tym pointerem czy nie zmianna nie byla by juz pelna zostawiam tablice dla gets()
char bufor[BUFOR_SIZE]; // nastepne wolne miesce w buforze
int buforP = 0;
void showBufor()
{
    int bp = buforP;
    printf("\n");
    for (bp; 0 <= bp; bp--)
        printf("%c", bufor[bp]);
}
int getch(void)
{
    if(buforP)
    return (buforP > 0) ? bufor[buforP--] : getchar(); // dorzuci liczbe lub wyjmij zapamietany znak stackPecjalny
} // funkcja buforwa z
void ungetch(char a)
{
    if (buforP < BUFOR_SIZE - 1)
        bufor[++buforP] = a;
    else
        printf("bufor is full!\n");
}
int strlen(char s[])
{
    if (s[0] == '\0')
        return 0;
    int i = 0;
    while (s[i++] != '\0')
        ;
    return i + 1;
}
void ungets(char s[])
{
    int i = strlen(s) - 1;
    while (0 <= i && buforP++ < BUFOR_SIZE)
        ungetch(s[i--]);
}
int mathExpr(char s[], int i, double varibles[]);
int getop(char s[], double varibles[])
{
    int i = 0, c = 0;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (islower(c))
        return mathExpr(s, i, varibles);

    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    else if (c == '-')
    {
        if (!isdigit((s[++i] = c = getch()))) // na potencjalna brak cyfry
        {
            ungetch(c); // zapamietuje znak w buforze aby nie przepadl
            return '-'; // zwrot zaporzyczonego minusa
        }
    }

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
void showStack()
{
    int pb = stackP;
    while (0 <= (pb--))
        printf("%.2f ", valStack[pb]);
    buforP--;
}
void clearStack()
{
    buforP = 0; // i tak zostaje pamiec zarezerwowana bo to statyka
    stackP = 0;
}
#define WORDS 5
#define NMATH_FUNCTIONS 4
#define FIRST_LETTER 0
void strcp(char s[], char s1[], int max)
{
    int i = 0;
    while (i <= max && s1[i] != '\0')
        s[i] = s1[i++];
}

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

    ungetch(c); // wyrzuc znak nie potrzbny lub cyfre
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
}
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