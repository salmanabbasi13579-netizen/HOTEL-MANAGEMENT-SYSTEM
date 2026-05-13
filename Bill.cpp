/*
    File: Bill.cpp
    Description:
    Implementation of the Bill class.
    This class handles all bill-related logic and display.
*/

#include "Bill.h"

// Set default empty/zero values
Bill::Bill() {
    customerName = "";
    roomNumber = 0;
    days = 0;
    roomPrice = 0;
    foodCharges = 0;
}

// Load all the data needed to generate the bill
void Bill::setBillDetails(string name, int room, int d, int price, int food) {
    customerName = name;
    roomNumber = room;
    days = d;
    roomPrice = price;
    foodCharges = food;
}

// Calculate total and print a nicely formatted bill
void Bill::displayBill() {
    int roomCost = roomPrice * days;  // Total room cost = price per day x days
    int total = roomCost + foodCharges;

    cout << "\n----- BILL -----\n";
    cout << "Customer   : " << customerName << endl;
    cout << "Room No    : " << roomNumber << endl;
    cout << "Days Stayed: " << days << endl;
    cout << "Room Charges: " << roomCost << endl;
    cout << "Food Charges: " << foodCharges << endl;
    cout << "TOTAL BILL  : " << total << endl;
    cout << "----------------\n";
}

// Returns the calculated total (room + food)
int Bill::getTotal() {
    return (roomPrice * days) + foodCharges;
}
