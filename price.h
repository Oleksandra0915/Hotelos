#ifndef PRICE_H
#define PRICE_H

#define MAX_PRICE_RANGES 5
#define MAX_PRICE_RANGE_NAME 50

typedef struct {
    int id;
    char name[MAX_PRICE_RANGE_NAME];
} PriceRange;

extern PriceRange priceRanges[MAX_PRICE_RANGES];
extern int priceRangesCount;

void initializePriceRanges();
void showPriceRanges();
int getPriceRangeChoice();
const char* getPriceRangeName(int rangeId);

#endif