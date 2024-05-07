#include "Robot.h"

// Accessors
int Robot::getStr() const { return str; }      // Return the strength of the robot
int Robot::getHp() const { return hp; }        // Return the health points of the robot
string Robot::getName() const { return name; } // Return the name of the robot
bool Robot::hasMoved() const { return moved; } // Return whether the robot has moved

// Mutators
void Robot::setType(string newType) { type = newType; }       // Set the type of the robot
void Robot::setStr(int newStr) { str = newStr; }              // Set the strength of the robot
void Robot::setHp(int newHp) { hp = newHp; }                  // Set the health points of the robot
void Robot::setName(const string& newName) { name = newName; } // Set the name of the robot
void Robot::setMoved(bool hasMoved) { moved = hasMoved; }     // Set whether the robot has moved

// Function to reduce the health points of the robot by given damage
void Robot::takeDamage(int dmg) { hp -= dmg; }

// Default constructor for the Robot class
Robot::Robot() : type("Unknown"), str(0), hp(0), name("Unknown") {}

// Parameterized constructor for the Robot class
Robot::Robot(string newType, int newStr, int newHp, string newName) : type(newType), str(newStr), hp(newHp), name(newName) {}

// Function to get the type of the robot
string Robot::getType() {
    // This function should be overridden by derived classes
    string x = "Base Virtual function...";
    return x;
}

// Function to calculate the damage caused by the robot
int Robot::getDamage() {
    // Calculate damage by generating a random number between 1 and the robot's strength
    int dmg = (rand() % str) + 1;
    // This function should be overridden by derived classes
    return dmg;
}
