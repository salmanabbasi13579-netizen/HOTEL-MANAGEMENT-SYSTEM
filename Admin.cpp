/*
    File: Admin.cpp
    Description:
    Implementation of the Admin class login system.
*/

#include "Admin.h"

// Set hardcoded admin credentials
Admin::Admin() {
    username = "admin";
    password = "123";
}

// Ask for input and compare with stored credentials
bool Admin::login() {
    string inputUser, inputPass;

    cout << "Admin username: ";
    cin >> inputUser;
    cout << "Admin password: ";
    cin >> inputPass;

    // Check if entered credentials match
    if (inputUser == username && inputPass == password) {
        cout << "Login successful\n";
        return true;
    }

    cout << "Invalid login\n";
    return false;
}
