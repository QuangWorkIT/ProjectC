#ifndef FLIGHT_H
#define FLIGHT_H
#include <stdbool.h>

// define all limitation 
#define MAX_FLIGHT 100
#define MAX_DESTINATION 50
#define MAX_AIRLINE 50
#define MAX_TIME 50
#define MAX_FLIGHT_STATUS 50
#define MAX_AIRLINE 50
#define MAX_PASSENGER_INFO 100
#define MAX_SEAT_NUMBER 50
#define MAX_DESTINATION 50
#define MAX_FLIGHT_STATUS 50
#define MAX_PASSENGER_INFO 100
#define MAX_EMAIL 50

enum Display{
    HOME ,
    FLIGHT ,
    TICKET ,
    CUSTOMER ,
    SEAT ,
    EXIT,
};
void menu(enum Display dis);
//// struct of flight information
typedef struct
{
    char destination[MAX_DESTINATION];
    char departure[MAX_DESTINATION];
    char takeoff_time[MAX_TIME];
    char landing_time[MAX_TIME];
    char airline[MAX_AIRLINE];
    char flight_time[MAX_TIME];
    char status[MAX_FLIGHT_STATUS];
} Flight;

void Flight_create(Flight flight[], int *current_id);
void Flight_remove(Flight flight[], int *current_id);
void Flight_list(Flight flight[], int *current_id);
void Flight_edit(Flight flight[], int *current_id);

//// struct of ticket information 
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
void remove_data_file(int j);
void save_ticket_data(Ticket tickets[], int *current_id);
void showAll_Ticket(Ticket tickets[], int *current_id);
void import_Ticket_Database(Ticket tickets[], int *current_id);
void show_ticket_list(Ticket tickets[], int *current_id, int *check);

//// struct of customer
typedef struct 
{
    char passport_number[MAX_PASSENGER_INFO];
    char passenger_name[MAX_PASSENGER_INFO];
    char phone[MAX_PASSENGER_INFO];
    char email[MAX_EMAIL];
} Customer;

void create_Customer(Customer customerList[], int *current_Id);
void set_passengerInfo(Customer customerList[], int *current_Id);
void showAll_Customer(Customer customerList[], int *current_Id);
void save_passenger_data(Customer customers[], int *current_id);
void import_passenger_Database(Customer customerList[], int *current_id, int check);
void showAllpassengerfromDatabase(Customer customerList[], int *current_id, int check);

//// struct of seat 
typedef struct Seat {
    char seatNumber[10];
    char status[20];
} Seat;
void createSeat(Seat seats[], int *numSeats);
void modifySeat(Seat seats[], int *current_id);
void remove_seat(Seat seats[], int *current_id);
void save_seat_data(Seat seats[], int *current_id);
void showAvailableSeat(Seat seats[], int *current_id, int *check);
void import_seat_Database(Seat seats[], int *current_id);
void showAll_seats(Seat seats[], int *current_id);
#endif