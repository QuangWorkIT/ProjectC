#ifndef TICKET_H
#define TICKET_H

#define MAX_DESTINATION 50
#define MAX_FLIGHT_STATUS 50
#define MAX_PASSENGER_INFO 100
#define MAX_EMAIL 50

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
void showAll(Customer customerList[], int *current_Id);
#endif