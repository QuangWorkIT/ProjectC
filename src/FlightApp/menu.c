#include "flight.h"
#include <stdio.h>
#include <stdlib.h>
void menu(enum Display dis){
    switch (dis)
    {
        case HOME:
            system("cls");
            printf("|--------------------|\n");
            printf("| Flight Programming |\n");
            printf("|      1.Flight      |\n");
            printf("|      2.Ticket      |\n");
            printf("|      3.Customer    |\n");
            printf("|      4.Seat        |\n");
            printf("|      5.Exit        |\n");
            printf("|--------------------|\n");
            break;
        case FLIGHT:
            system("cls");
            printf("|--------------------|\n");
            printf("|  *Flight Manager*  |\n");
            printf("|   1.Create flight  |\n");
            printf("|   2.Remove flight  |\n");
            printf("| 3.List all flights |\n");
            printf("|   4.Back to Home   |\n");
            printf("|--------------------|\n");
            break;
        case TICKET:
            system("cls");
            printf("|---------------------|\n");
            printf("|  *Ticket Manager*   |\n");
            printf("|   1.Create ticket   |\n");
            printf("|   2.Remove ticket   |\n");
            printf("|   3.List all ticket |\n");
            printf("|   4.Back to Home    |\n");
            printf("|---------------------|\n");
            break;
        case CUSTOMER:
            system("cls");
            printf("|-------------------------|\n");
            printf("|  *Customer Manager*     |\n");
            printf("|   1.Create Customer     |\n");
            printf("|   2.Set customer ID     |\n");
            printf("|   3.Set name            |\n");
            printf("|   4.Set phone number    |\n");
            printf("|   5.Set email           |\n");
            printf("|   6.Show all customers  |\n");
            printf("|   7.Back to Home        |\n");
            printf("|-------------------------|\n");
            break;
        case SEAT:
            system("cls");
            printf("|--------------------|\n");
            printf("|    *Seat Manager*  |\n");
            printf("|   1.Create seat    |\n");
            printf("|   2.Delete seat    |\n");
            printf("|   3.List of seat   |\n");
            printf("|   4.Modify seat    |\n");
            printf("|   5.Back to Home   |\n");
            printf("|--------------------|\n");
            break;
    }
}