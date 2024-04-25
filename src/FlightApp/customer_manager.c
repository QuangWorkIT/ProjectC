#include "flight.h"
#include <stdio.h>
#include <string.h>

void create_Customer(Customer customerList[], int *current_Id){
    printf("Enter passport number: ");
    scanf("%s", &customerList[*current_Id].passport_number);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Enter passenger name: ");
    scanf("%[^\n]", &customerList[*current_Id].passenger_name);
    c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Enter phone: ");
    scanf("%s", &customerList[*current_Id].phone);
    printf("Enter email (if any): ");
    scanf("%s", &customerList[*current_Id].email);
    (*current_Id)++;
    printf("Add new passenger successfully!\n");
    char s[3] = "";
    while (1) {
        printf("Press B to back home  ");
        scanf("%s", &s);
        if (strcmp(s,"B") == 0)
            break;
    }
}
void set_passengerInfo(Customer customerList[], int *current_Id){
    showAll_Customer(customerList, current_Id);
    printf("Enter customer ID: ");
    char Id[100]; 
    scanf("%s", &Id);
    int flag = 1;
    for (int i = 0; i < *current_Id; i++)
    {
        if(strcmp(customerList[i].passport_number, Id) == 0){
            flag = 0;
            int logic = 1;
            while (logic)
            {
                printf("|------------------------------------------------------------------|\n");
                printf("|     ID   |    Passenger Name   |   Phone  |         Email        |\n");
                printf("|------------------------------------------------------------------|\n");
                printf("|%-10s|%-20s |%-10s|%-22s|\n", customerList[i].passport_number,
                customerList[i].passenger_name, customerList[i].phone, customerList[i].email);
                printf("|------------------------------------------------------------------|\n");
                int n;
                printf("Enter the property(1..4) to modify: ");
                scanf("%d", &n);
                switch (n)
                {
                case 1:
                    printf("Modify ID number: ");
                    scanf("%s", &customerList[i].passport_number);
                    break;
                case 2:
                    printf("Modify name: ");
                    scanf("%[^\n]", &customerList[i].passenger_name);
                    break;
                case 3:
                    printf("Modify phone number: ");
                    scanf("%s", &customerList[i].phone);
                    break;
                case 4:
                    printf("Modify email: ");
                    scanf("%s", &customerList[i].email);
                    break;
                default:
                    logic = 0;
                    break;
                }
            }
        }
    }
    printf("%s", flag == 0? "Information modified successfully!\n" : "No such for customer ID!\n");
    char s2[1] = ""; 
    while (1) {
        printf("Press B to back home  ");
        scanf("%s", &s2);
        if (strcmp(s2,"B") == 0)
            break;
    }
}

void showAll_Customer(Customer customerList[], int *current_Id){
    printf("List of customer\n");
    for (int i = 0; i < *current_Id; i++)
    {   
        printf("|------------------------------------------------------------------|\n");
        printf("|     ID   |    Passenger Name   |   Phone  |         Email        |\n");
        printf("|------------------------------------------------------------------|\n");
        printf("|%-10s|%-20s |%-10s|%-22s|\n", customerList[i].passport_number,
        customerList[i].passenger_name, customerList[i].phone, customerList[i].email);
        printf("|------------------------------------------------------------------|\n");
    } 
    char s3[1] ="";
    while (1) {
        printf("Press B to back home  ");
        scanf("%s", &s3);
        if (strcmp(s3,"B") == 0)
            break;
    }
}