#include <stdio.h>
#include <string.h>
#include "price.h"

PriceRange priceRanges[NUM_PRICE_RANGES];

void initializePriceRanges() {
    priceRanges[0].id = 1;
    priceRanges[0].minPrice = 200;
    priceRanges[0].maxPrice = 700;
    strcpy(priceRanges[0].description, "Від 200 до 700");

    priceRanges[1].id = 2;
    priceRanges[1].minPrice = 700;
    priceRanges[1].maxPrice = 1500;
    strcpy(priceRanges[1].description, "Від 700 до 1500");

    priceRanges[2].id = 3;
    priceRanges[2].minPrice = 1500;
    priceRanges[2].maxPrice = 3000;
    strcpy(priceRanges[2].description, "Від 1500 до 3000");

    priceRanges[3].id = 4;
    priceRanges[3].minPrice = 3000;
    priceRanges[3].maxPrice = 0;
    strcpy(priceRanges[3].description, "Від 3000 і вище");
}

void showPriceRanges() {
    printf("\n--- Цінові діапазони ---\n");
    for (int i = 0; i < NUM_PRICE_RANGES; i++) {
        printf("%d. %s\n", priceRanges[i].id, priceRanges[i].description);
    }
}

int getPriceRangeChoice() {
    int choice;
    printf("Виберіть номер цінового діапазону: ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > NUM_PRICE_RANGES) {
        printf("Невірний вибір діапазону. Будь ласка, введіть номер від 1 до %d: ", NUM_PRICE_RANGES);
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    return choice;
}