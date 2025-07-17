#include <stdio.h>
#include <string.h>
#include "city.h"

City cities[MAX_CITIES];
int citiesCount = 0;

void initializeCities() {
    if (citiesCount == 0) {
        strcpy(cities[citiesCount].name, "Київ");
        cities[citiesCount].id = ++citiesCount;

        strcpy(cities[citiesCount].name, "Львів");
        cities[citiesCount].id = ++citiesCount;

        strcpy(cities[citiesCount].name, "Одеса");
        cities[citiesCount].id = ++citiesCount;

        strcpy(cities[citiesCount].name, "Харків");
        cities[citiesCount].id = ++citiesCount;

        strcpy(cities[citiesCount].name, "Дніпро");
        cities[citiesCount].id = ++citiesCount;
    }
}

void showCities() {
    printf("\n--- Доступні міста ---\n");
    for (int i = 0; i < citiesCount; i++) {
        printf("%d. %s\n", cities[i].id, cities[i].name);
    }
}

int getCityChoice() {
    int choice;
    printf("Виберіть номер міста: ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > citiesCount) {
        printf("Невірний вибір міста. Будь ласка, введіть номер від 1 до %d: ", citiesCount);
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    return choice;
}