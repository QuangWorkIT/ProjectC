#include "flight.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// void function to create a new ticket
void create_ticket(Ticket tickets[], int *current_id){
    printf("Enter ticket ID: ");
    scanf("%s", &tickets[*current_id].ticket_id);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Enter buyer info: ");
    scanf("%[^\n]", &tickets[*current_id].buyer_info);
    printf("Enter booking time: ");
    scanf("%s", &tickets[*current_id].booking_time);
    printf("Enter price: ");
    scanf("%f", &tickets[*current_id].price);
    printf("Enter class: ");
    scanf("%s", &tickets[*current_id].classification);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Enter flight number: ");
    scanf("%[^\n]", &tickets[*current_id].flight_number);
    printf("Enter seat number: ");  
    scanf("%s", &tickets[*current_id].seat_number);
    (*current_id)++;
    printf("Create ticket successfully!\n");
    
    char s[3] = "";
    while (1) {
        printf("Press B to back home  ");
        scanf("%s", &s);
        if (strcmp(s,"B") == 0)
            break;
    }
}

// void function of removing a ticket
void remove_ticket(Ticket tickets[], int *current_id) {
        int check = 0;
        show_ticket_list(tickets, current_id, &check);
        if(check == 1){
            char ticket_id[50];
            printf("Enter remove id: ");
            scanf("%s", &ticket_id); 
            int flag = 0;
            int j = -1;
            for (int i = 0; i < *current_id; i++)
                if(strcmp(tickets[i].ticket_id, ticket_id) == 0)
                    flag = 1, j = i;
            
            
            if(j != -1) {
                remove_data_file(j+1);
                for (j ; j < *current_id; j++)
                {
                    strcpy(tickets[j].booking_time, tickets[j+1].booking_time);
                    strcpy(tickets[j].buyer_info, tickets[j+1].buyer_info);
                    strcpy(tickets[j].classification, tickets[j+1].classification);
                    strcpy(tickets[j].flight_number, tickets[j+1].flight_number);
                    strcpy(tickets[j].seat_number, tickets[j+1].seat_number);
                    tickets[j].price = tickets[j+1].price;
                    strcpy(tickets[j].ticket_id, tickets[j+1].ticket_id);  
                }
            }
            if(flag == 0) printf("No search for ticket ID!\n");
            else printf("The %s has been removed from list\n", ticket_id),(*current_id)--;
        }
        
        char back2[1] = "";
        while (1)
        {
            printf("Press B to come back home: ");
            scanf("%s", &back2);
            if( strcmp(back2,"B")  == 0)
                break;
        }
}
void remove_data_file(int j){
    FILE *fptrRemoveData = fopen("ticket_database.txt", "r");
    if(fptrRemoveData == NULL) {
        printf("Error opening file\n"); 
        return;
    }
    FILE *fptrTmp = fopen("ticekettmpfile.txt", "w");
    if(fptrTmp == NULL){
        printf("Error opening file\n"); 
        return;   
    }

    char StringTmp[100];
    int countLine = 0;
    while (fgets(StringTmp, 100, fptrRemoveData) != NULL)
    {
        countLine++;
        if(countLine != j)
            fputs(StringTmp, fptrTmp);
    }
    fclose(fptrRemoveData);
    fclose(fptrTmp);
    remove("ticket_database.txt");
    rename("ticekettmpfile.txt", "ticket_database.txt");

}
// void function check whether the list is empty?
void show_ticket_list(Ticket tickets[], int *current_id, int *check){
    if(*current_id == 0) printf("Require to import tickets list\n"), *check = 0;
    else{
        *check = 1;
        printf("|-----------------------------------------------------------------------|\n");
        printf("|   ID   |       Customer     | Time |  Price  | Type |  Flight  | Seat |\n");
        printf("|-----------------------------------------------------------------------|\n");
            for (int i = 0; i < *current_id; i++)
            {
                printf("|%-8s|%-20s|%-6s|%-9.1f|%-6s|%-10s| %-4s |\n",
                    tickets[i].ticket_id,tickets[i].buyer_info, 
                    tickets[i].booking_time, tickets[i].price, tickets[i].classification,
                    tickets[i].flight_number, tickets[i].seat_number);
            }
        printf("|-----------------------------------------------------------------------|\n");
    }
}
// void function to import data from database
void import_Ticket_Database(Ticket tickets[], int *current_id){
        FILE *fptrEmptyList;
        fptrEmptyList = fopen("ticket_database.txt","r");
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
                            strcpy(tickets[j].seat_number, code);
                            break;
                        case 2:
                            strcpy(tickets[j].flight_number, code);
                            break;
                        case 3:
                            strcpy(tickets[j].classification, code);
                            break;
                        case 4:
                            tickets[j].price = atof(code);
                            break;
                        case 5:
                            strcpy(tickets[j].booking_time, code);
                            break;
                        case 6:
                            strcpy(tickets[j].buyer_info, code);
                            break;
                        case 7:
                            strcpy(tickets[j].ticket_id, code);
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
    showAll_Ticket(tickets, current_id);
}
// void funtion to show all tickets are remaining in list
void showAll_Ticket(Ticket tickets[], int *current_id) {
    if(*current_id == 0)
        import_Ticket_Database(tickets, current_id);
    else{
        printf("|-----------------------------------------------------------------------|\n");
        printf("|   ID   |       Customer     | Time |  Price  | Type |  Flight  | Seat |\n");
        printf("|-----------------------------------------------------------------------|\n");
        for (int i = 0; i < *current_id; i++)
        {
            printf("|%-8s|%-20s|%-6s|%-9.1f|%-6s|%-10s| %-4s |\n",
                tickets[i].ticket_id,tickets[i].buyer_info, 
                tickets[i].booking_time, tickets[i].price, tickets[i].classification,
                tickets[i].flight_number, tickets[i].seat_number);
        }
        printf("|-----------------------------------------------------------------------|\n");
        char back[1] = "";
        while (1)
        {
            printf("Press B to come back home: ");
            scanf("%s", &back);
            if( strcmp(back,"B")  == 0)
                break; 
        }
    }
}

// void function to storage ticket information into a file
void save_ticket_data(Ticket tickets[], int *current_id){
    FILE *fptr;
    char string[100]="";
    fptr = fopen("ticket_database.txt", "w");
    for (int i = 0; i < *current_id; i++)
    {
        // strcpy(string, tickets[i].ticket_id);
        fprintf(fptr, tickets[i].ticket_id);
        fprintf(fptr, "/");
        memset(string, 0, sizeof(string));

        // strcpy(string, tickets[i].buyer_info);
        fprintf(fptr,tickets[i].buyer_info);
        fprintf(fptr, "/");
        memset(string, 0, sizeof(string));

        // strcpy(string, tickets[i].booking_time);
        fprintf(fptr,tickets[i].booking_time);
        fprintf(fptr, "/");
        memset(string, 0, sizeof(string));

        sprintf(string, "%.1f", tickets[i].price);
        fprintf(fptr, string);
        fprintf(fptr, "/");
        memset(string, 0, sizeof(string));

        // strcpy(string, tickets[i].classification);
        fprintf(fptr,tickets[i].classification);
        fprintf(fptr, "/");
        memset(string, 0, sizeof(string));

        // strcpy(string,tickets[i].flight_number );
        fprintf(fptr,tickets[i].flight_number);
        fprintf(fptr, "/");
        memset(string, 0, sizeof(string));

        // strcpy(string,tickets[i].seat_number);
        fprintf(fptr, tickets[i].seat_number );
        fprintf(fptr, "/");
        memset(string, 0, sizeof(string));
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}