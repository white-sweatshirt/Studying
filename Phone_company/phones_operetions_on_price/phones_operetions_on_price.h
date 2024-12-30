#ifndef PHONES_OPERETIONS_ON_PRICE_H
#define PHONES_OPERETIONS_ON_PRICE_H

#include "finding_and_names.h"

#define PRICE_FOR_ONE_GB_OF_RAM 3
#define PRICE_PRICE_FOR_ONE_MP_OF_BACKCAMERA 0.1
#define PRICE_PRICE_FOR_ONE_MP_OF_FRONTCAMERA 2
#define PRICE_FOR_ONE_PIXEL 0.1
#define PRICE_FOR_ONE_LEVEL_OF_WIFI_SUPPORT 80
#define PRICE_FOR_ONE_GB_OF_INBUILT_MEMORY 30
#define AI_PREMIUM 1.2
#define MAPPLE_FEE 2

void quickSortByPriceForPhones(struct Phone phones[], int start, int finish);

float calculateAmmaountOfPixels(struct Phone phones[], int numberInCataloge);
float claculatePriceForCameras(struct Phone phones[], int numberInCataloge);
float calculatePrice(struct Phone phones[], int numberInCataloge);

void calculatePriceOfAllPhones(struct Phone phones[], int potentialNewAddtion);

#endif