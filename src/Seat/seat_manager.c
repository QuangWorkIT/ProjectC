void manageFlights() {
    while (1) {
        int choice;

        printf("\nFlight Management\n");
        printf("1. Create Flight\n");
        printf("2. Add Flight\n");
        printf("3. Delete Flight\n");
        printf("4. Modify Flight\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFlight(&flights, &numFlights);
                break;
            case 2:
                addFlight(&flights, &numFlights);
                break;
            case 3:
                deleteFlight(&flights, &numFlights);
                break;
            case 4:
                modifyFlight(&flights, &numFlights);
                break;
            case 5:
                return;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}


void createFlight(Flight **flights, int *numFlights) {
    *flights = (Flight *)realloc(*flights, (*numFlights + 1) * sizeof(Flight));
    if (*flights == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    Flight *newFlight = &(*flights)[*numFlights];

    printf("Enter flight number: ");
    scanf("%d", &newFlight->Flightnumber);

    printf("Enter destination: ");
    scanf("%s", newFlight->destination);

    printf("Enter departure date (YYYY-MM-DD): ");
    scanf("%s", newFlight->departureDate);

    printf("Enter departure time (HH:MM): ");
    scanf("%s", newFlight->departureTime);

    printf("Enter number of available seats: ");
    scanf("%d", &newFlight->availableSeats);

    createSeat(newFlight);

    (*numFlights)++;
}


void addFlight(Flight **flights, int *numFlights) {
    createFlight(flights, numFlights);
    printf("Flight added successfully.\n");
}


void deleteFlight(Flight **flights, int *numFlights) {
    if (*numFlights == 0) {
        printf("No flights available to delete.\n");
        return;
    }

    int flightNumberToDelete;
    printf("Enter flight number to delete: ");
    scanf("%d", &flightNumberToDelete);

    int found = 0;
    for (int i = 0; i < *numFlights; i++) {
        if ((*flights)[i].Flightnumber == flightNumberToDelete) {
           free((*flights)[i].seats);
            (*flights)[i] = (*flights)[(*numFlights) - 1];
            (*numFlights)--;
            found = 1;
            printf("Flight deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Flight with number %d not found.\n", flightNumberToDelete);
    }
}


void modifyFlight(Flight **flights, int numFlights) {
    if (numFlights == 0) {
        printf("No flights available to modify.\n");
        return;
    }

    int flightNumberToModify;
    printf("Enter flight number to modify: ");
    scanf("%d", &flightNumberToModify);

    int found = 0;
    for (int i = 0; i < numFlights; i++) {
        if ((*flights)[i].Flightnumber == flightNumberToModify) {
            Flight *flight = &(*flights)[i];

            printf("Enter new destination: ");
            scanf("%s", flight->destination);

            printf("Enter new departure date (YYYY-MM-DD): ");
            scanf("%s", flight->departureDate);

            printf("Enter new departure time (HH:MM): ");
            scanf("%s", flight->departureTime);

            printf("Enter new number of available seats: ");
            scanf("%d", &flight->availableSeats);

            createSeat(flight);

            printf("Flight modified successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Flight with number %d not found.\n", flightNumberToModify);
    }
}


void createSeat(Flight *flight) {
    flight->seats = (Seat *)malloc(flight->availableSeats * sizeof(Seat));
    if (flight->seats == NULL) {
        printf("Memory allocation failed for seats.\n");
        return;
    }

    for (int i = 0; i < flight->availableSeats; i++) {
        flight->seats[i].Seatnumber = i + 1;  
        strcpy(flight->seats[i].Passengername, ""); 
    }
}

void managePassengers(Flight *flights, int numFlights, Passenger *passengers, int *numPassengers) {
  while (1) {
    int choice;

    printf("\nPassenger Management\n");
    printf("1. Book Ticket\n");
    printf("2. Cancel Ticket\n");
    printf("3. Modify Passenger Information\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        bookTicket(flights, numFlights, passengers, numPassengers);
        break;
      case 2:
        cancelTicket(flights, numFlights, passengers, numPassengers);
        break;
      case 3:
        modifyPassengerInfo(passengers, numPassengers);
        break;
      case 4:
        return;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}








void managePassengers(Flight *flights, int numFlights, Passenger *passengers, int *numPassengers) {
    while (1) {
        int choice;

        printf("\nPassenger Management\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Modify Passenger Information\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket(flights, numFlights, passengers, numPassengers);
                break;
            case 2:
                cancelTicket(flights, numFlights, passengers, numPassengers);
                break;
            case 3:
                modifyPassengerInfo(passengers, numPassengers);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}


void bookTicket(Flight *flights, int numFlights, Passenger *passengers, int *numPassengers) {
    printf("Functionality to book a ticket will be implemented here.\n");
   
}


void cancelTicket(Flight *flights, int numFlights, Passenger *passengers, int *numPassengers) {
    printf("Functionality to cancel a ticket will be implemented here.\n");
   
}


void modifyPassengerInfo(Passenger *passengers, int *numPassengers) {
    printf("Functionality to modify passenger information will be implemented here.\n");
    
}


int main() {
    
    Flight flights[] = {
        {101, "New York"},
        {102, "London"},
        
    };
    int numFlights = sizeof(flights) / sizeof(Flight);

    Passenger passengers[100]; 
    int numPassengers = 0;

    managePassengers(flights, numFlights, passengers, &numPassengers);

    return 0;
}

int main() {
    flights = NULL;
    numFlights = 0;
    passengers = NULL;
    numPassengers = 0;

    int choice;
    do {
        printf("\nFlight Management System\n");
        printf("1. Add Flight\n");
        printf("2. Delete Flight\n");
        printf("3. Modify Flight\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFlight(&flights, &numFlights);
                break;
            case 2:
                deleteFlight(&flights, &numFlights);
                break;
            case 3:
                modifyFlight(&flights, numFlights);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    
    for (int i = 0; i < numFlights; i++) {
        free(flights[i].seats);
    }
    free(flights);
    free(passengers);

    return 0;
}