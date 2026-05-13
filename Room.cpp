/*
    File: Room.cpp
    Description:
    Implementation of the Room class. Room uses a RoomType object
    internally so that type name and price are managed together.
*/

#include "Room.h"

// Set default values for a new room object
Room::Room() {
    roomNumber = 0;
    status = "Available";
}

// Called during hotel initialization to set up each room
void Room::setRoom(int number, string typeName, int price) {
    roomNumber = number;
    type.setType(typeName, price); // Delegate type/price to RoomType
    status = "Available";
}

// Display one row of room information
void Room::displayRoom() {
    cout << roomNumber << "\t"
         << type.getTypeName() << "\t"
         << type.getBasePrice() << "\t"
         << status << endl;
}

int Room::getRoomNumber() {
    return roomNumber;
}

string Room::getStatus() {
    return status;
}

// Price is stored inside RoomType, so we ask RoomType for it
int Room::getPrice() {
    return type.getBasePrice();
}

void Room::bookRoom() {
    status = "Booked";
}

void Room::setAvailable() {
    status = "Available";
}

// Return the type name from the RoomType object inside this room
string Room::getTypeName() {
    return type.getTypeName();
}
