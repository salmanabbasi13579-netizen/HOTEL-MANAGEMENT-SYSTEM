/*
    File: RoomType.h
    Description:
    Instead of storing room type as a plain string inside Room,
    we use a separate RoomType class. This makes it easy to
    manage room categories and their base prices in one place.
    This is an example of object composition in OOP.
*/

#ifndef ROOMTYPE_H
#define ROOMTYPE_H

#include <iostream>
#include <string>
using namespace std;

class RoomType {
private:
    string typeName;  // e.g., Single, Double, Deluxe, Suite
    int basePrice;    // Default price for this room category

public:
    // Default constructor
    RoomType();

    // Set the type name and base price together
    void setType(string name, int price);

    // Returns the type name (used in display)
    string getTypeName();

    // Returns the base price of this room type
    int getBasePrice();
};

#endif
