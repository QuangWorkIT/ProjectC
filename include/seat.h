#ifndef SEAT_H
#define SEAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FLIGHT 100
#define MAX_DESTINATION 50
#define MAX_AIRLINE 50
#define MAX_FLIGHT_STATUS 50
#define MAX_AIRLINE 50
#define MAX_TIME 10
#define MAX_PASSENGER_INFO 100
#define MAX_SEAT_NUMBER 50

enum Display{
    HOME ,
    FLIGHT ,
    TICKET ,
    CUSTOMER ,
    SEAT ,
    EXIT,
};
typedef struct Seat {
    char seatNumber[10];
    char status[20]; 

} Seat;
void createSeat(Seat seats[], int *numSeats);
void modifySeat(Seat seats[], int *current_id);
void remove_seat(Seat seats[], int *current_id);
void save_seat_data(Seat seats[], int *current_id);
void showAvailableSeat(Seat seats[], int *current_id, int *check);
void import_seat_Database(Seat seats[], int *current_id,enum Display *dis);
void showAll_seats(Seat seats[], int *current_id, enum Display *dis);

#endif