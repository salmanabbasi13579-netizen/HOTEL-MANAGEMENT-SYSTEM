/*
    File: FileManager.cpp
    Description:
    Implementation of FileManager class.
    Saves and loads booking data to/from bookings.csv

    CSV Format:
    bookingID,customerName,customerPhone,roomNumber,days,foodCharges
*/

#include "FileManager.h"

// Default CSV filename
FileManager::FileManager() {
    filename = "bookings.csv";
}

// Save all active bookings to CSV file
void FileManager::saveBookings(Booking bookings[], int totalBookings, Room rooms[], int totalRooms) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open file for saving.\n";
        return;
    }

    // Write header row
    file << "BookingID,CustomerName,CustomerPhone,RoomNumber,Days,FoodCharges\n";

    // Write each booking as one line
    for (int i = 0; i < totalBookings; i++) {
        file << bookings[i].getBookingID() << ","
            << bookings[i].getCustomerName() << ","
            << bookings[i].getCustomerPhone() << ","
            << bookings[i].getRoomNumber() << ","
            << bookings[i].getDays() << ","
            << bookings[i].getFoodCharges() << "\n";
    }

    file.close();
    cout << "Data saved to " << filename << "\n";
}

// Load bookings from CSV back into arrays at startup
void FileManager::loadBookings(Booking bookings[], int& totalBookings, Room rooms[], int totalRooms) {
    ifstream file(filename);

    // If file doesn't exist yet, that's fine — first run
    if (!file.is_open()) {
        return;
    }

    string line;
    // Skip the header row
    getline(file, line);

    totalBookings = 0;

    while (getline(file, line) && totalBookings < 50) {
        stringstream ss(line);
        string bookingID, customerName, customerPhone;
        string roomNumberStr, daysStr, foodStr;

        // Parse each comma-separated value
        getline(ss, bookingID, ',');
        getline(ss, customerName, ',');
        getline(ss, customerPhone, ',');
        getline(ss, roomNumberStr, ',');
        getline(ss, daysStr, ',');
        getline(ss, foodStr, ',');

        // Skip empty lines
        if (bookingID.empty()) continue;

        int roomNumber = stoi(roomNumberStr);
        int days = stoi(daysStr);
        int foodCharges = stoi(foodStr);

        // Rebuild the booking object from CSV data
        bookings[totalBookings].loadFromCSV(bookingID, customerName,
            customerPhone, roomNumber,
            days, foodCharges);

        // Mark that room as booked in the rooms array
        for (int j = 0; j < totalRooms; j++) {
            if (rooms[j].getRoomNumber() == roomNumber) {
                rooms[j].bookRoom();
                break;
            }
        }

        totalBookings++;
    }

    file.close();

    if (totalBookings > 0)
        cout << totalBookings << " Bookings loaded from " << filename << "\n";
}