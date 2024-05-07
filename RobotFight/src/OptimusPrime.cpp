#include "OptimusPrime.h" // Include the header file for the OptimusPrime class

// Constructor for OptimusPrime objects
OptimusPrime::OptimusPrime(string o_name) : Humanic(100, 100, o_name) {}

// Function to calculate the damage caused by OptimusPrime
int OptimusPrime::getDamage() {
    // Generate a random number between 0 and 99 to simulate the probability of a strong attack
    int strongAttackProbability = rand() % 100;
    
    // Get the base damage from the base class Humanic
    int o_dmg = Humanic::getDamage();
    
    // If the random number is less than 15 (15% probability), double the damage
    if (strongAttackProbability < 15) {
        o_dmg *= 2;
    }
    
    return o_dmg;
}
