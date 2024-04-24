#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight.h"

void Flight_edit(Flight flight[], int *current_id)
{
    int i, choice, edit_choice;
    char new_value[100];

    // Print the list of flights
    printf("List of flights:\n");
    for (i = 0; i < *current_id; i++)
    {
        printf("%d. %s to %s\n", i+1, flight[i].departure, flight[i].destination);
    }

    // Ask the user to choose a flight to edit
    printf("Enter the number of the flight you want to edit: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > *current_id)
    {
        printf("Invalid choice.\n");
        return;
    }

    // Ask the user to choose which property of the flight to edit
    printf("Choose which property of the flight to edit:\n");
    printf("1. Destination\n");
    printf("2. Departure\n");
    printf("3. Takeoff time\n");
    printf("4. Landing time\n");
    printf("5. Airline\n");
    printf("6. Flight time\n");
    printf("7. Status\n");
    printf("Enter your choice: ");
    scanf("%d", &edit_choice);
    if (edit_choice < 1 || edit_choice > 7)
    {
        printf("Invalid choice.\n");
        return;
    }

    // Ask the user to enter the new value for the chosen property
    printf("Enter the new value for the chosen property: ");
    scanf("%s", new_value);

    // Update the chosen property of the selected flight
    switch (edit_choice)
    {
        case 1:
            strcpy(flight[choice-1].destination, new_value);
            break;
        case 2:
            strcpy(flight[choice-1].departure, new_value);
            break;
        case 3:
            strcpy(flight[choice-1].takeoff_time, new_value);
            break;
        case 4:
            strcpy(flight[choice-1].landing_time, new_value);
            break;
        case 5:
            strcpy(flight[choice-1].airline, new_value);
            break;
        case 6:
            strcpy(flight[choice-1].flight_time, new_value);
            break;
        case 7:
            strcpy(flight[choice-1].status, new_value);
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    // Write the updated flight data to the file
    FILE *file = fopen("C:\\Users\\DaShork\\Desktop\\prject c\\FlightManagement\\flights.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    for (i = 0; i < *current_id; i++)
    {
        fprintf(file, "Destination: %s\n", flight[i].destination);
        fprintf(file, "Departure: %s\n", flight[i].departure);
        fprintf(file, "Takeoff time: %s\n", flight[i].takeoff_time);
        fprintf(file, "Landing time: %s\n", flight[i].landing_time);
        fprintf(file, "Airline: %s\n", flight[i].airline);
        fprintf(file, "Flight time: %s\n", flight[i].flight_time);
        fprintf(file, "Status: %s\n", flight[i].status);
        fprintf(file, "\n");
    }
    fclose(file);

    printf("Flight updated successfully.\n");
}