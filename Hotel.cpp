/*
    File: Hotel.cpp
    Description:
    Implementation of all Hotel operations.
    Hotel coordinates between Room, Booking, Bill, Payment, Admin,
    Receipt, RoomSearch, and FileManager.

    FileManager is now called:
    - loadData()   -> at startup to restore saved bookings from CSV
    - saveBookings -> after every booking, food charge, or cancellation
      so data is never lost even if the program closes unexpectedly
*/

#include "Hotel.h"
#include <iostream>
using namespace std;

// Initialize room and booking counters
Hotel::Hotel() {
    totalRooms = 0;
    totalBookings = 0;
}

// Ask Admin object to handle login
bool Hotel::adminLogin() {
    return admin.login();
}

// Load all rooms with their types and prices into the rooms array
void Hotel::loadRooms() {
    int roomNum = 101;

    string types[] = { "Single", "Double", "Deluxe", "Suite" };
    int prices[] = { 2000, 3500, 5000, 8000 };
    int counts[] = { 12, 12, 13, 13 };

    for (int t = 0; t < 4; t++) {
        for (int i = 0; i < counts[t]; i++) {
            rooms[totalRooms].setRoom(roomNum++, types[t], prices[t]);
            totalRooms++;
        }
    }
}

// Load saved bookings from CSV file at startup
// Must be called AFTER loadRooms() so room statuses can be restored
void Hotel::loadData() {
    fileManager.loadBookings(bookings, totalBookings, rooms, totalRooms);
}

// Display all rooms with their number, type, price, and status
void Hotel::viewRooms() {
    cout << "\nRoom No\tType\tPrice\tStatus\n";
    for (int i = 0; i < totalRooms; i++) {
        rooms[i].displayRoom();
    }
}

// Book a room by room number
void Hotel::bookRoom() {
    int roomNumber;
    cout << "Enter room number: ";
    cin >> roomNumber;

    for (int i = 0; i < totalRooms; i++) {
        if (rooms[i].getRoomNumber() == roomNumber) {

            if (rooms[i].getStatus() == "Booked") {
                cout << "Room already booked\n";
                return;
            }

            bookings[totalBookings].createBooking();
            rooms[i].bookRoom();
            totalBookings++;

            // Save to CSV immediately so data is not lost
            fileManager.saveBookings(bookings, totalBookings, rooms, totalRooms);

            cout << "Room booked successfully\n";
            return;
        }
    }

    cout << "Room not found\n";
}

// Add food charges to an existing booking by booking ID
void Hotel::addFoodCharges() {
    string id;
    cout << "Enter booking ID: ";
    cin >> id;

    for (int i = 0; i < totalBookings; i++) {
        if (bookings[i].getBookingID() == id) {
            int charge;
            cout << "Enter food charges: ";
            cin >> charge;
            bookings[i].addFoodCharges(charge);

            // Save updated food charges to CSV
            fileManager.saveBookings(bookings, totalBookings, rooms, totalRooms);

            cout << "Charges added\n";
            return;
        }
    }

    cout << "Booking not found\n";
}

// Checkout: show bill, take payment, print receipt, free the room
void Hotel::checkout() {
    string id;
    cout << "Enter booking ID: ";
    cin >> id;

    for (int i = 0; i < totalBookings; i++) {
        if (bookings[i].getBookingID() == id) {

            int roomNumber = bookings[i].getRoomNumber();

            for (int j = 0; j < totalRooms; j++) {
                if (rooms[j].getRoomNumber() == roomNumber) {

                    int rCharges = rooms[j].getPrice() * bookings[i].getDays();
                    int fCharges = bookings[i].getFoodCharges();

                    Bill bill;
                    bill.setBillDetails(
                        bookings[i].getCustomerName(),
                        roomNumber,
                        bookings[i].getDays(),
                        rooms[j].getPrice(),
                        fCharges
                    );
                    bill.displayBill();

                    Payment payment;
                    payment.processPayment(bill.getTotal());

                    Receipt receipt;
                    receipt.setDetails(
                        bookings[i].getCustomerName(),
                        roomNumber,
                        rooms[j].getTypeName(),
                        bookings[i].getDays(),
                        rCharges,
                        fCharges,
                        bill.getTotal(),
                        payment.getMethod()
                    );
                    receipt.printReceipt();

                    rooms[j].setAvailable();

                    for (int k = i; k < totalBookings - 1; k++) {
                        bookings[k] = bookings[k + 1];
                    }
                    totalBookings--;

                    // Save updated bookings list (booking removed after checkout)
                    fileManager.saveBookings(bookings, totalBookings, rooms, totalRooms);

                    cout << "Checkout complete\n";
                    return;
                }
            }
        }
    }

    cout << "Booking not found\n";
}

// Search rooms by type or show all available rooms
void Hotel::searchRooms() {
    RoomSearch searcher;
    int choice;

    cout << "\n--- Room Search ---\n";
    cout << "1) Search by type (Single / Double / Deluxe / Suite)\n";
    cout << "2) Show all available rooms\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        string typeName;
        cout << "Enter room type: ";
        cin >> typeName;
        searcher.searchByType(rooms, totalRooms, typeName);
    }
    else {
        searcher.showAvailableRooms(rooms, totalRooms);
    }
}

// Cancel a booking and make the room available again
void Hotel::cancelBooking() {
    string id;
    cout << "Enter booking ID: ";
    cin >> id;

    for (int i = 0; i < totalBookings; i++) {
        if (bookings[i].getBookingID() == id) {

            int roomNumber = bookings[i].getRoomNumber();

            for (int j = 0; j < totalRooms; j++) {
                if (rooms[j].getRoomNumber() == roomNumber) {
                    rooms[j].setAvailable();
                }
            }

            for (int k = i; k < totalBookings - 1; k++) {
                bookings[k] = bookings[k + 1];
            }
            totalBookings--;

            // Save updated list to CSV after cancellation
            fileManager.saveBookings(bookings, totalBookings, rooms, totalRooms);

            cout << "Booking cancelled\n";
            return;
        }
    }

    cout << "Booking not found\n";
}