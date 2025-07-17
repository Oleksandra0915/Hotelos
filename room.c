#include <stdio.h>
#include <string.h>
#include "room.h"
#include "hotel.h"

void initializeHotelRooms(Room rooms[], int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isBooked = 0;
        strcpy(rooms[i].guestName, "");
        rooms[i].type = SINGLE;
        rooms[i].price = 0;
    }
}

void showHotelRooms(const Room rooms[], int numRooms) {
    printf("\n--- Номери в готелі ---\n");
    for (int i = 0; i < numRooms; i++) {
        printf("Номер %d (Тип: ", rooms[i].roomNumber);
        switch (rooms[i].type) {
            case SINGLE: printf("Одномісний"); break;
            case DOUBLE: printf("Двомісний"); break;
            case SUITE:  printf("Люкс"); break;
        }
        printf(", Ціна: %d грн) - %s\n", rooms[i].price,
               rooms[i].isBooked ? "Заброньовано" : "Вільний");
    }
}

void addRoomToHotel(Hotel* hotel, int roomNum, RoomType type, int price) {
    if (hotel->roomsCount < MAX_ROOMS_PER_HOTEL) {
        hotel->rooms[hotel->roomsCount].roomNumber = roomNum;
        hotel->rooms[hotel->roomsCount].isBooked = 0;
        strcpy(hotel->rooms[hotel->roomsCount].guestName, "");
        hotel->rooms[hotel->roomsCount].type = type;
        hotel->rooms[hotel->roomsCount].price = price;
        hotel->roomsCount++;
    } else {
        printf("Не вдалося додати номер %d: досягнуто ліміту номерів у готелі %s.\n", roomNum, hotel->name);
    }
}