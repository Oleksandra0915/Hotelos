#include <stdio.h>
#include <string.h>
#include "booking.h"
#include "room.h"

void createBooking(Booking* booking, int id, const char* customerName) {
    booking->id = id;
    strcpy(booking->customerName, customerName);
}

void showHotelBookingsInBookingC(Room rooms[], int count) {
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