#include <stdio.h>
#include <string.h>
#include "booking.h"
#include "room.h"

void bookHotelRoom(Room rooms[], int numRooms) {
    int num;
    char name[MAX_NAME];

    showHotelRooms(rooms, numRooms);
    printf("\nВведіть номер для бронювання: ");
    scanf("%d", &num);

    if (num < 1 || num > numRooms) {
        printf("Невірний номер.\n");
        return;
    }

    if (rooms[num - 1].isBooked) {
        printf("Номер %d вже заброньований гостем %s.\n", num, rooms[num-1].guestName);
        return;
    }

    printf("Ім'я гостя: ");
    getchar();
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = 0;

    rooms[num - 1].isBooked = 1;
    strcpy(rooms[num - 1].guestName, name);

    printf("Номер %d успішно заброньовано на ім'я %s!\n", num, name);
}

void showHotelBookings(const Room rooms[], int numRooms) {
    printf("\n--- Список бронювань в цьому готелі ---\n");
    int found = 0;
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].isBooked) {
            printf("Номер %d (Тип: ", rooms[i].roomNumber);
            switch (rooms[i].type) {
                case SINGLE: printf("Одномісний"); break;
                case DOUBLE: printf("Двомісний"); break;
                case SUITE:  printf("Люкс"); break;
            }
            printf(", Ціна: %d грн) - Заброньовано на ім'я: %s\n", rooms[i].price, rooms[i].guestName);
            found = 1;
        }
    }
    if (!found) {
        printf("Жодного бронювання немає в цьому готелі.\n");
    }
}

void cancelHotelBooking(Room rooms[], int numRooms) {
    int num;
    printf("\n--- Скасування бронювання ---\n");
    showHotelBookings(rooms, numRooms);

    if (numRooms == 0) {
         printf("Немає номерів для скасування.\n");
         return;
    }

    printf("Введіть номер для скасування бронювання: ");
    scanf("%d", &num);

    if (num < 1 || num > numRooms) {
        printf("Невірний номер.\n");
        return;
    }

    if (!rooms[num - 1].isBooked) {
        printf("Номер %d не заброньований.\n", num);
        return;
    }

    printf("Скасування бронювання для номера %d гостя %s...\n", num, rooms[num-1].guestName);
    rooms[num - 1].isBooked = 0;
    strcpy(rooms[num - 1].guestName, "");
    printf("Бронювання номера %d успішно скасовано.\n", num);
}