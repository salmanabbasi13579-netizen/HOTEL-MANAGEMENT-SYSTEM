/*
    File: Admin.h
    Description:
    The Admin class handles the login system for the hotel.
*/

#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
using namespace std;

class Admin {
private:
    string username; // Stored admin username
    string password; // Stored admin password

public:
    // Constructor sets the default admin credentials
    Admin();

    // Asks user for credentials and checks if they match
    bool login();
};

#endif
