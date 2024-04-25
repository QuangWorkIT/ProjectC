#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight.h"

void Flight_remove(Flight flight[], int *current_id)
{
    int index;
    int i;

    // Ask the user to enter the index of the flight to remove
    printf("Enter the index of the flight to remove: ");
    scanf("%d", &index);

    // Check if the index is within the bounds of the array
    if (index < 0  || index >= *current_id)
    {
        printf("Invalid index.\n");
        return;
    }

    // Set the flight at the specified index to all zeros
    memset(&flight[index], 0, sizeof(Flight));

    // Shift the remaining flights to fill the gap left by the removed flight
    for (i = index; i < *current_id - 1; i++)
    {
        flight[i] = flight[i + 1];
    }

    // Decrement the current_id to remove the last added flight
    (*current_id)--;

    // Open the file in write mode
    FILE *file = fopen("C:\\Users\\DaShork\\Desktop\\prject c\\FlightManagement\\flights.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    // Write the updated flight data to the file
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

    // Close the file
    fclose(file);

    printf("Flight removed successfully.\n");
}