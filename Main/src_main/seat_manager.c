#include "flight.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//// void function to create or add a new seat to list
void createSeat(Seat seats[], int *numSeats) {
    printf("Enter the seat number: ");
    scanf(" %[^\n]", &seats[*numSeats].seatNumber);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Enter the status of the chair: ");
    scanf(" %[^\n]", &seats[*numSeats].status);
    printf("Seat added successfully.\n");
    (*numSeats)++;
    save_seat_data(seats, numSeats);

    char s1[3] = "";
    while (1) {
        printf("Press B to back home  ");
        scanf("%s", &s1);
        if (strcmp(s1,"B") == 0)
            break;
    }
} 
//// void function to modify the element's property 
void modifySeat(Seat seats[], int *current_id){
    char modifyID[10];
    int check = 0;
    showAvailableSeat(seats, current_id, &check);
    if(check == 1 ) {
        printf("Enter the seat number need to be modified: ");
        scanf("%s", &modifyID);
        int flag = 0;
        for (int i = 0; i < *current_id; i++){
            if(strcmp(seats[i].seatNumber, modifyID) == 0)
            {
                flag = 1;
                printf("Change seat status: ");
                scanf("%s", &seats[i].status);
            }
        }
        save_seat_data(seats, current_id);
        printf("%s", flag == 1 ? "Modified seat information successfully!\n": "Not found for seat number\n");
    }  
    char s2[3] = "";
    while (1) {
        printf("Press B to back home  ");
        scanf("%s", &s2);
        if (strcmp(s2,"B") == 0)
            break;
    } 
}
//// void function to delete an element in list 
void remove_seat(Seat seats[], int *current_id) { 
        int check = 0;
        showAvailableSeat(seats, current_id, &check);
        if(check == 1){
            char seat_id[50];
            printf("Enter remove seat number: ");
            scanf("%s", &seat_id); 
            int flag = 0;
            int j = -1;
            for (int i = 0; i < *current_id; i++)
                if(strcmp(seats[i].seatNumber, seat_id) == 0)
                    flag = 1, j = i;
            
            if(j != -1) {
                for (j ; j < *current_id; j++)
                {
                    strcpy(seats[j].seatNumber, seats[j+1].seatNumber);
                    strcpy(seats[j].status, seats[j+1].status);

                }
            }
            if(flag == 0) printf("No search for seat number!\n");
            else printf("The %s has been removed from list\n", seat_id),(*current_id)--;
        }
        save_seat_data(seats, current_id);
        char back2[1] = "";
        while (1)
        {
            printf("Press B to come back home: ");
            scanf("%s", &back2);
            if( strcmp(back2,"B")  == 0)
                break;
        }
}
//// void function to show whether the list is empty?
void showAvailableSeat(Seat seats[], int *current_id, int *check){
    if(*current_id == 0) printf("Require to import seats list\n"), *check = 0;
    else{
        *check = 1;
        printf("|---------------------|\n");
        printf("| Number |    Status  |\n");
        printf("|---------------------|\n");
            for (int i = 0; i < *current_id; i++)
            {
                printf("| %-6s | %-10s |\n", seats[i].seatNumber, seats[i].status);
            }
        printf("|---------------------|\n");
    }
}
//// import from seat database
void import_seat_Database(Seat seats[], int *current_id){
        FILE *fptrEmptyList;
        fptrEmptyList = fopen("seat_database.txt","r");
        char fstring[100] ="";
        char code[100] ="";
        int j = 0;

            while (fgets(fstring, 100, fptrEmptyList))
            { 
                int count = 0;
                for (int i = 0; i < strlen(fstring); i++)
                    if(fstring[i] == '/')
                        count++;
                int k = 0;
                for(int i=0; i< strlen(fstring); i++){
                    if(fstring[i] != '/')
                    {
                        code[k++] = fstring[i];	
                    }else
                    {
                        switch (count)
                        {
                        case 1:
                            strcpy(seats[j].status, code);
                            break;
                        case 2:
                            strcpy(seats[j].seatNumber, code);
                            break;
                        }   
                        count--;
                        k = 0;
                        memset(code, 0, sizeof(code));
                    }
                }
                j++;
                (*current_id) = j;  
            }
        fclose(fptrEmptyList);
    showAll_seats(seats, current_id);
}
// void funtion to show all tickets are remaining in list
void showAll_seats(Seat seats[], int *current_id) {
    if(*current_id == 0)
        import_seat_Database(seats, current_id);
    else{
        printf("|---------------------|\n");
        printf("| Number |    Status  |\n");
        printf("|---------------------|\n");
            for (int i = 0; i < *current_id; i++)
            {
                printf("| %-6s | %-10s |\n", seats[i].seatNumber, seats[i].status);
            }
        printf("|---------------------|\n");
    }
    char s3[3] = "";
    while (1) {
        printf("Press B to back home  ");
        scanf("%s", &s3);
        if (strcmp(s3,"B") == 0)
            break;
    }
}
//// void function to save data to file
void save_seat_data(Seat seats[], int *current_id){
    FILE *fptr;
    char string[100]="";
    fptr = fopen("seat_database.txt", "w");
    for (int i = 0; i < *current_id; i++)
    {
        fprintf(fptr, seats[i].seatNumber);
        fprintf(fptr, "/");
        memset(string, 0, sizeof(string));

        fprintf(fptr,seats[i].status);
        fprintf(fptr, "/");
        memset(string, 0, sizeof(string));
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}