// Part Showing info About a Phones
#include "phones_showing.h"

void showPartialInfo(struct Phone phones[], int numberInCatalog)
{
    printf("+=======================================================+\n");
    printf("nazwa telefonu: %s\n", phones[numberInCatalog].name);
    printf("numer telefonu w ksiedze : %d\n", numberInCatalog);
    printf("jego cena: %3.2f\n", phones[numberInCatalog].price);
    printf("+=======================================================+\n");
}

void showSystem(struct Phone phones[], int numberInCatalog)
{
    if (phones[numberInCatalog].phoneSystem == ANDROID)
        printf("system telefonu to Android\n");
    else if (phones[numberInCatalog].phoneSystem == IOS)
        printf("system telefonu to IOS\n");
    else
        printf("system telefonu jest niestandardowy\n");
}

void showFullInfo(struct Phone phones[], int numberInCatalog)
{
    printf("+=======================================================+\n");
    printf("nazwa telefonu: %s\n", phones[numberInCatalog].name);

    printf("ilosci ramu w Gb: %d\n", phones[numberInCatalog].volumeOfRam);
    for (int i = 0; i < phones[numberInCatalog].howManyBackCameras && i < MAX_NUMBER_OF_CAMERAS; i++)
        printf("kamera  z tylu nr. %d ma tyle Mgpx :%d \n", i + 1, phones[numberInCatalog].Cameras.backCamereas[i]);

    printf("kamere przednia w Mgpx :%d\n", phones[numberInCatalog].Cameras.frontCamera);

    printf(" przekatna: %d", phones[numberInCatalog].Screen.diagonal);
    printf("pierwsza rozdzielczosc: %d\n", phones[numberInCatalog].Screen.pixelResolution[0]);
    printf("druga rozdzielczosc: %d\n", phones[numberInCatalog].Screen.pixelResolution[1]);

    showSystem(phones, numberInCatalog);
    printf("maksymalny wspierany standard internetu %d G\n", phones[numberInCatalog].supportedStadnardOfWiFi);
    printf(" ilosci pamieci wbudowanej w telefonie w Gb : %d\n", phones[numberInCatalog].builtInMemory);

    if (phones[numberInCatalog].hasAi)
        printf("telefon ma Ai\n");
    else
        printf("telefon nie ma Ai\n");

    if (phones[numberInCatalog].isItMapple)
        printf("telfon jest firmy maplle \n");
    else
        printf("telfon nie jest firmy maplle \n");

    printf("tefon kosztuje %3.2f\n", phones[numberInCatalog].price);

    printf("+=======================================================+\n");
}

void showingPhonesInRisingOrder(struct Phone phones[], int howManyPhonesToShow, int potentialNewAddition)
{
    if (howManyPhonesToShow > 0)
        for (int i = potentialNewAddition - 1; i > giveLargerIntiger(0, potentialNewAddition - howManyPhonesToShow - 1); i--)
            showPartialInfo(phones, i);
}

void showingPhonesInDescendingOrder(struct Phone phones[], int howManyPhonesToShow, int potentialNewAddition)
{
    for (int i = 0; i < giveSmallerIntiger(howManyPhonesToShow, potentialNewAddition); i++)
        showPartialInfo(phones, i);
}

void showPhonesInGivenPrice(struct Phone phones[], int howManyPhonesAre, bool personWantsToKnowEverything)
{
    double minimalPrice = 0;
    double maximumPrice = 0;
    bool foundedPhone = 0;
    printf("podaj widelki cenowe\n");
    printf("podaj cene maksymalna: ");
    scanf("%f", &maximumPrice);
    printf("podaj cene minimalna: ");
    scanf("%f", &minimalPrice);

    for (int i = 0; i < howManyPhonesAre; i++)
    {
        if (phones[i].price <= maximumPrice && !personWantsToKnowEverything && phones[i].price >= minimalPrice)

        {
            showPartialInfo(phones, i);
            foundedPhone = 1;
        }
        else if (phones[i].price <= maximumPrice && phones[i].price >= minimalPrice)

        {
            showFullInfo(phones, i);
            foundedPhone = 1;
        }
    }
    if (!foundedPhone)
        communicateThatPhoneWasntFounded();
}

void showPhoneInGivenName(struct Phone phones[], int potentialNewAddition, bool clientWantsToKnowEverything)
{
    char nameOfModel[LENGHT_OF_NAME];

    printf("podaj nazwe modelu max %d znakow: ", LENGHT_OF_NAME);
    saveText(nameOfModel);

    int numberInCatolage = findPhoneInGivenName(phones, nameOfModel, potentialNewAddition);

    if (numberInCatolage > -1)
    {
        if (clientWantsToKnowEverything)
            showFullInfo(phones, numberInCatolage);
        else
            showPartialInfo(phones, numberInCatolage);
    }
    else
        communicateThatPhoneWasntFounded();
}

void showPhoneChoiceMenu(struct Phone phones[], int potentialNewAddition)
{
    int clientWantsToKnowEverything = 0;
    int nameOrPrice = 1;

    printf("czy chcesz zobaczyc wszystkie detale telefonu ktorego chcesz znalezc? 1-tak 0- nie : ");
    scanf("%d", &clientWantsToKnowEverything);

    printf("wolisz zobaczyc telefony bedace w danych widelkach cenowych -1 \nczy wolisz mze znalezc konkretny model -0?: ");
    scanf("%d", &nameOrPrice);

    if (nameOrPrice)
        showPhonesInGivenPrice(phones, potentialNewAddition, clientWantsToKnowEverything);
    else
        showPhoneInGivenName(phones, potentialNewAddition, clientWantsToKnowEverything);
}

void showAllPhones(struct Phone phones[], int potentialNewAddition)
{
    int clientWantsToKnowEverything = 0;

    printf("powiedz czy chcesz zobarzyc wsztykie detalle (1) czy tylko najwazniejsze(0):  ");
    scanf("%d", &clientWantsToKnowEverything);

    if (clientWantsToKnowEverything == 1)
        for (int i = 0; i < potentialNewAddition; i++)
            showFullInfo(phones, i);
    else
        for (int i = 0; i < potentialNewAddition; i++)
            showPartialInfo(phones, i);
}

void showingSortedPhonesByPrice(struct Phone phones[], int potentialNewAddition)
{
    int howManyPhonesClientWantsToSee = 0;
    int risingOrder = 1;

    printf("chcesz zobaczyc telfony malejaco -1 czy rosnaco -0: ");
    scanf("%d", &risingOrder);
    printf("ile telefonow chcesz zobaczyc: ");
    scanf("%d", &howManyPhonesClientWantsToSee);

    if (risingOrder)
        showingPhonesInRisingOrder(phones, howManyPhonesClientWantsToSee, potentialNewAddition);
    else
        showingPhonesInDescendingOrder(phones, howManyPhonesClientWantsToSee, potentialNewAddition);
}
