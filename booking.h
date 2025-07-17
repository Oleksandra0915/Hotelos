#ifndef BOOKING_H
#define BOOKING_H

#define MAX_CUSTOMER_NAME 50

typedef struct Booking {
    int id;
    char customerName[MAX_CUSTOMER_NAME];
} Booking;

#endif