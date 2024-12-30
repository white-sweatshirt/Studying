#ifndef PHONES_SHOWING_H
#define PHONES_SHOWING_H
#include "finding_and_names.h"

void showPartialInfo(struct Phone phones[], int numberInCatalog);
void showSystem(struct Phone phones[], int numberInCatalog);
void showFullInfo(struct Phone phones[], int numberInCatalog);

void showingTopPhonesByHigherPrice(struct Phone phones[], int howManyPhonesToShow, int potentialNewAddition);
void showingTopPhonesByLowerPrice(struct Phone phones[], int howManyPhonesToShow, int potentialNewAddition);

void showPhonesInGivenPrice(struct Phone phones[], int howManyPhonesAre, bool personWantsToKnowEverything);

void showPhoneInGivenName(struct Phone phones[], int potentialNewAddition, bool clientWantsToKnowEverything);
void showPhoneChoiceMenu(struct Phone phones[], int potentialNewAddition);

void showAllPhones(struct Phone phones[], int potentialNewAddition);
void showingSortedPhonesByPrice(struct Phone phones[],int potentialNewAddition);
#endif