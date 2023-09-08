#ifndef _MATRIX_H
#define _MATRIX_H

#include <iostream>
using namespace std;

class Matrix
{
public:
    // default constructor
    Matrix();

    // first parametrized constructor
    Matrix(size_t num_rows, size_t num_columns, float init);

    // second parametrized constructor
    Matrix(size_t num_rows, size_t num_columns, float *arr_ptr);

    // copy constructor (creates a deepcopy)
    Matrix(const Matrix &copy);

    // destructor
    ~Matrix();

    // Matrix addition
    Matrix operator+(const Matrix &rhs) const;

    // Matrix subtraction
    Matrix operator-(const Matrix &rhs) const;

    // Matrix multiplication
    Matrix operator*(const Matrix &rhs) const;

    // Matrix Negation
    Matrix operator-() const;

    // Matrix transposition
    Matrix transpose() const;

    // Bracket operator for accessing element as float pointer
    float *operator[](unsigned int index);

    // Const bracket operator for accessing element as float pointer
    const float *operator[](unsigned int index) const;

    // Stream insertion operator
    friend std::ostream &operator<<(ostream &os, const Matrix &matrix);

    // Stream extraction operator
    friend std::istream &operator>>(istream &is, Matrix &matrix);

    // public attributes
    unsigned int rows, columns, size;

private:
    // private attribute for storing the pointer-to-pointers of rows
    float **matrix;
};

#endif