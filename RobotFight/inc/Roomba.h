#ifndef ROOMBA_H
#define ROOMBA_H

#include "Robot.h" // Include the base class header file

class Roomba : public Robot { // Define a class Roomba which inherits from Robot
public:
    Roomba(string r_name); // Constructor for Roomba objects

    // Override functions from the base class Robot
    virtual string getType() override; // Function to get the type of the Roomba
    virtual int getDamage() override; // Function to get the damage caused by the Roomba
};

#endif
