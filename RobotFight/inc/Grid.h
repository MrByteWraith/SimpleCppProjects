#ifndef GRID_H
#define GRID_H

#include "Robot.h" // Include the header file for the Robot class

const int grid_size = 10; // Define a constant representing the size of the grid

class Grid {
private:
    Robot* grid[grid_size][grid_size]; // 2D array representing the grid with Robot pointers
public:
    // Constructor for the Grid class
    Grid();

    // Getter method to retrieve a pointer to a Robot at a specific position on the grid
    Robot* getGrid(int i, int j);

    // Method to add a Robot to the grid at a specific position
    void addRobot(Robot* robot, int x, int y);

    // Method to place a new Robot randomly on the grid
    void placeRandomRobot(Robot* newRobot);

    // Method to simulate a round of actions for each Robot on the grid
    void simulateRound();

    // Method to handle a fight between two Robots on the grid
    void fight(Robot* currentRobot, int i, int j, int tempi, int tempj);
};

#endif // GRID_H
