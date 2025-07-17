#ifndef ROOM_H
#define ROOM_H

#define MAX_NAME 100

typedef enum {
    SINGLE,
    DOUBLE,
    SUITE
} RoomType;

typedef struct {
    int roomNumber;
    int isBooked;
    char guestName[MAX_NAME];
    RoomType type;
    int price;
} Room;

struct Hotel;

void initializeHotelRooms(Room rooms[], int numRooms);
void showHotelRooms(const Room rooms[], int numRooms);
void addRoomToHotel(struct Hotel* hotel, int roomNum, RoomType type, int price);

#endif