#ifndef BULLDOZER_H
#define BULLDOZER_H

#include "Robot.h" // Include the header file for the base class Robot

class Bulldozer : public Robot { // Define a class Bulldozer which inherits from Robot
public:
    // Constructor for Bulldozer objects
    Bulldozer(string b_name);

    // Override function to get the type of the Bulldozer
    virtual string getType() override;

    // Override function to calculate the damage caused by the Bulldozer
    virtual int getDamage() override;
};

#endif // BULLDOZER_H
