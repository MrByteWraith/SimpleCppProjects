# Sparse Vector and Matrix Operations

This C++ library provides functionalities for performing operations on sparse vectors and matrices efficiently.



## Features
	- Addition of sparse vectors and matrices.
	- Subtraction of sparse vectors and matrices.
	- Negation of sparse vectors and matrices.
	- Dot product of sparse vectors.
	- Matrix multiplication.
	- Transposition of matrices.



## Installation

To use this library, follow these steps:

	1. Clone the repository: `git clone https://github.com/your-username/sparse-vector-matrix.git`
	2. Include the necessary header files (`SparseVector.h` and `SparseMatrix.h`) in your project.
	3. Compile the source files (`SparseVector.cpp` and `SparseMatrix.cpp`) along with your project.



## Usage

Compilation and Execution:

	1. g++ main.cpp SparseVector.cpp SparseMatrix.cpp -o main
	2. ./main


## Input File

Sparse Vector Format:

	<index>:<data> <index>:<data> <index>:<data> ...

Sparse Matrix Format:

	<row_index> <index>:<data> <index>:<data> <index>:<data> ...
	<row_index> <index>:<data> <index>:<data> <index>:<data> ...
	<row_index> <index>:<data> <index>:<data> <index>:<data> ...
	.
	.
	.


## Output File

The output file 'output.txt' will contain the results of the operations performed by the program.
	


##Explanation

The main.cpp file performs the following operations:

	1.Initializes a sparse vector a1 from data in the file "a1.txt".
	2.Writes the contents of a1 to the output file.
	3.Performs addition operation a1 + a1 and assigns the result back to a1.
	4.Writes the updated a1 to the output file.
	5.Initializes sparse matrices m1 and m2 from data in files "m1.txt" and "m2.txt" respectively.
	6.Writes the contents of m2 to the output file.
	7.Writes the transpose of m2 to the output file.
	8.Calculates the dot product of a1 with itself and writes the result to the output file.



## Dependencies

This program has no external dependencies beyond the standard C++ library.



## License
This program is licensed under the MIT License - see the LICENSE file for details.
