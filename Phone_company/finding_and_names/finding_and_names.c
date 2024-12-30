#include "finding_and_names.h"
#define MOVMENT_TO_LOWER_CASE 'a' - 'A' // it is standard lenght for all letters betewwen lower and upper
#define PLACE_ON_END 1

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
    name[numberOfLastCharacter + 1] = '\0';
}

void removeWhiteSymbols(char name[])
{
    int i = 0,j=0 ;
    char rewritten[LENGHT_OF_NAME] = "\0";
    while (name[i] != '\0')
    {
        if (name[i] == ' ' || name[i] == '\t')
            i++;
        else
            rewritten[j++] = name[i++];
    }
    insertFinishCharacter(rewritten, i);
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
    int i = 0;
    for (int i = 0; i < giveSmallerIntiger(strnlen(standarisedNameOfFirstPhone, LENGHT_OF_NAME), strnlen(standarisedNameOfSecundPhone, LENGHT_OF_NAME)); i++)
    {
        if (standarisedNameOfFirstPhone[i] > standarisedNameOfSecundPhone[i])
            return 1;
        if (standarisedNameOfFirstPhone[i] < standarisedNameOfSecundPhone[i])
            return 0;
    }
    if (strnlen(standarisedNameOfFirstPhone, LENGHT_OF_NAME) > strnlen(standarisedNameOfSecundPhone, LENGHT_OF_NAME))
        return 0;
    else
        return 1;
}
void quicksortAlphabeticly(struct Phone phones[], int start, int finish)
{
    if (start >= finish)
        return;
    int smallestIndexOfGranderThanPivot = start;
    int largestIndexOfGranderThanPivot = start;
    int currentUnsortedIndex = start;
    int pivot = (start + finish - (start + finish) % 2) / 2;
    char valueOfPivot[LENGHT_OF_NAME];

    standariseText(phones[pivot].name, valueOfPivot);
    swapPhonesInCataloge(phones, finish, pivot);

    while (currentUnsortedIndex <= finish) // conqer part
    {
        if (isFirstBeforeSecund(phones[currentUnsortedIndex].name, valueOfPivot))
            largestIndexOfGranderThanPivot++;
        else
        {
            swapPhonesInCataloge(phones, smallestIndexOfGranderThanPivot, currentUnsortedIndex);
            largestIndexOfGranderThanPivot++;
            smallestIndexOfGranderThanPivot++;

        }

        currentUnsortedIndex++;
    }

    if (smallestIndexOfGranderThanPivot - PLACE_FOR_PIVOT > start)
        quicksortAlphabeticly(phones, start, smallestIndexOfGranderThanPivot - PLACE_FOR_PIVOT);
    if (smallestIndexOfGranderThanPivot + PLACE_FOR_PIVOT < finish)
        quicksortAlphabeticly(phones, smallestIndexOfGranderThanPivot + PLACE_FOR_PIVOT, finish);
}
bool areTextTheSame(char text1[],char text2[] )
{
    if(strlen(text1)!=strlen(text2))
        return 0;

    for(int i=0;i<strlen(text1);i++)
        if(text1[i]!=text2[i])
            return 0;

    return 1;
    
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

struct Phone addPhone()// biedna funkcja nie ma gdzie sie podziac
{
    struct Phone phoneToAdd;
    printf("podaj nazwe telefonu: ");
    scanf("%s", phoneToAdd.name);

    printf("podaj ilosci ramu w Gb: ");
    scanf("%d", &phoneToAdd.volumeOfRam);

    printf("podaj ilosc kamer z tlu kamery i ich parametry");
    scanf("%d", &phoneToAdd.howManyBackCameras);
    for (int i = 0; i < phoneToAdd.howManyBackCameras && i < MAX_NUMBER_OF_CAMERAS; i++)
    {
        printf("podaj kamere numer %d :", i + 1);
        scanf("%d", &phoneToAdd.Cameras.backCamereas[i]);
    }
    printf("podaj kamere przednia w Mgpx: ");
    scanf("%d", &phoneToAdd.Cameras.frontCamera);

    printf("podaj parametry wyswietlacza!!!\n");
    printf("podaj przekatna: ");
    scanf("%d", &phoneToAdd.Screen.diagonal);
    printf("podaj pierwsza rozdzielczosc: ");
    scanf("%d", &phoneToAdd.Screen.pixelResolution[0]);
    printf("podaj druga rozdzielczosc: ");
    scanf("%d", &phoneToAdd.Screen.pixelResolution[1]);

    int system;
    printf("podaj system telefonu %d-Android, %d-IOS, %d-Inne :", ANDROID, IOS, OTCHER);
    scanf("%d", &system);
    phoneToAdd.phoneSystem = system - 1;

    printf("podaj maksymalny wspierany standard internetu: ");
    scanf("%d", &phoneToAdd.supportedStadnardOfWiFi);
    printf("podaj ilosci pamieci wbudowanej w telefonie w Gb: ");
    scanf("%d", &phoneToAdd.builtInMemory);
    printf("podaj 1- jerzeli  telefon ma wbudowane Ai natomiast 0- jerzeli nie ma  wbudowanego ai: ");
    scanf("%d", &phoneToAdd.hasAi);
    printf("podaj 1- jerzeli telfon jest firmy maplle 0- jerzeli  telfon nie jest firmy maplle: ");
    scanf("%d", &phoneToAdd.isItMapple);

    phoneToAdd.price=0;//robocza wartosc
    return phoneToAdd;
}