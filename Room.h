/*
    File: Room.h
    Description:
    Represents a single hotel room. Each room has a unique number,
    a RoomType object (which holds the category and price),
    and a status (Available or Booked).
*/

#ifndef ROOM_H
#define ROOM_H

#include "RoomType.h"
#include <iostream>
#include <string>
using namespace std;

class Room {
private:
    int roomNumber;    // Unique identifier for this room
    RoomType type;     // Contains the room category and price
    string status;     // "Available" or "Booked"

public:
    // Constructor sets default values
    Room();

    // Assigns room number, type name, and price
    void setRoom(int number, string typeName, int price);

    // Prints room info in a single formatted line
    void displayRoom();

    // Getter for room number
    int getRoomNumber();

    // Getter for current status
    string getStatus();

    // Getter for price (comes from RoomType)
    int getPrice();

    // Mark the room as booked
    void bookRoom();

    // Mark the room as available again
    void setAvailable();

    // Returns the type name string (used by RoomSearch for filtering)
    string getTypeName();
};

#endif
