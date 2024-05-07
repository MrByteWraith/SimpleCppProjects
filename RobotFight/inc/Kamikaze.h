#ifndef KAMIKAZE_H
#define KAMIKAZE_H

#include "Robot.h" // Include the header file for the base class Robot

class Kamikaze : public Robot { // Define a class Kamikaze which inherits from Robot
public:
    // Constructor for Kamikaze objects
    Kamikaze(string k_name);

    // Override function to get the type of the Kamikaze
    virtual string getType() override;

    // Override function to calculate the damage caused by the Kamikaze
    virtual int getDamage() override;
};

#endif // KAMIKAZE_H
