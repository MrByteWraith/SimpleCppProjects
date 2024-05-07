#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include "Humanic.h" // Include the base class header file

class OptimusPrime : public Humanic { // Define a class OptimusPrime which inherits from Humanic
public:
    OptimusPrime(string o_name); // Constructor for OptimusPrime objects

    // Override function from the base class Humanic
    virtual int getDamage() override; // Function to get the damage caused by OptimusPrime
};

#endif // OPTIMUSPRIME_H
