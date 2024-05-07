#include "Humanic.h" // Include the header file for the Humanic class

// Constructor for Humanic objects
Humanic::Humanic(int newStr, int newHp, string h_name) : Robot("Humanic", newStr, newHp, h_name) {}

// Override function to get the type of the Humanic
string Humanic::getType() {
    return "Humanic"; // Return the type of the Humanic
}

// Override function to calculate the damage caused by the Humanic
int Humanic::getDamage() {
    int nuke_probability = rand() % 100; // Generate a random number between 0 and 99
    int h_dmg = Robot::getDamage(); // Get the base damage from the base class Robot

    if (nuke_probability < 10) { // Check if the random number is less than 10 (10% probability)
        h_dmg += 50; // If so, add 50 to the damage (nuke attack)
    }

    return h_dmg; // Return the calculated damage
}
