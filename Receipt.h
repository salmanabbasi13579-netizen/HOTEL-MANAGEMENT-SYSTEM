/*
    File: Receipt.h
    Description:
    The Receipt class prints a final formatted receipt after
    payment is completed at checkout. While Bill calculates
    and shows the charges, Receipt is responsible for the
    presentation — a nicely bordered summary the customer
    can read before leaving. This follows the Single
    Responsibility Principle: Bill handles math, Receipt
    handles the final printout.
*/

#ifndef RECEIPT_H
#define RECEIPT_H

#include <iostream>
#include <string>
using namespace std;

class Receipt {
private:
    string customerName;  // Customer name printed on receipt
    int roomNumber;       // Room number stayed in
    string roomType;      // Type of room (Single, Double, etc.)
    int days;             // Total days of stay
    int roomCharges;      // Total room cost (price x days)
    int foodCharges;      // Total food charges
    int totalAmount;      // Grand total paid
    string paymentMethod; // How they paid (Cash or Card)

public:
    // Default constructor — initializes all to zero/empty
    Receipt();

    // Load all values needed to print the receipt
    void setDetails(string name, int room, string type, int d,
                    int rCharges, int fCharges, int total, string method);

    // Print the full receipt to the screen
    void printReceipt();
};

#endif
