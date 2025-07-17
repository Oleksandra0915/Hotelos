#ifndef HOTEL_H
#define HOTEL_H

#include "city.h"
#include "room.h"
#include "price.h"

#define MAX_HOTELS 10
#define MAX_HOTEL_NAME 100
#define MAX_ROOMS_PER_HOTEL 20

typedef struct {
    int id;
    char name[MAX_HOTEL_NAME];
    City city;
    Room rooms[MAX_ROOMS_PER_HOTEL];
    int roomsCount;
    PriceRange priceRange;
} Hotel;

extern Hotel hotels[MAX_HOTELS];
extern int hotelsCount;

void initializeHotels();
void showHotels();
int getHotelChoice();
Hotel* findHotelById(int hotelId);
void filterAndShowHotels(int cityChoice, int priceRangeChoice);

#endif