#ifndef ROBOCOP_H
#define ROBOCOP_H

#include "Humanic.h" // Include the base class header file

class Robocop : public Humanic { // Define a class Robocop which inherits from Humanic
public:
    Robocop(string rb_name); // Constructor for Robocop objects

    // Override function from the base class Humanic
    virtual int getDamage() override; // Function to get the damage caused by the Robocop
};

#endif // ROBOCOP_H
