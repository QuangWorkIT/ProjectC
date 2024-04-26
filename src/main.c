#include "flight.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int choice = 0;
    enum Display dis = HOME;
    Flight flights[100];
    Ticket tickets[100];
    Customer customers[100];
    Seat seats[100];
    int current_flight_id = 0; 
    int current_ticket_id = 0; 
    int current_customer_id = 0;
    int current_seat_id = 0;

    while (dis == HOME)
    {
        User user;
        printf("Username:");
        scanf("%s", user.username);

        printf("Password:");
        scanf("%s", user.password);

        if(!login("user_database.txt", "token_database.txt", user.username, user.password) ){
            register_auth("user_database.txt", &user);
        }
        else{
            menu(dis);
            printf("\nEnter an option: ");
            scanf("%d", &choice);
            int option;
            switch (choice)
            {
                case 1:
                    dis = FLIGHT;
                    do
                    {
                        menu(dis);
                        printf("Enter an option on the flight screen: ");
                        scanf("%d", &option);
                        switch (option)
                        {
                            case 1:
                                printf("Create a flight\n");
                                Flight_create(flights, &current_flight_id);
                                break;
                            case 2:
                                printf("Remove a flight\n");
                                Flight_remove(flights, &current_flight_id);
                                break;
                            case 3:
                                printf("Modify flight's properties\n");
                                Flight_edit(flights, &current_flight_id);
                                break;
                            case 4:
                                printf("List of flights\n");
                                Flight_list(flights, &current_flight_id);
                                break;
                            case 5: dis = HOME ; break;
                            default:
                            printf("Wrong choice!\n");
                        }
                    } while (dis != HOME);
                    break;
                case 2:
                    dis = TICKET;
                    do
                    {
                        menu(dis);
                        printf("Enter an option on the ticket screen: ");
                        scanf("%d", &option);
                        switch (option)
                        {
                            case 1:
                                system("cls");
                                printf("Create a ticket\n");
                                create_ticket(tickets, &current_ticket_id);
                                save_ticket_data(tickets, &current_ticket_id );
                                break;
                            case 2:
                                system("cls");
                                printf("Remove a ticket\n");
                                remove_ticket(tickets, &current_ticket_id);
                                break;
                            case 3:
                                system("cls");
                                printf("List of tickets\n");
                                showAll_Ticket(tickets, &current_ticket_id);  
                                break;
                            case 4 : dis = HOME; break;
                            default:
                                printf("Wrong choice!\n");
                                break;
                        }   
                    }while(dis!=HOME);
                    break;
                case 3:
                    dis = CUSTOMER;
                    do
                    {
                        menu(dis);
                        printf("Enter an option on the customer screen: ");
                        scanf("%d", &option);
                        switch (option)
                        {
                            case 1:
                                printf("Create customer information\n");
                                create_Customer(customers, &current_customer_id);
                                break;
                            case 2:
                                printf("Set passenger's information\n");
                                set_passengerInfo(customers, &current_customer_id);
                                break;
                            case 3:
                                printf("Show list of passengers\n");
                                showAllpassengerfromDatabase(customers, &current_customer_id, -1);
                                break;
                            case 4: dis = HOME;break;
                            default:
                                printf("Wrong choice!\n");
                        }
                    } while (dis!=HOME);    
                    break;
                case 4:
                    dis = SEAT;
                    do
                    {
                        menu(dis);
                        printf("Enter an option on the seat screen: ");
                        scanf("%d", &option);
                        switch (option)
                        {
                            case 1:
                                system("cls");
                                printf("Create a seat\n");
                                createSeat(seats, &current_seat_id);
                                break;
                            case 2:
                                system("cls");
                                printf("Remove a seat\n");
                                remove_seat(seats, &current_seat_id);
                                break;
                            case 3:
                                system("cls");
                                printf("Show all seats in list\n");
                                showAll_seats(seats, &current_seat_id);
                                break;
                            case 4:
                                system("cls");
                                printf("Modify seat's property\n");
                                modifySeat(seats, &current_seat_id);
                                break;
                            case 5: dis = HOME ; break;
                            default:
                            printf("Wrong choice!\n");
                        }  
                    } while (dis!=HOME);
                    break;
                case 5: 
                    printf("EXIT");
                    dis = 100;
                    break;
                default:
                    printf("Wrong choice!");
                    break;
            }
        }
    }
}