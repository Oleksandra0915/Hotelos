#ifndef HOTEL_H
#define HOTEL_H

#include "city.h"
#include "price.h"
#include "room.h" 

#define MAX_HOTELS 10
#define MAX_HOTEL_NAME 100
#define MAX_ROOMS_PER_HOTEL 20

typedef struct Hotel {
    int id;
    char name[MAX_HOTEL_NAME];
    int cityId;
    int priceRangeId;
    Room rooms[MAX_ROOMS_PER_HOTEL];
    int roomsCount;
} Hotel;

extern Hotel hotels[MAX_HOTELS];
extern int hotelsCount;

void initializeHotels();
void addHotel(const char* name, int cityId, int priceRangeId);
void showHotels();
void filterAndShowHotels(int cityId, int priceRangeId);
Hotel* findHotelById(int id);

#endif