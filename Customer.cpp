/*
    File: Customer.cpp
    Description:
    Implementation of the Customer class.
    Handles input and retrieval of customer personal data.
*/

#include "Customer.h"

// Initialize with empty strings
Customer::Customer() {
    name = "";
    phone = "";
}

// Ask user to enter their name and phone number
void Customer::setDetails() {
    cout << "Enter customer name: ";
    cin >> name;
    cout << "Enter phone number: ";
    cin >> phone;
}

// Set name and phone directly from CSV data (no user input needed)
void Customer::setFromCSV(string n, string p) {
    name = n;
    phone = p;
}

// Return the customer's name
string Customer::getName() {
    return name;
}

// Return the customer's phone number
string Customer::getPhone() {
    return phone;
}