#include "Bulldozer.h" // Include the header file for the Bulldozer class

// Constructor for Bulldozer objects
Bulldozer::Bulldozer(string b_name) : Robot("Bulldozer", 50, 200, b_name) {}

// Override function to get the type of the Bulldozer
string Bulldozer::getType() {
    return "Bulldozer";
}

// Override function to calculate the damage caused by the Bulldozer
int Bulldozer::getDamage() {
    int b_dmg = Robot::getDamage(); // Get the base damage from the Robot class
    return b_dmg; // Return the damage
}
