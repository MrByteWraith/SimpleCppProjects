## MasterMind

This C++ project is a simulation game of number guessing. 


## Modes

The program can be run in two different mode.

	1. Mode R (-r): In this mode, computer will generate a random number. User is expected to guess it in less than 100 rounds.
	2. Mode U (-u): The program will let the user give a number with some restrictions. 

These modes can be seen as Human vs Computer for the first and Human vs Human for the second.


## Features

Generated (or given) numbers will have following properties:

	1. It can have up to 15 digits.
	2. It must have at least 1 digit.
	3. The digits will be chosen from the list {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e}.
	4. There will be no repetitive digits.
	5. Guessings must not exceed 15 digits.
	6. Guessings must not have repetitive digits.
	7. Digits of guessings must be chosen from the list {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e}.
	8. Both guessings and generated numbers cannot start with 0.
	9. Generated numbers will always start with a number (given numbers may not).

If these features are not followed, users may end up with an error code E0 or E1 depending on the violation.


## Installation

To use this library, follow these steps:

	1. Clone the repository: `git clone https://github.com/MrByteWraith/SimpleCppProjects/MasterMind.git`
	2. Include the necessary header files (`Mastermind.h`) in your project.
	3. Compile the source files (`Mastermind.cpp` and `Main.cpp`) along with your project.



## Usage

Compilation and Execution:

	1. g++ Main.cpp Mastermind.cpp -o MasterMind
	2. For Mode R: .\MasterMind -r [NUMBEROFDIGITS]
	3. For Mode U: .\MasterMind -u [INPUTNUMBER]


## Explanation

The main.cpp file orchestrates the Mastermind game and carries out the following steps:

	1. Argument Validation: Checks if the correct number of command-line arguments is provided. If not, it displays an error message (E1) and exits.
	2. Mode Verification: Validates whether the specified mode is either random (-r) or user-specified (-u). If not, it displays an error message (E0) and exits.
	3. Secret Code Initialization:
		- In the random mode:
			- Generates a random secret code based on the provided size.
		- In the user-specified mode:
			- Validates the provided user-specified secret code.
			-Initializes the secret code with the provided value.
	4. Game Loop:
		- Executes the game loop, allowing the player up to 100 guesses to crack the secret code.
		- For each guess:
			- Validates the guess against the specified mode's requirements.
			- Counts the number of exact and misplaced digits in the guess.
			- Provides feedback on the guess by displaying the counts of exact and misplaced digits.
			- Checks if the guess matches the secret code. If so, displays "FOUND" and exits the loop.
	5. Game Termination:
		- If the secret code is not cracked within 100 guesses, displays "FAILED" and terminates the game.


## Dependencies

This program has no external dependencies beyond the standard C++ library.



## License
This program is licensed under the MIT License - see the LICENSE file for details.
