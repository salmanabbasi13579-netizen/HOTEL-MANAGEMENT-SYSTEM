/*
    File: Booking.h
    Description:
    The Booking class represents a single reservation in the hotel.
    It links a Customer to a specific room and tracks the stay duration.
    It now uses Customer and FoodService as composed objects, which
    keeps each class focused on its own responsibility.
*/

#ifndef BOOKING_H
#define BOOKING_H

#include "Customer.h"
#include "FoodService.h"
#include <iostream>
#include <string>
using namespace std;

class Booking {
private:
    string bookingID;    // Unique ID to identify this booking
    Customer customer;   // Customer details (name, phone)
    int roomNumber;      // Which room is booked
    int days;            // How many days the customer stays
    FoodService food;    // Tracks food charges for this booking

public:
    // Default constructor
    Booking();

    // Collects all booking information from user
    void createBooking();

    // Add food charges through FoodService
    void addFoodCharges(int charge);

    // Return total food charges (used by Bill at checkout)
    int getFoodCharges();

    // Return customer name (for Bill display)
    string getCustomerName();

    // Return customer phone (for CSV saving)
    string getCustomerPhone();

    // Load a booking directly from CSV data (no user input)
    void loadFromCSV(string bID, string name, string phone,
        int roomNum, int d, int foodCharge);

    // Return number of days (for Bill calculation)
    int getDays();

    // Getters used by Hotel class
    string getBookingID();
    int getRoomNumber();
};

#endif