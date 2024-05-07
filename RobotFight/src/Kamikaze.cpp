#include "Kamikaze.h" // Include the header file for the Kamikaze class

// Constructor for Kamikaze objects
Kamikaze::Kamikaze(string k_name) : Robot("Kamikaze", 10, 10, k_name) {}

// Override function to get the type of the Kamikaze
string Kamikaze::getType() {
    return "Kamikaze"; // Return the type of the Kamikaze
}

// Override function to calculate the damage caused by the Kamikaze
int Kamikaze::getDamage() {
    int k_dmg = getHp(); // Get the current health points of the Kamikaze
    setHp(0); // Set the health points of the Kamikaze to 0 (self-destruct)
    return k_dmg; // Return the damage caused by the Kamikaze
}
