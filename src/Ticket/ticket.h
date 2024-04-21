#ifndef TICKET_H
#define TICKET_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AIRLINE 50
#define MAX_TIME 10
#define MAX_PASSENGER_INFO 100
#define MAX_SEAT_NUMBER 50

typedef struct 
{
    char buyer_info[MAX_PASSENGER_INFO];
    char booking_time[MAX_TIME];
    float price;
    char classification[MAX_AIRLINE];
    char flight_number[MAX_AIRLINE];
    char seat_number[MAX_TIME];
    char ticket_id[MAX_PASSENGER_INFO];
} Ticket;

void create_ticket(Ticket tickets[], int *current_id);
void remove_ticket(Ticket tickets[], int *current_id);
void save_data(Ticket tickets[], int *current_id);
void showAll(Ticket tickets[], int *current_id);
#endif