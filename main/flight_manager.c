#include "flight.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// create a flight
void Flight_create(Flight flight[], int *current_id)
{
    printf("Enter destination: ");
    scanf(" %[^\n]%*c", flight[*current_id].destination);
    printf("Enter departure: ");
    scanf(" %[^\n]%*c", flight[*current_id].departure);
    printf("Enter takeoff time: ");
    scanf(" %[^\n]%*c", flight[*current_id].takeoff_time);
    printf("Enter landing time: ");
    scanf(" %[^\n]%*c", flight[*current_id].landing_time);
    printf("Enter airline: ");
    scanf(" %[^\n]%*c", flight[*current_id].airline);
    printf("Flight time: ");
    scanf(" %[^\n]%*c", flight[*current_id].flight_time);
    printf("Enter status: ");
    scanf(" %[^\n]%*c", flight[*current_id].status);

    FILE *file = fopen("flights.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    fprintf(file, "Destination: %s\n", flight[*current_id].destination);
    fprintf(file, "Departure: %s\n", flight[*current_id].departure);
    fprintf(file, "Takeoff time: %s\n", flight[*current_id].takeoff_time);
    fprintf(file, "Landing time: %s\n", flight[*current_id].landing_time);
    fprintf(file, "Airline: %s\n", flight[*current_id].airline);
    fprintf(file, "Flight time: %s\n", flight[*current_id].flight_time);
    fprintf(file, "Status: %s\n", flight[*current_id].status);

    fclose(file);
    (*current_id)++;
}
// remove a flight
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
    FILE *file = fopen("flights.txt", "w");
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
    fclose(file);

    printf("Flight removed successfully.\n");
}

// list of flight
void Flight_list(Flight flight[], int *current_id)
{
    int i = 0;
    // Open the file in read mode
    FILE *file = fopen("flights.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the flight data from the file
    while (fscanf(file, "Destination: %[^\n]\nDeparture: %[^\n]\nTakeoff time: %[^\n]\nLanding time: %[^\n]\nAirline: %[^\n]\nFlight time: %[^\n]\nStatus: %[^\n]\n",
                  flight[i].destination, flight[i].departure, flight[i].takeoff_time, flight[i].landing_time, flight[i].airline, flight[i].flight_time, flight[i].status) != EOF)
    {
        printf("Flight number: %d\n", i+1);
        printf("Destination: %s\n", flight[i].destination);
        printf("Departure: %s\n", flight[i].departure);
        printf("Takeoff time: %s\n", flight[i].takeoff_time);
        printf("Landing time: %s\n", flight[i].landing_time);
        printf("Airline: %s\n", flight[i].airline);
        printf("Flight time: %s\n", flight[i].flight_time);
        printf("Status: %s\n", flight[i].status);
        printf("\n");
        i++;
    }
    // Update the current_id variable to reflect the number of flights read from the file
    *current_id = i;
    fclose(file);
}