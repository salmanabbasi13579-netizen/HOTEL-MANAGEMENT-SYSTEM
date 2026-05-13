/*
    File: Payment.cpp
    Description:
    Implementation of the Payment class.
*/

#include "Payment.h"

// Start as unpaid with no method selected
Payment::Payment() {
    method = "";
    paid = false;
}

// Ask user to pick payment method and mark payment as done
void Payment::processPayment(int totalAmount) {
    int choice;
    cout << "\nTotal Amount Due: " << totalAmount << endl;
    cout << "Select Payment Method:\n";
    cout << "1) Cash\n";
    cout << "2) Card\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        method = "Cash";
    } else {
        method = "Card";
    }

    // For simplicity, payment is always confirmed
    paid = true;
    cout << "Payment of " << totalAmount << " received via " << method << ". Thank you!\n";
}

// Returns true if payment was successfully processed
bool Payment::isPaid() {
    return paid;
}

// Returns the method selected so Receipt can print it
string Payment::getMethod() {
    return method;
}
