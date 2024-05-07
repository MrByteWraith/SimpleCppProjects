#ifndef HUMANIC_H
#define HUMANIC_H

#include "Robot.h" // Include the header file for the base class Robot

class Humanic : public Robot { // Define a class Humanic which inherits from Robot
public:
    // Constructor for Humanic objects
    Humanic(int newStr, int newHp, string h_name);

    // Override function to get the type of the Humanic
    virtual string getType() override;

    // Override function to calculate the damage caused by the Humanic
    virtual int getDamage() override;
};

#endif // HUMANIC_H
