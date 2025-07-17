#ifndef ROOM_H
#define ROOM_H

#include "booking.h"

typedef struct Hotel Hotel;

#define MAX_BOOKINGS_PER_ROOM 5

typedef enum {
    SINGLE,
    DOUBLE,
    SUITE
} RoomType;

typedef struct Room {
    int roomNumber;
    RoomType type;
    int price;
    int isBooked;
    Booking bookings[MAX_BOOKINGS_PER_ROOM];
    int bookingsCount;
} Room;

void addRoomToHotel(Hotel* hotel, int roomNum, RoomType type, int price);

void showRoomType(RoomType type);
void showHotelRooms(Room rooms[], int count);
void bookHotelRoom(Room rooms[], int count);
void showHotelBookings(Room rooms[], int count);
void cancelHotelBooking(Room rooms[], int count);
Room* findRoomByNumber(Room rooms[], int count, int roomNumber);

#endif