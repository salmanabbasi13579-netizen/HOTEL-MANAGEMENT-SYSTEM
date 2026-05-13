/*
    File: Payment.h
    Description:
    The Payment class handles the payment step after checkout.
    It asks the user to choose a payment method (Cash or Card)
    and confirms the payment. This is a simple but important
    part of the hotel system and deserves its own class.
*/

#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>
using namespace std;

class Payment {
private:
    string method;   // "Cash" or "Card"
    bool paid;       // Whether payment has been made

public:
    // Constructor sets default values
    Payment();

    // Asks user to choose payment method and confirms it
    void processPayment(int totalAmount);

    // Returns whether payment was completed
    bool isPaid();

    // Returns the payment method chosen (Cash or Card) — used by Receipt
    string getMethod();
};

#endif
