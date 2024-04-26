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
    printf("Create flight successfully!\n");
    char back[1] = "";
        while (1)
        {
            printf("Press B to come back home: ");
            scanf("%s", &back);
            if( strcmp(back,"B")  == 0)
                break; 
        }
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
    char back2[1] = "";
        while (1)
        {
            printf("Press B to come back home: ");
            scanf("%s", &back2);
            if( strcmp(back2,"B")  == 0)
                break; 
        }
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
    char back3[1] = "";
        while (1)
        {
            printf("Press B to come back home: ");
            scanf("%s", &back3);
            if( strcmp(back3,"B")  == 0)
                break; 
        }
}

void Flight_edit(Flight flight[], int *current_id){
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
    FILE *file = fopen("flights.txt", "w");
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
    char back4[1] = "";
        while (1)
        {
            printf("Press B to come back home: ");
            scanf("%s", &back4);
            if( strcmp(back4,"B")  == 0)
                break; 
        }
}
