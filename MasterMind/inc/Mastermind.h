#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

class Mastermind {
private:
    const int max_digit = 15;
    const char elements[15] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e'};
    
public:
    // Constructor
    Mastermind();
    
    // Destructor
    ~Mastermind();
    
    // Function to check if the given number is valid
    bool Check_Valid(int size, char *num);
    
    // Function to check if the given number contains valid elements without repetition
    bool Check_given_number(int size, char *num);
    
    // Function to generate a random number
    void Generate_Number(char *num, int size);
    
    // Function to count the exact and misplaced digits
    void Counting(const char *secret, const char *guess, int size, int &Cexact, int &Cmisplaced);
};

#endif /* MASTERMIND_H */
