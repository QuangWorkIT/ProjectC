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

void create_ticket(Ticket tickets[], int *current_id, enum Display *dis);
void remove_ticket(Ticket tickets[], int *current_id, enum Display *dis);
void save_data(Ticket tickets[], int *current_id);
void showAll_Ticket(Ticket tickets[], int *current_id, enum Display *dis);
void import_Ticket_Database(Ticket tickets[], int *current_id,enum Display *dis);
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
void set_ID(Customer customerList[], int *current_Id);
void set_Name(Customer customerList[], int *current_Id);
void set_Phone_Number(Customer customerList[], int *current_Id);
void set_Email(Customer customerList[], int *current_Id);
void showAll_Customer(Customer customerList[], int *current_Id);

//// struct of seat 
typedef struct Seat {
    int Seatnumber;
    char Passengername[MAX_PASSENGER_INFO];
} Seat;

void createSeat(Flight *flight);
void addSeat(Flight *flight);
void deleteSeat(Flight *flight);
void modifySeat(Flight *flight);
#endif 