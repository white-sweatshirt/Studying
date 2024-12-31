// All the fuction used to calculate price of the phone will be here
#include "phones_operetions_on_price.h"
#define PLACE_FOR_BECOMING_LARGER 1
int divisonForQuickSortForPrices(struct Phone phones[], int start, int finish)
{
    int current=start;
    int borderBetweenLargerAndSmaller=start;
    while (current<finish)
    {
        if(phones[current].price<=phones[finish].price)
            {
                swapPhonesInCataloge(phones,current,borderBetweenLargerAndSmaller);
                borderBetweenLargerAndSmaller++;
            }
            
        current++;
    }
    swapPhonesInCataloge(phones,borderBetweenLargerAndSmaller,finish);
    return borderBetweenLargerAndSmaller;
}
void quickSortByPriceForPhones(struct Phone phones[], int start, int finish)
{
    if (start >= finish)
        return;
    int borderBetweetLargerAndSmaller=start;
    int pivot = (start + finish) / 2;
    swapPhonesInCataloge(phones,finish,pivot);
    borderBetweetLargerAndSmaller=divisonForQuickSortForPrices(phones,start,finish);
    if (borderBetweetLargerAndSmaller - PLACE_FOR_PIVOT > start)
        quickSortByPriceForPhones(phones, start, borderBetweetLargerAndSmaller - PLACE_FOR_PIVOT);

    if (borderBetweetLargerAndSmaller + PLACE_FOR_PIVOT < finish)
        quickSortByPriceForPhones(phones, borderBetweetLargerAndSmaller + PLACE_FOR_PIVOT, finish);
}

double calculateAmmaountOfPixels(struct Phone phones[], int numberInCataloge)
{
    return (double)phones[numberInCataloge].Screen.pixelResolution[0] * (double)phones[numberInCataloge].Screen.pixelResolution[1];
}

double claculatePriceForCameras(struct Phone phones[], int numberInCataloge)
{
    double priceForCameras = 0;

    for (int i = 0; i < phones[numberInCataloge].howManyBackCameras; i++)
        priceForCameras += PRICE_PRICE_FOR_ONE_MP_OF_BACKCAMERA * (double)phones[numberInCataloge].Cameras.backCamereas[i];

    priceForCameras += PRICE_PRICE_FOR_ONE_MP_OF_FRONTCAMERA * (double)phones[numberInCataloge].Cameras.frontCamera;

    return priceForCameras;
}

double calculatePrice(struct Phone phones[], int numberInCataloge)
{
    double totalPrice = 0;

    totalPrice += PRICE_FOR_ONE_GB_OF_RAM * (double)phones[numberInCataloge].builtInMemory;

    totalPrice += claculatePriceForCameras(phones, numberInCataloge);

    totalPrice += (double)PRICE_FOR_ONE_PIXEL * calculateAmmaountOfPixels(phones, numberInCataloge);
    totalPrice += (double)PRICE_FOR_ONE_LEVEL_OF_WIFI_SUPPORT * (double)phones[numberInCataloge].supportedStadnardOfWiFi;
    totalPrice += (double)PRICE_FOR_ONE_GB_OF_INBUILT_MEMORY * (double)phones[numberInCataloge].builtInMemory;

    if (phones[numberInCataloge].hasAi)
        totalPrice *= AI_PREMIUM;

    if (phones[numberInCataloge].isItMapple)
        totalPrice *= MAPPLE_FEE;
    return totalPrice;
}
double roundDestroyNumbersAfterPoint(double a)
{
    a = 1000 * a;
    int temprorary = (int)a;
    if (temprorary % 10 >= 5)
        temprorary = temprorary + 10;
    temprorary = temprorary - temprorary % 10;
    a = (double)temprorary;
    a = a / 1000;
    return a;
}
void calculatePriceOfAllPhones(struct Phone phones[], int potentialNewAddtion)
{
    for (int i = 0; i < potentialNewAddtion; i++)
        phones[i].price = roundDestroyNumbersAfterPoint(calculatePrice(phones, i));
}