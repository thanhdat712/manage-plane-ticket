// --- DATA STRUCTURES ---
typedef struct {
    int day, month, year;
} DATE;

typedef struct {
    int h, m;
} HOUR;

// Structure for flight/plane
typedef struct {
    char ID[10];
    char name[20];
    int seatNormal;
    int seatVIP; 
    int seatHolded;
    int seatVIPHolded;
    char origin[20], destination[20];  
    DATE date;
    HOUR hour;
} Flight;

// Structure for ticket
typedef struct {
    char flightID[10];
    int rank; 
    int ticketID;
    char passengerName[20];
    char seat[5];
    char position[20];
    char origin[20];  
    char destination[20];
    long long idCard;
    DATE date;
    HOUR hour;
} Ticket;

// --- LINKED LIST MANAGEMENT ---
// Define Node for flight list
typedef struct NodeFlight { 
    Flight data; 
    struct NodeFlight* next; 
} NodeFlight;

// Define Node for ticket list
typedef struct NodeTicket { 
    Ticket data; 
    struct NodeTicket* next; 
} NodeTicket;

// Declare head pointers for the lists
NodeFlight* headFlight = NULL;
NodeTicket* headTicket = NULL;

// --- MAIN PROGRAM (MENU) ---
int main() {
    int choice;
    loadData();
    do {
        printf("\n======= FLIGHT MANAGEMENT SYSTEM =======");
        printf("\n1. Add a flight");
        printf("\n2. Display flight list");
        printf("\n3. Book a ticket");
        printf("\n4. Cancel a ticket");
        printf("\n5. Display booked tickets list");
        printf("\n0. Exit program");
        printf("\nChoose an option: ");
        
        // Validate menu input
        if(scanf("%d", &choice) != 1) { 
            clearBuffer(); 
            printf("Please enter numbers only!\n");
            continue; 
        }
        
        switch(choice) {
            case 1: addFlight(); break;
            case 2: displayFlights(); break;
            case 3: bookTicket(); break;
            case 4: cancelTicket(); break;
            case 5: displayTickets(); break;
            case 0: printf("Ending program, Goodbye!\n"); break;
            default: printf("Invalid option! Please try again.\n");
        }
    } while(choice != 0);
    saveData();
    return 0;
}
