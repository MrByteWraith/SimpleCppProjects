#include "Roomba.h" // Include the header file for the Roomba class

// Constructor for Roomba objects
Roomba::Roomba(string r_name) : Robot("Roomba", 3, 10, r_name) {}

// Function to get the type of the Roomba
string Roomba::getType() {
    return "Roomba";
}

// Function to calculate the damage caused by the Roomba
int Roomba::getDamage() {
    // Get the damage from the base class Robot twice and sum them up
    int r_dmg1 = Robot::getDamage();
    int r_dmg2 = Robot::getDamage();
    return r_dmg1 + r_dmg2;
}
