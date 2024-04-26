#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seat.h"

int main() {
    Seat seats[100]; // Array of seats
    int current_seat_id = 0; // Number of seats currently present

    while (1) {
        int choice;

        printf("\nSeat Management System\n");
        printf("1. Create Seat\n");
        printf("2. show Seat\n");
        printf("3. Delete Seat\n");
        printf("4. Modify Seat\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createSeat(seats, &current_seat_id);
                break;
            case 2:
                showAll_seats(seats, &current_seat_id, NULL);
                break;
            case 3:
                remove_seat(seats, &current_seat_id);
                break;
            case 4:
                modifySeat(seats, &current_seat_id);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid selection, please select again.\n");
        }
    }
    return 0;
}
