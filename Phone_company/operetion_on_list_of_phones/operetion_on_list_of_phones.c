#include "operetion_on_list_of_phones.h"

int delatePhone(struct Phone phones[], int potenialNewAddition)
{
    char nameToDelate[LENGHT_OF_NAME];
    printf("podaj nazwe telefonu ktory chcesz usunac :");
    saveText(nameToDelate);
    int deletionIndex = findPhoneInGivenName(phones, nameToDelate, potenialNewAddition);
    if (deletionIndex > -1)
    {
        swapPhonesInCataloge(phones, deletionIndex, potenialNewAddition - PLACE_ON_END);
        return potenialNewAddition - MAKING_DELATED_PHONE_WORK_SPACE;
    }
    else
        communicateThatPhoneWasntFounded();
    return potenialNewAddition;
}

struct Phone addPhone() // biedna funkcja nie ma gdzie sie podziac
{
    struct Phone phoneToAdd;
    printf("podaj nazwe telefonu: ");
    saveText(phoneToAdd.name);

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

    printf("podaj system telefonu %d-Android, %d-IOS, %d-Inne :", ANDROID, IOS, OTCHER);
    scanf("%d", &phoneToAdd.phoneSystem);

    printf("podaj maksymalny wspierany standard internetu: ");
    scanf("%d", &phoneToAdd.supportedStadnardOfWiFi);
    printf("podaj ilosci pamieci wbudowanej w telefonie w Gb: ");
    scanf("%d", &phoneToAdd.builtInMemory);
    printf("podaj 1- jerzeli  telefon ma wbudowane Ai natomiast 0- jerzeli nie ma  wbudowanego ai: ");
    scanf("%d", &phoneToAdd.hasAi);
    printf("podaj 1- jerzeli telfon jest firmy maplle 0- jerzeli  telfon nie jest firmy maplle: ");
    scanf("%d", &phoneToAdd.isItMapple);

    phoneToAdd.price = 0; // robocza wartosc
    return phoneToAdd;
}