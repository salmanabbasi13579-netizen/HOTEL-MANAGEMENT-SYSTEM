/*
    File: FoodService.h
    Description:
    Manages food charges for a booking. Previously, food charges
    were just an integer inside Booking. By making it a class,
    we can later expand it to track individual food items,
    quantities, etc. For now it stores the total food charge.
*/

#ifndef FOODSERVICE_H
#define FOODSERVICE_H

#include <iostream>
using namespace std;

class FoodService {
private:
    int totalFoodCharges; // Running total of all food added

public:
    // Start with zero food charges
    FoodService();

    // Add more food charges to the running total
    void addCharge(int amount);

    // Return the current total food charges
    int getTotal();

    // Reset food charges (used when booking is cleared)
    void reset();
};

#endif
