#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight/flight.h"

int main()
{
    int choice;
    int current_id = 0;
    Flight flight[MAX_FLIGHT];
    do
    {
        printf("1.Create Flight\n");
        printf("2.Remove Flight\n");
        printf("3.Flight list\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        switch (choice)
        {
            case 1:
                printf("Create new Flight:\n");
                Flight_create(flight, &current_id);

                break;
            case 2: 
                printf("Remove flights:\n");
                Flight_remove(flight, &current_id);
                break;
            case 3:
                printf("Flight list:\n");
                Flight_list(flight, &current_id);
                break;
            default:
                printf("Unfound command, Exitting program..");
                break;
        }
    } while (choice > 0 && choice < 4);
    // Write the flights to a file

    return 0;
}