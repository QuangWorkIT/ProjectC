#include <stdio.h>
#include "ticket.h"

void save_data(Ticket tickets[], int *current_id){
    FILE *fptr;
    fptr = fopen("database.txt", "w");
    for (int i = 0; i < *current_id; i++)
    {
        char string[100];
        strcpy(string, tickets[i].ticket_id);
        fprintf(fptr, string);
        fprintf(fptr, "/");
        string[0] = '\0';

        strcpy(string, tickets[i].buyer_info);
        fprintf(fptr, string);
        fprintf(fptr, "/");
        string[0] = '\0';

        strcpy(string, tickets[i].booking_time);
        fprintf(fptr, string);
        fprintf(fptr, "/");
        string[0] = '\0';

        sprintf(string, "%6.1f", tickets[i].price);
        fprintf(fptr, string);
        fprintf(fptr, "/");
        string[0] = '\0';

        strcpy(string, tickets[i].classification);
        fprintf(fptr, string);
        fprintf(fptr, "/");
        string[0] = '\0';

        strcpy(string, tickets[i].flight_number);
        fprintf(fptr, string);
        fprintf(fptr, "/");
        string[0] = '\0';

        strcpy(string, tickets[i].seat_number);
        fprintf(fptr, string);
        fprintf(fptr, "/");
        string[0] = '\0';
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}