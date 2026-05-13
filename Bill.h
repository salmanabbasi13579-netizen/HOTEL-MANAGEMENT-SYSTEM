/*
    File: Bill.h
    Description:
    The Bill class is responsible for calculating and displaying
    the final invoice for a customer at checkout time.
    It takes the room price, number of days, and food charges,
    then computes and prints the total bill.

    Separating billing into its own class is good OOP design
    because it follows the Single Responsibility Principle —
    Booking should not be responsible for calculating bills.
*/

#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <string>
using namespace std;

class Bill {
private:
    string customerName; // Name shown on the bill
    int roomNumber;      // Room the customer stayed in
    int days;            // Number of days of stay
    int roomPrice;       // Price per day for the room
    int foodCharges;     // Total food charges added during stay

public:
    // Constructor initializes all fields to zero/empty
    Bill();

    // Set all values needed to calculate the bill
    void setBillDetails(string name, int room, int d, int price, int food);

    // Print the full formatted bill to the screen
    void displayBill();

    // Calculate and return the grand total
    int getTotal();
};

#endif
