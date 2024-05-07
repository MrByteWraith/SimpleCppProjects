#include "Grid.h" // Include the header file for the Grid class
#include <iostream> // Include the necessary header for input/output
#include <ctime> // Include the header for time-related functions

// Constructor for the Grid class
Grid::Grid() {
    // Initialize the grid with nullptrs
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            grid[i][j] = nullptr;
        }
    }
}

// Getter method to retrieve a pointer to a Robot at a specific position on the grid
Robot* Grid::getGrid(int i, int j) {
    return grid[i][j];
}

// Method to add a Robot to the grid at a specific position
void Grid::addRobot(Robot* robot, int x, int y) {
    if (x >= 0 && x < grid_size && y >= 0 && y < grid_size) {
        grid[x][y] = robot;
    }
}

// Method to place a new Robot randomly on the grid
void Grid::placeRandomRobot(Robot* newRobot) {
    srand(time(0)); // Seed the random number generator with the current time
    for (int i = 0; i < 25; ++i) { // Attempt to place the robot 25 times
        int x = rand() % grid_size; // Generate random x coordinate
        int y = rand() % grid_size; // Generate random y coordinate
        Robot* cell = grid[x][y]; // Get the robot at the generated coordinates
        while (cell != nullptr) { // If the cell is not empty, find another random position
            x = rand() % grid_size;
            y = rand() % grid_size;
            cell = grid[x][y];
            if (cell == nullptr) {
                break;
            }
        }
        addRobot(newRobot, x, y); // Add the new robot to the grid at the generated coordinates
        break; // Exit the loop after placing the robot once
    }
}

// Method to simulate a round of actions for each Robot on the grid
void Grid::simulateRound() {
    // Reset the moved flag for all robots on the grid
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->setMoved(false);
            }
        }
    }

    // Iterate through each cell on the grid
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            if (grid[i][j] != nullptr && !grid[i][j]->hasMoved()) { // If the cell contains a robot and it hasn't moved yet
                Robot* currentRobot = grid[i][j]; // Get the current robot

                int tempi;
                int tempj;
                while (true) {
                    int direction = rand() % 4; // Generate a random direction (0: up, 1: down, 2: left, 3: right)

                    int newX = i;
                    int newY = j;

                    switch (direction) { // Update the new position based on the random direction
                        case 0:
                            newX--;
                            break;
                        case 1:
                            newX++;
                            break;
                        case 2:
                            newY--;
                            break;
                        case 3:
                            newY++;
                            break;
                    }

                    if (newX >= 0 && newX < grid_size && newY >= 0 && newY < grid_size) { // Check if the new position is within the grid boundaries
                        if (grid[newX][newY] == nullptr) { // If the new position is empty
                            grid[newX][newY] = currentRobot; // Move the current robot to the new position
                            grid[i][j] = nullptr; // Set the old position to nullptr
                            i = newX; // Update the current position
                            j = newY;
                        } else { // If the new position is occupied by another robot, stop moving
                            tempi = newX;
                            tempj = newY;
                            break;
                        }
                    } else { // If the new position is outside the grid boundaries, continue moving in other directions
                        continue;
                    }
                }

                // If the opponent robot hasn't moved yet, fight
                if (!grid[tempi][tempj]->hasMoved()) {
                    currentRobot->setMoved(true); // Mark the current robot as moved
                    fight(currentRobot, i, j, tempi, tempj); // Initiate a fight between the current robot and the opponent
                    break; // Exit the loop after the fight
                }
            }
        }
    }
}

// Method to handle a fight between two Robots on the grid
void Grid::fight(Robot* currentRobot, int i, int j, int tempi, int tempj) {
    Robot* opponentRobot = grid[tempi][tempj]; // Get the opponent robot
    while (currentRobot->getHp() > 0 && opponentRobot->getHp() > 0) { // While both robots are alive
        int temphp = currentRobot->getHp(); // Get the current hit points of the current robot
        int dmg_c = currentRobot->getDamage(); // Get the damage inflicted by the current robot
        cout << currentRobot->getName() << "(" << temphp << ") hits " << opponentRobot->getName() << "(" << opponentRobot->getHp() << ") with " << dmg_c << endl; // Print the attack message
        opponentRobot->takeDamage(dmg_c); // Inflict damage on the opponent robot
        cout << "The new hitpoints of " << opponentRobot->getName() << " is " << opponentRobot->getHp() << endl; // Print the new hit points of the opponent robot
        if (opponentRobot->getHp() > 0) { // If the opponent robot is still alive
            int temphp2 = opponentRobot->getHp(); // Get the current hit points of the opponent robot
            int dmg_o = opponentRobot->getDamage(); // Get the damage inflicted by the opponent robot
            cout << opponentRobot->getName() << "(" << temphp2 << ") hits " << currentRobot->getName() << "(" << currentRobot->getHp() << ") with " << dmg_o << endl; // Print the attack message
            currentRobot->takeDamage(dmg_o); // Inflict damage on the current robot
            cout << "The new hitpoints of " << currentRobot->getName() << " is " << currentRobot->getHp() << endl; // Print the new hit points of the current robot
        }
    }
    if (currentRobot->getHp() <= 0) { // If the current robot is destroyed
        cout << currentRobot->getName() << " has been destroyed!" << endl; // Print the destruction message
        grid[i][j] = nullptr; // Set the grid cell to nullptr
    }
    if (opponentRobot->getHp() <= 0) { // If the opponent robot is destroyed
        cout << opponentRobot->getName() << " has been destroyed!" << endl; // Print the destruction message
        grid[tempi][tempj] = currentRobot; // Move the current robot to the opponent's cell
        grid[i][j] = nullptr; // Set the grid cell to nullptr
    }
}
