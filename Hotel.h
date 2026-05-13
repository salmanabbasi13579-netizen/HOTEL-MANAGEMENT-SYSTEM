/*
    File: Hotel.h
    Description:
    The Hotel class is the central manager of the entire system.
    It holds all rooms and bookings, and coordinates operations
    like booking a room, adding food charges, checkout, and cancellation.
    It now delegates login to Admin, billing to Bill, and payment to Payment.
*/

#ifndef HOTEL_H
#define HOTEL_H

#include "Room.h"
#include "Booking.h"
#include "Admin.h"
#include "Bill.h"
#include "Payment.h"
#include "Receipt.h"
#include "RoomSearch.h"
#include "FileManager.h"

class Hotel {
private:
    static const int MAX = 50; // Max number of rooms and bookings allowed
    Room rooms[MAX];           // Array of all hotel rooms
    Booking bookings[MAX];     // Array of all active bookings
    int totalRooms;            // How many rooms are loaded
    int totalBookings;         // How many bookings are currently active
    Admin admin;               // Admin object handles login
    FileManager fileManager;   // Handles CSV save/load of bookings

public:
    // Constructor sets counters to zero
    Hotel();

    // Delegates login check to Admin class
    bool adminLogin();

    // Populates rooms array with default hotel rooms
    void loadRooms();

    // Prints all rooms and their current status
    void viewRooms();

    // Creates a new booking for a selected room
    void bookRoom();

    // Adds food charges to an existing booking
    void addFoodCharges();

    // Generates bill, takes payment, and frees the room
    void checkout();

    // Cancels a booking and makes room available again
    void cancelBooking();

    // Search rooms by type using the RoomSearch class
    void searchRooms();

    // Load saved bookings from CSV at startup
    void loadData();
};

#endif