#include "finding_and_names.h"
#define MOVMENT_TO_LOWER_CASE 'a' - 'A' // it is standard lenght for all letters betewwen lower and upper


int giveSmallerIntiger(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int giveLargerIntiger(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// Zawiera Funkcje operujace na nazwach i podstatwowe
void saveText(char placeToSave[])
{
    int i = 0, charaterFromInput = 0;
    charaterFromInput = getchar();
    while (((charaterFromInput = getchar()) != '\n') && i < LENGHT_OF_NAME - PLACE_ON_END)
    {
        placeToSave[i] = charaterFromInput;
        i++;
    }
    placeToSave[i] = '\0';
}
void makeItLowerCase(char characters[])
{
    for (int i = 0; characters[i] != '\0' && i < LENGHT_OF_NAME; i++)
    {
        if (characters[i] >= 'A' && characters[i] <= 'Z')
            characters[i] = characters[i] + MOVMENT_TO_LOWER_CASE;
    }
}

void insertFinishCharacter(char name[], int numberOfLastCharacter)
{
    name[numberOfLastCharacter] = '\0';
}

void removeWhiteSymbols(char name[])
{
    int i = 0, j = 0;
    char rewritten[LENGHT_OF_NAME];
    while (name[i] != '\0')
    {
        if (name[i] == ' ' || name[i] == '\t')
            i++;
        else
            rewritten[j++] = name[i++];
    }
    insertFinishCharacter(rewritten, j);
    i = 0;
    while (rewritten[i] != '\0')
    {
        name[i] = rewritten[i];
        i++;
    }
    insertFinishCharacter(name, i);
}
void standariseText(char textToStanadarise[], char standarisedText[])
{
    strcpy(standarisedText, textToStanadarise);
    makeItLowerCase(standarisedText);
    removeWhiteSymbols(standarisedText);
}
void swapPhonesInCataloge(struct Phone phones[], int to, int from)
{
    struct Phone temproray = phones[to];
    phones[to] = phones[from];
    phones[from] = temproray;
}
bool isFirstBeforeSecund(char firstName[], char secondName[])
{
    char standarisedNameOfFirstPhone[LENGHT_OF_NAME];
    char standarisedNameOfSecundPhone[LENGHT_OF_NAME];

    standariseText(firstName, standarisedNameOfFirstPhone);
    standariseText(secondName, standarisedNameOfSecundPhone);

    for (int i = 0; i < giveSmallerIntiger(strlen(standarisedNameOfFirstPhone), strlen(standarisedNameOfSecundPhone)); i++)
    {
        if (standarisedNameOfFirstPhone[i] > standarisedNameOfSecundPhone[i])
            return 0;
        if (standarisedNameOfFirstPhone[i] < standarisedNameOfSecundPhone[i])
            return 1;
    }
    if (strlen(standarisedNameOfFirstPhone) > strlen(standarisedNameOfSecundPhone))
        return 0;
    else
        return 1;
}
int divsionInQuickSortAlphabeticly(struct Phone phones[], int start, int finish)
{
    int current = start;
    int borderBetweetnLargerAndSmaller = start;
    while (current < finish)
    {
        if (isFirstBeforeSecund(phones[current].name, phones[finish].name))
        {
            swapPhonesInCataloge(phones, current, borderBetweetnLargerAndSmaller);
            borderBetweetnLargerAndSmaller++;
            
        }
        current++;
    }
    swapPhonesInCataloge(phones, borderBetweetnLargerAndSmaller, finish);
    return borderBetweetnLargerAndSmaller;
}
void quicksortAlphabeticly(struct Phone phones[], int start, int finish)
{
    if (start >= finish)
        return;
    int lineOfdivision = 0;
    int pivot = (start + finish) / 2;

    swapPhonesInCataloge(phones, finish, pivot);

    lineOfdivision = divsionInQuickSortAlphabeticly(phones, start, finish);

    if (lineOfdivision - PLACE_FOR_PIVOT > start)
        quicksortAlphabeticly(phones, start, lineOfdivision - PLACE_FOR_PIVOT);
    if (lineOfdivision + PLACE_FOR_PIVOT < finish)
        quicksortAlphabeticly(phones, lineOfdivision + PLACE_FOR_PIVOT, finish);
}
bool areTextTheSame(char text1[], char text2[])
{
    if (strlen(text1) != strlen(text2))
        return 0;

    for (int i = 0; i < strlen(text1); i++)
        if (text1[i] != text2[i])
            return 0;

    return 1;
}

void communicateThatPhoneWasntFounded()
{
    printf("nie znaleziono takiego modelu!\n");
}
int findPhoneInGivenName(struct Phone phones[], char nameOfModel[], int howManyPhonesAre)
{

    int i = 0;
    for (i = 0; i < howManyPhonesAre; i++)
    {
        char lowerCaseInBase[LENGHT_OF_NAME];
        char lowerCaseToFind[LENGHT_OF_NAME];
        standariseText(nameOfModel, lowerCaseToFind);
        standariseText(phones[i].name, lowerCaseInBase);
        if (areTextTheSame(lowerCaseInBase, lowerCaseToFind))
            return i;
    }
    return -1; // wartosc ze nie znaleziono
}
