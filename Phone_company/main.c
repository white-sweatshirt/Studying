#include "finding_and_names.h"
#include "phones_operetions_on_price.h"
#include "phones_showing.h"

#define PLACE_FOR_LAST 1

int main()
{
    int i[MAX_NUMBER_OF_CAMERAS] = {1, 1, 2, 3, 4, 4};
    struct Phone phones[MAX_NUMBER_OF_PHONES_IN_DATABASE] = {
        {"IPhone Xpro Super Duper Uber Duper MegaMax", 1, {1, {3, 4, 4}}, 3, {1, {2, 3}}, 1, 3, 43, 1, 1, (float)1.1}, // najdrozszy
        {"Szajsung", 1, {1, {3, 4, 4}}, 3, {1, {2, 3}}, 0, 3, 43, 1, 0, (float)1.1},                                   // srednio drogi
        {"Motocorola", 1, {1, {3, 4, 4}}, 3, {1, {2, 3}}, 0, 3, 43, 0, 0, (float)1.1},                                 // najtaniszy
        {"Megabit", 1, {1, {3, 4, 4}}, 3, {1, {2, 3}}, 2, 3, 21, 0, 0, (float)1.1}                                     // nieprzeliczony
    };
    int potentialNewAddtion = 4;
    bool maintainLoop = true;

    printf("Hello, and welcome from my kitchen! \n");
    printf("Uwaga dla zachowania wygody wszystkie nazwy modeli nie beda rozrozniac duzych i malych liter!\n");
    while (maintainLoop)
    {
        int choiceOfUser = 0;

        printf("======MENU======\n");
        printf("1- Dodaj telefon do bazy\n");
        printf("2- wypisz wszystkie telefony\n");
        printf("3- znajdz telefon w podanej cenie lub nazwie\n");
        printf("4- wylicz i posortoj telefony - wyswietl ilosc telefonow rosnaco badzi malejaco\n");
        printf("5- sortowanie alfabetyczne\n");
        printf("6- zakoncz petle\n");
        printf("twoj wybor----->");
        scanf("%d", &choiceOfUser);
        printf("================\n");
        switch (choiceOfUser)
        {
        case 1:
            phones[potentialNewAddtion++] = addPhone();
            break;

        case 2:
            showAllPhones(phones, potentialNewAddtion);
            break;

        case 3:
            showPhoneChoiceMenu(phones, potentialNewAddtion);
            break;

        case 4:
            calculatePriceOfAllPhones(phones, potentialNewAddtion);
            quickSortByPriceForPhones(phones, 0, potentialNewAddtion - PLACE_FOR_LAST);
            showingSortedPhonesByPrice(phones, potentialNewAddtion);
            break;

        case 5:
            quicksortAlphabeticly(phones, 0, potentialNewAddtion - PLACE_FOR_LAST);
            break;

        case 6:
            maintainLoop = false;
            break;

        default:
            printf("nie ma takiej opcji!\n");
            break;
        }
    }
    printf("dotarlismy do konca\n");
    return 0;
}
