#include "Robocop.h" // Include the header file for the Robocop class

// Constructor for Robocop objects
Robocop::Robocop(string rb_name) : Humanic(30, 40, rb_name) {}

// Function to calculate the damage caused by the Robocop
int Robocop::getDamage() {
    // Get the damage from the base class Humanic
    return Humanic::getDamage();
}
