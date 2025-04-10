#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>      // for I/O
#include <vector>        // for matrix data
#include <iomanip>       // for formatting output
#include <cstddef>       // for size_t
#include <stdexcept>     // for bounds checking
#include <fstream>       // for reading from file

using namespace std;     // no std:: everywhere

// template class to support both int and double matrices
template <typename T>
class Matrix {
private:
    vector<vector<T>> data;  //2D vector to store matrix values
    size_t size;    //size of the square matrix (N)

public:
    // constructor to create N x N matrix filled with zeros
    Matrix(size_t N) : size(N), data(N, vector<T>(N)) {}

    // constructor to create matrix with predefined 2D vector
    Matrix(const vector<vector<T>>& nums) : size(nums.size()), data(nums) {}

    // reads matrix data from input stream
    void read(istream& in) {
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                in >> data[i][j]; //read element by element
    }

    // overload + operator to add two matrices
    Matrix<T> operator+(const Matrix<T>& rhs) const {
        Matrix<T> result(size); // create result matrix
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result.data[i][j] = data[i][j] + rhs.data[i][j];
        return result;
    }

    // overload * operator to multiply two matrices
    Matrix<T> operator*(const Matrix<T>& rhs) const {
        Matrix<T> result(size); //create result matrix initialized to 0
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                for (size_t k = 0; k < size; ++k)
                    result.data[i][j] += data[i][k] * rhs.data[k][j];
        return result;
    }

    // update a specific element in the matrix
    void set_value(size_t i, size_t j, T val) {
        if (i < size && j < size)
            data[i][j] = val;
    }

    // return a specific element in the matrix
    T get_value(size_t i, size_t j) const {
        return (i < size && j < size) ? data[i][j] : T(); //return 0 or 0.0 if invalid
    }

    // return matrix size
    size_t get_size() const {
        return size;
    }

    // sum of main (major) diagonal (top-left to bottom-right)
    T sum_diagonal_major() const {
        T sum = 0;
        for (size_t i = 0; i < size; ++i)
            sum += data[i][i];
        return sum;
    }

    // sum of secondary (minor) diagonal (top-right to bottom-left)
    T sum_diagonal_minor() const {
        T sum = 0;
        for (size_t i = 0; i < size; ++i)
            sum += data[i][size - 1 - i];
        return sum;
    }

    // swap two rows (by index)
    void swap_rows(size_t r1, size_t r2) {
        if (r1 < size && r2 < size)
            swap(data[r1], data[r2]);
    }

    // swap two columns (by index)
    void swap_cols(size_t c1, size_t c2) {
        if (c1 < size && c2 < size) {
            for (size_t i = 0; i < size; ++i)
                swap(data[i][c1], data[i][c2]);
        }
    }

    // print matrix with proper formatting
    void print() const {
        for (const auto& row : data) {
            for (const auto& val : row)
                cout << setw(6) << val << " "; // align columns
            cout << "\n";
        }
    }
};

//generic function to update a matrix element (supports both int/double)
template <typename T>
void update_value(Matrix<T>& mat, size_t row, size_t col, T new_val) {
    mat.set_value(row, col, new_val);
}

#endif // __MATRIX_HPP__
