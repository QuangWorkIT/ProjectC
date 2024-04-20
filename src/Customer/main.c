#include <stdio.h>
#include "customer.h"

int main(){
    Customer customerList[100];
    int current_id = 0;
    int flag = 1;
    do
    {
        printf("Enter option: ");
        int n; 
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                printf("Enter new customer information\n");
                create_Customer(customerList, &current_id);
                break;
            case 2:
                printf("Set id\n");
                set_ID(customerList, &current_id);
                break;
            case 3:
                printf("Set name\n");
                set_Name(customerList, &current_id);
                break;
            case 4:
                printf("Set phone number\n");
                set_Phone_Number(customerList, &current_id);
                break;
            case 5:
                printf("Set email");
                set_Email(customerList, &current_id);
                break;
            case 6:
                showAll(customerList, &current_id);
                break;
            default:
                flag = 0;
                printf("Exit");
                break;
        }
    } while (flag == 1);
    return 0;
}