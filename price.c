#include <stdio.h>
#include "price.h"

PriceRange priceRanges[MAX_PRICE_RANGES];
int priceRangesCount = 0;

void initializePriceRanges() {
    priceRangesCount = 0;
    priceRanges[priceRangesCount].id = 1;
    snprintf(priceRanges[priceRangesCount].name, MAX_PRICE_RANGE_NAME, "Economy (up to 1000 UAH)");
    priceRangesCount++;

    priceRanges[priceRangesCount].id = 2;
    snprintf(priceRanges[priceRangesCount].name, MAX_PRICE_RANGE_NAME, "Standard (1000-2000 UAH)");
    priceRangesCount++;

    priceRanges[priceRangesCount].id = 3;
    snprintf(priceRanges[priceRangesCount].name, MAX_PRICE_RANGE_NAME, "Luxury (from 2000 UAH)");
    priceRangesCount++;
}

void showPriceRanges() {
    printf("\n--- Price Ranges ---\n");
    for (int i = 0; i < priceRangesCount; i++) {
        printf("%d. %s\n", priceRanges[i].id, priceRanges[i].name);
    }
}

int getPriceRangeChoice() {
    int choice;
    printf("Select price range ID: ");
    while (scanf("%d", &choice) != 1 || choice <= 0 || choice > priceRangesCount) {
        printf("Invalid range choice. Please enter a valid ID: ");
        while(getchar() != '\n');
    }
    while(getchar() != '\n');
    return choice;
}

const char* getPriceRangeName(int rangeId) {
    for (int i = 0; i < priceRangesCount; i++) {
        if (priceRanges[i].id == rangeId) {
            return priceRanges[i].name;
        }
    }
    return "Unknown Range";
}