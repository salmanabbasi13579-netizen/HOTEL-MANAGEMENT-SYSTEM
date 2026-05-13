/*
    File: main.cpp
    Description:
    Entry point of the Hotel Management System.
    Creates the Hotel object, loads rooms, restores saved bookings
    from CSV, authenticates admin, then runs the main menu loop.

    Classes used in this project:
    1.  Customer      - stores customer name and phone
    2.  RoomType      - stores room category and base price
    3.  Room          - represents a hotel room (uses RoomType)
    4.  FoodService   - tracks food charges for a booking
    5.  Booking       - reservation linking customer to room
    6.  Admin         - handles admin login
    7.  Bill          - calculates and displays the checkout bill
    8.  Payment       - handles payment method and confirmation
    9.  Receipt       - prints a final formatted receipt after payment
    10. RoomSearch    - filters rooms by type or availability
    11. Hotel         - main controller class (uses all above)
    12. FileManager   - saves and loads bookings to/from bookings.csv
*/

#include <iostream>
#include "Hotel.h"
using namespace std;

int main() {
    Hotel hotel;

    // Step 1: Load all 50 rooms into memory
    hotel.loadRooms();

    // Step 2: Restore any previously saved bookings from bookings.csv
    // This is what makes data PERSIST between sessions
    hotel.loadData();

    // Step 3: Admin must log in before accessing the system
    if (!hotel.adminLogin())
        return 0;

    int choice;

    while (true) {
        cout << "\n--- HOTEL MANAGEMENT MENU ---\n";
        cout << "1) View All Rooms\n";
        cout << "2) Search Rooms\n";
        cout << "3) Book Room\n";
        cout << "4) Add Food Charges\n";
        cout << "5) Checkout\n";
        cout << "6) Cancel Booking\n";
        cout << "7) Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: hotel.viewRooms();      break;
        case 2: hotel.searchRooms();    break;
        case 3: hotel.bookRoom();       break;
        case 4: hotel.addFoodCharges(); break;
        case 5: hotel.checkout();       break;
        case 6: hotel.cancelBooking();  break;
        case 7:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}