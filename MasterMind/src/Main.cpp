#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "Mastermind.h"

using namespace std;

int main(int argc, char *argv[]) {
    const int max_digit = 15;

    if(argc != 3) {
        cout << "E1" << endl;
        return 1;
    }

    if(strcmp(argv[1],"-r") != 0 && strcmp(argv[1],"-u") != 0) {
        cout << "E0" << endl;
        return 1;
    }  

    char secret[max_digit + 1];

    srand(time(0)); // Seed for generating random numbers

    if(strcmp(argv[1], "-r") == 0) { // Start the program according to argument "r"
        int size_r = atoi(argv[2]); // Converting the second argument to int in case of "r" argument
        
        if(size_r <= 0 || size_r > max_digit) {
            cout << "E1" << endl;
            return 1;
        }

        Mastermind game;
        game.Generate_Number(secret, size_r);

        int turn = 1;
        int Cexact, Cmisplaced;
        while(turn <= 100) {
            char guess[max_digit + 1];
            cin >> guess;

            if(strlen(guess) != size_r) { // Check the size of input number is equal to provided size
                cout << "E1" << endl;
                return 1;
            }

            if(!game.Check_given_number(size_r, guess)) { // Check the input number doesn't contain repeated numbers and start with 0
                cout << "E0" << endl;
                return 1;
            }   

            game.Counting(secret, guess, size_r, Cexact, Cmisplaced);
            cout << Cexact  << " " << Cmisplaced << endl;

            if(Cexact == size_r) {
                cout << "FOUND" << endl;
                return 0;
            }

            turn++;
        }   

        cout << "FAILED" << endl;
        return 0;     
    }

    if(strcmp(argv[1], "-u") == 0) { // Start the program according to the argument "u"
        int size_u = strlen(argv[2]); // Using the length of the second argument to determine the size in case of "u" argument
        
        if(size_u <= 0 || size_u > max_digit) {
            cout << "E1" << endl;
            return 1;
        }

        char *given_num = argv[2];

        if(!Check_given_number(size_u, given_num)) { // Check the given secret doesn't start with 0 and contain repeated numbers
            cout << "E0" << endl;
            return 1;
        }
    
        for(int i = 0; i < size_u; ++i) {
            secret[i] = given_num[i]; // Putting the digits of given secret number to "secret" array
        }

        int turn = 1;
        int Cexact, Cmisplaced;
        while(turn <= 100) {
            char guess[max_digit + 1];
            cin >> guess;

            if(strlen(guess) != size_u) {
                cout << "E1" << endl;
                return 1;
            }

            if(!Check_given_number(size_u, guess)) {
                cout << "E0" << endl;
                return 1;
            }   

            Counting(secret, guess, size_u, Cexact, Cmisplaced);
            cout << Cexact  << " " << Cmisplaced << endl;

            if(Cexact == size_u) {
                cout << "FOUND" << endl;
                return 0;
            }

            turn++;
        }   

        cout << "FAILED" << endl;
        return 0;   
    }

    return 0;
}
