#ifndef FINDING_AND_SHOWING_PHONES_H
#define FINDING_AND_SHOWING_PHONES_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LENGHT_OF_NAME 80
#define MAX_NUMBER_OF_PHONES_IN_DATABASE 50
#define MAX_NUMBER_OF_CAMERAS 8
#define PLACE_FOR_PIVOT 1

enum OperationalSystem
{
    ANDROID,
    IOS,
    OTCHER
};

struct CamerasParameters
{
    int frontCamera;                         // in Mpx
    int backCamereas[MAX_NUMBER_OF_CAMERAS]; // in Mpx
};

struct ScreenParameters
{
    int diagonal;
    int pixelResolution[2];
};

struct Phone
{
    char name[LENGHT_OF_NAME];
    int volumeOfRam;
    struct CamerasParameters Cameras;
    int howManyBackCameras;
    struct ScreenParameters Screen;
    int phoneSystem; // values from zero to two;
    int supportedStadnardOfWiFi;
    int builtInMemory;
    bool hasAi;
    bool isItMapple;
    double price;
};

enum Collors
{
    Yellow,
    White,
    Brown,
    Golden
};

int giveSmallerIntiger(int a, int b);
int giveLargerIntiger(int a, int b);

void swapPhonesInCataloge(struct Phone phones[], int to, int from);
void saveText(char placeToSave[]);
void makeItLowerCase(char characters[]);
void insertFinishCharacter(char name[], int numberOfLastCharacter);
void removeWhiteSymbols(char name[]);
void standariseText(char textToStanadarise[], char standarisedText[]);

void quicksortAlphabeticly(struct Phone phones[], int start, int finish);

void communicateThatPhoneWasntFounded();
int findPhoneInGivenName(struct Phone phones[], char nameOfModel[], int howManyPhonesAre);

int  delatePhone(struct Phone phones[],int potenialNewAddition);
struct Phone addPhone();

#endif