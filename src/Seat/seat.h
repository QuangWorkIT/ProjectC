#ifndef SEAT_H
#define SEAT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Seat {
    int Seatnumber;
     char Passengername[50];

} Seat;

typedef struct Flight {
    int Flightnumber;
    char destination[50];
    char departureDate[20];
    char departureTime[10];
    int availableSeats;
    struct Seat *seats;
} Flight;


typedef struct Passenger {
    int bookingId;
    char name[50];
    char email[50];
    char phoneNumber[20];
    int Flightnumber;
    int Seatnumber;
} Passenger;

void createFlight(Flight **flights, int *numFlights);
void addFlight(Flight **flights, int *numFlights);
void deleteFlight(Flight **flights, int *numFlights);
void modifyFlight(Flight **flights, int numFlights);

void createSeat(Flight *flight);
void addSeat(Flight *flight);
void deleteSeat(Flight *flight);
void modifySeat(Flight *flight);

void createPassenger();
void bookTicket(Flight *flights, int numFlights, Passenger *passengers, int *numPassengers);
void cancelTicket(Flight *flights, int numFlights, Passenger *passengers, int *numPassengers);
void modifyPassengerInfo(Passenger *passengers, int numPassengers);


Flight *flights = NULL;
int numFlights = 0;
Passenger *passengers = NULL;
int numPassengers = 0;
#endif