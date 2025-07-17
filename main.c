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
        printf("Select action: ");
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        processMainMenuChoice(choice);
    } while (choice != 0);

    printf("Thank you for using the hotel booking system!\n");
    return 0;
}

void displayMainMenu() {
    printf("\n--- Main Menu ---\n");
    printf("1. Hotel Operations\n");
    printf("2. Show all hotels\n");
    printf("0. Exit\n");
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
            printf("Invalid action. Please try again.\n");
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
        printf("\n--- Hotel Operations ---\n");
        printf("1. Filter hotels by city\n");
        printf("2. Filter hotels by price range\n");
        printf("3. Filter hotels by city AND price range\n");
        printf("4. Show all hotels\n");
        printf("5. Select a hotel for booking/room viewing\n");
        printf("0. Return to main menu\n");
        printf("Select action: ");
        while (scanf("%d", &subChoice) != 1) {
            printf("Invalid input. Please enter a number: ");
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
                printf("Enter the ID of the hotel you want to select: ");
                while (scanf("%d", &hotelId) != 1) {
                    printf("Invalid input. Please enter a number: ");
                    while (getchar() != '\n');
                }
                while (getchar() != '\n');
                selectedHotel = findHotelById(hotelId);
                if (selectedHotel != NULL) {
                    printf("Selected hotel: %s\n", selectedHotel->name);
                    handleBookingOperations(selectedHotel);
                } else {
                    printf("Hotel with ID %d not found.\n", hotelId);
                }
                break;
            case 0:
                break;
            default:
                printf("Invalid action. Please try again.\n");
                break;
        }
    } while (subChoice != 0);
}

void handleBookingOperations(Hotel* selectedHotel) {
    if (selectedHotel == NULL) {
        printf("No hotel selected.\n");
        return;
    }

    int subChoice;
    do {
        printf("\n--- Operations with rooms in hotel '%s' ---\n", selectedHotel->name);
        printf("1. Show all rooms\n");
        printf("2. Book a room\n");
        printf("3. Show my bookings\n");
        printf("4. Cancel booking\n");
        printf("0. Return to hotel selection\n");
        printf("Select action: ");
        while (scanf("%d", &subChoice) != 1) {
            printf("Invalid input. Please enter a number: ");
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
                printf("Invalid action. Please try again.\n");
                break;
        }
    } while (subChoice != 0);
}