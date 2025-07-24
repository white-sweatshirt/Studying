#include <stdio.h>
#include <ctype.h>
#define MAX_CHARACTERS 100
int getline(char *s, int n)
{
    int c = 0;
    int i = 0;
    while ((*s++ = c = getchar()) != '\n' && c != '\v' && c != EOF && c != '\0' && i++ < n)
        ;
    *(--s) = '\0'; // bez  nawisu tez by przeszlo
    if (i > 0)
        return 1;
    else
        return 0;
} // getline assumes that all spaces in the line are desiareable
int atoi(int *number, char *text)
{
    int sign = 1;
    while (isspace(*text))
        text++;
    if (!isdigit(*text) && *text != '+' && *text != '-')
        return 0;
    sign = (*text == '-' ? -1 : 1);
    text++;
    *number = 0;
    if (isdigit(*text))
        while (*text != '\0')
            *number = 10 * (*number) + (*text++ - '0');
    *number = *number * sign;
    return 1;
} // atoi with getline implemented above without static buffer
void itoa(int *a, int start, int finsh, int valueStart)
{
    for (int i = start; i < finsh + 1; i++)
        *(a + i) = valueStart++;
}
void reverse(char *s)
{
    int i = 0;
    while (*(s + i++) != '\0')
        ;
    i -= 2; // powrot za index po punkcie '\0'
    int j = 0;
    char temp;
    while (j < i)
    {
        temp = *(s + j);
        *(s + j++) = *(s + i);
        *(s + i--) = temp;
    }
}
int strnindex(char *s, char *t)
{
    for (int i = 0; *(s + i) != '\0'; i++)
    {
        int k = 0, j = i;
        for (; *(s + j) == *(t + k) && *(s + j) != '\0'; j++, k++)
            ;
        if (k > 0 && *(t + k) == '\0')
            return i;
    }
    return -1;
}
int pBuffer = 0;
char buffer[MAX_CHARACTERS] = {};
int getch(void)
{
    return (pBuffer > 0) ? buffer[--pBuffer] : getchar();
}
void ungetch(int c)
{
    if (pBuffer < MAX_CHARACTERS)
        buffer[pBuffer++] = c;
    else
        printf("brak pamieci !");
}
int gettop(double *number)
{
    int c;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != '+' && c != '.' && c != '-')
    {
        ungetch(c); // not a number
        return -1;
    }
    double sign = (c == '-') ? -1.0 : 1.0;
    if (isdigit(c))
        ;
    else if (!isdigit(c = getch()))
    {
        ungetch(c);
        return -2; // not a number
    }
    double power = 1.0f;
    *number = 0.0;
    while (isdigit(c))
    {
        *number = 10 * (*number) + (c - '0');
        c = getch();
    }

    if (c == '.')
    {
        c = getch();
        while (isdigit(c))
        {
            *number = 10 * (*number) + (c - '0');
            c = getch();
            power *= 10;
        }
    }
    if (c != EOF)
        ungetch(c);
    else
        return 0;
    *number *= sign  / power;
    return 1;
} // I am using return fuction as troubleshotting
//werid thing if you change declaration of valabries from double to float
//then after a point you will have random numbers.
int main()
{
    double number = 0;
    char s[MAX_CHARACTERS];
    char t[MAX_CHARACTERS];
    while (gettop(&number)>0)
        printf("liczba: %f\n", number);

    return 0;
}