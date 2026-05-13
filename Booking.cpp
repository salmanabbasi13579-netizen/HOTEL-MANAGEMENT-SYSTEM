/*
    File: Booking.cpp
    Description:
    Implementation of the Booking class.
    Handles creation of a reservation and food charge tracking.
*/

#include "Booking.h"

// Initialize all fields with default empty/zero values
Booking::Booking() {
    bookingID = "";
    roomNumber = 0;
    days = 0;
}

// Collect all information needed for the booking
void Booking::createBooking() {
    cout << "Enter booking ID: ";
    cin >> bookingID;

    // Customer class handles its own input
    customer.setDetails();

    cout << "Enter room number: ";
    cin >> roomNumber;

    cout << "Enter number of days: ";
    cin >> days;

    // Food charges start at 0 when booking is created
    food.reset();
}

// Pass the charge down to the FoodService object
void Booking::addFoodCharges(int charge) {
    food.addCharge(charge);
}

// Return total food charges from FoodService
int Booking::getFoodCharges() {
    return food.getTotal();
}

// Return customer name from the Customer object
string Booking::getCustomerName() {
    return customer.getName();
}

// Return customer phone — needed by FileManager to save to CSV
string Booking::getCustomerPhone() {
    return customer.getPhone();
}

// Load a booking from CSV without asking for user input
// Called by FileManager when the program starts
void Booking::loadFromCSV(string bID, string name, string phone,
    int roomNum, int d, int foodCharge) {
    bookingID = bID;
    roomNumber = roomNum;
    days = d;
    customer.setFromCSV(name, phone); // set customer details directly
    food.reset();
    food.addCharge(foodCharge);       // restore any saved food charges
}

// Return number of days stayed
int Booking::getDays() {
    return days;
}

// Return the unique booking ID
string Booking::getBookingID() {
    return bookingID;
}

// Return the room number linked to this booking
int Booking::getRoomNumber() {
    return roomNumber;
}