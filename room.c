#include <stdio.h>
#include <string.h>
#include "room.h"
#include "hotel.h"

void addRoomToHotel(Hotel* hotel, int roomNum, RoomType type, int price) {
    if (hotel != NULL && hotel->roomsCount < MAX_ROOMS_PER_HOTEL) {
        Room newRoom;
        newRoom.roomNumber = roomNum;
        newRoom.type = type;
        newRoom.price = price;
        newRoom.isBooked = 0;
        newRoom.bookingsCount = 0;
        hotel->rooms[hotel->roomsCount++] = newRoom;
    }
}

void showRoomType(RoomType type) {
    switch (type) {
        case SINGLE:
            printf("Single");
            break;
        case DOUBLE:
            printf("Double");
            break;
        case SUITE:
            printf("Suite");
            break;
        default:
            printf("Unknown");
            break;
    }
}

void showHotelRooms(Room rooms[], int count) {
    if (count == 0) {
        printf("No rooms available for this hotel.\n");
        return;
    }
    printf("\n--- Available Rooms ---\n");
    for (int i = 0; i < count; i++) {
        printf("Room: %d, Type: ", rooms[i].roomNumber);
        showRoomType(rooms[i].type);
        printf(", Price: %d UAH, Status: %s", rooms[i].price, rooms[i].isBooked ? "Booked" : "Available");

        if (rooms[i].isBooked && rooms[i].bookingsCount > 0) {
            printf(", Booked by: %s", rooms[i].bookings[0].customerName);
        }
        printf("\n");
    }
}

void bookHotelRoom(Room rooms[], int count) {
    int roomNumber;
    char customerName[MAX_CUSTOMER_NAME];
    printf("Enter room number to book: ");
    while (scanf("%d", &roomNumber) != 1) {
        printf("Invalid input. Please enter a number: ");
        while(getchar() != '\n');
    }
    while(getchar() != '\n');

    Room* room = findRoomByNumber(rooms, count, roomNumber);
    if (room != NULL) {
        if (!room->isBooked) {
            if (room->bookingsCount < MAX_BOOKINGS_PER_ROOM) {
                printf("Enter your name: ");
                fgets(customerName, sizeof(customerName), stdin);
                customerName[strcspn(customerName, "\n")] = 0;

                Booking newBooking;
                newBooking.id = room->bookingsCount + 1;
                strcpy(newBooking.customerName, customerName);
                room->bookings[room->bookingsCount++] = newBooking;

                room->isBooked = 1;
                printf("Room %d successfully booked for %s.\n", roomNumber, customerName);
            } else {
                printf("Maximum number of bookings for this room reached.\n");
            }
        } else {
            printf("Room %d is already booked.\n", roomNumber);
        }
    } else {
        printf("Room %d not found.\n", roomNumber);
    }
}

void showHotelBookings(Room rooms[], int count) {
    int foundBookings = 0;
    printf("\n--- My Bookings ---\n");
    for (int i = 0; i < count; i++) {
        if (rooms[i].isBooked) {
            for (int j = 0; j < rooms[i].bookingsCount; j++) {
                printf("Room: %d, Client: %s (Booking ID: %d)\n", rooms[i].roomNumber, rooms[i].bookings[j].customerName, rooms[i].bookings[j].id);
                foundBookings = 1;
            }
        }
    }
    if (!foundBookings) {
        printf("No active bookings.\n");
    }
}

void cancelHotelBooking(Room rooms[], int count) {
    int roomNumber;
    int bookingId;
    printf("Enter the room number whose booking you want to cancel: ");
    while (scanf("%d", &roomNumber) != 1) {
        printf("Invalid input. Please enter a number: ");
        while(getchar() != '\n');
    }
    while(getchar() != '\n');

    printf("Enter the booking ID you want to cancel: ");
    while (scanf("%d", &bookingId) != 1) {
        printf("Invalid input. Please enter a number: ");
        while(getchar() != '\n');
    }
    while(getchar() != '\n');

    Room* room = findRoomByNumber(rooms, count, roomNumber);
    if (room != NULL) {
        if (room->isBooked) {
            int bookingFound = 0;
            for (int i = 0; i < room->bookingsCount; i++) {
                if (room->bookings[i].id == bookingId) {
                    for (int j = i; j < room->bookingsCount - 1; j++) {
                        room->bookings[j] = room->bookings[j+1];
                    }
                    room->bookingsCount--;
                    if (room->bookingsCount == 0) {
                        room->isBooked = 0;
                    }
                    printf("Booking ID %d for room %d successfully cancelled.\n", bookingId, roomNumber);
                    bookingFound = 1;
                    break;
                }
            }
            if (!bookingFound) {
                printf("Booking with ID %d for room %d not found.\n", bookingId, roomNumber);
            }
        } else {
            printf("Room %d has no active bookings.\n", roomNumber);
        }
    } else {
        printf("Room %d not found.\n", roomNumber);
    }
}

Room* findRoomByNumber(Room rooms[], int count, int roomNumber) {
    for (int i = 0; i < count; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            return &rooms[i];
        }
    }
    return NULL;
}