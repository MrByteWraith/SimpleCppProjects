#include <iostream>
#include <string>
#include <vector>
#include "Robot.h"
#include "Grid.h"
#include "Kamikaze.h"
#include "Bulldozer.h"
#include "Roomba.h"
#include "Robocop.h"
#include "OptimusPrime.h"

using namespace std;

int main() {
    // Create instances of Kamikaze robots
    Kamikaze kamikaze_1("kamikaze_1");
    Kamikaze kamikaze_2("kamikaze_2");
    Kamikaze kamikaze_3("kamikaze_3");
    Kamikaze kamikaze_4("kamikaze_4");
    Kamikaze kamikaze_5("kamikaze_5");

    // Create instances of Bulldozer robots
    Bulldozer bulldozer_1("bulldozer_1");
    Bulldozer bulldozer_2("bulldozer_2");
    Bulldozer bulldozer_3("bulldozer_3");
    Bulldozer bulldozer_4("bulldozer_4");
    Bulldozer bulldozer_5("bulldozer_5");

     // Create instances of Roomba robots
    Roomba roomba_1("roomba_1");
    Roomba roomba_2("roomba_2");
    Roomba roomba_3("roomba_3");
    Roomba roomba_4("roomba_4");
    Roomba roomba_5("roomba_5");

    // Create instances of Robocop robots
    Robocop robocop_1("robocop_1");
    Robocop robocop_2("robocop_2");
    Robocop robocop_3("robocop_3");
    Robocop robocop_4("robocop_4");
    Robocop robocop_5("robocop_5");

     // Create instances of OptimusPrime robots
    OptimusPrime optimusprime_1("optimusprime_1");
    OptimusPrime optimusprime_2("optimusprime_2");
    OptimusPrime optimusprime_3("optimusprime_3");
    OptimusPrime optimusprime_4("optimusprime_4");
    OptimusPrime optimusprime_5("optimusprime_5");

    // Create a grid object
    Grid grid;
    // Create a vector to store active robots
    vector<Robot*> activeRobots;

    // Array of pointers to all robots
    Robot* robots[] = { &kamikaze_1, &kamikaze_2, &kamikaze_3, &kamikaze_4, &kamikaze_5,
                      &bulldozer_1, &bulldozer_2, &bulldozer_3, &bulldozer_4, &bulldozer_5,
                      &roomba_1, &roomba_2, &roomba_3, &roomba_4, &roomba_5,
                      &robocop_1, &robocop_2, &robocop_3, &robocop_4, &robocop_5,
                      &optimusprime_1, &optimusprime_2, &optimusprime_3, &optimusprime_4 };

    // Place each robot on the grid and add them to the activeRobots vector
    for (auto robot : robots) {
        grid.placeRandomRobot(robot);   // Place the robot on the grid
        activeRobots.push_back(robot);  // Add the robot to the activeRobots vector
    }
    
    int round = 1; // Round count
    do {
        cout << "Round: " << round << endl; // Display the current round number
        grid.simulateRound();   // Simulate actions for each robot on the grid

        // Update active robots
        vector<Robot*> stillActive;
        for (auto robot : activeRobots) {
            if (robot->getHp() > 0) {   // Check if the robot's health points are greater than 0
                stillActive.push_back(robot);   // Add the robot to the stillActive vector
            }
        }
        activeRobots = stillActive; // Update the activeRobots vector with the stillActive vector

        // Show active robots
        cout << "Active robots: ";  // Display message indicating active robots
        for (auto robot : activeRobots) {
            cout << robot->getName() << " ";     // Display the name of each active robot
        }
        cout << endl;   // Move to the next line for clarity

        if (activeRobots.size() <= 1) { // If there is only one or zero active robots left
            break;  // Exit the loop
        }
        round++;    // Increment the round count
        cout << "----------------------" << endl;   // Display a separator for clarity
    } while (!activeRobots.empty());    // Repeat the loop until there are no more active robots

    if (activeRobots.size() == 1) { // If there is exactly one active robot left
        cout << "Last robot standing: " << activeRobots.front()->getName() << endl; // Display the name of the last robot standing
    } else {
        cout << "No robots left standing." << endl;  // Display message indicating no robots left standing
    }

    return 0;
}
