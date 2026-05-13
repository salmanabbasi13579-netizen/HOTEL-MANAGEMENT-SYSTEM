/*
    File: FoodService.cpp
    Description:
    Implementation of FoodService class.
*/

#include "FoodService.h"

// Initialize with no food charges
FoodService::FoodService() {
    totalFoodCharges = 0;
}

// Add a new charge on top of existing total
void FoodService::addCharge(int amount) {
    totalFoodCharges += amount;
}

// Return total food charges accumulated so far
int FoodService::getTotal() {
    return totalFoodCharges;
}

// Reset to zero (used on checkout/cancel)
void FoodService::reset() {
    totalFoodCharges = 0;
}
