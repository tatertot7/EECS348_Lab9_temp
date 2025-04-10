#include <iostream>      // for input/output
#include <fstream>       // for file I/O
#include <string>        // for std::string
#include <iomanip>       // for formatting output
#include "matrix.hpp"    // include custom Matrix class

using namespace std;     // no std::

int main(int argc, char *argv[]) {
    // check that the user provides exactly one argument (filename)
    if (argc != 2) {
        cerr << "Usage: ./matrix.exe <input_file>" << endl;
        return 1;
    }

    // open the input file
    ifstream infile(argv[1]);
    if (!infile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // read matrix size and type flag (0 = int, 1 = double)
    size_t N;
    int type_flag;
    infile >> N >> type_flag;

    // handle integer matrices
    if (type_flag == 0) {
        Matrix<int> A(N), B(N);  // declare two int matrices of size N
        A.read(infile);          // read matrix A
        B.read(infile);          // read matrix B

        cout << "Matrix A:\n";
        A.print();

        cout << "Matrix B:\n";
        B.print();

        cout << "A + B:\n";
        (A + B).print(); //add matrices and print result

        cout << "A * B:\n";
        (A * B).print(); // multiply matrices and print result

        cout << "Sum of major diagonal of A: " << A.sum_diagonal_major() << "\n";
        cout << "Sum of minor diagonal of A: " << A.sum_diagonal_minor() << "\n";

        A.swap_rows(0, 1); // swap rows 0 and 1
        cout << "A after swapping rows 0 and 1:\n";
        A.print();

        A.swap_cols(0, 1); // swap columns 0 and 1
        cout << "A after swapping columns 0 and 1:\n";
        A.print();

        update_value(A, 1, 1, 42); // update A[1][1] to 42
        cout << "A after updating (1,1) to 42:\n";
        A.print();

    // handle double matrices
    } else if (type_flag == 1) {
        Matrix<double> A(N), B(N);
        A.read(infile);
        B.read(infile);

        cout << fixed << setprecision(2); // set float output precision

        //print matrix a
        cout << "Matrix A:\n";
        A.print();

        //print matrix b
        cout << "Matrix B:\n";
        B.print();

        //print a+b
        cout << "A + B:\n";
        (A + B).print();

        //print a*b
        cout << "A * B:\n";
        (A * B).print();

        //diagonals
        cout << "Sum of major diagonal of A: " << A.sum_diagonal_major() << "\n";
        cout << "Sum of minor diagonal of A: " << A.sum_diagonal_minor() << "\n";

        //print swapped rows
        A.swap_rows(0, 1);
        cout << "A after swapping rows 0 and 1:\n";
        A.print();

        //print swapped cols
        A.swap_cols(0, 1);
        cout << "A after swapping columns 0 and 1:\n";
        A.print();

        //print with updated value
        update_value(A, 1, 1, 42.42);
        cout << "A after updating (1,1) to 42.42:\n";
        A.print();
    }

    return 0;
}