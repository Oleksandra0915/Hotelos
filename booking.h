#ifndef BOOKING_H
#define BOOKING_H

#include "room.h"

void bookHotelRoom(Room rooms[], int numRooms);
void showHotelBookings(const Room rooms[], int numRooms);
void cancelHotelBooking(Room rooms[], int numRooms);

#endif