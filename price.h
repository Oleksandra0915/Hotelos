#ifndef PRICE_H
#define PRICE_H

#define NUM_PRICE_RANGES 4

typedef struct {
    int id;
    int minPrice;
    int maxPrice;
    char description[50];
} PriceRange;

extern PriceRange priceRanges[NUM_PRICE_RANGES];
void initializePriceRanges();
void showPriceRanges();
int getPriceRangeChoice();

#endif