#include<stdio.h>
int main() {
  while (1) {
    int choice;

    printf("\nFlight Management System\n");
    printf("1. Manage Flights\n");
    printf("2. Manage Seats\n");
    printf("3. Manage Passengers\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        manageFlights();
        break;
      case 2:
        manageSeats();
        break;
      case 3:
        managePassengers();
        break;
      case 4:
             printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}