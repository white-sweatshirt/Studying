// All the fuction used to calculate price of the phone will be here
#include "phones_operetions_on_price.h"

#define PLACE_FOR_BECOMING_LARGER 1

void quickSortByPriceForPhones(struct Phone phones[], int start, int finish)
{
    if (start >= finish)
        return;
    // conqer part

    int smallestIndexOfLargerThanPivot = start;
    int largestIndexOfLargerThanPivot = start; // ich rownosc symoblizuje ze jeszcze nie ma pozyscji wiekszych od pivota
    int notYetSortedStarts = start;
    int pivot = (start + finish - (start + finish) % 2) / 2;
    float valueOfPivot = phones[pivot].price;

    swapPhonesInCataloge(phones, pivot, finish); // ensuring pivot will be on its place

    while (notYetSortedStarts <= finish) // dla od wiekszgo do najwieszgo zamien znaki nierownopsci w prownaniu do wartosci pivota
    {
        if (valueOfPivot < phones[notYetSortedStarts].price)
            largestIndexOfLargerThanPivot++;

        if (valueOfPivot >= phones[notYetSortedStarts].price) // tu moglo by byc else
        {
            swapPhonesInCataloge(phones, notYetSortedStarts, smallestIndexOfLargerThanPivot);

            largestIndexOfLargerThanPivot++;
            smallestIndexOfLargerThanPivot++;
        }

        notYetSortedStarts++;
    }
    if (start < smallestIndexOfLargerThanPivot - PLACE_FOR_PIVOT)
        quickSortByPriceForPhones(phones, start, smallestIndexOfLargerThanPivot - PLACE_FOR_PIVOT);

    if (finish > smallestIndexOfLargerThanPivot + PLACE_FOR_PIVOT)
        quickSortByPriceForPhones(phones, smallestIndexOfLargerThanPivot + PLACE_FOR_PIVOT, finish);
}

float calculateAmmaountOfPixels(struct Phone phones[], int numberInCataloge)
{
    return (float)phones[numberInCataloge].Screen.pixelResolution[0] * (float)phones[numberInCataloge].Screen.pixelResolution[1];
}

float claculatePriceForCameras(struct Phone phones[], int numberInCataloge)
{
    float priceForCameras = 0;

    for (int i = 0; i < phones[numberInCataloge].howManyBackCameras; i++)
        priceForCameras += PRICE_PRICE_FOR_ONE_MP_OF_BACKCAMERA * (float)phones[numberInCataloge].Cameras.backCamereas[i];

    priceForCameras += PRICE_PRICE_FOR_ONE_MP_OF_FRONTCAMERA * (float)phones[numberInCataloge].Cameras.frontCamera;

    return priceForCameras;
}

float calculatePrice(struct Phone phones[], int numberInCataloge)
{
    float totalPrice = 0;

    totalPrice += PRICE_FOR_ONE_GB_OF_RAM * (float)phones[numberInCataloge].builtInMemory;

    totalPrice += claculatePriceForCameras(phones, numberInCataloge);

    totalPrice += (float)PRICE_FOR_ONE_PIXEL * calculateAmmaountOfPixels(phones, numberInCataloge);
    totalPrice += (float)PRICE_FOR_ONE_LEVEL_OF_WIFI_SUPPORT * (float)phones[numberInCataloge].supportedStadnardOfWiFi;
    totalPrice += (float)PRICE_FOR_ONE_GB_OF_INBUILT_MEMORY * (float)phones[numberInCataloge].builtInMemory;

    if (phones[numberInCataloge].hasAi)
        totalPrice *= AI_PREMIUM;

    if (phones[numberInCataloge].isItMapple)
        totalPrice *= MAPPLE_FEE;
    return totalPrice;
}

void calculatePriceOfAllPhones(struct Phone phones[], int potentialNewAddtion)
{
    for (int i = 0; i < potentialNewAddtion; i++)
        phones[i].price = calculatePrice(phones, i);
}