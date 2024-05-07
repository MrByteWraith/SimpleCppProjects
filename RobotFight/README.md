## Robot Fight Simulator

This program simulates the fights between different kind of robots randomly.


## Inheritance

The program designed to be inherited from a base class, which is class Robot, to other classes.
There are 5 types of robots:
	
	1. Roomba
	2. Bulldozer
	3. Kamikaze
	4. Robocop
	5. Optimus Prime

The all these types inhareted from the class Robot, and the last two (Robocop-Optimus Prime) are inhareted one more step from the class Humanic.
You may see the diagram:


					* Roomba
				  	
		Robot (Base Class)--->	* Bulldozer
		
					* Humanic --->	* Robocop

							*Optimus Prime


## Attack Algorithm

All robots can inflict damage randomly based on their strength (STR). 
The method used "rand() % str + 1" is guarantees each robot can inflict damage at most STR.


## Properties Of Robots


	1. Roomba:
		* is fast, they attack twice.
		* HP: 10
		* STR: 3

	2. Bulldozer:
		* HP: 200
		* STR: 50

	3. Optimus Prime:
		* can double the whole attack with %15 chance.
		* can perform nuke attack with %10 chance (Humanic feature).
		* HP: 100
		* STR: 100

	4. Robocop:
		* can perform nuke attack with %10 chance (Humanic feature).
		* HP: 40
		* STR: 30

	5. Kamikaze:
		* inflict all the damage equals to its HP and eliminated after the attack.
		* HP: 10
		* STR: 10


## Placement Of Robots

A 10x10 grid is created and all robots placed randomly.


## Round Simulation

After the placement of robots is done, program will go through cells until it finds a robot which hasn't moved. 
The robot will be moved randomly until it come across another robot then Fight Simulation takes role. The rounds will continue until there is a last robot standing.


## Fight Simulation

When two robots come across, they fight to death. The first attack will be done by moving robot. If standing robot is alive after the attack, it attacks back.
When any of them die, it is removed from the grid.



## License

This program is licensed under the MIT License - see the LICENSE file for details.