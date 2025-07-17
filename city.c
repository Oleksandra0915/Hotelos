#include <stdio.h>
#include "city.h"

City cities[MAX_CITIES];
int citiesCount = 0;

void initializeCities() {
    citiesCount = 0;
    cities[citiesCount].id = 1;
    snprintf(cities[citiesCount].name, MAX_CITY_NAME, "Kyiv");
    citiesCount++;

    cities[citiesCount].id = 2;
    snprintf(cities[citiesCount].name, MAX_CITY_NAME, "Lviv");
    citiesCount++;

    cities[citiesCount].id = 3;
    snprintf(cities[citiesCount].name, MAX_CITY_NAME, "Odesa");
    citiesCount++;
}

void showCities() {
    printf("\n--- Cities ---\n");
    for (int i = 0; i < citiesCount; i++) {
        printf("%d. %s\n", cities[i].id, cities[i].name);
    }
}

int getCityChoice() {
    int choice;
    printf("Select city ID: ");
    while (scanf("%d", &choice) != 1 || choice <= 0 || choice > citiesCount) {
        printf("Invalid city choice. Please enter a valid ID: ");
        while(getchar() != '\n');
    }
    while(getchar() != '\n');
    return choice;
}

const char* getCityName(int cityId) {
    for (int i = 0; i < citiesCount; i++) {
        if (cities[i].id == cityId) {
            return cities[i].name;
        }
    }
    return "Unknown City";
}