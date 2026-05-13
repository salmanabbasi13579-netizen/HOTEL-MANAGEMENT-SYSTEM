/*
    File: Customer.h
    Description:
    This class stores personal information of the customer
    who is making a hotel booking. It keeps the name and
    phone number separate from booking details, which is
    good OOP practice (each class has one responsibility).
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    string name;   // Full name of the customer
    string phone;  // Contact number of the customer

public:
    // Default constructor - sets empty values
    Customer();

    // Takes customer details as input from the user
    void setDetails();

    // Directly set name and phone (used when loading from CSV)
    void setFromCSV(string n, string p);

    // Returns customer name (used in bill display)
    string getName();

    // Returns customer phone number
    string getPhone();
};

#endif