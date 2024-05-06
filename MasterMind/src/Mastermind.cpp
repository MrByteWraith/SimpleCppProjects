#include "Mastermind.h"

// Constructor
Mastermind::Mastermind() {}

// Destructor
Mastermind::~Mastermind() {}

// Function to check if the given number is valid
bool Mastermind::Check_Valid(int size, char *num) {
    if(size > max_digit) return false;
    if(num[0] == '0') return false;
    return true;
}

// Function to check if the given number contains valid elements without repetition
bool Mastermind::Check_given_number(int size, char *num) {
    if(num[0] == '0') return false;                  //Checking first digit
    
    bool found_elements[max_digit] = {false};        //Array for used digits
    
    for(int i = 0; i < size; ++i) {
        bool found = false;
        for(int j = 0; j < max_digit; ++j) {         //Checking repeating numbers
            if(num[i] == elements[j]) {
                if(found_elements[j]) 
                    return false; 
                
                found_elements[j] = true; 
                found = true;
                break;
            }
        }
        if(!found) return false;
    }
    
    return true;
}

// Function to generate a random number
void Mastermind::Generate_Number(char *num, int size) {
    bool selected_number[max_digit] = {false};
    num[0] = elements[rand() % 9 + 1];
    selected_number[num[0] - '0'] = true;
    for(int i = 1; i < size; ++i) {
        int random_index;
        do {                                  //Mechanism to generate unique digits
            random_index = rand() % 16;
        } while (selected_number[random_index]);
        num[i] = elements[random_index];
        selected_number[random_index] = true;
    }
}

// Function to count the exact and misplaced digits
void Mastermind::Counting(const char *secret, const char *guess, int size, int &Cexact, int &Cmisplaced) {
    Cexact = 0;
    Cmisplaced = 0;
    
    for(int i = 0; i < size; ++i) {        
        if(secret[i] == guess[i]) {                 //Guessing the digits of secret correct in place
            ++Cexact;
        }
        else {
            for(int j = 0; j < size; ++j) {
                if (secret[i] == guess[j] && i != j) {       //Guessing the the digits of secret correct but misplaced
                    ++Cmisplaced;
                    break;
                }
            }
        }
    }
}
