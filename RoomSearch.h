/*
    File: RoomSearch.h
    Description:
    The RoomSearch class provides a way to filter and display
    rooms by their type (e.g., show only "Deluxe" rooms).
    Without this, the user would have to scroll through all
    50 rooms to find available ones of a specific type.

    This class is given a reference to the rooms array from Hotel
    and does the filtering work independently — another example
    of separating responsibilities across classes.
*/

#ifndef ROOMSEARCH_H
#define ROOMSEARCH_H

#include "Room.h"
#include <iostream>
#include <string>
using namespace std;

class RoomSearch {
public:
    /*
        Search through the rooms array and print only rooms
        that match the requested type AND are available.
        Parameters:
          rooms[]    - the full array of rooms from Hotel
          totalRooms - how many rooms are in the array
          typeName   - the category to filter by (e.g. "Suite")
    */
    void searchByType(Room rooms[], int totalRooms, string typeName);

    /*
        Display only the rooms that are currently available
        regardless of type — useful for quick availability check.
    */
    void showAvailableRooms(Room rooms[], int totalRooms);
};

#endif
