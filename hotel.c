#include <stdio.h>
#include <string.h>
#include "hotel.h" 

Hotel hotels[MAX_HOTELS];
int hotelsCount = 0;

void initializeHotels() {
    hotelsCount = 0;

    addHotel("Grand Hotel Kyiv", 1, 1);
    addHotel("Lviv Plaza", 2, 2);
    addHotel("Odesa Beach Resort", 3, 3);
    addHotel("Kyiv City Stay", 1, 2);
    addHotel("Lviv Boutique", 2, 1);

    if (hotelsCount > 0) {
        addRoomToHotel(&hotels[0], 101, SINGLE, 800);
        addRoomToHotel(&hotels[0], 102, DOUBLE, 1200);
        addRoomToHotel(&hotels[0], 103, SUITE, 2500);
    }
    if (hotelsCount > 1) {
        addRoomToHotel(&hotels[1], 201, SINGLE, 750);
        addRoomToHotel(&hotels[1], 202, DOUBLE, 1100);
    }
}

void addHotel(const char* name, int cityId, int priceRangeId) {
    if (hotelsCount < MAX_HOTELS) {
        hotels[hotelsCount].id = hotelsCount + 1;
        strcpy(hotels[hotelsCount].name, name);
        hotels[hotelsCount].cityId = cityId;
        hotels[hotelsCount].priceRangeId = priceRangeId;
        hotels[hotelsCount].roomsCount = 0;
        hotelsCount++;
    } else {
        printf("Cannot add more hotels. Maximum capacity reached.\n");
    }
}

void showHotels() {
    if (hotelsCount == 0) {
        printf("No hotels available.\n");
        return;
    }
    printf("\n--- Available Hotels ---\n");
    for (int i = 0; i < hotelsCount; i++) {
        printf("ID: %d, Name: %s, City: %s, Price Range: %s\n",
               hotels[i].id, hotels[i].name,
               getCityName(hotels[i].cityId),
               getPriceRangeName(hotels[i].priceRangeId));
    }
}

void filterAndShowHotels(int cityId, int priceRangeId) {
    int found = 0;
    printf("\n--- Filtered Hotels ---\n");
    for (int i = 0; i < hotelsCount; i++) {
        int cityMatch = (cityId == 0 || hotels[i].cityId == cityId);
        int priceMatch = (priceRangeId == 0 || hotels[i].priceRangeId == priceRangeId);

        if (cityMatch && priceMatch) {
            printf("ID: %d, Name: %s, City: %s, Price Range: %s\n",
                   hotels[i].id, hotels[i].name,
                   getCityName(hotels[i].cityId),
                   getPriceRangeName(hotels[i].priceRangeId));
            found = 1;
        }
    }
    if (!found) {
        printf("No hotels found matching the criteria.\n");
    }
}

Hotel* findHotelById(int id) {
    for (int i = 0; i < hotelsCount; i++) {
        if (hotels[i].id == id) {
            return &hotels[i];
        }
    }
    return NULL;
}