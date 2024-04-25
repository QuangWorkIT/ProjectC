#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight.h"

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

    FILE *file = fopen("C:\\Users\\DaShork\\Desktop\\prject c\\FlightManagement\\flights.txt", "w");
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