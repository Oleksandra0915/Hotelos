#ifndef CITY_H
#define CITY_H

#define MAX_CITIES 10
#define MAX_CITY_NAME 50

typedef struct {
    int id;
    char name[MAX_CITY_NAME];
} City;

extern City cities[MAX_CITIES];
extern int citiesCount;

void initializeCities();
void showCities();
int getCityChoice();

#endif