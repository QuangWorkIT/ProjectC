#include "ticket.h"
#include <string.h>


void create_ticket(Ticket tickets[], int *current_id){
    printf("Enter ticket ID: ");
    scanf("%s", &tickets[*current_id].ticket_id);
    printf("Enter buyer info: ");
    scanf("%s", &tickets[*current_id].buyer_info);
    printf("Enter booking time: ");
    scanf("%s", &tickets[*current_id].booking_time);
    printf("Enter price: ");
    scanf("%f", &tickets[*current_id].price);
    printf("Enter class: ");
    scanf("%s", &tickets[*current_id].classification);
    printf("Enter flight number: ");
    scanf("%s", &tickets[*current_id].flight_number);
    printf("Enter seat number: ");  
    scanf("%s", &tickets[*current_id].seat_number);
    (*current_id)++;
}

void remove_ticket(Ticket tickets[], int *current_id) {
        char ticket_id[50];
        printf("Enter remove id: ");
        scanf("%s", &ticket_id); 
        int flag = 0;
        for (int i = 0; i < *current_id; i++)
        {
            if(strcmp(tickets[i].ticket_id, ticket_id) == 0){
                strcpy(tickets[i].booking_time, tickets[i+1].booking_time);
                strcpy(tickets[i].buyer_info, tickets[i+1].buyer_info);
                strcpy(tickets[i].classification, tickets[i+1].classification);
                strcpy(tickets[i].flight_number, tickets[i+1].flight_number);
                strcpy(tickets[i].seat_number, tickets[i+1].seat_number);
                tickets[i].price = tickets[i+1].price;
                strcpy(tickets[i].ticket_id, tickets[i+1].ticket_id);  
                flag = 1;     
            }
        }
        if(flag == 0) printf("No search for ticket ID!");
        else printf("The %s ticket has been removed from list\n", ticket_id);
        (*current_id)--;
}
void showAll(Ticket tickets[], int *current_id) {
    printf("List of tickets\n");
    for (int i = 0; i < *current_id; i++)
    {
        printf("%-10s|%-10s|%-10s|%-6.1f|%-10s|%-10s|%-5s|\n",tickets[i].ticket_id,tickets[i].buyer_info, 
        tickets[i].booking_time, tickets[i].price, tickets[i].classification,
        tickets[i].flight_number, tickets[i].seat_number);
    }
}