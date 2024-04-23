#include <stdio.h>
#include <stdlib.h>
#include "flight.h"

void Flight_list(Flight flight[], int *current_id)
{
    int i = 0;
    // Open the file in read mode
    FILE *file = fopen("C:\\Users\\DaShork\\Desktop\\prject c\\FlightManagement\\flights.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the flight data from the file
    while (fscanf(file, "Destination: %[^\n]\nDeparture: %[^\n]\nTakeoff time: %[^\n]\nLanding time: %[^\n]\nAirline: %[^\n]\nFlight time: %[^\n]\nStatus: %[^\n]\n",
                  flight[i].destination, flight[i].departure, flight[i].takeoff_time, flight[i].landing_time, flight[i].airline, flight[i].flight_time, flight[i].status) != EOF)
    {
        // Print the flight data
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

    // Close the file
    fclose(file);
}