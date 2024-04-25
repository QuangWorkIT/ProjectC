#include "flight.h"
#include <stdio.h>
#include <string.h>

void create_Customer(Customer customerList[], int *current_Id){
    printf("Enter passport number: ");
    scanf("%s", customerList[*current_Id].passport_number);
    printf("Enter passenger name: ");
    scanf("%s", customerList[*current_Id].passenger_name);
    printf("Enter phone: ");
    scanf("%s", customerList[*current_Id].phone);
    printf("Enter email (if any): ");
    scanf("%s", customerList[*current_Id].email);
    (*current_Id)++;
}
void set_ID(Customer customerList[], int *current_Id){
    printf("Enter customer ID: ");
    char Id[100]; 
    scanf("%s", &Id);
    int flag = 1;
    for (int i = 0; i < *current_Id; i++)
    {
        if(strcmp(customerList[i].passport_number, Id) == 0){
            printf("Modify ID number: ");
            scanf("%s", &customerList[i].passport_number);
            flag = 0;
        }
    }
    if(flag == 1) printf("No search for Id");
}
void set_Name(Customer customerList[], int *current_Id){
    printf("Enter customer ID: ");
    char Id[100]; 
    scanf("%s", &Id);
    int flag = 1;
    for (int i = 0; i < *current_Id; i++)
    {
        if(strcmp(customerList[i].passport_number, Id) == 0){
            printf("Modify customer's name: ");
            scanf("%s", &customerList[i].passenger_name);
            flag = 0;
        }
    }
    if(flag == 1) printf("No search for Id");
}
void set_Email(Customer customerList[], int *current_Id){
    printf("Enter customer ID: ");
    char Id[100]; 
    scanf("%s", &Id);
    int flag = 1;
    for (int i = 0; i < *current_Id; i++)
    {
        if(strcmp(customerList[i].passport_number, Id) == 0){
            printf("Modify customer's email: ");
            scanf("%s", &customerList[i].email);
            flag = 0;
        }
    }
    if(flag == 1) printf("No search for Id");
}
void set_Phone_Number(Customer customerList[], int *current_Id){
    printf("Enter customer ID: ");
    char Id[100]; 
    scanf("%s", &Id);
    int flag = 1;
    for (int i = 0; i < *current_Id; i++)
    {
        if(strcmp(customerList[i].passport_number, Id) == 0){
            printf("Modify customer's phone number: ");
            scanf("%s", &customerList[i].phone);
            flag = 0;
        }
    }
    if(flag == 1) printf("No search for Id");
}

void showAll_Customer(Customer customerList[], int *current_Id){
    for (int i = 0; i < *current_Id; i++)
    {
        printf("|%-10s|%-10s|%-10s|%-20s|\n", customerList[i].passport_number,
        customerList[i].passenger_name, customerList[i].phone, customerList[i].email);
    } 
}