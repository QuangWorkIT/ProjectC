#include <stdio.h>
#include "ticket.h"

int main(){
    int current_id = 0;
    // tạo 1 cấu trúc dữ liệu mảng để lưu cái object thông tin chuyến bay
    Ticket tickets[100];
    int logic = 1;
    do
    {
        printf("Menu of ticket\n");
        printf("1.Create new ticket \n2.Remove a available ticket \n3.Show all the tickets\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Create a new new tickets\n");
                // hàm tạo vé trong ticket_create.c
                create_ticket(tickets, &current_id);
                break;
            case 2:
                // hàm loại bỏ vé thông qua ID của vé
                remove_ticket(tickets, &current_id);
                break;
            case 3:
                // hàm in danh sách các vé đã lưu trữ trong mảng
                showAll(tickets, &current_id);
                break;
            default:
                printf("Exit");
                logic = 0;
                break;
            }
    } while (logic == 1);
    
    return 0;
}