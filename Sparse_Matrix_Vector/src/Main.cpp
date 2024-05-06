#include <iostream>
#include <fstream>
#include <string>
#include "SparseVector.h"
#include "SparseMatrix.h"

using namespace std;


int main()
{
    ofstream outfile;
    outfile.open("output.txt", ios::out | ios::trunc);


    SparseVector a1("a1.txt");
    outfile << "a1" << endl << a1 << endl;


    a1 = a1 + a1;
    outfile << "a1" << endl << a1 << endl;


    SparseMatrix m1("m1.txt");
    SparseMatrix m2("m2.txt");

    outfile << "m2" << endl << m2 << endl;

    outfile << m2.transpose() << endl;

    outfile << dot(a1, a1) << endl;

    return 0;
}