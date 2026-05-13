/*
    File: RoomSearch.cpp
    Description:
    Implementation of the RoomSearch class.
    Provides filtering functionality for the rooms array.
*/

#include "RoomSearch.h"

// Show only rooms matching the given type name
void RoomSearch::searchByType(Room rooms[], int totalRooms, string typeName) {
    bool found = false;

    cout << "\n--- Rooms of type: " << typeName << " ---\n";
    cout << "Room No\tType\tPrice\tStatus\n";

    for (int i = 0; i < totalRooms; i++) {
        // Room exposes getTypeName via its RoomType internally
        // We call displayRoom() only for matching rooms
        if (rooms[i].getTypeName() == typeName) {
            rooms[i].displayRoom();
            found = true;
        }
    }

    if (!found) {
        cout << "No rooms found for type: " << typeName << endl;
    }
}

// Show all rooms that are currently not booked
void RoomSearch::showAvailableRooms(Room rooms[], int totalRooms) {
    bool found = false;

    cout << "\n--- Available Rooms ---\n";
    cout << "Room No\tType\tPrice\tStatus\n";

    for (int i = 0; i < totalRooms; i++) {
        if (rooms[i].getStatus() == "Available") {
            rooms[i].displayRoom();
            found = true;
        }
    }

    if (!found) {
        cout << "No rooms available at the moment.\n";
    }
}
