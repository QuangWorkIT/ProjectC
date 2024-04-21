#ifndef FLIGHT_H
#define FLIGHT_H
#include <stdbool.h>
// Tao gioi han do dai cua thong tin thong tin


#define MAX_FLIGHT 100
#define MAX_DESTINATION 50
#define MAX_AIRLINE 50
#define MAX_TIME 50
#define MAX_FLIGHT_STATUS 50
// Define cac yeu to
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
// Khai bao cac function de viec goi function trong cac ham de dang hon
void Flight_create(Flight flight[], int *current_id);
void Flight_remove(Flight flight[], int *current_id);
void Flight_list(Flight flight[], int *current_id);
#endif