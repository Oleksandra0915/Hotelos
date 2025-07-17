#include <stdio.h>
#include <stdlib.h>
#include "city.h"
#include "price.h"
#include "hotel.h"
#include "room.h"
#include "booking.h"

void displayMainMenu();
void processMainMenuChoice(int choice);
void handleHotelOperations();
void handleBookingOperations(Hotel* selectedHotel);

int main() {
    initializeCities();
    initializePriceRanges();
    initializeHotels();

    int choice;
    do {
        displayMainMenu();
        printf("Виберіть дію: ");
        while (scanf("%d", &choice) != 1) {
            printf("Невірний ввід. Будь ласка, введіть число: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        processMainMenuChoice(choice);
    } while (choice != 0);

    printf("Дякуємо за користування системою бронювання готелів!\n");
    return 0;
}

void displayMainMenu() {
    printf("\n--- Головне меню ---\n");
    printf("1. Операції з готелями\n");
    printf("2. Показати всі готелі\n");
    printf("0. Вихід\n");
}

void processMainMenuChoice(int choice) {
    switch (choice) {
        case 1:
            handleHotelOperations();
            break;
        case 2:
            showHotels();
            break;
        case 0:
            break;
        default:
            printf("Невірна дія. Будь ласка, спробуйте ще раз.\n");
            break;
    }
}

void handleHotelOperations() {
    int cityFilter = 0;
    int priceFilter = 0;
    int hotelId;
    Hotel* selectedHotel = NULL;

    int subChoice;
    do {
        printf("\n--- Операції з готелями ---\n");
        printf("1. Фільтрувати готелі за містом\n");
        printf("2. Фільтрувати готелі за ціновим діапазоном\n");
        printf("3. Фільтрувати готелі за містом ТА ціновим діапазоном\n");
        printf("4. Показати всі готелі\n");
        printf("5. Вибрати готель для бронювання/перегляду номерів\n");
        printf("0. Повернутися в головне меню\n");
        printf("Виберіть дію: ");
        while (scanf("%d", &subChoice) != 1) {
            printf("Невірний ввід. Будь ласка, введіть число: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');

        switch (subChoice) {
            case 1:
                showCities();
                cityFilter = getCityChoice();
                priceFilter = 0;
                filterAndShowHotels(cityFilter, priceFilter);
                break;
            case 2:
                showPriceRanges();
                priceFilter = getPriceRangeChoice();
                cityFilter = 0;
                filterAndShowHotels(cityFilter, priceFilter);
                break;
            case 3:
                showCities();
                cityFilter = getCityChoice();
                showPriceRanges();
                priceFilter = getPriceRangeChoice();
                filterAndShowHotels(cityFilter, priceFilter);
                break;
            case 4:
                showHotels();
                break;
            case 5:
                showHotels();
                printf("Введіть ID готелю, який ви хочете вибрати: ");
                while (scanf("%d", &hotelId) != 1) {
                    printf("Невірний ввід. Будь ласка, введіть число: ");
                    while (getchar() != '\n');
                }
                while (getchar() != '\n');
                selectedHotel = findHotelById(hotelId);
                if (selectedHotel != NULL) {
                    printf("Вибрано готель: %s\n", selectedHotel->name);
                    handleBookingOperations(selectedHotel);
                } else {
                    printf("Готель з ID %d не знайдено.\n", hotelId);
                }
                break;
            case 0:
                break;
            default:
                printf("Невірна дія. Будь ласка, спробуйте ще раз.\n");
                break;
        }
    } while (subChoice != 0);
}

void handleBookingOperations(Hotel* selectedHotel) {
    if (selectedHotel == NULL) {
        printf("Готель не вибрано.\n");
        return;
    }

    int subChoice;
    do {
        printf("\n--- Операції з номерами готелю '%s' ---\n", selectedHotel->name);
        printf("1. Показати всі номери\n");
        printf("2. Забронювати номер\n");
        printf("3. Показати мої бронювання\n");
        printf("4. Скасувати бронювання\n");
        printf("0. Повернутися до вибору готелю\n");
        printf("Виберіть дію: ");
        while (scanf("%d", &subChoice) != 1) {
            printf("Невірний ввід. Будь ласка, введіть число: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');

        switch (subChoice) {
            case 1:
                showHotelRooms(selectedHotel->rooms, selectedHotel->roomsCount);
                break;
            case 2:
                bookHotelRoom(selectedHotel->rooms, selectedHotel->roomsCount);
                break;
            case 3:
                showHotelBookings(selectedHotel->rooms, selectedHotel->roomsCount);
                break;
            case 4:
                cancelHotelBooking(selectedHotel->rooms, selectedHotel->roomsCount);
                break;
            case 0:
                break;
            default:
                printf("Невірна дія. Будь ласка, спробуйте ще раз.\n");
                break;
        }
    } while (subChoice != 0);
}