#include <stdio.h>
#include <string.h>
#include "hotel.h"
#include "city.h"
#include "room.h"
#include "price.h"

Hotel hotels[MAX_HOTELS];
int hotelsCount = 0;

void initializeHotels() {
    if (citiesCount == 0) {
        initializeCities();
    }
    initializePriceRanges();

    hotels[hotelsCount].id = ++hotelsCount;
    strcpy(hotels[hotelsCount-1].name, "Гранд Готель Київ");
    hotels[hotelsCount-1].city = cities[0];
    hotels[hotelsCount-1].priceRange = priceRanges[1];

    hotels[hotelsCount-1].roomsCount = 0;
    addRoomToHotel(&hotels[hotelsCount-1], 101, SINGLE, 800);
    addRoomToHotel(&hotels[hotelsCount-1], 102, DOUBLE, 1200);
    addRoomToHotel(&hotels[hotelsCount-1], 103, SUITE, 1500);

    hotels[hotelsCount].id = ++hotelsCount;
    strcpy(hotels[hotelsCount-1].name, "Львівська Опера");
    hotels[hotelsCount-1].city = cities[1];
    hotels[hotelsCount-1].priceRange = priceRanges[0];

    hotels[hotelsCount-1].roomsCount = 0;
    addRoomToHotel(&hotels[hotelsCount-1], 201, SINGLE, 400);
    addRoomToHotel(&hotels[hotelsCount-1], 202, DOUBLE, 650);

    hotels[hotelsCount].id = ++hotelsCount;
    strcpy(hotels[hotelsCount-1].name, "Морський Бриз");
    hotels[hotelsCount-1].city = cities[2];
    hotels[hotelsCount-1].priceRange = priceRanges[2];

    hotels[hotelsCount-1].roomsCount = 0;
    addRoomToHotel(&hotels[hotelsCount-1], 301, SUITE, 2000);
    addRoomToHotel(&hotels[hotelsCount-1], 302, DOUBLE, 1800);
    addRoomToHotel(&hotels[hotelsCount-1], 303, SINGLE, 1600);

    hotels[hotelsCount].id = ++hotelsCount;
    strcpy(hotels[hotelsCount-1].name, "Харківська Фортеця");
    hotels[hotelsCount-1].city = cities[3];
    hotels[hotelsCount-1].priceRange = priceRanges[1];

    hotels[hotelsCount-1].roomsCount = 0;
    addRoomToHotel(&hotels[hotelsCount-1], 401, DOUBLE, 900);
    addRoomToHotel(&hotels[hotelsCount-1], 402, SINGLE, 750);

    hotels[hotelsCount].id = ++hotelsCount;
    strcpy(hotels[hotelsCount-1].name, "Дніпровські Зорі");
    hotels[hotelsCount-1].city = cities[4];
    hotels[hotelsCount-1].priceRange = priceRanges[3];

    hotels[hotelsCount-1].roomsCount = 0;
    addRoomToHotel(&hotels[hotelsCount-1], 501, SUITE, 3500);
    addRoomToHotel(&hotels[hotelsCount-1], 502, DOUBLE, 3200);
}

void showHotels() {
    printf("\n--- Доступні готелі ---\n");
    for (int i = 0; i < hotelsCount; i++) {
        printf("%d. %s (%s, %s)\n",
               hotels[i].id,
               hotels[i].name,
               hotels[i].city.name,
               hotels[i].priceRange.description);
    }
}

int getHotelChoice() {
    int choice;
    printf("Виберіть номер готелю: ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > hotelsCount) {
        printf("Невірний вибір готелю. Будь ласка, введіть номер від 1 до %d: ", hotelsCount);
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    return choice;
}

Hotel* findHotelById(int hotelId) {
    for (int i = 0; i < hotelsCount; i++) {
        if (hotels[i].id == hotelId) {
            return &hotels[i];
        }
    }
    return NULL;
}

void filterAndShowHotels(int cityChoice, int priceRangeChoice) {
    printf("\n--- Результати пошуку готелів ---\n");
    int foundCount = 0;
    for (int i = 0; i < hotelsCount; i++) {
        int cityMatch = (cityChoice == 0) || (hotels[i].city.id == cityChoice);
        int priceMatch = (priceRangeChoice == 0) || (hotels[i].priceRange.id == priceRangeChoice);

        if (cityMatch && priceMatch) {
            printf("%d. %s (%s, %s)\n",
                   hotels[i].id,
                   hotels[i].name,
                   hotels[i].city.name,
                   hotels[i].priceRange.description);
            foundCount++;
        }
    }
    if (foundCount == 0) {
        printf("Готелів за вказаними критеріями не знайдено.\n");
    }
}