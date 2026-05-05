#include "function.h"

// Định nghĩa biến toàn cục (chỉ cấp phát bộ nhớ ở đây)
NodeFlight* headFlight = NULL;
NodeTicket* headTicket = NULL;

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
        printf("\n6. Search flight by origin and destination");
        printf("\n7. Search flight by origin");
        printf("\n8. Search flight by destination");
        printf("\n9. Update System"); // Sửa lại số 9 hiển thị trên menu cho khớp logic
        printf("\n0. Exit program");
        printf("\nChoose an option: ");
        
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
            case 6: searchFlightByLocation(); break;
            case 7: searchFlightByOrigin(); break;
            case 8: searchFlightByDestination(); break;
            case 9: updateSystem(); break;
            case 0: printf("Ending program, Goodbye!\n"); break;
            default: printf("Invalid option! Please try again.\n");
        }
    } while(choice != 0);
    
    saveData();
    return 0;
}
