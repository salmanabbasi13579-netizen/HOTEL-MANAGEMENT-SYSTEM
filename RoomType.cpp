/*
    File: RoomType.cpp
    Description:
    Implementation of the RoomType class.
*/

#include "RoomType.h"

// Initialize with empty/zero values
RoomType::RoomType() {
    typeName = "";
    basePrice = 0;
}

// Assign the type name and price
void RoomType::setType(string name, int price) {
    typeName = name;
    basePrice = price;
}

// Return the type name string
string RoomType::getTypeName() {
    return typeName;
}

// Return the base price for this category
int RoomType::getBasePrice() {
    return basePrice;
}
