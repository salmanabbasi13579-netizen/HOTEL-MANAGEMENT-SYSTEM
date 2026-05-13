/*
    File: FileManager.h
    Description:
    The FileManager class handles saving and loading of booking
    data to/from a CSV file (bookings.csv). This ensures that
    all bookings PERSIST even after the program is closed.
    When the program starts again, all previous bookings are
    loaded back automatically.

    CSV Format (one booking per line):
    bookingID, customerName, customerPhone, roomNumber, days, foodCharges
*/

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Booking.h"
#include "Room.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class FileManager {
private:
    string filename; // Name of the CSV file to save/load

public:
    // Constructor — sets the default filename
    FileManager();

    // Saves all current bookings to the CSV file
    // Called automatically after every new booking
    void saveBookings(Booking bookings[], int totalBookings, Room rooms[], int totalRooms);

    // Loads bookings from the CSV file into the arrays
    // Called once at program startup
    void loadBookings(Booking bookings[], int& totalBookings, Room rooms[], int totalRooms);
};

#endif