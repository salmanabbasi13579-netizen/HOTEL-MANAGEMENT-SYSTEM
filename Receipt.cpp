/*
    File: Receipt.cpp
    Description:
    Implementation of the Receipt class.
    Prints a clean, bordered checkout receipt for the customer.
*/

#include "Receipt.h"

// Initialize all fields to safe default values
Receipt::Receipt() {
    customerName  = "";
    roomNumber    = 0;
    roomType      = "";
    days          = 0;
    roomCharges   = 0;
    foodCharges   = 0;
    totalAmount   = 0;
    paymentMethod = "";
}

// Store all the details needed before printing
void Receipt::setDetails(string name, int room, string type, int d,
                         int rCharges, int fCharges, int total, string method) {
    customerName  = name;
    roomNumber    = room;
    roomType      = type;
    days          = d;
    roomCharges   = rCharges;
    foodCharges   = fCharges;
    totalAmount   = total;
    paymentMethod = method;
}

// Print the formatted receipt to the console
void Receipt::printReceipt() {
    cout << "\n========================================\n";
    cout << "         GRAND STAR HOTEL               \n";
    cout << "            RECEIPT                     \n";
    cout << "========================================\n";
    cout << "Customer    : " << customerName  << endl;
    cout << "Room No     : " << roomNumber    << endl;
    cout << "Room Type   : " << roomType      << endl;
    cout << "Days Stayed : " << days          << endl;
    cout << "----------------------------------------\n";
    cout << "Room Charges: " << roomCharges   << endl;
    cout << "Food Charges: " << foodCharges   << endl;
    cout << "----------------------------------------\n";
    cout << "TOTAL PAID  : " << totalAmount   << endl;
    cout << "Paid Via    : " << paymentMethod << endl;
    cout << "========================================\n";
    cout << "  Thank you for staying with us!        \n";
    cout << "========================================\n";
}
