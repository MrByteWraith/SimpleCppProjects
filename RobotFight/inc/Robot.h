#ifndef ROBOT_H
#define ROBOT_H

#include <string>

using namespace std;

class Robot {
private:
    string type;    // Type of the robot
    int str;        // Strength of the robot
    int hp;         // Health points of the robot
    string name;    // Name of the robot
    bool moved;     // Flag indicating whether the robot has moved or not

public:
    // Virtual function to get the type of the robot
    virtual string getType();

    // Virtual function to calculate the damage caused by the robot
    virtual int getDamage();

    // Getters for private member variables
    int getStr() const;             // Get strength
    int getHp() const;              // Get health points
    string getName() const;         // Get name
    bool hasMoved() const;          // Check if the robot has moved

    // Setters for private member variables
    void setType(string newType);   // Set type
    void setStr(int newStr);        // Set strength
    void setHp(int newHp);          // Set health points
    void setName(const string& newName); // Set name
    void setMoved(bool hasMoved);   // Set moved flag
    void takeDamage(int dmg);       // Reduce health points by given damage

    // Constructors
    Robot();                        // Default constructor
    Robot(string newType, int newStr, int newHp, string newName); // Parameterized constructor

};

#endif
